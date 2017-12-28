#include <QFile>
#include <QTextStream>
#include <iostream>
#include "gurobi_c++.h"

#define FOOD_NUM 427
#define M 1000000

enum _nutrition {
    cost,
    calorie,
    protien,
    carbohydrate,
    vitaminA,
    calcium,
    fat,
    cholesterol,
    sodium,
    fiber,
    vitaminC
};

using namespace std;

int main(int argc, char *argv[])
{
    double table[FOOD_NUM][11];
    int objective;
    int target[11] = {0};
    int ignore[11] = {0};
    int constraintNum = 0;
    int errVarNum = 0;
    QString limit[11];
    QString line;
    QStringList stringList;
    QFile inFile("mat.csv");
    QFile outFile("model.lp");
    QTextStream textStream;

    for (int i = 0; i < 11; ++i) {
        limit[i] = QString(" >= ");
    }

    if (argc != 2) {
        cerr << "argc" << endl;
        exit(1);
    }

    /*
     * read file
     * nutrition data
     */
    inFile.open(QIODevice::ReadOnly | QIODevice::Text);
    if (!inFile.isOpen()) {
        cerr << "file" << endl;
        exit(1);
    }
    for (int row = 0; !inFile.atEnd(); ++row) {
        line = inFile.readLine();
        stringList = line.split(QRegExp("\n|\r\n|\r|,"));
        if (row > 0) {
            for (int i = 0; i < 11; i++) {
                table[row - 1][i] = stringList.at(i + 2).toDouble();
            }
        }
    }
    inFile.close();

    /*
     * read file
     * objective, target[], ignore[]
     */
    inFile.setFileName(argv[1]);
    inFile.open(QIODevice::ReadOnly | QIODevice::Text);
    if (!inFile.isOpen()) {
        cerr << "file" << endl;
        exit(1);
    }
    line = inFile.readLine();
    stringList = line.split(QRegExp("\n|\r\n|\r|,"));
    objective = stringList.at(1).toInt();
    for (int i = 1; i < 11; ++i) {
        line = inFile.readLine();
        stringList = line.split(QRegExp("\n|\r\n|\r|,"));
        target[i] = stringList.at(0).toInt();
        ignore[i] = stringList.at(1).toInt();
    }
    inFile.close();

    /*
     * write file
     * lp model
     */
    outFile.open(QIODevice::WriteOnly | QIODevice::Text);
    textStream.setDevice(&outFile);

    // objective function
    textStream << "Minimize" << endl;
    textStream << " ";
    switch (objective) {
    case 0: // cost
        for (int i = 0; i < FOOD_NUM; i++) {
            textStream << table[i][0] << " x" << i << " + ";
        }
        break;
    case 1: // calorie
        for (int i = 0; i < FOOD_NUM; i++) {
            textStream << table[i][1] << " x" << i << " + ";
        }
        break;
    case 2: // carbohydrate
        for (int i = 0; i < FOOD_NUM; i++) {
            textStream << table[i][3] << " x" << i << " + ";
        }
        break;
    case 3: // protien fat ratio
        for (int i = 0; i < FOOD_NUM; i++) {
            textStream << table[i][2]/(table[i][6] + 1) << " x" << i << " + ";
        }
        break;
    case 4: // fat
        for (int i = 0; i < FOOD_NUM; i++) {
            textStream << table[i][6] << " x" << i << " + ";
        }
        break;
    default:
        break;
    }
    textStream << "[ e0 ^ 2";
    for (int i = 1; i < 10; ++i) {
        textStream << " + e" << i << " ^ 2";
    }
    textStream << " ]" << endl;

    // constraint
    textStream << "Subject To" << endl;
    for (int i = 0; i < 11; ++i) {
        if ((objective == 0 && i == cost)
                || (objective == 1 && i == calorie)
                || (objective == 2 && i == carbohydrate)
                || (objective == 3 && i == protien)
                || (objective == 3 && i == fat)
                || (objective == 4 && i == protien)) {
            continue;
        } else {
            textStream << " c" << constraintNum++ << ": e" << errVarNum++;
            for (int j = 0; j < FOOD_NUM; j++) {
               textStream << " + " << table[j][i] << " x" << j;
            }
            textStream << limit[i] << target[i] << endl;
        }
    }

    /*
     * M * y >= x
     * M * x >= y
     */
    for (int i = 0; i < FOOD_NUM; ++i) {
        textStream << " c" << constraintNum++ << ": x" << i << " - " << M << " y" << i << " <= 0" << endl;
        textStream << " c" << constraintNum++ << ": y" << i << " - " << M << " x" << i << " <= 0" << endl;
    }

    /*
     * SUM(Y) = 3
     */
    textStream << " c" << constraintNum++ << ": ";
    for (int i = 0; i < FOOD_NUM - 1; ++i) {
        textStream << "y" << i << " + ";
    }
    textStream << "y" << FOOD_NUM - 1 << " = 3" << endl;

    // variable
    textStream <<"Bounds" << endl;
    textStream <<"Binary" << endl;
    for (int i = 0; i < FOOD_NUM; i++) {
        textStream << " y" << i;
    }
    textStream << endl << "Integer" << endl;
    for (int i = 0; i < FOOD_NUM; i++) {
        textStream << " x" << i;
    }
    for (int i = 0; i < 10; ++i) {
        textStream << " e" << i;
    }
    textStream << endl << "END" << endl;
    outFile.close();

    /*
     * call gurobi solver
     * read file
     * foodName[]
     * write file
     */
    try {
        GRBEnv env = GRBEnv();
        GRBModel model = GRBModel(env, "model.lp");

        model.optimize();

        int optimstatus = model.get(GRB_IntAttr_Status);

        if (optimstatus == GRB_INF_OR_UNBD) {
            model.set(GRB_IntParam_Presolve, 0);
            model.optimize();
            optimstatus = model.get(GRB_IntAttr_Status);
        }

        if (optimstatus == GRB_OPTIMAL) {
            double objval = model.get(GRB_DoubleAttr_ObjVal);
            cout << "Optimal objective: " << objval << endl;

            inFile.setFileName("mat.csv");
            inFile.open(QIODevice::ReadOnly | QIODevice::Text);
            vector<QString> foodName;

            int row = 0;
            while(!inFile.atEnd()) {
                line = inFile.readLine();
                if (row > 0) {
                    foodName.push_back(line.split(',').at(1));
                }
                row++;
            }
            inFile.close();

            outFile.setFileName("recipe.txt");
            outFile.open(QIODevice::WriteOnly | QIODevice::Text);
            textStream.setDevice(&outFile);
            textStream.setCodec("UTF-8");
            for (int k = 0; k < FOOD_NUM; k++) {
                if (model.getVar(k).get(GRB_DoubleAttr_X) > 0) {
                    textStream << foodName.at(k) << "*";
                }
            }
            outFile.close();
        } else if (optimstatus == GRB_INFEASIBLE) {
            cout << "Model is infeasible" << endl;
            // compute and write out IIS
            model.computeIIS();
            model.write("model.ilp");
        } else if (optimstatus == GRB_UNBOUNDED) {
            cout << "Model is unbounded" << endl;
        } else {
            cout << "Optimization was stopped with status = "
                 << optimstatus << endl;
        }
    } catch(GRBException e) {
        cout << "Error code = " << e.getErrorCode() << endl;
        cout << e.getMessage() << endl;
    } catch(...) {
        cout << "Exception during optimization" << endl;
    }

    return 0;
}
