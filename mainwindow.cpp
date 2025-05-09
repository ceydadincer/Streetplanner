#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QRandomGenerator>
#include "city.h"
#include "street.h"
#include "dialog.h"
#include "streetdialog.h"
#include "mapionrw.h"
#include <QInputDialog>
#include "dijkstra.h"


MainWindow::MainWindow(QWidget *parent) // we establish a child-parent relationship
    // in order to manage memory. For example MainWindow is a type of QWidget, if we
    // declare an instance of a class, that should be in relation to MainWindow, we
    // can declare MainWindow as a parent.
    : QMainWindow(parent) // base class, we have to declare it
    , ui(new Ui::MainWindow) // in order to benefit from the functionalities of Ui
    // namespace with MainWindow, we declare a pointer that points to a member of Ui::MainWindow
{
    ui->setupUi(this);
    // sets up all the UI components (widgets, layouts, connections) defined in Qt Designer
    // within the current MainWindow instance.

    ui->graphicsView->setScene(&scene); // die Szene vom GUI-ELement graphicsView wird zu scene
    scene.setBackgroundBrush(Qt::white);

    ui->checkBox->setChecked(false);

    if (ui->checkBox->isChecked())
    {
        ui->label->show();
        ui->lineEdit->show();
        ui->pushButton->show();
        ui->testDrawCities->show();
        ui->testDrawMapWithCities->show();
        ui->testDrawStreets->show();
        ui->testDrawMapWithStreets->show();
        ui->testRejectStreet->show();
        ui->testAbstractMap->show();
        ui->testDijkstraAlgorithm->show();
    }
    else
    {
        ui->label->hide();
        ui->lineEdit->hide();
        ui->pushButton->hide();
        ui->testDrawCities->hide();
        ui->testDrawMapWithCities->hide();
        ui->testDrawStreets->hide();
        ui->testDrawMapWithStreets->hide();
        ui->testRejectStreet->hide();
        ui->testAbstractMap->hide();
        ui->testDijkstraAlgorithm->hide();
    }

    mapio = new MapIoNrw();

}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
* @brief Slot, der ausgeloest wird, wenn der Knopf pushButton geklickt wird.
*
* Liest die Eingabe aus dem lineEdit-Widget und ueberprueft, ob sie eine Ganzzahl ist.
* Wenn die Eingabe eine Ganzzahl ist, erhoeht sie den Wert um 4.
* Fuegt ein Rechteck zu der Szene an einer zufaelligen Position hinzu.
 */
void MainWindow::on_pushButton_clicked()
{
    qDebug() << "Button was pushed.";

    int x = QRandomGenerator::global()->bounded(10); // eine zufällige Zahl zwischen 0-9
    int y = QRandomGenerator::global()->bounded(10);

    // ein Rechteck hinzufuegen
    scene.addRect(x * 10, y * 10, 50, 50);
    qDebug() << "A 50X50 rectangle is added to the position (" << x*10 << ", " << y*10 << ").";

    // Einlesen der Eingabe für lineEdit
    QString input = ui->lineEdit->text(); // lineEdit ist der Name des GUI-Elements

    // der Benutzer gibt keine Eingabe ein
    if (input.isEmpty())
    {
        QString text = "No input is entered.";

        // Ausgeben des Texts auf der Konsole und dem Bildschirm
        qDebug() << text; // text wird auf der Konsole mit "" angezeigt

        // Ausgeben des Texts auf dem Bildschirm als ein Message Box
        QMessageBox msgBox;
        msgBox.setText(text);
        msgBox.exec();
        return;
    }
    QString text = QString("The input:  %1").arg(input);

    qDebug() << text;
    QMessageBox msgBox;
    msgBox.setText(text);

    QString text2; // fuer informativeText

    bool ok;
    int number = input.toInt(&ok); // ueberprueft, ob eingabe eine Ganzzahl ist
    // wenn ja, wird die Zeichenkette zu einer Ganzzahl umgewandelt
    if (ok)
    {
        int increasedNumber = number + 4;

        text2 = QString("The input is an integer.\nIncreased by 4: %1").arg(increasedNumber);
        qDebug() << text2;
    }
    else
    {
        text2 = "The input is not an integer.";
        qDebug() << text2;
    }

    msgBox.setInformativeText(text2);
    msgBox.setStandardButtons(QMessageBox::Ok); // mit "Ok" beschrifteter Knopf
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.exec();
}

/**
 * @brief Slot, der ausgeloest wird, wenn die Aktion 'Beenden' aktiviert wird.
 *
 * Schliesst das Hauptfenster und beendet das Programm (durch File->Exit oder Alt+E).
 */
void MainWindow::on_actionExit_triggered()
{
    close(); // beendet das Programm
}

