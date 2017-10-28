#include "foodlist.h"
#include "ui_foodlist.h"

FoodList::FoodList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FoodList)
{
    ui->setupUi(this);
}

FoodList::~FoodList()
{
    delete ui;
}
