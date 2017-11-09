#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include<QtGui>
#include<QString>
#include<QTextEdit>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDir>
#include "foodlist.h"

#define NUM_FOOD 5

#include "programming.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)  
{
    ui->setupUi(this);
    ui->textEditcal->setText("2000");
    ui->textEditcho->setText("0");
    ui->textEditfat->setText("0");
    ui->textEditna->setText("0");
    ui->textEditcar->setText("0");
    ui->textEditfib->setText("25");
    ui->textEditpro->setText("50");
    ui->textEditvitA->setText("5000");
    ui->textEditvitC->setText("50");
    ui->textEditca->setText("800");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    bodyweightt=ui->textEditwg->toPlainText();
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
    //money cal pro carbo vA ca fat chol so fib vc
    ///set equation
  /*  double A[5][11] = {
            {0.16,73.8,0.0,0.8,68.2,13.6,8.5,8,5867.4,160.2,159},
            {0.07,23.7,0,0.1,19.2,5.6,1.6,0.6,15471,5.1,14.9},
            {0.06,171.5,0,0.2,15.2,19.9,3.2,3.7,0,15.6,22.7},
            {0.84,277.4,129.9,10.8,125.6,0,0,42.2,77.4,0,21.9},
            {0.78,358.2,0,12.3,1237.1,58.3,11.6,8.2,3055.2,27.9,80.2}
    };
    */

    double A[NUM_FOOD][11] = {
            {0.16,73.8,8.0,13.6,5867.4,159.0,0.8,0.0,68.2,8.5,160.2},
            {0.07,23.7,0.6,5.6,15471.0,14.9,0.1,0.0,19.2,1.6,5.1},
            {0.18,72.2,2.5,17.1,106.6,3.3,0.6,0.0,2.5,2.0,5.2},
            {0.49,46.4,0.8,11.3,133.0,19.8,0.3,0.0,3.8,2.6,74.5},
            {0.59,369.4,20.7,26.7,855.0,220.6,20.6,56.4,802.0,0.0,2.2}
    };

    //money
    QTextEdit buf;
    QTextCursor cursor = buf.textCursor();
    buf.insertPlainText("min z = ");
    buf.moveCursor(QTextCursor::End);
    buf.insertPlainText(QString::number(A[0][0]) + "x" + QString::number(0));
    buf.moveCursor(QTextCursor::End);
    for (int i = 1; i < NUM_FOOD; i++){
        buf.insertPlainText(" + " + QString::number(A[i][0]) + "x" + QString::number(i));
        buf.moveCursor(QTextCursor::End);
    }

    //kcal
    buf.append(QString::number(A[0][1]) + "x" + QString::number(0));
    for (int i = 1; i < NUM_FOOD; i++){
        buf.insertPlainText(" + " + QString::number(A[i][1]) + "x" + QString::number(i));
        buf.moveCursor(QTextCursor::End);
    }

    //buf.insertPlainText( QString::number(kcal));
    buf.insertPlainText(limitscal + QString::number(kcal));
    if(ignorecal){

cursor.movePosition(QTextCursor::End);
cursor.select(QTextCursor::LineUnderCursor);
cursor.removeSelectedText();
cursor.deletePreviousChar(); // Added to trim the newline char when removing last line
buf.setTextCursor(cursor);
}



    //protein
    buf.append(QString::number(A[0][2]) + "x" + QString::number(0));
    for (int i = 1; i < NUM_FOOD; i++){
        buf.insertPlainText(" + " + QString::number(A[i][2]) + "x" + QString::number(i));
        buf.moveCursor(QTextCursor::End);
    }
    buf.insertPlainText(limitspro + QString::number(protein));
    if(ignorepro){

cursor.movePosition(QTextCursor::End);
cursor.select(QTextCursor::LineUnderCursor);
cursor.removeSelectedText();
cursor.deletePreviousChar(); // Added to trim the newline char when removing last line
buf.setTextCursor(cursor);
}
    //carbohydrate
    buf.append(QString::number(A[0][3]) + "x" + QString::number(0));
    for (int i = 1; i < NUM_FOOD; i++){
        buf.insertPlainText(" + " + QString::number(A[i][3]) + "x" + QString::number(i));
        buf.moveCursor(QTextCursor::End);
    }
    buf.insertPlainText(limitscar + QString::number(carbohydrate));
    if(ignorecar){

cursor.movePosition(QTextCursor::End);
cursor.select(QTextCursor::LineUnderCursor);
cursor.removeSelectedText();
cursor.deletePreviousChar(); // Added to trim the newline char when removing last line
buf.setTextCursor(cursor);
}
    //vitaminA
    buf.append(QString::number(A[0][4]) + "x" + QString::number(0));
    for (int i = 1; i < NUM_FOOD; i++){
        buf.insertPlainText(" + " + QString::number(A[i][4]) + "x" + QString::number(i));
        buf.moveCursor(QTextCursor::End);
    }
    buf.insertPlainText(limitsvA + QString::number(vitaminA));
    if(ignorevA){

cursor.movePosition(QTextCursor::End);
cursor.select(QTextCursor::LineUnderCursor);
cursor.removeSelectedText();
cursor.deletePreviousChar(); // Added to trim the newline char when removing last line
buf.setTextCursor(cursor);
}
    //calcium
    buf.append(QString::number(A[0][5]) + "x" + QString::number(0));
    for (int i = 1; i < NUM_FOOD; i++){
        buf.insertPlainText(" + " + QString::number(A[i][5]) + "x" + QString::number(i));
        buf.moveCursor(QTextCursor::End);
    }
    buf.insertPlainText(limitsca + QString::number(calcium));
    if(ignoreca){

cursor.movePosition(QTextCursor::End);
cursor.select(QTextCursor::LineUnderCursor);
cursor.removeSelectedText();
cursor.deletePreviousChar(); // Added to trim the newline char when removing last line
buf.setTextCursor(cursor);
}
    //fat
    buf.append(QString::number(A[0][6]) + "x" + QString::number(0));
    for (int i = 1; i < NUM_FOOD; i++){
        buf.insertPlainText(" + " + QString::number(A[i][6]) + "x" + QString::number(i));
        buf.moveCursor(QTextCursor::End);
    }
    buf.insertPlainText(limitsfat + QString::number(fat));
    if(ignorefat){

cursor.movePosition(QTextCursor::End);
cursor.select(QTextCursor::LineUnderCursor);
cursor.removeSelectedText();
cursor.deletePreviousChar(); // Added to trim the newline char when removing last line
buf.setTextCursor(cursor);
}
    //cholesterol
    buf.append(QString::number(A[0][7]) + "x" + QString::number(0));
    for (int i = 1; i < NUM_FOOD; i++){
        buf.insertPlainText(" + " + QString::number(A[i][7]) + "x" + QString::number(i));
        buf.moveCursor(QTextCursor::End);
    }
    buf.insertPlainText(limitscho + QString::number(cholesterol));
    if(ignorecho){

cursor.movePosition(QTextCursor::End);
cursor.select(QTextCursor::LineUnderCursor);
cursor.removeSelectedText();
cursor.deletePreviousChar(); // Added to trim the newline char when removing last line
buf.setTextCursor(cursor);
}
    //sodium
    buf.append(QString::number(A[0][8]) + "x" + QString::number(0));
    for (int i = 1; i < NUM_FOOD; i++){
        buf.insertPlainText(" + " + QString::number(A[i][8]) + "x" + QString::number(i));
        buf.moveCursor(QTextCursor::End);
    }
    buf.insertPlainText(limitsna + QString::number(sodium));
    if(ignorena){

cursor.movePosition(QTextCursor::End);
cursor.select(QTextCursor::LineUnderCursor);
cursor.removeSelectedText();
cursor.deletePreviousChar(); // Added to trim the newline char when removing last line
buf.setTextCursor(cursor);
}
    //fiber
    buf.append(QString::number(A[0][9]) + "x" + QString::number(0));
    for (int i = 1; i < NUM_FOOD; i++){
        buf.insertPlainText(" + " + QString::number(A[i][9]) + "x" + QString::number(i));
        buf.moveCursor(QTextCursor::End);
    }
    buf.insertPlainText(limitsfib + QString::number(fiber));
    if(ignorefib){

cursor.movePosition(QTextCursor::End);
cursor.select(QTextCursor::LineUnderCursor);
cursor.removeSelectedText();
cursor.deletePreviousChar(); // Added to trim the newline char when removing last line
buf.setTextCursor(cursor);
}
    //vitaminC
    buf.append(QString::number(A[0][10]) + "x" + QString::number(0));
    for (int i = 1; i < NUM_FOOD; i++){
        buf.insertPlainText(" + " + QString::number(A[i][10]) + "x" + QString::number(i));
        buf.moveCursor(QTextCursor::End);
    }
    buf.insertPlainText(limitsvC + QString::number(vitaminC));
    if(ignorevC){
//QTextCursor cursor = buf.textCursor();
cursor.movePosition(QTextCursor::End);
cursor.select(QTextCursor::LineUnderCursor);
cursor.removeSelectedText();
cursor.deletePreviousChar(); // Added to trim the newline char when removing last line
buf.setTextCursor(cursor);
}



    ///write file
    QFile file;
    file.setFileName("model");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);
    out << buf.toPlainText() << endl;
    std::cout << QDir::currentPath().toStdString() << std::endl;

    programming=new ProGramming(this, buf.toPlainText());
    programming->show();
}

