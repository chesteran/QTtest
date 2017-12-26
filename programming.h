#ifndef PROGRAMMING_H
#define PROGRAMMING_H

#include <QMainWindow>
#include <iostream>
#include <QFile>
#include <QTextStream>
#include "gurobi_c++.h"

#define NUM_FOOD 428

using namespace std;

namespace Ui {
class ProGramming;
}

class ProGramming : public QMainWindow
{
    Q_OBJECT

public:
    explicit ProGramming(QWidget *parent = 0, QString equ = "");
    ~ProGramming();

private slots:
    void on_calculate_clicked();

private:
    Ui::ProGramming *ui;
};

#endif // PROGRAMMING_H
