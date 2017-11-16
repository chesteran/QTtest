#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    //set equation
    /*
    double A[NUM_FOOD][11] = {
            {0.16,73.8,8.0,13.6,5867.4,159.0,0.8,0.0,68.2,8.5,160.2},
            {0.07,23.7,0.6,5.6,15471.0,14.9,0.1,0.0,19.2,1.6,5.1},
            {0.18,72.2,2.5,17.1,106.6,3.3,0.6,0.0,2.5,2.0,5.2},
            {0.49,46.4,0.8,11.3,133.0,19.8,0.3,0.0,3.8,2.6,74.5},
            {0.59,369.4,20.7,26.7,855.0,220.6,20.6,56.4,802.0,0.0,2.2}
    };
    */
    double A[NUM_FOOD][11];
    int row = 0;
    QFile in;
    in.setFileName("Mat.csv");
    in.open(QIODevice::ReadOnly);
    if (!in.isOpen()) {
        qDebug() << in.errorString();
        return;
    }

    while(!in.atEnd()) {
        QString line = in.readLine();
        QStringList list = line.split(QRegExp("\n|\r\n|\r|,"));
        if (row > 0) {
            for (int i = 0; i < 11; i++) {
                A[row - 1][i] = list.at(i + 1).toDouble();
            }
        }
        row++;
    }

    in.close();

    //objective 0=cost 1=cal 2=carbon 3=pro/fat 4=fat
    QTextEdit buf;
    QTextCursor cursor = buf.textCursor();
    buf.insertPlainText("Minimize\n ");
    buf.moveCursor(QTextCursor::End);
    if(objective==0){
        buf.insertPlainText(QString::number(A[0][0]) + " x" + QString::number(0));
        buf.moveCursor(QTextCursor::End);
        for (int i = 1; i < NUM_FOOD; i++){
            buf.insertPlainText(" + " + QString::number(A[i][0]) + " x" + QString::number(i));
            buf.moveCursor(QTextCursor::End);
        }
    }
    else if(objective==1){
        buf.insertPlainText(QString::number(A[0][1]) + " x" + QString::number(0));
        buf.moveCursor(QTextCursor::End);
        for (int i = 1; i < NUM_FOOD; i++){
            buf.insertPlainText(" + " + QString::number(A[i][1]) + " x" + QString::number(i));
            buf.moveCursor(QTextCursor::End);
        }
    }
    else if(objective==2){
        buf.insertPlainText(QString::number(A[0][3]) + " x" + QString::number(0));
        buf.moveCursor(QTextCursor::End);
        for (int i = 1; i < NUM_FOOD; i++){
            buf.insertPlainText(" + " + QString::number(A[i][3]) + " x" + QString::number(i));
            buf.moveCursor(QTextCursor::End);
        }
    }
    else if(objective==3){
        buf.insertPlainText(QString::number(A[0][2]/(A[0][6]+1)) + " x" + QString::number(0));
        buf.moveCursor(QTextCursor::End);
        for (int i = 1; i < NUM_FOOD; i++){
            buf.insertPlainText(" + " + QString::number(A[i][2]/(A[i][6]+1)) + " x" + QString::number(i));
            buf.moveCursor(QTextCursor::End);
        }
    }
    else if(objective==4){
        buf.insertPlainText(QString::number(A[0][2]) + " x" + QString::number(0));
        buf.moveCursor(QTextCursor::End);
        for (int i = 1; i < NUM_FOOD; i++){
            buf.insertPlainText(" + " + QString::number(A[i][2]) + " x" + QString::number(i));
            buf.moveCursor(QTextCursor::End);
        }
    }

    buf.append("Subject To");
    //money
    if(objective != 0){
        buf.append(" c0: " + QString::number(A[0][0]) + " x" + QString::number(0));
        for (int i = 1; i < NUM_FOOD; i++){
            buf.insertPlainText(" + " + QString::number(A[i][0]) + " x" + QString::number(i));
            buf.moveCursor(QTextCursor::End);
        }
        buf.insertPlainText(limitscost + QString::number(money));
        if(ignorecost){
            cursor.movePosition(QTextCursor::End);
            cursor.select(QTextCursor::LineUnderCursor);
            cursor.removeSelectedText();
            cursor.deletePreviousChar(); // Added to trim the newline char when removing last line
            buf.setTextCursor(cursor);
        }
    }

    //kcal
    if(objective !=1){
        buf.append(" c1: " + QString::number(A[0][1]) + " x" + QString::number(0));
        for (int i = 1; i < NUM_FOOD; i++){
            buf.insertPlainText(" + " + QString::number(A[i][1]) + " x" + QString::number(i));
            buf.moveCursor(QTextCursor::End);
        }

        buf.insertPlainText(limitscal + QString::number(kcal));
        if(ignorecal){
            cursor.movePosition(QTextCursor::End);
            cursor.select(QTextCursor::LineUnderCursor);

            cursor.removeSelectedText();
            cursor.deletePreviousChar(); // Added to trim the newline char when removing last line
            buf.setTextCursor(cursor);
        }
    }

    //protein
    if(objective!=4||objective!=3){
        buf.append(" c2: " + QString::number(A[0][2]) + " x" + QString::number(0));
        for (int i = 1; i < NUM_FOOD; i++){
            buf.insertPlainText(" + " + QString::number(A[i][2]) + " x" + QString::number(i));
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
    }
    //carbohydrate
    if(objective!=2){
        buf.append(" c3: " + QString::number(A[0][3]) + " x" + QString::number(0));
        for (int i = 1; i < NUM_FOOD; i++){
            buf.insertPlainText(" + " + QString::number(A[i][3]) + " x" + QString::number(i));
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
    }
    //vitaminA
    buf.append(" c4: " + QString::number(A[0][4]) + " x" + QString::number(0));
    for (int i = 1; i < NUM_FOOD; i++){
        buf.insertPlainText(" + " + QString::number(A[i][4]) + " x" + QString::number(i));
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
    buf.append(" c5: " + QString::number(A[0][5]) + " x" + QString::number(0));
    for (int i = 1; i < NUM_FOOD; i++){
        buf.insertPlainText(" + " + QString::number(A[i][5]) + " x" + QString::number(i));
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
    if(objective!=3){
        buf.append(" c6: " + QString::number(A[0][6]) + " x" + QString::number(0));
        for (int i = 1; i < NUM_FOOD; i++){
            buf.insertPlainText(" + " + QString::number(A[i][6]) + " x" + QString::number(i));
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
    }
    //cholesterol
    buf.append(" c7: " + QString::number(A[0][7]) + " x" + QString::number(0));
    for (int i = 1; i < NUM_FOOD; i++){
        buf.insertPlainText(" + " + QString::number(A[i][7]) + " x" + QString::number(i));
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
    buf.append(" c8: " + QString::number(A[0][8]) + " x" + QString::number(0));
    for (int i = 1; i < NUM_FOOD; i++){
        buf.insertPlainText(" + " + QString::number(A[i][8]) + " x" + QString::number(i));
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
    buf.append(" c9: " + QString::number(A[0][9]) + " x" + QString::number(0));
    for (int i = 1; i < NUM_FOOD; i++){
        buf.insertPlainText(" + " + QString::number(A[i][9]) + " x" + QString::number(i));
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
    buf.append(" c10: " + QString::number(A[0][10]) + " x" + QString::number(0));
    for (int i = 1; i < NUM_FOOD; i++){
        buf.insertPlainText(" + " + QString::number(A[i][10]) + " x" + QString::number(i));
        buf.moveCursor(QTextCursor::End);
    }
    buf.insertPlainText(limitsvC + QString::number(vitaminC));
    if(ignorevC){
        cursor.movePosition(QTextCursor::End);
        cursor.select(QTextCursor::LineUnderCursor);
        cursor.removeSelectedText();
        cursor.deletePreviousChar(); // Added to trim the newline char when removing last line
        buf.setTextCursor(cursor);
    }

    //buf.append(" cb: b0 + b1 + b2 + b3 + b4 = 3");

    buf.append("Bounds");
    buf.append("Integer");
    buf.append("");
    for (int i = 0; i < NUM_FOOD; i++) {
        buf.insertPlainText(" x" + QString::number(i));
    }
    //buf.append("binary");
    //buf.append(" b0 b1 b2 b3 b4");
    buf.append("End");

    //write file
    QFile file;
    file.setFileName("model.lp");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);
    out << buf.toPlainText() << endl;

    programming=new ProGramming(this, buf.toPlainText());
    programming->show();
}


void MainWindow::on_checkBox_5_clicked()
{
    if (ui->checkBox_6->isChecked())
        {ui->checkBox_6->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_4->isChecked())
        {ui->checkBox_4->setCheckState(Qt::Unchecked);}
    limitscost=" >= ";
    ignorecost=0;
}

void MainWindow::on_checkBox_4_clicked()
{
    if (ui->checkBox_6->isChecked())
        {ui->checkBox_6->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_5->isChecked())
        {ui->checkBox_5->setCheckState(Qt::Unchecked);}
    limitscost="  <=  ";
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
    limitscal=" >= ";
    ignorecal=0;
}

void MainWindow::on_checkBox_7_clicked()
{
    if (ui->checkBox_8->isChecked())
        {ui->checkBox_8->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_9->isChecked())
        {ui->checkBox_9->setCheckState(Qt::Unchecked);}
    limitscal=" <= ";
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
    limitspro=" >= ";
    ignorepro=0;
}

void MainWindow::on_checkBox_10_clicked()
{
    if (ui->checkBox_11->isChecked())
        {ui->checkBox_11->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_12->isChecked())
        {ui->checkBox_12->setCheckState(Qt::Unchecked);}
    limitspro=" <= ";
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
    limitscar=" >= ";
    ignorecar=0;
}

void MainWindow::on_checkBox_26_clicked()
{
    if (ui->checkBox_22->isChecked())
        {ui->checkBox_22->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_27->isChecked())
        {ui->checkBox_27->setCheckState(Qt::Unchecked);}
    limitscar=" <= ";
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
    limitsvA=" <= ";
    ignorevA=0;
}

void MainWindow::on_checkBox_33_clicked()
{
    if (ui->checkBox_28->isChecked())
        {ui->checkBox_28->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_32->isChecked())
        {ui->checkBox_32->setCheckState(Qt::Unchecked);}
    limitsvA=" >= ";
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
    limitsca=" >= ";
    ignoreca=0;
}

void MainWindow::on_checkBox_38_clicked()
{
    if (ui->checkBox_39->isChecked())
        {ui->checkBox_39->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_34->isChecked())
        {ui->checkBox_34->setCheckState(Qt::Unchecked);}
    limitsca=" <= ";
    ignoreca=0;
}

void MainWindow::on_checkBox_15_clicked()
{
    if (ui->checkBox_13->isChecked())
        {ui->checkBox_13->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_14->isChecked())
        {ui->checkBox_14->setCheckState(Qt::Unchecked);}
    limitsfat=" >= ";
    ignorefat=0;
}

void MainWindow::on_checkBox_14_clicked()
{
    if (ui->checkBox_15->isChecked())
        {ui->checkBox_15->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_13->isChecked())
        {ui->checkBox_13->setCheckState(Qt::Unchecked);}
    limitsfat=" <= ";
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
    limitscho=" <= ";
    ignorecho=0;
}

void MainWindow::on_checkBox_18_clicked()
{
    if (ui->checkBox_16->isChecked())
        {ui->checkBox_16->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_17->isChecked())
        {ui->checkBox_17->setCheckState(Qt::Unchecked);}
    limitscho=" >= ";
    ignorecho=0;
}

void MainWindow::on_checkBox_21_clicked()
{
    if (ui->checkBox_19->isChecked())
        {ui->checkBox_19->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_20->isChecked())
        {ui->checkBox_20->setCheckState(Qt::Unchecked);}
    limitsna=" >= ";
    ignorena=0;
}

void MainWindow::on_checkBox_20_clicked()
{
    if (ui->checkBox_19->isChecked())
        {ui->checkBox_19->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_21->isChecked())
        {ui->checkBox_21->setCheckState(Qt::Unchecked);}
    limitsna=" <= ";
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
    limitsfib=" >= ";
    ignorefib=0;
}

void MainWindow::on_checkBox_24_clicked()
{
    if (ui->checkBox_23->isChecked())
        {ui->checkBox_23->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_25->isChecked())
        {ui->checkBox_25->setCheckState(Qt::Unchecked);}
    limitsfib=" <= ";
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
    limitsvC=" >= ";
    ignorevC=0;
}

void MainWindow::on_checkBox_37_clicked()
{
    if (ui->checkBox_36->isChecked())
        {ui->checkBox_36->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_35->isChecked())
        {ui->checkBox_35->setCheckState(Qt::Unchecked);}
    //limits=" >= ";
}

void MainWindow::on_checkBox_36_clicked()
{
    if (ui->checkBox_35->isChecked())
        {ui->checkBox_35->setCheckState(Qt::Unchecked);}
    if (ui->checkBox_37->isChecked())
        {ui->checkBox_37->setCheckState(Qt::Unchecked);}
   //limits=" <= ";
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

void MainWindow::on_radioButton_1_clicked()
{
    objective=0;
}

void MainWindow::on_radioButton_2_clicked()
{
    objective=1;
}

void MainWindow::on_radioButton_3_clicked()
{
    objective=2;
}

void MainWindow::on_radioButton_4_clicked()
{
    objective=3;
}

void MainWindow::on_radioButton_9_clicked()
{
    objective=4;
}

