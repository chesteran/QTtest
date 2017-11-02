#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include "foodlist.h"
#include "programming.h"
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

    int ignorecost=1;
    int ignorepro=1;
    int ignorecal=1;
    int ignorevA=1;
    int ignorecho=1;
    int ignorena=1;
    int ignorefib=1;
    int ignorevC=1;
    int ignorecar=1;
    int ignoreca=1;
    int ignorefat=1;
    QString limitscost=" not relate to ";
    QString limitscal=" not relate to ";
    QString limitspro=" not relate to ";
    QString limitscar=" not relate to ";
    QString limitsvA=" not relate to ";
    QString limitsca=" not relate to ";
    QString limitsfat=" not relate to ";
    QString limitscho=" not relate to ";
    QString limitsna=" not relate to ";
    QString limitsfib=" not relate to ";
    QString limitsvC=" not relate to ";
    QString limitsbla=" not relate to ";

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

private:
    Ui::MainWindow *ui;
    FoodList *foodlist;
    ProGramming *programming;
};

#endif // MAINWINDOW_H
