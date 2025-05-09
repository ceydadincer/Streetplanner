/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QFormLayout *formLayout;
    QLineEdit *lineEditName;
    QLabel *label_2;
    QLineEdit *lineEditX;
    QLabel *label_3;
    QLineEdit *lineEditY;
    QDialogButtonBox *buttonBox;
    QLabel *label;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(272, 221);
        formLayout = new QFormLayout(Dialog);
        formLayout->setObjectName("formLayout");
        lineEditName = new QLineEdit(Dialog);
        lineEditName->setObjectName("lineEditName");

        formLayout->setWidget(1, QFormLayout::SpanningRole, lineEditName);

        label_2 = new QLabel(Dialog);
        label_2->setObjectName("label_2");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        lineEditX = new QLineEdit(Dialog);
        lineEditX->setObjectName("lineEditX");

        formLayout->setWidget(3, QFormLayout::SpanningRole, lineEditX);

        label_3 = new QLabel(Dialog);
        label_3->setObjectName("label_3");

        formLayout->setWidget(4, QFormLayout::LabelRole, label_3);

        lineEditY = new QLineEdit(Dialog);
        lineEditY->setObjectName("lineEditY");

        formLayout->setWidget(5, QFormLayout::SpanningRole, lineEditY);

        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout->setWidget(6, QFormLayout::FieldRole, buttonBox);

        label = new QLabel(Dialog);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);


        retranslateUi(Dialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, Dialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, Dialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Add City", nullptr));
#if QT_CONFIG(tooltip)
        lineEditName->setToolTip(QCoreApplication::translate("Dialog", "the name of the city.", nullptr));
#endif // QT_CONFIG(tooltip)
        lineEditName->setText(QString());
        lineEditName->setPlaceholderText(QCoreApplication::translate("Dialog", "Accepted: A-Z / a-z / - / \\n", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", "x-Coordinate:", nullptr));
#if QT_CONFIG(tooltip)
        lineEditX->setToolTip(QCoreApplication::translate("Dialog", "the x-coordinate of the city.", nullptr));
#endif // QT_CONFIG(tooltip)
        lineEditX->setText(QString());
        lineEditX->setPlaceholderText(QCoreApplication::translate("Dialog", "Accepted: Integers", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog", "y-Coordinate:", nullptr));
#if QT_CONFIG(tooltip)
        lineEditY->setToolTip(QCoreApplication::translate("Dialog", "The y-coordinate of the city.", nullptr));
#endif // QT_CONFIG(tooltip)
        lineEditY->setText(QString());
        lineEditY->setPlaceholderText(QCoreApplication::translate("Dialog", "Accepted: Integers", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "Name:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
