#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include<QtGui>
#include<QString>
#include<QTextEdit>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include "foodlist.h"
#include "programming.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)  
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{   bodyweightt=ui->textEditwg->toPlainText();
    bodyweight=bodyweightt.toDouble();
    moneyt=ui->textEditcost->toPlainText();
    money=moneyt.toInt();
    kcalt=ui->textEditcal->toPlainText();
    kcal=kcalt.toDouble();
    proteint=ui->textEditpro->toPlainText();
    protein=proteint.toDouble();
    carbohydratet=ui->textEditcar->toPlainText();
    carbohydrate=carbohydratet.toDouble();
    vitaminAt=ui->textEditvitA->toPlainText();
    vitaminA=vitaminAt.toDouble();
    calciumt=ui->textEditca->toPlainText();
    calcium=calciumt.toDouble();
    fatt=ui->textEditfat->toPlainText();
    fat=fatt.toDouble();
    cholesterolt=ui->textEditcho->toPlainText();
    cholesterol=cholesterolt.toDouble();
    sodiumt=ui->textEditna->toPlainText();
    sodium=sodiumt.toDouble();
    fibert=ui->textEditfib->toPlainText();
    fiber=fibert.toDouble();
    vitaminCt=ui->textEditvitC->toPlainText();
    vitaminC=vitaminCt.toDouble();

    programming=new ProGramming(this);
    programming->show();
   // ui->label_15->show();
 //   ui->textEdit_14->show();

///////////////////////////////////////////////////////////////read file


   // QFile inputFile("/home/user/文件/testQT/in.txt");
   // inputFile.open(QIODevice::ReadOnly);
   // if (!inputFile.isOpen())
     //   return;

   // QTextStream stream(&inputFile);
  //  QString line = stream.readLine();
 //   ui->textEdit_14->clear();
  //  if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
 //   while (!stream.atEnd()) {
        /* process information */

    //    line = stream.readLine();
      //  ui->textEdit_14->append(line);
 //   ui->textEdit_14->setText(ui->textEdit_14->toPlainText()+line+"\n");

   //  qDebug() << "linea: "<<line;
   // };
   // }
  /*  QFile file("out.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);
    out << "The magic number is: " << 49 << "\n";
    ui->textEdit_14->append(line);*/
  //  file.close();

}



void MainWindow::on_checkBox_5_clicked()
{
    if (ui->checkBox_6->isChecked())
        {ui->checkBox_6->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_4->isChecked())
        {ui->checkBox_4->setCheckState(Qt::Unchecked);}
}

void MainWindow::on_checkBox_4_clicked()
{
    if (ui->checkBox_6->isChecked())
        {ui->checkBox_6->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_5->isChecked())
        {ui->checkBox_5->setCheckState(Qt::Unchecked);}
}

void MainWindow::on_checkBox_6_clicked()
{
    if (ui->checkBox_5->isChecked())
        {ui->checkBox_5->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_4->isChecked())
        {ui->checkBox_4->setCheckState(Qt::Unchecked);}
}

void MainWindow::on_checkBox_8_clicked()
{
    if (ui->checkBox_7->isChecked())
        {ui->checkBox_7->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_9->isChecked())
        {ui->checkBox_9->setCheckState(Qt::Unchecked);}
}

void MainWindow::on_checkBox_7_clicked()
{
    if (ui->checkBox_8->isChecked())
        {ui->checkBox_8->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_9->isChecked())
        {ui->checkBox_9->setCheckState(Qt::Unchecked);}
}

void MainWindow::on_checkBox_9_clicked()
{
    if (ui->checkBox_7->isChecked())
        {ui->checkBox_7->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_8->isChecked())
        {ui->checkBox_8->setCheckState(Qt::Unchecked);}
}

void MainWindow::on_checkBox_11_clicked()
{
    if (ui->checkBox_10->isChecked())
        {ui->checkBox_10->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_12->isChecked())
        {ui->checkBox_12->setCheckState(Qt::Unchecked);}
}

void MainWindow::on_checkBox_10_clicked()
{
    if (ui->checkBox_11->isChecked())
        {ui->checkBox_11->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_12->isChecked())
        {ui->checkBox_12->setCheckState(Qt::Unchecked);}
}

void MainWindow::on_checkBox_12_clicked()
{
    if (ui->checkBox_10->isChecked())
        {ui->checkBox_10->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_11->isChecked())
        {ui->checkBox_11->setCheckState(Qt::Unchecked);}
}

void MainWindow::on_checkBox_22_clicked()
{
    if (ui->checkBox_26->isChecked())
        {ui->checkBox_26->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_27->isChecked())
        {ui->checkBox_27->setCheckState(Qt::Unchecked);}
}

void MainWindow::on_checkBox_27_clicked()
{
    if (ui->checkBox_26->isChecked())
        {ui->checkBox_26->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_22->isChecked())
        {ui->checkBox_22->setCheckState(Qt::Unchecked);}
}

void MainWindow::on_checkBox_26_clicked()
{
    if (ui->checkBox_22->isChecked())
        {ui->checkBox_22->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_27->isChecked())
        {ui->checkBox_27->setCheckState(Qt::Unchecked);}
}

void MainWindow::on_checkBox_28_clicked()
{
    if (ui->checkBox_32->isChecked())
        {ui->checkBox_32->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_33->isChecked())
        {ui->checkBox_33->setCheckState(Qt::Unchecked);}
}

void MainWindow::on_checkBox_32_clicked()
{
    if (ui->checkBox_33->isChecked())
        {ui->checkBox_33->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_28->isChecked())
        {ui->checkBox_28->setCheckState(Qt::Unchecked);}
}