void MainWindow::on_checkBox_5_clicked()
{
    if (ui->checkBox_6->isChecked())
        {ui->checkBox_6->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_4->isChecked())
        {ui->checkBox_4->setCheckState(Qt::Unchecked);}
    limitscost=">=";
    ignorecost=0;
}

void MainWindow::on_checkBox_4_clicked()
{
    if (ui->checkBox_6->isChecked())
        {ui->checkBox_6->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_5->isChecked())
        {ui->checkBox_5->setCheckState(Qt::Unchecked);}
    limitscost="<=";
    ignorecost=0;

}

void MainWindow::on_checkBox_6_clicked()
{
    if (ui->checkBox_5->isChecked())
        {ui->checkBox_5->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_4->isChecked())
        {ui->checkBox_4->setCheckState(Qt::Unchecked);}
    ignorecost=1;
}

void MainWindow::on_checkBox_8_clicked()
{
    if (ui->checkBox_7->isChecked())
        {ui->checkBox_7->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_9->isChecked())
        {ui->checkBox_9->setCheckState(Qt::Unchecked);}
    limitscal=">=";
    ignorecal=0;
}

void MainWindow::on_checkBox_7_clicked()
{
    if (ui->checkBox_8->isChecked())
        {ui->checkBox_8->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_9->isChecked())
        {ui->checkBox_9->setCheckState(Qt::Unchecked);}
    limitscal="<=";
    ignorecal=0;
}

