#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)  
{
    ui->setupUi(this);

    limitscost = " >= ";
    limitscal = " >= ";
    limitspro = " >= ";
    limitscar = " >= ";
    limitsvA = " >= ";
    limitsca = " >= ";
    limitsfat = " >= ";
    limitscho = " >= ";
    limitsna = " >= ";
    limitsfib = " >= ";
    limitsvC = " >= ";
    limitsbla = " >= ";

    objective = 0;
    ignorecost = 0;
    ignorepro = 0;
    ignorecal = 0;
    ignorevA = 0;
    ignorecho = 0;
    ignorena = 0;
    ignorefib = 0;
    ignorevC = 0;
    ignorecar = 0;
    ignoreca = 0;
    ignorefat = 0;

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
    bodyweight = ui->textEditwg->toPlainText().toDouble();
    money = ui->textEditcost->toPlainText().toInt();
    kcal = ui->textEditcal->toPlainText().toDouble();
    protein = ui->textEditpro->toPlainText().toDouble();
    carbohydrate = ui->textEditcar->toPlainText().toDouble();
    vitaminA = ui->textEditvitA->toPlainText().toDouble();
    calcium = ui->textEditca->toPlainText().toDouble();
    fat = ui->textEditfat->toPlainText().toDouble();
    cholesterol = ui->textEditcho->toPlainText().toDouble();
    sodium = ui->textEditna->toPlainText().toDouble();
    fiber = ui->textEditfib->toPlainText().toDouble();
    vitaminC = ui->textEditvitC->toPlainText().toDouble();

    /*
     * read food nutrition matrix
     * column names:
     *  0       1       2       3           4           5       6   7           8       9       10
     *  money   calorie protien carbohydrat vitamin A   calcium fat cholesterol sodium  fiber   vitaminC
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

    /*
     * write equation on window textEdit
     */

    // objective function
    QTextEdit buf;
    buf.insertPlainText("Minimize\n ");
    buf.moveCursor(QTextCursor::End);
    switch (objective) {
    case 0: // cost
        for (int i = 0; i < NUM_FOOD; i++) {
            buf.insertPlainText(QString::number(A[i][0]) + " x" + QString::number(i) + " + ");
        }
        break;
    case 1: // calorie
        for (int i = 0; i < NUM_FOOD; i++) {
            buf.insertPlainText(QString::number(A[i][1]) + " x" + QString::number(i) + " + ");
        }
        break;
    case 2: // carbohydrate
        for (int i = 0; i < NUM_FOOD; i++) {
            buf.insertPlainText(QString::number(A[i][3]) + " x" + QString::number(i) + " + ");
            buf.moveCursor(QTextCursor::End);
        }
        break;
    case 3: // protien fat ratio
        for (int i = 0; i < NUM_FOOD; i++) {
            buf.insertPlainText(QString::number(A[i][2]/(A[i][6] + 1)) + " x" + QString::number(i) + " + ");
        }
        break;
    case 4: // fat
        for (int i = 0; i < NUM_FOOD; i++) {
            buf.insertPlainText(QString::number(A[i][6]) + " x" + QString::number(i) + " + ");
            buf.moveCursor(QTextCursor::End);
        }
        break;

    default:
        break;
    }
    buf.insertPlainText("[ e0 ^ 2");
    for (int i = 1; i < 10; ++i) {
        buf.insertPlainText(" + e" + QString::number(i) + " ^ 2");
    }
    buf.insertPlainText(" ]");

    // constraint
    int constraintNum = 0;
    int errVarNum = 0;
    buf.append("Subject To");
    // money
    if (objective != 0) {
        buf.append(" c" + QString::number(constraintNum++) + ": e" + QString::number(errVarNum++));
        for (int i = 0; i < NUM_FOOD; i++) {
            buf.insertPlainText(" + " + QString::number(A[i][0]) + " x" + QString::number(i));
        }
        buf.insertPlainText(limitscost + QString::number(money));
        if (ignorecost) ignore(&buf);
    }

    // kcal
    if (objective != 1) {
        buf.append(" c" + QString::number(constraintNum++) + ": e" + QString::number(errVarNum++));
        for (int i = 0; i < NUM_FOOD; i++) {
            buf.insertPlainText(" + " + QString::number(A[i][1]) + " x" + QString::number(i));
        }
        buf.insertPlainText(limitscal + QString::number(kcal));
        if(ignorecal) ignore(&buf);
    }

    // protein
    if (objective != 3 || objective != 4) {
        buf.append(" c" + QString::number(constraintNum++) + ": e" + QString::number(errVarNum++));
        for (int i = 0; i < NUM_FOOD; i++) {
            buf.insertPlainText(" + " + QString::number(A[i][2]) + " x" + QString::number(i));
        }
        buf.insertPlainText(limitspro + QString::number(protein));
        if (ignorepro) ignore(&buf);
    }

    // carbohydrate
    if (objective != 2) {
        buf.append(" c" + QString::number(constraintNum++) + ": e" + QString::number(errVarNum++));
        for (int i = 0; i < NUM_FOOD; i++) {
            buf.insertPlainText(" + " + QString::number(A[i][3]) + " x" + QString::number(i));
        }
        buf.insertPlainText(limitscar + QString::number(carbohydrate));
        if (ignorecar) ignore(&buf);
    }

    // vitaminA
    buf.append(" c" + QString::number(constraintNum++) + ": e" + QString::number(errVarNum++));
    for (int i = 0; i < NUM_FOOD; i++) {
        buf.insertPlainText(" + " + QString::number(A[i][4]) + " x" + QString::number(i));
    }
    buf.insertPlainText(limitsvA + QString::number(vitaminA));
    if (ignorevA) ignore(&buf);

    // calcium
    buf.append(" c" + QString::number(constraintNum++) + ": e" + QString::number(errVarNum++));
    for (int i = 0; i < NUM_FOOD; i++) {
        buf.insertPlainText(" + " + QString::number(A[i][5]) + " x" + QString::number(i));
    }
    buf.insertPlainText(limitsca + QString::number(calcium));
    if (ignoreca) ignore(&buf);

    // fat
    if (objective != 3) {
        buf.append(" c" + QString::number(constraintNum++) + ": e" + QString::number(errVarNum++));
        for (int i = 0; i < NUM_FOOD; i++) {
            buf.insertPlainText(" + " + QString::number(A[i][6]) + " x" + QString::number(i));
        }
        buf.insertPlainText(limitsfat + QString::number(fat));
        if (ignorefat) ignore(&buf);
    }

    // cholesterol
    buf.append(" c" + QString::number(constraintNum++) + ": e" + QString::number(errVarNum++));
    for (int i = 0; i < NUM_FOOD; i++) {
        buf.insertPlainText(" + " + QString::number(A[i][7]) + " x" + QString::number(i));
    }
    buf.insertPlainText(limitscho + QString::number(cholesterol));
    if (ignorecho) ignore(&buf);

    // sodium
    buf.append(" c" + QString::number(constraintNum++) + ": e" + QString::number(errVarNum++));
    for (int i = 0; i < NUM_FOOD; i++) {
        buf.insertPlainText(" + " + QString::number(A[i][8]) + " x" + QString::number(i));
    }
    buf.insertPlainText(limitsna + QString::number(sodium));
    if(ignorena) ignore(&buf);

    // fiber
    buf.append(" c" + QString::number(constraintNum++) + ": e" + QString::number(errVarNum++));
    for (int i = 0; i < NUM_FOOD; i++) {
        buf.insertPlainText(" + " + QString::number(A[i][9]) + " x" + QString::number(i));
    }
    buf.insertPlainText(limitsfib + QString::number(fiber));
    if (ignorefib) ignore(&buf);

    // vitaminC
    buf.append(" c" + QString::number(constraintNum++) + ": e" + QString::number(errVarNum++));
    for (int i = 0; i < NUM_FOOD; i++) {
        buf.insertPlainText(" + " + QString::number(A[i][10]) + " x" + QString::number(i));
    }
    buf.insertPlainText(limitsvC + QString::number(vitaminC));
    if (ignorevC) ignore(&buf);

    /*
     * M * y >= x
     * M * x >= y
     */
    buf.append("");
    for (int i = 0; i < NUM_FOOD; ++i) {
        buf.insertPlainText(" c" + QString::number(constraintNum++) + ": x" + QString::number(i) + " - 1000000 y" + QString::number(i) + " <= 0\n");
        buf.insertPlainText(" c" + QString::number(constraintNum++) + ": y" + QString::number(i) + " - 1000000 x" + QString::number(i) + " <= 0\n");
    }

    /*
     * SUM(Y) = 3
     */
    buf.insertPlainText(" c" + QString::number(constraintNum++) + ": ");
    for (int i = 0; i < NUM_FOOD - 1; ++i) {
        buf.insertPlainText("y" + QString::number(i) + " + ");
    }
    buf.insertPlainText("y" + QString::number(NUM_FOOD-1) + " = 3\n");

    // variable
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
    for (int i = 0; i < errVarNum; ++i) {
        buf.insertPlainText(" e" + QString::number(i));
    }
    buf.append("End");

    /*
     * write model to file
     */
    QFile file;
    file.setFileName("model.lp");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);
    out << buf.toPlainText() << endl;

    //
    programming=new ProGramming(this, buf.toPlainText());
    programming->show();
}


