#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include <QtGui>
#include <QString>
#include <QTextEdit>
#include <QTextStream>
#include <QMessageBox>
#include <QDir>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#include "foodlist.h"
#include "programming.h"
#include "gurobi_c++.h"

#define NUM_FOOD 433

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public:
    int gender;
    static void process_line(const QByteArray &)
    {
    }

    static void process_line(const QString &)
    {
    }
    int money;
    double bodyweight;
    double protein;
    double kcal;
    double vitaminA;
    double cholesterol;
    double sodium;
    double fiber;
    double vitaminC;
    double carbohydrate;
    double calcium;
    double fat;
    int objective=0; //0=cost 1=cal 2=carbon 3=pro/fat 4=fat
    int ignorecost=0;
    int ignorepro=0;
    int ignorecal=0;
    int ignorevA=0;
    int ignorecho=0;
    int ignorena=0;
    int ignorefib=0;
    int ignorevC=0;
    int ignorecar=0;
    int ignoreca=0;
    int ignorefat=0;
    QString limitscost=" >= ";
    QString limitscal=" >= ";
    QString limitspro=" >= ";
    QString limitscar=" >= ";
    QString limitsvA=" >= ";
    QString limitsca=" >= ";
    QString limitsfat=" >= ";
    QString limitscho=" >= ";
    QString limitsna=" >= ";
    QString limitsfib=" >= ";
    QString limitsvC=" >= ";
    QString limitsbla=" >= ";

    QString fatt;
    QString calciumt;
    QString carbohydratet;
    QString fibert;
    QString sodiumt;
    QString cholesterolt;
    QString moneyt;
    QString bodyweightt;
    QString proteint;
    QString kcalt;
    QString vitaminAt;
    QString vitaminCt;

private slots:
    void on_pushButton_clicked();

    void on_checkBox_5_clicked();

    void on_checkBox_4_clicked();

    void on_checkBox_6_clicked();

    void on_checkBox_8_clicked();

    void on_checkBox_7_clicked();

    void on_checkBox_9_clicked();

    void on_checkBox_11_clicked();

    void on_checkBox_10_clicked();

    void on_checkBox_12_clicked();

    void on_checkBox_22_clicked();

    void on_checkBox_27_clicked();

    void on_checkBox_26_clicked();

    void on_checkBox_28_clicked();

    void on_checkBox_32_clicked();

    void on_checkBox_33_clicked();

    void on_checkBox_34_clicked();

    void on_checkBox_39_clicked();

    void on_checkBox_38_clicked();

    void on_checkBox_15_clicked();

    void on_checkBox_14_clicked();

    void on_checkBox_13_clicked();

    void on_checkBox_16_clicked();

    void on_checkBox_17_clicked();

    void on_checkBox_18_clicked();

    void on_checkBox_21_clicked();

    void on_checkBox_20_clicked();

    void on_checkBox_19_clicked();

    void on_checkBox_25_clicked();

    void on_checkBox_24_clicked();

    void on_checkBox_23_clicked();

    void on_checkBox_29_clicked();

    void on_checkBox_30_clicked();

    void on_checkBox_31_clicked();

    void on_checkBox_37_clicked();

    void on_checkBox_36_clicked();

    void on_checkBox_35_clicked();

    void on_pushButton_2_clicked();

    void on_radioButton_1_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

    void on_radioButton_9_clicked();

private:
    Ui::MainWindow *ui;
    FoodList *foodlist;
    ProGramming *programming;
};

#endif // MAINWINDOW_H