void MainWindow::on_checkBox_9_clicked()
{
    if (ui->checkBox_7->isChecked())
        {ui->checkBox_7->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_8->isChecked())
        {ui->checkBox_8->setCheckState(Qt::Unchecked);}
   // limitscal="not relate to ";
    ignorecal=1;
}

void MainWindow::on_checkBox_11_clicked()
{
    if (ui->checkBox_10->isChecked())
        {ui->checkBox_10->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_12->isChecked())
        {ui->checkBox_12->setCheckState(Qt::Unchecked);}
    limitspro=">=";
    ignorepro=0;
}

void MainWindow::on_checkBox_10_clicked()
{
    if (ui->checkBox_11->isChecked())
        {ui->checkBox_11->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_12->isChecked())
        {ui->checkBox_12->setCheckState(Qt::Unchecked);}
    limitspro="<=";
    ignorepro=0;
}

void MainWindow::on_checkBox_12_clicked()
{
    if (ui->checkBox_10->isChecked())
        {ui->checkBox_10->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_11->isChecked())
        {ui->checkBox_11->setCheckState(Qt::Unchecked);}
    //limitspro="not relate to ";
    ignorepro=1;
}

void MainWindow::on_checkBox_22_clicked()
{
    if (ui->checkBox_26->isChecked())
        {ui->checkBox_26->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_27->isChecked())
        {ui->checkBox_27->setCheckState(Qt::Unchecked);}
    //limitscar="not relate to ";
    ignorecar=1;
}

