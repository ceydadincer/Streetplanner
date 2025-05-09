#ifndef DIALOG_H
#define DIALOG_H
#include <QDialog>

class City;

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    City* createCity();

private slots:

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
