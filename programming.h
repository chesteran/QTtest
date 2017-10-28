#ifndef PROGRAMMING_H
#define PROGRAMMING_H

#include <QMainWindow>

namespace Ui {
class ProGramming;
}

class ProGramming : public QMainWindow
{
    Q_OBJECT

public:
    explicit ProGramming(QWidget *parent = 0);
    ~ProGramming();

private:
    Ui::ProGramming *ui;
};

#endif // PROGRAMMING_H
