#include "programming.h"
#include "ui_programming.h"

ProGramming::ProGramming(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ProGramming)
{
    ui->setupUi(this);
}

ProGramming::~ProGramming()
{
    delete ui;
}
