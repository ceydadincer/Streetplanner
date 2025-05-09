#include "streetdialog.h"
#include "ui_streetdialog.h"
#include <QMessageBox>
#include <QRegularExpression>

StreetDialog::StreetDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::StreetDialog)
{
    ui->setupUi(this);
}

StreetDialog::~StreetDialog()
{
    delete ui;
}

/**
 * @brief Erstellt einen Vektor von Strings mit den vom Benutzer angegebenen Daten.
 *
 * Gibt den Vektor zurueck, der von der Funktion "Add Street" verwendet wird, um
 * eine Strasse zu erstellen.
 * Die zwei Elemente dieses Vektors sind die Namen der Staedte, die die Strasse verbindet.
 *
 * @return Der neu erzeugte Vektor oder nullptr
 */
QVector<QString*> StreetDialog::createCitiesVector()
{
    QMessageBox msgBox;
    QString text;

    QVector<QString*> names = {};
    QString inputCity1Name = ui->lineEditCity1->text();
    QString inputCity2Name = ui->lineEditCity2->text();

    // Eine Instanz von QRegularExpression mit dem regulaeren Ausdruck fuer eine Stadt.
    QRegularExpression re("^[A-Za-z\\s-]+$");
    // ^ am Anfang stellt sicher, dass sich keine Zeichen vor dem Muster befinden.
    // [A-Za-z\\s] eine Zeichenklasse fuer gueltige Zeichen fuer einen Stadtnamen
    // $ am Ende stellt sicher, dass sich keine Zeichen nach dem Muster befinden.

    // Eine Instanz von QRegularExpressionMatch, die ueberprueft, ob der angegebener String
    // dem Muster entspricht
    QRegularExpressionMatch match1 = re.match(inputCity1Name);

    // Wenn ja, ist hasMatch true
    bool hasMatch1 = match1.hasMatch();

    QRegularExpressionMatch match2 = re.match(inputCity2Name);
    bool hasMatch2 = match2.hasMatch();

    // der Benutzer gibt keine Eingabe ein
    if (inputCity1Name.isEmpty() || inputCity2Name.isEmpty())
    {
        text = "All boxes must be filled.";
        qDebug() << text;
        msgBox.setText(text);
        msgBox.exec();
        return names;
    }

    // der Benutzer gibt zweimal die gleiche Stadt ein
    if (inputCity1Name == inputCity2Name)
    {
        text = "Same city entered twice.";
        qDebug() << text;
        msgBox.setText(text);
        msgBox.exec();
        return names;
    }

    if (!(hasMatch1 && hasMatch2))
    {
        text = "The city name isn't in the accepted format.";
        qDebug() << text;
        msgBox.setText(text);
        msgBox.exec();
        return names;
    }

    names.push_back(new QString(inputCity1Name));
    names.push_back(new QString(inputCity2Name));
    return names;
}