void MainWindow::on_checkBox_5_clicked()
{
    if (ui->checkBox_6->isChecked()) {
        ui->checkBox_6->setCheckState(Qt::Unchecked);
    }
    if (ui->checkBox_4->isChecked()) {
        ui->checkBox_4->setCheckState(Qt::Unchecked);
    }
    limitscost = " >= ";
    ignorecost = 0;
}

void MainWindow::on_checkBox_4_clicked()
{
    if (ui->checkBox_6->isChecked()) {
        ui->checkBox_6->setCheckState(Qt::Unchecked);
    }
    if (ui->checkBox_5->isChecked()) {
        ui->checkBox_5->setCheckState(Qt::Unchecked);
    }
    limitscost = "  <=  ";
    ignorecost = 0;
}

void MainWindow::on_checkBox_6_clicked()
{
    if (ui->checkBox_5->isChecked()) {
        ui->checkBox_5->setCheckState(Qt::Unchecked);
    }
    if (ui->checkBox_4->isChecked()) {
        ui->checkBox_4->setCheckState(Qt::Unchecked);
    }
    ignorecost = 1;
}

void MainWindow::on_checkBox_8_clicked()
{
    if (ui->checkBox_7->isChecked()) {
        ui->checkBox_7->setCheckState(Qt::Unchecked);
    }
    if (ui->checkBox_9->isChecked()) {
        ui->checkBox_9->setCheckState(Qt::Unchecked);
    }
    limitscal = " >= ";
    ignorecal = 0;
}