void MainWindow::on_checkBox_27_clicked()
{
    if (ui->checkBox_26->isChecked())
        {ui->checkBox_26->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_22->isChecked())
        {ui->checkBox_22->setCheckState(Qt::Unchecked);}
    limitscar=">=";
    ignorecar=0;
}

void MainWindow::on_checkBox_26_clicked()
{
    if (ui->checkBox_22->isChecked())
        {ui->checkBox_22->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_27->isChecked())
        {ui->checkBox_27->setCheckState(Qt::Unchecked);}
    limitscar="<=";
    ignorecar=0;
}

void MainWindow::on_checkBox_28_clicked()
{
    if (ui->checkBox_32->isChecked())
        {ui->checkBox_32->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_33->isChecked())
        {ui->checkBox_33->setCheckState(Qt::Unchecked);}
    //limitsvA="not relate to ";
    ignorevA=1;
}

void MainWindow::on_checkBox_32_clicked()
{
    if (ui->checkBox_33->isChecked())
        {ui->checkBox_33->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_28->isChecked())
        {ui->checkBox_28->setCheckState(Qt::Unchecked);}
    limitsvA="<=";
    ignorevA=0;
}

void MainWindow::on_checkBox_33_clicked()
{
    if (ui->checkBox_28->isChecked())
        {ui->checkBox_28->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_32->isChecked())
        {ui->checkBox_32->setCheckState(Qt::Unchecked);}
    limitsvA=">=";
    ignorevA=0;
}

void MainWindow::on_checkBox_34_clicked()
{
    if (ui->checkBox_39->isChecked())
        {ui->checkBox_39->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_38->isChecked())
        {ui->checkBox_38->setCheckState(Qt::Unchecked);}
   // limitsca="not relate to ";
    ignoreca=1;
}

void MainWindow::on_checkBox_39_clicked()
{
    if (ui->checkBox_38->isChecked())
        {ui->checkBox_38->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_34->isChecked())
        {ui->checkBox_34->setCheckState(Qt::Unchecked);}
    limitsca=">=";
    ignoreca=0;
}

void MainWindow::on_checkBox_38_clicked()
{
    if (ui->checkBox_39->isChecked())
        {ui->checkBox_39->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_34->isChecked())
        {ui->checkBox_34->setCheckState(Qt::Unchecked);}
    limitsca="<=";
    ignoreca=0;
}

void MainWindow::on_checkBox_15_clicked()
{
    if (ui->checkBox_13->isChecked())
        {ui->checkBox_13->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_14->isChecked())
        {ui->checkBox_14->setCheckState(Qt::Unchecked);}
    limitsfat=">=";
    ignorefat=0;
}

void MainWindow::on_checkBox_14_clicked()
{
    if (ui->checkBox_15->isChecked())
        {ui->checkBox_15->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_13->isChecked())
        {ui->checkBox_13->setCheckState(Qt::Unchecked);}
    limitsfat="<=";
    ignorefat=0;
}

void MainWindow::on_checkBox_13_clicked()
{
    if (ui->checkBox_15->isChecked())
        {ui->checkBox_15->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_14->isChecked())
        {ui->checkBox_14->setCheckState(Qt::Unchecked);}
    //limitsfat="not relate to ";
    ignorefat=1;
}

