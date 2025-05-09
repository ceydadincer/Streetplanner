#ifndef STREETDIALOG_H
#define STREETDIALOG_H

#include <QDialog>

class Street;

namespace Ui {
class StreetDialog;
}

class StreetDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StreetDialog(QWidget *parent = nullptr);
    ~StreetDialog();
    QVector<QString*> createCitiesVector();

private:
    Ui::StreetDialog *ui;
};

#endif // STREETDIALOG_H