void MainWindow::on_checkBox_7_clicked()
{
    if (ui->checkBox_8->isChecked()) {
        ui->checkBox_8->setCheckState(Qt::Unchecked);
    }
    if (ui->checkBox_9->isChecked()) {
        ui->checkBox_9->setCheckState(Qt::Unchecked);
    }
    limitscal = " <= ";
    ignorecal = 0;
}

void MainWindow::on_checkBox_9_clicked()
{
    if (ui->checkBox_7->isChecked()) {
        ui->checkBox_7->setCheckState(Qt::Unchecked);
    }
    if (ui->checkBox_8->isChecked()) {
        ui->checkBox_8->setCheckState(Qt::Unchecked);
    }
    ignorecal = 1;
}

void MainWindow::on_checkBox_11_clicked()
{
    if (ui->checkBox_10->isChecked()) {
        ui->checkBox_10->setCheckState(Qt::Unchecked);
    }
    if (ui->checkBox_12->isChecked()) {
        ui->checkBox_12->setCheckState(Qt::Unchecked);
    }
    limitspro = " >= ";
    ignorepro = 0;
}

void MainWindow::on_checkBox_10_clicked()
{
    if (ui->checkBox_11->isChecked()) {
        ui->checkBox_11->setCheckState(Qt::Unchecked);
    }
    if (ui->checkBox_12->isChecked()) {
        ui->checkBox_12->setCheckState(Qt::Unchecked);
    }
    limitspro = " <= ";
    ignorepro = 0;
}