/**
* @brief Slot, der ausgeloest wird, wenn die Aktion 'Szene loeschen' aktiviert wird.
*
* Loescht alle Elemente aus der QGraphicsScene (durch Scene->Clear Scene oder Alt+S).
*/
void MainWindow::on_actionClear_Scene_triggered()
{
    scene.clear(); //
}

/**
 * @brief Slot, der ausgeloest wird, wenn die Aktion 'Ueber' aktiviert wird.
 *
 * Zeigt einen Message Box mit Informationen über das Programm an (durch Info->About).
 */
void MainWindow::on_actionAbout_triggered()
{
    QString aboutText ="Eine UI-App fuer das Projekt 'Streetplanner'.";
    QMessageBox::about(this, "About", aboutText); // about ist eine Funktion von QMessageBox
    // erzeugt einen Message Box mit dem Titel "About" und dem Text aboutText.
}

/**
 * @brief Slot, der ausgeloest wird, wenn der Knopf testDrawCities geklickt wird.
 *
 * Erzeugt zwei City Objekte und testet die draw-Funktion von City.
 */
void MainWindow::on_testDrawCities_clicked()
{
    City* c1 = new City("City1", 20, 50);
    City* c2 = new City("City2", 100, 200);

    c1->draw(scene);
    c2->draw(scene);
}

/**
 * @brief Slot, der ausgeloest wird, wenn der Knopf testDrawMapWithCities geklickt wird.
 *
 * Erzeugt zwei City Objekte und testet die addCity- und draw-Funktionen von Map.
 */
void MainWindow::on_testDrawMapWithCities_clicked()
{
    Map testMap;
    City* c3 = new City("City3", 40, 100);
    City* c4 = new City("City4", 200, 100);

    testMap.addCity(c3);
    testMap.addCity(c4);
    testMap.draw(scene);
}

/**
 * @brief Slot, der ausgeloest wird, wenn der Knopf testDrawStreets geklickt wird.
 *
 * Erzeugt zwei City Objekte, ein Street Objekt und testet die draw-Funktion von Street.
 */
void MainWindow::on_testDrawStreets_clicked()
{
    City* c1 = new City("City1", 20, 50);
    City* c2 = new City("City2", 100, 200);
    City* c3 = new City("City3", 40, 100);
    City* c4 = new City("City4", 200, 100);

    Street* s1 = new Street("Street1", c1, c2);
    Street* s2 = new Street("Street2", c3, c4);

    s1->draw(scene);
    s2->draw(scene);
}

/**
 * @brief Slot, der ausgeloest wird, wenn der Knopf testDrawMapWithStreets geklickt wird.
 *
 * Erzeugt vier City Objekte, zwei Street Objekte und testet die addCity-, addStreet-
 * und draw-Funktionen von Map. (Die Strassen sollen hinzugefuegt werden koennen.)
 */
void MainWindow::on_testDrawMapWithStreets_clicked()
{
    Map testMap;
    City* c5 = new City("City5", 80, 200);
    City* c6 = new City("City6", 40, 30);
    City* c7 = new City("City7", 80, 100);
    City* c8 = new City("City8", 140, 70);
    Street* s3 = new Street("Street3",c5, c6);
    Street* s4 = new Street("Street4",c7, c8);

    testMap.addCity(c5);
    testMap.addCity(c6);
    testMap.addCity(c7);
    testMap.addCity(c8);
    if (!(testMap.addStreet(s3)))
    {
        qDebug() << "Street " << s3->getName() << " cannot be added.";
    }
    if (!(testMap.addStreet(s4)))
    {
        qDebug() << "Street " << s4->getName() << " cannot be added.";
    }

    testMap.draw(scene);
}


/**
 * @brief Slot, der ausgeloest wird, wenn der Knopf testRejectStreet geklickt wird.
 *
 * Erzeugt zwei City Objekte, ein Street Objekt und testet die addCity-, addStreet-
 * und draw-Funktionen von Map. (Die Strasse soll hinzugefuegt werden koennen.)
 */
void MainWindow::on_testRejectStreet_clicked()
{
    Map testMap;
    City* c9 = new City("City9", 50, 50);
    City* c10 = new City("City10", 130, 240);
    Street* s5 = new Street("Street5",c9, c10);
    testMap.addCity(c9);


    if (!(testMap.addStreet(s5)))
    {
        qDebug() << "Street " << s5->getName() << " cannot be added.";
    }

    testMap.draw(scene);
}


/**
 * @brief Slot, der ausgeloest wird, wenn das Kaestchen checkBox geklickt wird
 *
 * Bestimmte UI-Elemente werden ein- oder auszublenden, abhängig davon, ob das
 * Kontrollkaestchen aktiviert ist oder nicht.
 */
