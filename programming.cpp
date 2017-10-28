#include "programming.h"
#include "ui_programming.h"
#include "simplex.h"

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
    Simplex S;
    S.read("model");
    S.print();
    S.solve();
}