void MainWindow::on_checkBox_12_clicked()
{
    if (ui->checkBox_10->isChecked()) {
        ui->checkBox_10->setCheckState(Qt::Unchecked);
    }
    if (ui->checkBox_11->isChecked()) {
        ui->checkBox_11->setCheckState(Qt::Unchecked);
    }
    ignorepro = 1;
}

void MainWindow::on_checkBox_22_clicked()
{
    if (ui->checkBox_26->isChecked()) {
        ui->checkBox_26->setCheckState(Qt::Unchecked);
    }
    if (ui->checkBox_27->isChecked()) {
        ui->checkBox_27->setCheckState(Qt::Unchecked);
    }
    ignorecar = 1;
}

void MainWindow::on_checkBox_27_clicked()
{
    if (ui->checkBox_26->isChecked()) {
        ui->checkBox_26->setCheckState(Qt::Unchecked);
    }
    if (ui->checkBox_22->isChecked()) {
        ui->checkBox_22->setCheckState(Qt::Unchecked);
    }
    limitscar = " >= ";
    ignorecar = 0;
}

void MainWindow::on_checkBox_26_clicked()
{
    if (ui->checkBox_22->isChecked()) {
        ui->checkBox_22->setCheckState(Qt::Unchecked);
    }
    if (ui->checkBox_27->isChecked()) {
        ui->checkBox_27->setCheckState(Qt::Unchecked);
    }
    limitscar = " <= ";
    ignorecar = 0;
}

void MainWindow::on_checkBox_28_clicked()
{
    if (ui->checkBox_32->isChecked()) {
        ui->checkBox_32->setCheckState(Qt::Unchecked);
    }
    if (ui->checkBox_33->isChecked()) {
        ui->checkBox_33->setCheckState(Qt::Unchecked);
    }
    ignorevA = 1;
}

void MainWindow::on_checkBox_32_clicked()
{
    if (ui->checkBox_33->isChecked()) {
        ui->checkBox_33->setCheckState(Qt::Unchecked);
    }
    if (ui->checkBox_28->isChecked()) {
        ui->checkBox_28->setCheckState(Qt::Unchecked);
    }
    limitsvA = " <= ";
    ignorevA = 0;
}

void MainWindow::on_checkBox_33_clicked()
{
    if (ui->checkBox_28->isChecked()) {
        ui->checkBox_28->setCheckState(Qt::Unchecked);
    }
    if (ui->checkBox_32->isChecked()) {
        ui->checkBox_32->setCheckState(Qt::Unchecked);
    }
    limitsvA = " >= ";
    ignorevA = 0;
}

void MainWindow::on_checkBox_34_clicked()
{
    if (ui->checkBox_39->isChecked()) {
        ui->checkBox_39->setCheckState(Qt::Unchecked);
    }
    if (ui->checkBox_38->isChecked()) {
        ui->checkBox_38->setCheckState(Qt::Unchecked);
    }
    ignoreca = 1;
}

void MainWindow::on_checkBox_39_clicked()
{
    if (ui->checkBox_38->isChecked()) {
        ui->checkBox_38->setCheckState(Qt::Unchecked);
    }
    if (ui->checkBox_34->isChecked()) {
        ui->checkBox_34->setCheckState(Qt::Unchecked);
    }
    limitsca = " >= ";
    ignoreca = 0;
}