void MainWindow::on_checkBox_clicked()
{
    if (ui->checkBox->isChecked())
    {
        ui->label->show();
        ui->lineEdit->show();
        ui->pushButton->show();
        ui->testDrawCities->show();
        ui->testDrawMapWithCities->show();
        ui->testDrawStreets->show();
        ui->testDrawMapWithStreets->show();
        ui->testRejectStreet->show();
        ui->testAbstractMap->show();
        ui->testDijkstraAlgorithm->show();
    }
    else
    {
        ui->label->hide();
        ui->lineEdit->hide();
        ui->pushButton->hide();
        ui->testDrawCities->hide();
        ui->testDrawMapWithCities->hide();
        ui->testDrawStreets->hide();
        ui->testDrawMapWithStreets->hide();
        ui->testRejectStreet->hide();
        ui->testAbstractMap->hide();
        ui->testDijkstraAlgorithm->hide();
    }

}


/**
 * @brief Slot, der ausgeloest wird, wenn der Knopf addCity geklickt wird
 *
 * Ein Dialogfenster wird geöffnet, um Benutzereingaben für eine neue Stadt zu erfassen.
 * Die Funktion createCity wird ausgefuehrt und wenn die vom Benutzer angegebene Stadt
 * gueltig ist, wird sie zum system hinzugefuegt und in der Karte gezeichnet.
 */
void MainWindow::on_addCity_clicked()
{
    // Erstellen eines Objekts der Klasse Dialog
    Dialog dialog(this);
    // Dialog ausfuehren und den Rueckgabewert speichern
    int result = dialog.exec();
    if (result == QDialog::Accepted) // 1 ("Ok" wurde geklickt)
    {
        // Erstellen einer Stadt mit angegebenen Daten
        City* city = dialog.createCity();
        if (city == nullptr) return;
        // Zeichnen der Stadt
        if (map.addCity(city))
        {
          city->draw(scene);
        }
        qDebug() << "Dialog was accepted";
    }
    else if (result == QDialog::Rejected) // 0 ("Cancel" wurde geklickt)
    {
        qDebug() << "Dialog was rejected or canceled";
    }
}



/**
 * @brief Slot, der ausgeloest wird, wenn der Knopf addStreet geklickt wird
 *
 * Ein Dialogfenster wird geöffnet, um Benutzereingaben für eine neue Strasse zu erfassen.
 * Die Funktion createCitiesVector wird ausgefuehrt und wenn die gegebene Stadt gueltig
 * ist, wird eine Strasse, die sie verbindet, wird hinzugefuegt und in der Karte gezeichnet.
 */
void MainWindow::on_addStreet_clicked()
{
    QMessageBox msgBox;
    QString text;
    // Erstellen eines Objekts der Klasse StreetDialog
    StreetDialog dialog(this);
    // Dialog ausfuehren und den Rueckgabewert speichern
    int result = dialog.exec();

    if (result == QDialog::Accepted)
    {
        QVector<QString*> names = dialog.createCitiesVector();
        if (names.empty()) return; // leere kaestchen / gleiche Stadt zweimal eingegeben

        QString city1Name = *(names[0]);
        QString city2Name = *(names[1]);

        City* city1 = map.findCity(city1Name);
        // Wenn die Stadt gefunden werden kann, gibt die Funktion die Stadt zurueck
        // keine Ausgabe in der Konsole
        // Wenn nicht, wird eine Ausgabe in der Konsole gegeben, aber keinen Message Box
        // deswegen muessen wir ihn hier hinzufuegen
        if (city1 == nullptr)
        {
            text = "The city with the given name doesn't exist in the system.";
            msgBox.setText(text);
            msgBox.exec();
            return;
        }
        City* city2 = map.findCity(city2Name);
        if (city2 == nullptr)
        {
            text = "The city with the given name doesn't exist in the system.";
            msgBox.setText(text);
            msgBox.exec();
            return;
        }

        Street* street = new Street("", city1, city2);

        // Zeichnen der Strasse
        // addStreet handelt die Faelle:
        // Wenn die Strasse bereits existiert, wenn die Staedte nicht im Vektor vorhanden sind
        if (map.addStreet(street))
        {
            street->draw(scene);
        }
        qDebug() << "Dialog was accepted";
    }
    else if (result == QDialog::Rejected)
    {
        qDebug() << "Dialog was rejected or canceled";
    }
}


/**
 * @brief Slot, der ausgeloest wird, wenn der Knopf fillMap geklickt wird
 *
 * Fuegt City und Street Objekte dem System hinzu und zeichnet die in der Karte.
 */
