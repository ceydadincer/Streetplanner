#ifndef DIJKSTRADIALOG_H
#define DIJKSTRADIALOG_H

#include <QDialog>

namespace Ui {
class DijkstraDialog;
}

class DijkstraDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DijkstraDialog(QWidget *parent = nullptr);
    ~DijkstraDialog();

private:
    Ui::DijkstraDialog *ui;
};

#endif // DIJKSTRADIALOG_H
