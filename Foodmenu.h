#ifndef FOODMENU_H
#define FOODMENU_H

#include <QDialog>

namespace Ui {
class Foodmenu;
}

class Foodmenu : public QDialog
{
    Q_OBJECT

public:
    explicit Foodmenu(QWidget *parent = 0);
    ~Foodmenu();

private:
    Ui::Foodmenu *ui;
};

#endif // FOODMENU_H