void MainWindow::on_fillMap_clicked()
{
    mapio->fillMap(map);
    map.draw(scene);
}

/**
 * @brief Slot, der ausgeloest wird, wenn der Knopf testAbstractMap geklickt wird
 *
 * Erzeugt Objekte von City und Street. Ueberprueft die folgenden Funktionen von Map:
 * addStreet, findCity, getOppositeCity, getLength, getStreetList.
 * addCity und findStreet werden spaeter hinzugefuegt.
 */
void MainWindow::on_testAbstractMap_clicked()
{
    Map testMap;
    City *a = new City("a", 0, 0);
    City *b = new City("b", 0, 100);
    City *c = new City("c", 100, 300);
    Street *s = new Street("s1", a, b);
    Street *s2 = new Street("s2", b, c);


    qDebug() << "MapTest: Start Test of the Map";
    {
        qDebug() << "MapTest: adding wrong street";
        bool t1 = testMap.addStreet(s);
        if (t1) {
            qDebug() << "-Error: Street should not be added, if cities have not been added.";
        }
    }

    {
        qDebug() << "MapTest: adding correct street";
        testMap.addCity(a);
        testMap.addCity(b);
        bool t1 = testMap.addStreet(s);
        if (!t1) {
            qDebug() << "-Error: It should be possible to add this street.";
        }
    }

    {
        qDebug() << "MapTest: findCity";
        City* city = testMap.findCity("a");
        if (city != a)
            qDebug() << "-Error: City a could not be found.";

        city = testMap.findCity("b");
        if (city != b)
            qDebug() << "-Error: City b could not be found.";

        city = testMap.findCity("c");
        if (city != nullptr)
            qDebug() << "-Error: If city could not be found, 0 should be returned.";
    }


    testMap.addCity(c);
    testMap.addStreet(s2);

    {
        qDebug() << "MapTest: getOppositeCity";
        const City *city = testMap.getOppositeCity(s, a);
        if (city != b)
            qDebug() << "-Error: Opposite city should be b.";

        city = testMap.getOppositeCity(s, c);
        if (city != nullptr)
            qDebug() << "-Error: Opposite city for a city which is not linked by given street should be 0.";
    }

    {
        qDebug() << "MapTest: streetLength";
        double l = testMap.getLength(s2);
        double expectedLength = 223.6;
        // compare doubles with 5% tolerance
        if (l < expectedLength * 0.95 || l > expectedLength *1.05)
            qDebug() << "-Error: Street Length is not equal to the expected.";

    }

    {
        qDebug() << "MapTest: getStreetList";
        QVector<Street*> streetList1 = testMap.getStreetList(a);
        QVector<Street*> streetList2 = testMap.getStreetList(b);
        if (streetList1.size() != 1) {
            qDebug() << "-Error: One street should be found for city a.";
        }
        else if (*streetList1.begin() != s) {
            qDebug() << "-Error: The wrong street has been found for city a.";
        }

        if (streetList2.size() != 2)
            qDebug() << "-Error: Two streets should be found for city b.";
    }

    qDebug() << "MapTest: End Test of the Map.";
}


/**
 * @brief Slot, der ausgeloest wird, wenn der Knopf testDijkstraAlgorithm geklickt wird
 *
 * Testet die Funktion für das Dijkstra-Algorithmus auf zwei Staedte.
 */
void MainWindow::on_testDijkstraAlgorithm_clicked()
{
    Map testMap;

    City* c11 = new City("City11", 0, 0);
    City* c12 = new City("City12", 35, 20);
    City* c13 = new City("City13", 60, 50);
    City* c14 = new City("City14", 100, 200);
    City* c15 = new City("City15", 50, 60);
    Street* s6 = new Street("Street6", c11, c12);
    Street* s7 = new Street("Street7", c12, c13);
    Street* s8 = new Street("Street8", c13, c15);
    Street* s9 = new Street("Street9", c11, c14);
    Street* s10 = new Street("Street10", c14, c15);
    testMap.addCity(c11);
    testMap.addCity(c12);
    testMap.addCity(c13);
    testMap.addCity(c14);
    testMap.addCity(c15);
    testMap.addStreet(s6);
    testMap.addStreet(s7);
    testMap.addStreet(s8);
    testMap.addStreet(s9);
    testMap.addStreet(s10);

    testMap.draw(scene);

    QVector<Street*> shortestPath = Dijkstra::search(testMap, c11->getName(), c15->getName());

    qDebug() << "The streets that form the shortest path in order: ";
    for (Street* street: shortestPath)
    {
        qDebug() <<  "The street " << street->getName() << " between " <<
            street->getCity1()->getName() << " and " << street->getCity2()->getName();
        street->drawRed(scene);
    }
}




