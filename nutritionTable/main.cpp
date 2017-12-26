#include <QFile>
#include <QTextStream>
#include <iostream>

using namespace std;

enum _nutrition {
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

int main(int argc, char *argv[])
{
    int gender;
    int age;
    int nutrition[10] = {0};
    int ignore[10] = {0};
    QFile inFile(argv[1]);
    QFile outFile(argv[2]);

    if (argc != 3)
    {
        cerr << "argc" << endl;
        exit(1);
    }

    /*
     * read file
     * gender, age
     */
    inFile.open(QIODevice::ReadOnly | QIODevice::Text);
    if (!inFile.isOpen()) {
        cerr << "file" << endl;
        exit(1);
    }
    QString string = inFile.readLine();
    QStringList stringList = string.split(QRegExp("\n|\r\n|\r|,"));
    if (stringList.at(0) == "male")
    {
        gender = 0;
    }
    else if (stringList.at(0) == "female")
    {
        gender = 1;
    }
    else
    {
        cerr << "gender" << endl;
        exit(1);
    }
    age = stringList.at(1).toInt();
    inFile.close();

    /*
     * determine dietary reference intake(DRI)
     */
    if (gender  ==  0)
    {
        if (age > 0 && age <= 15)
        {
            nutrition[calorie] = 2800;
            nutrition[cholesterol] = 0;
            nutrition[fat] = 0;
            nutrition[sodium] = 0;
            nutrition[carbohydrate] = 0;
            nutrition[fiber] = 0;
            nutrition[protien] = 70;
            nutrition[vitaminA] = 600;
            nutrition[vitaminC] = 100;
            nutrition[calcium] = 1200;
        }
        else if (age > 15 && age <= 20)
        {
            nutrition[calorie] = 2900;
            nutrition[cholesterol] = 0;
            nutrition[fat] = 0;
            nutrition[sodium] = 0;
            nutrition[carbohydrate] = 0;
            nutrition[fiber] = 0;
            nutrition[protien] = 75;
            nutrition[vitaminA] = 700;
            nutrition[vitaminC] = 100;
            nutrition[calcium] = 1200;
        }
        else if (age > 20  &&  age <= 30)
        {
            nutrition[calorie] = 2400;
            nutrition[cholesterol] = 0;
            nutrition[fat] = 0;
            nutrition[sodium] = 0;
            nutrition[carbohydrate] = 0;
            nutrition[fiber] = 0;
            nutrition[protien] = 60;
            nutrition[vitaminA] = 600;
            nutrition[vitaminC] = 100;
            nutrition[calcium] = 1200;
        }
        else if (age > 30 && age <= 40)
        {
            nutrition[calorie] = 2400;
            nutrition[cholesterol] = 0;
            nutrition[fat] = 0;
            nutrition[sodium] = 0;
            nutrition[carbohydrate] = 0;
            nutrition[fiber] = 0;
            nutrition[protien] = 60;
            nutrition[vitaminA] = 600;
            nutrition[vitaminC] = 100;
            nutrition[calcium] = 1200;
        }
        else if (age > 40 && age <= 50)
        {
            nutrition[calorie] = 2400;
            nutrition[cholesterol] = 0;
            nutrition[fat] = 0;
            nutrition[sodium] = 0;
            nutrition[carbohydrate] = 0;
            nutrition[fiber] = 0;
            nutrition[protien] = 60;
            nutrition[vitaminA] = 600;
            nutrition[vitaminC] = 100;
            nutrition[calcium] = 1200;
        }
        else if (age > 50 && age <= 60)
        {
            nutrition[calorie] = 2250;
            nutrition[cholesterol] = 0;
            nutrition[fat] = 0;
            nutrition[sodium] = 0;
            nutrition[carbohydrate] = 0;
            nutrition[fiber] = 0;
            nutrition[protien] = 55;
            nutrition[vitaminA] = 600;
            nutrition[vitaminC] = 100;
            nutrition[calcium] = 1000;
        }
        else if (age > 60)
        {
            nutrition[calorie] = 2150;
            nutrition[cholesterol] = 0;
            nutrition[fat] = 0;
            nutrition[sodium] = 0;
            nutrition[carbohydrate] = 0;
            nutrition[fiber] = 0;
            nutrition[protien] = 60;
            nutrition[vitaminA] = 600;
            nutrition[vitaminC] = 100;
            nutrition[calcium] = 1000;
        }
    }
    else if (gender == 1)
    {
        if (age > 0 && age <= 15)
        {
            nutrition[calorie] = 2350;
            nutrition[cholesterol] = 0;
            nutrition[fat] = 0;
            nutrition[sodium] = 0;
            nutrition[carbohydrate] = 0;
            nutrition[fiber] = 0;
            nutrition[protien] = 70;
            nutrition[vitaminA] = 600;
            nutrition[vitaminC] = 100;
            nutrition[calcium] = 1200;
        }
        else if (age > 15 && age <= 20)
        {
            nutrition[calorie] = 2250;
            nutrition[cholesterol] = 0;
            nutrition[fat] = 0;
            nutrition[sodium] = 0;
            nutrition[carbohydrate] = 0;
            nutrition[fiber] = 0;
            nutrition[protien] = 55;
            nutrition[vitaminA] = 500;
            nutrition[vitaminC] = 100;
            nutrition[calcium] = 1200;
        }
        else if (age > 20 && age <= 30)
        {
            nutrition[calorie] = 1900;
            nutrition[cholesterol] = 0;
            nutrition[fat] = 0;
            nutrition[sodium] = 0;
            nutrition[carbohydrate] = 0;
            nutrition[fiber] = 0;
            nutrition[protien] = 50;
            nutrition[vitaminA] = 500;
            nutrition[vitaminC] = 100;
            nutrition[calcium] = 1200;
        }
        else if (age > 30 && age <= 40)
        {
            nutrition[calorie] = 1900;
            nutrition[cholesterol] = 0;
            nutrition[fat] = 0;
            nutrition[sodium] = 0;
            nutrition[carbohydrate] = 0;
            nutrition[fiber] = 0;
            nutrition[protien] = 50;
            nutrition[vitaminA] = 500;
            nutrition[vitaminC] = 100;
            nutrition[calcium] = 1200;
        }
        else if (age > 40 && age <= 50)
        {
            nutrition[calorie] = 1900;
            nutrition[cholesterol] = 0;
            nutrition[fat] = 0;
            nutrition[sodium] = 0;
            nutrition[carbohydrate] = 0;
            nutrition[fiber] = 0;
            nutrition[protien] = 50;
            nutrition[vitaminA] = 500;
            nutrition[vitaminC] = 100;
            nutrition[calcium] = 1200;
        }
        else if (age > 50 && age <= 60)
        {
            nutrition[calorie] = 1800;
            nutrition[cholesterol] = 0;
            nutrition[fat] = 0;
            nutrition[sodium] = 0;
            nutrition[carbohydrate] = 0;
            nutrition[fiber] = 0;
            nutrition[protien] = 50;
            nutrition[vitaminA] = 500;
            nutrition[vitaminC] = 100;
            nutrition[calcium] = 1000;
        }
        else if (age > 60)
        {
            nutrition[calorie] = 1700;
            nutrition[cholesterol] = 0;
            nutrition[fat] = 0;
            nutrition[sodium] = 0;
            nutrition[carbohydrate] = 0;
            nutrition[fiber] = 0;
            nutrition[protien] = 60;
            nutrition[vitaminA] = 600;
            nutrition[vitaminC] = 100;
            nutrition[calcium] = 1000;
        }
    }
    ignore[cholesterol] = 1;
    ignore[fat] = 1;
    ignore[sodium] = 1;
    ignore[carbohydrate] = 1;
    ignore[fiber] = 1;

    /*
     * write file
     * nutrition[], ignore[]
     */
    outFile.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream textStream(&outFile);
    for (int i = 0; i < 10; ++i) {
        textStream << nutrition[i] << "," << ignore[i] << endl;
    }
    outFile.close();

    return 0;
}
