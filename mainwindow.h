#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "map.h"

class MapIo;

QT_BEGIN_NAMESPACE

namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
private:
    Q_OBJECT
    // enables Qt's meta-object system for the class. This allows the use of signals and slots
    // for communication between objects, dynamic properties for objects, and facilitates
    // Qt's translation mechanism.
    Ui::MainWindow *ui; ///< eine Instanz von Ui::MainWindow, um auf die GUI-Elemente zuzugriffen (ui->...).
    QGraphicsScene scene; ///< eine Instanz von QGraphicsScene, um grafische Elemente zu verwalten und darzustellen
    Map map; ///< eine Instanz von Map, um die Karte auf der Szene zu verwalten
    MapIo* mapio; ///< eine Instanz von MapIo, um die Karte zu fuellen

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_clicked();
    void on_actionExit_triggered();
    void on_actionClear_Scene_triggered();
    void on_actionAbout_triggered();
    void on_testDrawCities_clicked();
    void on_testDrawMapWithCities_clicked();
    void on_testDrawStreets_clicked();
    void on_testDrawMapWithStreets_clicked();
    void on_testRejectStreet_clicked();
    void on_checkBox_clicked();
    void on_addCity_clicked();
    void on_addStreet_clicked();
    void on_fillMap_clicked();
    void on_testAbstractMap_clicked();
    void on_testDijkstraAlgorithm_clicked();
};
#endif // MAINWINDOW_H
