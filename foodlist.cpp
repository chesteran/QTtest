#include "foodlist.h"
#include "ui_foodlist.h"

FoodList::FoodList(QWidget *parent, QString equ) :
    QDialog(parent),
    ui(new Ui::FoodList)
{
    ui->setupUi(this);
    ui->textEdit->insertPlainText(equ);
}

FoodList::~FoodList()
{
    delete ui;
}

void FoodList::on_pushButton_clicked()
{

}
