#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)  
{
    ui->setupUi(this);
    ui->textEditcal->setText("2400");
    ui->textEditcho->setText("0");
    ui->textEditfat->setText("0");
    ui->textEditna->setText("0");
    ui->textEditcar->setText("0");
    ui->textEditfib->setText("0");
    ui->textEditpro->setText("60");
    ui->textEditvitA->setText("600");
    ui->textEditvitC->setText("100");
    ui->textEditca->setText("1200");
    ui->textgender->setText("0");
    ui->textage->setText("30");
    ui->textEditca->hide();
    ui->textEditcal->hide();
    ui->textEditcar->hide();
    ui->textEditcho->hide();
    ui->textEditcost->hide();
    ui->textEditfat->hide();
    ui->textEditfib->hide();
    ui->textEditna->hide();
    ui->textEditpro->hide();
    ui->textEditvitA->hide();
    ui->textEditvitC->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    gendert=ui->textgender->toPlainText();
    gender=gendert.toInt();
    aget=ui->textage->toPlainText();
    age=aget.toInt();
    if(gender==0){
    if(age>0&&age<=15)
    {   ui->textEditcal->setText("2800");
        ui->textEditcho->setText("0");
        ui->textEditfat->setText("0");
        ui->textEditna->setText("0");
        ui->textEditcar->setText("0");
        ui->textEditfib->setText("0");
        ui->textEditpro->setText("70");
        ui->textEditvitA->setText("600");
        ui->textEditvitC->setText("100");
        ui->textEditca->setText("1200");}
    else if(age>15&&age<=20)
    {   ui->textEditcal->setText("2900");
        ui->textEditcho->setText("0");
        ui->textEditfat->setText("0");
        ui->textEditna->setText("0");
        ui->textEditcar->setText("0");
        ui->textEditfib->setText("0");
        ui->textEditpro->setText("75");
        ui->textEditvitA->setText("700");
        ui->textEditvitC->setText("100");
        ui->textEditca->setText("1200");}
    else if(age>20&&age<=30)
    {   ui->textEditcal->setText("2400");
        ui->textEditcho->setText("0");
        ui->textEditfat->setText("0");
        ui->textEditna->setText("0");
        ui->textEditcar->setText("0");
        ui->textEditfib->setText("0");
        ui->textEditpro->setText("60");
        ui->textEditvitA->setText("600");
        ui->textEditvitC->setText("100");
        ui->textEditca->setText("1200");}
    else if(age>30&&age<=40)
    {   ui->textEditcal->setText("2400");
        ui->textEditcho->setText("0");
        ui->textEditfat->setText("0");
        ui->textEditna->setText("0");
        ui->textEditcar->setText("0");
        ui->textEditfib->setText("0");
        ui->textEditpro->setText("60");
        ui->textEditvitA->setText("600");
        ui->textEditvitC->setText("100");
        ui->textEditca->setText("1200");}
    else if(age>40&&age<=50)
    {   ui->textEditcal->setText("2400");
        ui->textEditcho->setText("0");
        ui->textEditfat->setText("0");
        ui->textEditna->setText("0");
        ui->textEditcar->setText("0");
        ui->textEditfib->setText("0");
        ui->textEditpro->setText("60");
        ui->textEditvitA->setText("600");
        ui->textEditvitC->setText("100");
        ui->textEditca->setText("1200");}
    else if(age>50&&age<=60)
    {   ui->textEditcal->setText("2250");
        ui->textEditcho->setText("0");
        ui->textEditfat->setText("0");
        ui->textEditna->setText("0");
        ui->textEditcar->setText("0");
        ui->textEditfib->setText("0");
        ui->textEditpro->setText("55");
        ui->textEditvitA->setText("600");
        ui->textEditvitC->setText("100");
        ui->textEditca->setText("1000");}
    else if(age>60)
    {
             ui->textEditcal->setText("2150");
             ui->textEditcho->setText("0");
             ui->textEditfat->setText("0");
             ui->textEditna->setText("0");
             ui->textEditcar->setText("0");
             ui->textEditfib->setText("0");
             ui->textEditpro->setText("60");
             ui->textEditvitA->setText("600");
             ui->textEditvitC->setText("100");
             ui->textEditca->setText("1000");}

    }
    else if(gender==1)
   {
        if(age>0&&age<=15)
        {   ui->textEditcal->setText("2350");
            ui->textEditcho->setText("0");
            ui->textEditfat->setText("0");
            ui->textEditna->setText("0");
            ui->textEditcar->setText("0");
            ui->textEditfib->setText("0");
            ui->textEditpro->setText("70");
            ui->textEditvitA->setText("600");
            ui->textEditvitC->setText("100");
            ui->textEditca->setText("1200");}
        else if(age>15&&age<=20)
        {   ui->textEditcal->setText("2250");
            ui->textEditcho->setText("0");
            ui->textEditfat->setText("0");
            ui->textEditna->setText("0");
            ui->textEditcar->setText("0");
            ui->textEditfib->setText("0");
            ui->textEditpro->setText("55");
            ui->textEditvitA->setText("500");
            ui->textEditvitC->setText("100");
            ui->textEditca->setText("1200");}
        else if(age>20&&age<=30)
        {   ui->textEditcal->setText("1900");
            ui->textEditcho->setText("0");
            ui->textEditfat->setText("0");
            ui->textEditna->setText("0");
            ui->textEditcar->setText("0");
            ui->textEditfib->setText("0");
            ui->textEditpro->setText("50");
            ui->textEditvitA->setText("500");
            ui->textEditvitC->setText("100");
            ui->textEditca->setText("1200");}
        else if(age>30&&age<=40)
        {   ui->textEditcal->setText("1900");
            ui->textEditcho->setText("0");
            ui->textEditfat->setText("0");
            ui->textEditna->setText("0");
            ui->textEditcar->setText("0");
            ui->textEditfib->setText("0");
            ui->textEditpro->setText("50");
            ui->textEditvitA->setText("500");
            ui->textEditvitC->setText("100");
            ui->textEditca->setText("1200");}
        else if(age>40&&age<=50)
        {   ui->textEditcal->setText("1900");
            ui->textEditcho->setText("0");
            ui->textEditfat->setText("0");
            ui->textEditna->setText("0");
            ui->textEditcar->setText("0");
            ui->textEditfib->setText("0");
            ui->textEditpro->setText("50");
            ui->textEditvitA->setText("500");
            ui->textEditvitC->setText("100");
            ui->textEditca->setText("1200");}
        else if(age>50&&age<=60)
        {   ui->textEditcal->setText("1800");
            ui->textEditcho->setText("0");
            ui->textEditfat->setText("0");
            ui->textEditna->setText("0");
            ui->textEditcar->setText("0");
            ui->textEditfib->setText("0");
            ui->textEditpro->setText("50");
            ui->textEditvitA->setText("500");
            ui->textEditvitC->setText("100");
            ui->textEditca->setText("1000");}
        else if(age>60)
        {   ui->textEditcal->setText("1700");
            ui->textEditcho->setText("0");
            ui->textEditfat->setText("0");
            ui->textEditna->setText("0");
            ui->textEditcar->setText("0");
            ui->textEditfib->setText("0");
            ui->textEditpro->setText("60");
            ui->textEditvitA->setText("600");
            ui->textEditvitC->setText("100");
            ui->textEditca->setText("1000");
        }

    }
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
                A[row - 1][i] = list.at(i + 2).toDouble();
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
    //y1,y2,,,,,
    //y1+y2+..=3
   buf.append("");
    for(int i=0;i<NUM_FOOD;i++){
        buf.insertPlainText(" c" + QString::number(60+i) + ": x" + QString::number(i) + " - 1000000 y" + QString::number(i) + " <= 0\n");
        buf.insertPlainText(" c" + QString::number(61+i) + ": y" + QString::number(i) + " - 1000000 x" + QString::number(i) + " <= 0\n");
    }
    buf.insertPlainText(" c" + QString::number(60 + NUM_FOOD + 1) + ": ");
    for(int i=0;i<NUM_FOOD-1;i++){
        buf.insertPlainText("y" + QString::number(i) + " + ");
    }
    buf.insertPlainText("y"+QString::number(49)+" = 3\n");
    buf.append("Bounds");
    buf.append("Binary\n");
    for (int i = 0; i < NUM_FOOD; i++) {
        buf.insertPlainText(" y" + QString::number(i));
    }
    buf.append("Integer");
    buf.append("");
    for (int i = 0; i < NUM_FOOD; i++) {
        buf.insertPlainText(" x" + QString::number(i));
    }
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



void MainWindow::on_pushButton_2_clicked()
{
    QTextEdit foodbuf;
    QTextCursor cursor = foodbuf.textCursor();
   // banlist
   /* QFile foodin;
    foodin.setFileName("/home/user/下載/QTtest-master/Mat.csv");
    foodin.open(QIODevice::ReadOnly);
       if (!foodin.isOpen()) {
           qDebug() << foodin.errorString();
        return;
       }

      // QStringList dataList;
       while (!foodin.atEnd()) {
           QString line = foodin.readLine();
           foodbuf.append(line.split(",").first());
       }
       foodin.close();*/
    //foodbuf.insertPlainText("e04");

       //qDebug() << foodbuf;
/*QStringList firstColumn;
QFile f1("h:/1.txt");
f1.open(QIODevice::ReadOnly);
QTextStream s1(&f1);
while (!in.atEnd()){
  QString s=s1.readLine(); // reads line from file
  firstColumn.append(s.split(",").first()); // appends first column to list, ',' is separator
}
f1.close();*/

   /* programming=new ProGramming(this, buf.toPlainText());
    programming->show();*/
 //QCheckBox foodbox[50];
    QFile in;
    in.setFileName("/home/user/下載/QTtest-master/Mat.csv");
    in.open(QIODevice::ReadOnly);
    QTextStream is(&in);
    is.setCodec("UTF-8");
    QByteArray line;
   // vector<QString> foodName;

    int row = 0;
    while(!in.atEnd()) {
        line = in.readLine();
        if (row > 0) {
           // foodbuf.insertPlainText(row+" ");

            foodbuf.append(line.split(',').first());
          //  foodName.push_back(line.split(',').first());
        }
        row++;
    }


    foodlist=new FoodList(this,foodbuf.toPlainText());
    foodlist->show();



}
/*
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
*/

void MainWindow::on_pushButton_3_clicked()
{
    dietdisplay= new DietdisPlay(this,gender,age);
    dietdisplay->show();
}
