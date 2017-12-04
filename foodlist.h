#ifndef FOODLIST_H
#define FOODLIST_H


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
#include <QDialog>
using namespace std;
namespace Ui {
class FoodList;
}

class FoodList : public QDialog
{
    Q_OBJECT

public:
    explicit FoodList(QWidget *parent = 0,QString equ = "");
    ~FoodList();

private slots:
    void on_pushButton_clicked();

private:
    Ui::FoodList *ui;
};

#endif // FOODLIST_H