void MainWindow::on_checkBox_16_clicked()
{
    if (ui->checkBox_18->isChecked())
        {ui->checkBox_18->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_17->isChecked())
        {ui->checkBox_17->setCheckState(Qt::Unchecked);}
    //limitscho="not relate to ";
    ignorecho=1;

}

void MainWindow::on_checkBox_17_clicked()
{
    if (ui->checkBox_16->isChecked())
        {ui->checkBox_16->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_18->isChecked())
        {ui->checkBox_18->setCheckState(Qt::Unchecked);}
    limitscho="<=";
    ignorecho=0;
}

void MainWindow::on_checkBox_18_clicked()
{
    if (ui->checkBox_16->isChecked())
        {ui->checkBox_16->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_17->isChecked())
        {ui->checkBox_17->setCheckState(Qt::Unchecked);}
    limitscho=">=";
    ignorecho=0;
}

void MainWindow::on_checkBox_21_clicked()
{
    if (ui->checkBox_19->isChecked())
        {ui->checkBox_19->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_20->isChecked())
        {ui->checkBox_20->setCheckState(Qt::Unchecked);}
    limitsna=">=";
    ignorena=0;
}

void MainWindow::on_checkBox_20_clicked()
{
    if (ui->checkBox_19->isChecked())
        {ui->checkBox_19->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_21->isChecked())
        {ui->checkBox_21->setCheckState(Qt::Unchecked);}
    limitsna="<=";
    ignorena=0;
}

void MainWindow::on_checkBox_19_clicked()
{
    if (ui->checkBox_20->isChecked())
        {ui->checkBox_20->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_21->isChecked())
        {ui->checkBox_21->setCheckState(Qt::Unchecked);}
    //limitsna="not relate to ";
    ignorena=1;
}

void MainWindow::on_checkBox_25_clicked()
{
    if (ui->checkBox_23->isChecked())
        {ui->checkBox_23->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_24->isChecked())
        {ui->checkBox_24->setCheckState(Qt::Unchecked);}
    limitsfib=">=";
    ignorefib=0;
}

void MainWindow::on_checkBox_24_clicked()
{
    if (ui->checkBox_23->isChecked())
        {ui->checkBox_23->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_25->isChecked())
        {ui->checkBox_25->setCheckState(Qt::Unchecked);}
    limitsfib="<=";
    ignorefib=0;
}

void MainWindow::on_checkBox_23_clicked()
{
    if (ui->checkBox_25->isChecked())
        {ui->checkBox_25->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_24->isChecked())
        {ui->checkBox_24->setCheckState(Qt::Unchecked);}
    limitsfib="not relate to ";
    ignorefib=1;
}

void MainWindow::on_checkBox_29_clicked()
{
    if (ui->checkBox_30->isChecked())
        {ui->checkBox_30->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_31->isChecked())
        {ui->checkBox_31->setCheckState(Qt::Unchecked);}
    //limitsvC="not relate to ";
    ignorevC=1;
}

void MainWindow::on_checkBox_30_clicked()
{
    if (ui->checkBox_29->isChecked())
        {ui->checkBox_29->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_31->isChecked())
        {ui->checkBox_31->setCheckState(Qt::Unchecked);}
    limitsvC="<=";
    ignorevC=0;
}

void MainWindow::on_checkBox_31_clicked()
{
    if (ui->checkBox_29->isChecked())
        {ui->checkBox_29->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_30->isChecked())
        {ui->checkBox_30->setCheckState(Qt::Unchecked);}
    limitsvC=">=";
    ignorevC=0;
}

void MainWindow::on_checkBox_37_clicked()
{
    if (ui->checkBox_36->isChecked())
        {ui->checkBox_36->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_35->isChecked())
        {ui->checkBox_35->setCheckState(Qt::Unchecked);}
    //limits=">=";
}

void MainWindow::on_checkBox_36_clicked()
{
    if (ui->checkBox_35->isChecked())
        {ui->checkBox_35->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_37->isChecked())
        {ui->checkBox_37->setCheckState(Qt::Unchecked);}
   //limits="<=";
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
