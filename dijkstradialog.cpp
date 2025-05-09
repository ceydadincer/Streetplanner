#include "dijkstradialog.h"
#include "ui_dijkstradialog.h"

DijkstraDialog::DijkstraDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DijkstraDialog)
{
    ui->setupUi(this);
}

DijkstraDialog::~DijkstraDialog()
{
    delete ui;
}
