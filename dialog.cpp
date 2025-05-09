#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>
#include "city.h"
#include <QRegularExpression>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


/**
 * @brief Erstellt eine neue Stadt mit den vom Benutzer angegebenen Daten.
 *
 * @return Zeiger auf die neu erzuegte City-Instanz
 */
City* Dialog::createCity()
{
    QString name = ui->lineEditName->text();
    QString inputX = ui->lineEditX->text();
    QString inputY = ui->lineEditY->text();

    QMessageBox msgBox;
    QString text;

    QRegularExpression re("^[A-Za-z\\s-]+$");
    QRegularExpressionMatch match = re.match(name);
    bool hasMatch = match.hasMatch();

    // der Benutzer gibt keine Eingabe ein
    if (name.isEmpty() || inputX.isEmpty() || inputY.isEmpty())
    {
        text = "All boxes must be filled.";
        qDebug() << text;
        msgBox.setText(text);
        msgBox.exec();
        return nullptr;
    }

    if (!(hasMatch))
    {
        text = "The city name isn't in the accepted format.";
        qDebug() << text;
        msgBox.setText(text);
        msgBox.exec();
        return nullptr;
    }

    bool okX;
    bool okY;
    int x = inputX.toInt(&okX);
    int y = inputY.toInt(&okY);

    if(!(okX && okY))
    {
        text = "The coordinates aren't in the accepted format.";
        qDebug() << text;
        msgBox.setText(text);
        msgBox.exec();
        return nullptr;
    }


    City* city = new City(name, x, y);
    qDebug() << "The city " << name << " with the coordinates (" << x << ", " << y << ") is created.";
    return city;
}



