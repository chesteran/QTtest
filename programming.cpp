#include "programming.h"
#include "ui_programming.h"

ProGramming::ProGramming(QWidget *parent, QString equ) :
    QMainWindow(parent),
    ui(new Ui::ProGramming)
{
    ui->setupUi(this);
    ui->textEdit->insertPlainText(equ);
}

ProGramming::~ProGramming()
{
    delete ui;
}

void ProGramming::on_calculate_clicked()
{
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

            QFile in;
            in.setFileName("Mat.csv");
            in.open(QIODevice::ReadOnly);
            QTextStream is(&in);
            is.setCodec("UTF-8");
            QByteArray line;
            vector<QString> foodName;

            int row = 0;
            while(!in.atEnd()) {
                line = in.readLine();
                if (row > 0) {
                    foodName.push_back(line.split(',').at(1));
                }
                row++;
            }

            QFile out;
            out.setFileName("recipe.txt");
            out.open(QIODevice::WriteOnly | QIODevice::Text);
            QTextStream os(&out);
            os.setCodec("UTF-8");
            for (int k = 0; k < NUM_FOOD; k++) {
                if (model.getVar(k).get(GRB_DoubleAttr_X) > 0) {
                    os << foodName.at(k) << "*";
                }
                //cout << "x" << k << ": " << model.getVar(k).get(GRB_DoubleAttr_X) << endl;
            }
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
}
