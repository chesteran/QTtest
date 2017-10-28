#ifndef FOODLIST_H
#define FOODLIST_H

#include <QDialog>

namespace Ui {
class FoodList;
}

class FoodList : public QDialog
{
    Q_OBJECT

public:
    explicit FoodList(QWidget *parent = 0);
    ~FoodList();

private:
    Ui::FoodList *ui;
};

#endif // FOODLIST_H