void MainWindow::on_checkBox_38_clicked()
{
    if (ui->checkBox_39->isChecked()) {
        ui->checkBox_39->setCheckState(Qt::Unchecked);
    }
    if (ui->checkBox_34->isChecked()) {
        ui->checkBox_34->setCheckState(Qt::Unchecked);
    }
    limitsca = " <= ";
    ignoreca = 0;
}

void MainWindow::on_checkBox_15_clicked()
{
    if (ui->checkBox_13->isChecked()) {
        ui->checkBox_13->setCheckState(Qt::Unchecked);
    }
    if (ui->checkBox_14->isChecked()) {
        ui->checkBox_14->setCheckState(Qt::Unchecked);
    }
    limitsfat = " >= ";
    ignorefat = 0;
}

void MainWindow::on_checkBox_14_clicked()
{
    if (ui->checkBox_15->isChecked()) {
        ui->checkBox_15->setCheckState(Qt::Unchecked);
    }
    if (ui->checkBox_13->isChecked()) {
        ui->checkBox_13->setCheckState(Qt::Unchecked);
    }
    limitsfat=" <= ";
    ignorefat=0;
}

void MainWindow::on_checkBox_13_clicked()
{
    if (ui->checkBox_15->isChecked()) {
        ui->checkBox_15->setCheckState(Qt::Unchecked);
    }
    if (ui->checkBox_14->isChecked()) {
        ui->checkBox_14->setCheckState(Qt::Unchecked);
    }
    ignorefat = 1;
}

void MainWindow::on_checkBox_16_clicked()
{
    if (ui->checkBox_18->isChecked()) {
        ui->checkBox_18->setCheckState(Qt::Unchecked);
    }
    if (ui->checkBox_17->isChecked()) {
        ui->checkBox_17->setCheckState(Qt::Unchecked);
    }
    ignorecho = 1;

}

void MainWindow::on_checkBox_17_clicked()
{
    if (ui->checkBox_16->isChecked()) {
        ui->checkBox_16->setCheckState(Qt::Unchecked);
    }
    if (ui->checkBox_18->isChecked()) {
        ui->checkBox_18->setCheckState(Qt::Unchecked);
    }
    limitscho = " <= ";
    ignorecho = 0;
}

void MainWindow::on_checkBox_18_clicked()
{
    if (ui->checkBox_16->isChecked()) ui->checkBox_16->setCheckState(Qt::Unchecked);
    if (ui->checkBox_17->isChecked()) ui->checkBox_17->setCheckState(Qt::Unchecked);
    limitscho = " >= ";
    ignorecho = 0;
}

void MainWindow::on_checkBox_21_clicked()
{
    if (ui->checkBox_19->isChecked()) ui->checkBox_19->setCheckState(Qt::Unchecked);
    if (ui->checkBox_20->isChecked()) ui->checkBox_20->setCheckState(Qt::Unchecked);
    limitsna = " >= ";
    ignorena = 0;
}

void MainWindow::on_checkBox_20_clicked()
{
    if (ui->checkBox_19->isChecked()) ui->checkBox_19->setCheckState(Qt::Unchecked);
    if (ui->checkBox_21->isChecked()) ui->checkBox_21->setCheckState(Qt::Unchecked);
    limitsna = " <= ";
    ignorena = 0;
}

void MainWindow::on_checkBox_19_clicked()
{
    if (ui->checkBox_20->isChecked()) ui->checkBox_20->setCheckState(Qt::Unchecked);
    if (ui->checkBox_21->isChecked()) ui->checkBox_21->setCheckState(Qt::Unchecked);
    ignorena = 1;
}

