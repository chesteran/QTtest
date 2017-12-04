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
  //  int row=0;
//QTextCursor cursor = ui->textEdit->textCursor();
//cursor.position(row);
//int row=0;
/*cursor.select(QTextCursor::LineUnderCursor);
            cursor.removeSelectedText();
            cursor.deletePreviousChar(); // Added to trim the newline char when removing last line
            buf.setTextCursor(cursor)*/
//ui->textEdit_2=cursor.
//QString line;
//QString line2;
//line2=ui->textEdit->re
//line=ui->textEdit_2->toPlainText();
//for(int i=0;i<50;i++){
//if(line!=)

//}
//line=ui->textEdit->goto
//ui->textEdit_3.insertPlainText();
//if(textEdit_2.toPlainText)
ui->textEdit_3->append("e04");
}
