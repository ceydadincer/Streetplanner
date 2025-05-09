/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionExit;
    QAction *actionClear_Scene;
    QAction *actionAbout;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *testDrawMapWithStreets;
    QGraphicsView *graphicsView;
    QCheckBox *checkBox;
    QLabel *label;
    QPushButton *testAbstractMap;
    QPushButton *pushButton;
    QPushButton *testDrawCities;
    QPushButton *testDijkstraAlgorithm;
    QPushButton *fillMap;
    QPushButton *addCity;
    QPushButton *testRejectStreet;
    QPushButton *testDrawMapWithCities;
    QPushButton *testDrawStreets;
    QSpacerItem *verticalSpacer;
    QLineEdit *lineEdit;
    QPushButton *addStreet;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuSave;
    QMenu *menuScene;
    QMenu *menuInfo;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(600, 450);
        MainWindow->setMinimumSize(QSize(600, 450));
        MainWindow->setAutoFillBackground(true);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName("actionOpen");
        actionOpen->setEnabled(false);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName("actionExit");
        actionClear_Scene = new QAction(MainWindow);
        actionClear_Scene->setObjectName("actionClear_Scene");
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName("actionAbout");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        testDrawMapWithStreets = new QPushButton(centralwidget);
        testDrawMapWithStreets->setObjectName("testDrawMapWithStreets");

        gridLayout->addWidget(testDrawMapWithStreets, 6, 0, 1, 1);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setAutoFillBackground(false);

        gridLayout->addWidget(graphicsView, 0, 1, 16, 1);

        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName("checkBox");
        checkBox->setChecked(false);

        gridLayout->addWidget(checkBox, 10, 0, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        testAbstractMap = new QPushButton(centralwidget);
        testAbstractMap->setObjectName("testAbstractMap");

        gridLayout->addWidget(testAbstractMap, 8, 0, 1, 1);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");

        gridLayout->addWidget(pushButton, 2, 0, 1, 1);

        testDrawCities = new QPushButton(centralwidget);
        testDrawCities->setObjectName("testDrawCities");

        gridLayout->addWidget(testDrawCities, 3, 0, 1, 1);

        testDijkstraAlgorithm = new QPushButton(centralwidget);
        testDijkstraAlgorithm->setObjectName("testDijkstraAlgorithm");

        gridLayout->addWidget(testDijkstraAlgorithm, 9, 0, 1, 1);

        fillMap = new QPushButton(centralwidget);
        fillMap->setObjectName("fillMap");

        gridLayout->addWidget(fillMap, 13, 0, 1, 1);

        addCity = new QPushButton(centralwidget);
        addCity->setObjectName("addCity");

        gridLayout->addWidget(addCity, 11, 0, 1, 1);

        testRejectStreet = new QPushButton(centralwidget);
        testRejectStreet->setObjectName("testRejectStreet");

        gridLayout->addWidget(testRejectStreet, 7, 0, 1, 1);

        testDrawMapWithCities = new QPushButton(centralwidget);
        testDrawMapWithCities->setObjectName("testDrawMapWithCities");

        gridLayout->addWidget(testDrawMapWithCities, 4, 0, 1, 1);

        testDrawStreets = new QPushButton(centralwidget);
        testDrawStreets->setObjectName("testDrawStreets");

        gridLayout->addWidget(testDrawStreets, 5, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 15, 0, 1, 1);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setClearButtonEnabled(true);

        gridLayout->addWidget(lineEdit, 1, 0, 1, 1);

        addStreet = new QPushButton(centralwidget);
        addStreet->setObjectName("addStreet");

        gridLayout->addWidget(addStreet, 12, 0, 1, 1);

        gridLayout->setColumnStretch(1, 1);
        MainWindow->setCentralWidget(centralwidget);
        pushButton->raise();
        testDrawCities->raise();
        label->raise();
        lineEdit->raise();
        testDrawMapWithCities->raise();
        testDrawStreets->raise();
        testDrawMapWithStreets->raise();
        checkBox->raise();
        addCity->raise();
        fillMap->raise();
        testAbstractMap->raise();
        graphicsView->raise();
        testRejectStreet->raise();
        testDijkstraAlgorithm->raise();
        addStreet->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 600, 17));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuSave = new QMenu(menuFile);
        menuSave->setObjectName("menuSave");
        menuSave->setEnabled(true);
        menuScene = new QMenu(menubar);
        menuScene->setObjectName("menuScene");
        menuInfo = new QMenu(menubar);
        menuInfo->setObjectName("menuInfo");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuScene->menuAction());
        menubar->addAction(menuInfo->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(actionOpen);
        menuFile->addAction(menuSave->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuScene->addAction(actionClear_Scene);
        menuInfo->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
#if QT_CONFIG(shortcut)
        actionExit->setShortcut(QCoreApplication::translate("MainWindow", "Alt+E", nullptr));
#endif // QT_CONFIG(shortcut)
        actionClear_Scene->setText(QCoreApplication::translate("MainWindow", "Clear Scene", nullptr));
#if QT_CONFIG(shortcut)
        actionClear_Scene->setShortcut(QCoreApplication::translate("MainWindow", "Alt+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
#if QT_CONFIG(tooltip)
        testDrawMapWithStreets->setToolTip(QCoreApplication::translate("MainWindow", "Adds cities and streets to the system and draws them on the map.", nullptr));
#endif // QT_CONFIG(tooltip)
        testDrawMapWithStreets->setText(QCoreApplication::translate("MainWindow", "Test Map Street", nullptr));
#if QT_CONFIG(tooltip)
        graphicsView->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        checkBox->setToolTip(QCoreApplication::translate("MainWindow", "Shows the test buttons.", nullptr));
#endif // QT_CONFIG(tooltip)
        checkBox->setText(QCoreApplication::translate("MainWindow", "Show the test buttons", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Your input:", nullptr));
#if QT_CONFIG(tooltip)
        testAbstractMap->setToolTip(QCoreApplication::translate("MainWindow", "Tests various function of the class \"Map\".", nullptr));
#endif // QT_CONFIG(tooltip)
        testAbstractMap->setText(QCoreApplication::translate("MainWindow", "Test Abstract Map", nullptr));
#if QT_CONFIG(tooltip)
        pushButton->setToolTip(QCoreApplication::translate("MainWindow", "Tests, if the input is an integer or a string.", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton->setText(QCoreApplication::translate("MainWindow", "Test", nullptr));
#if QT_CONFIG(tooltip)
        testDrawCities->setToolTip(QCoreApplication::translate("MainWindow", "Draws two cities on the map.", nullptr));
#endif // QT_CONFIG(tooltip)
        testDrawCities->setText(QCoreApplication::translate("MainWindow", "Test Draw City", nullptr));
#if QT_CONFIG(tooltip)
        testDijkstraAlgorithm->setToolTip(QCoreApplication::translate("MainWindow", "Tests the Dijkstra-Algorithm on two cities.", nullptr));
#endif // QT_CONFIG(tooltip)
        testDijkstraAlgorithm->setText(QCoreApplication::translate("MainWindow", "Test Dijkstra-Algorithm", nullptr));
#if QT_CONFIG(tooltip)
        fillMap->setToolTip(QCoreApplication::translate("MainWindow", "Fills the map with cities and streets.", nullptr));
#endif // QT_CONFIG(tooltip)
        fillMap->setText(QCoreApplication::translate("MainWindow", "Fill Map", nullptr));
#if QT_CONFIG(tooltip)
        addCity->setToolTip(QCoreApplication::translate("MainWindow", "Adds a city with the given data.", nullptr));
#endif // QT_CONFIG(tooltip)
        addCity->setText(QCoreApplication::translate("MainWindow", "Add City", nullptr));
#if QT_CONFIG(tooltip)
        testRejectStreet->setToolTip(QCoreApplication::translate("MainWindow", "Adds a city and tries to add a street to the system but fails.", nullptr));
#endif // QT_CONFIG(tooltip)
        testRejectStreet->setText(QCoreApplication::translate("MainWindow", "Test Map Street (Reject)", nullptr));
#if QT_CONFIG(tooltip)
        testDrawMapWithCities->setToolTip(QCoreApplication::translate("MainWindow", "Adds two cities to the system and draws them on the map.", nullptr));
#endif // QT_CONFIG(tooltip)
        testDrawMapWithCities->setText(QCoreApplication::translate("MainWindow", "Test Map City", nullptr));
#if QT_CONFIG(tooltip)
        testDrawStreets->setToolTip(QCoreApplication::translate("MainWindow", "Draws a street on the map.", nullptr));
#endif // QT_CONFIG(tooltip)
        testDrawStreets->setText(QCoreApplication::translate("MainWindow", "Test Draw Street", nullptr));
#if QT_CONFIG(tooltip)
        lineEdit->setToolTip(QCoreApplication::translate("MainWindow", "Enter input", nullptr));
#endif // QT_CONFIG(tooltip)
        lineEdit->setText(QString());
        lineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Input: ", nullptr));
#if QT_CONFIG(tooltip)
        addStreet->setToolTip(QCoreApplication::translate("MainWindow", "Adds a street between the given cities.", nullptr));
#endif // QT_CONFIG(tooltip)
        addStreet->setText(QCoreApplication::translate("MainWindow", "Add Street", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuSave->setTitle(QCoreApplication::translate("MainWindow", "Save", nullptr));
        menuScene->setTitle(QCoreApplication::translate("MainWindow", "Scene", nullptr));
        menuInfo->setTitle(QCoreApplication::translate("MainWindow", "Info", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