void MainWindow::on_checkBox_25_clicked()
{
    if (ui->checkBox_23->isChecked()) ui->checkBox_23->setCheckState(Qt::Unchecked);
    if (ui->checkBox_24->isChecked()) ui->checkBox_24->setCheckState(Qt::Unchecked);
    limitsfib = " >= ";
    ignorefib = 0;
}

void MainWindow::on_checkBox_24_clicked()
{
    if (ui->checkBox_23->isChecked()) ui->checkBox_23->setCheckState(Qt::Unchecked);
    if (ui->checkBox_25->isChecked()) ui->checkBox_25->setCheckState(Qt::Unchecked);
    limitsfib = " <= ";
    ignorefib = 0;
}

void MainWindow::on_checkBox_23_clicked()
{
    if (ui->checkBox_25->isChecked()) ui->checkBox_25->setCheckState(Qt::Unchecked);
    if (ui->checkBox_24->isChecked())ui->checkBox_24->setCheckState(Qt::Unchecked);
    limitsfib = "not relate to ";
    ignorefib = 1;
}

void MainWindow::on_checkBox_29_clicked()
{
    if (ui->checkBox_30->isChecked()) ui->checkBox_30->setCheckState(Qt::Unchecked);
    if (ui->checkBox_31->isChecked()) ui->checkBox_31->setCheckState(Qt::Unchecked);
    ignorevC=1;
}

void MainWindow::on_checkBox_30_clicked()
{
    if (ui->checkBox_29->isChecked()) ui->checkBox_29->setCheckState(Qt::Unchecked);
    if (ui->checkBox_31->isChecked()) ui->checkBox_31->setCheckState(Qt::Unchecked);
    limitsvC = "<=";
    ignorevC = 0;
}

void MainWindow::on_checkBox_31_clicked()
{
    if (ui->checkBox_29->isChecked()) ui->checkBox_29->setCheckState(Qt::Unchecked);
    if (ui->checkBox_30->isChecked()) ui->checkBox_30->setCheckState(Qt::Unchecked);
    limitsvC = " >= ";
    ignorevC = 0;
}

void MainWindow::on_checkBox_37_clicked()
{
    if (ui->checkBox_36->isChecked()) ui->checkBox_36->setCheckState(Qt::Unchecked);
    if (ui->checkBox_35->isChecked()) ui->checkBox_35->setCheckState(Qt::Unchecked);
}

void MainWindow::on_checkBox_36_clicked()
{
    if (ui->checkBox_35->isChecked()) ui->checkBox_35->setCheckState(Qt::Unchecked);
    if (ui->checkBox_37->isChecked()) ui->checkBox_37->setCheckState(Qt::Unchecked);
}

void MainWindow::on_checkBox_35_clicked()
{
    if (ui->checkBox_36->isChecked()) ui->checkBox_36->setCheckState(Qt::Unchecked);
    if (ui->checkBox_37->isChecked()) ui->checkBox_37->setCheckState(Qt::Unchecked);
}

void MainWindow::on_pushButton_2_clicked()
{
    /**
    QTextEdit foodbuf;
    QTextCursor cursor = foodbuf.textCursor();

    QFile in("Mat.csv");
    in.open(QIODevice::ReadOnly);
    QTextStream is(&in);
    is.setCodec("UTF-8");
    QByteArray line;
    vector<QString> foodName;

    int row = 0;
    while (!in.atEnd()) {
        line = in.readLine();
        if (row > 0) {
            foodbuf.append(line.split(',').first());

        }
        row++;
    }

    foodlist = new FoodList(this,foodbuf.toPlainText());
    foodlist->show();
    */
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

void MainWindow::ignore(QTextEdit * textEdit)
{
    textEdit->textCursor().movePosition(QTextCursor::End);
    textEdit->textCursor().select(QTextCursor::LineUnderCursor);
    textEdit->textCursor().removeSelectedText();
    textEdit->textCursor().deletePreviousChar();// Added to trim the newline char when removing last line
    textEdit->setTextCursor(textEdit->textCursor());
}