void MainWindow::on_checkBox_33_clicked()
{
    if (ui->checkBox_28->isChecked())
        {ui->checkBox_28->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_32->isChecked())
        {ui->checkBox_32->setCheckState(Qt::Unchecked);}
}

void MainWindow::on_checkBox_34_clicked()
{
    if (ui->checkBox_39->isChecked())
        {ui->checkBox_39->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_38->isChecked())
        {ui->checkBox_38->setCheckState(Qt::Unchecked);}
}

void MainWindow::on_checkBox_39_clicked()
{
    if (ui->checkBox_38->isChecked())
        {ui->checkBox_38->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_34->isChecked())
        {ui->checkBox_34->setCheckState(Qt::Unchecked);}
}

void MainWindow::on_checkBox_38_clicked()
{
    if (ui->checkBox_39->isChecked())
        {ui->checkBox_39->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_34->isChecked())
        {ui->checkBox_34->setCheckState(Qt::Unchecked);}
}

void MainWindow::on_checkBox_15_clicked()
{
    if (ui->checkBox_13->isChecked())
        {ui->checkBox_13->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_14->isChecked())
        {ui->checkBox_14->setCheckState(Qt::Unchecked);}
}

void MainWindow::on_checkBox_14_clicked()
{
    if (ui->checkBox_15->isChecked())
        {ui->checkBox_15->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_13->isChecked())
        {ui->checkBox_13->setCheckState(Qt::Unchecked);}
}

void MainWindow::on_checkBox_13_clicked()
{
    if (ui->checkBox_15->isChecked())
        {ui->checkBox_15->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_14->isChecked())
        {ui->checkBox_14->setCheckState(Qt::Unchecked);}
}

void MainWindow::on_checkBox_16_clicked()
{
    if (ui->checkBox_18->isChecked())
        {ui->checkBox_18->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_17->isChecked())
        {ui->checkBox_17->setCheckState(Qt::Unchecked);}
}

void MainWindow::on_checkBox_17_clicked()
{
    if (ui->checkBox_16->isChecked())
        {ui->checkBox_16->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_18->isChecked())
        {ui->checkBox_18->setCheckState(Qt::Unchecked);}
}

void MainWindow::on_checkBox_18_clicked()
{
    if (ui->checkBox_16->isChecked())
        {ui->checkBox_16->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_17->isChecked())
        {ui->checkBox_17->setCheckState(Qt::Unchecked);}
}

void MainWindow::on_checkBox_21_clicked()
{
    if (ui->checkBox_19->isChecked())
        {ui->checkBox_19->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_20->isChecked())
        {ui->checkBox_20->setCheckState(Qt::Unchecked);}
}

void MainWindow::on_checkBox_20_clicked()
{
    if (ui->checkBox_19->isChecked())
        {ui->checkBox_19->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_21->isChecked())
        {ui->checkBox_21->setCheckState(Qt::Unchecked);}
}

void MainWindow::on_checkBox_19_clicked()
{
    if (ui->checkBox_20->isChecked())
        {ui->checkBox_20->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_21->isChecked())
        {ui->checkBox_21->setCheckState(Qt::Unchecked);}
}

void MainWindow::on_checkBox_25_clicked()
{
    if (ui->checkBox_23->isChecked())
        {ui->checkBox_23->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_24->isChecked())
        {ui->checkBox_24->setCheckState(Qt::Unchecked);}
}

void MainWindow::on_checkBox_24_clicked()
{
    if (ui->checkBox_23->isChecked())
        {ui->checkBox_23->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_25->isChecked())
        {ui->checkBox_25->setCheckState(Qt::Unchecked);}
}

void MainWindow::on_checkBox_23_clicked()
{
    if (ui->checkBox_25->isChecked())
        {ui->checkBox_25->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_24->isChecked())
        {ui->checkBox_24->setCheckState(Qt::Unchecked);}
}

void MainWindow::on_checkBox_29_clicked()
{
    if (ui->checkBox_30->isChecked())
        {ui->checkBox_30->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_31->isChecked())
        {ui->checkBox_31->setCheckState(Qt::Unchecked);}
}

void MainWindow::on_checkBox_30_clicked()
{
    if (ui->checkBox_29->isChecked())
        {ui->checkBox_29->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_31->isChecked())
        {ui->checkBox_31->setCheckState(Qt::Unchecked);}
}

void MainWindow::on_checkBox_31_clicked()
{
    if (ui->checkBox_29->isChecked())
        {ui->checkBox_29->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_30->isChecked())
        {ui->checkBox_30->setCheckState(Qt::Unchecked);}
}

void MainWindow::on_checkBox_37_clicked()
{
    if (ui->checkBox_36->isChecked())
        {ui->checkBox_36->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_35->isChecked())
        {ui->checkBox_35->setCheckState(Qt::Unchecked);}
}

void MainWindow::on_checkBox_36_clicked()
{
    if (ui->checkBox_35->isChecked())
        {ui->checkBox_35->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_37->isChecked())
        {ui->checkBox_37->setCheckState(Qt::Unchecked);}
}

void MainWindow::on_checkBox_35_clicked()
{
    if (ui->checkBox_36->isChecked())
        {ui->checkBox_36->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_37->isChecked())
        {ui->checkBox_37->setCheckState(Qt::Unchecked);}
}

void MainWindow::on_pushButton_2_clicked()
{

    foodlist=new FoodList(this);
    foodlist->show();

}
