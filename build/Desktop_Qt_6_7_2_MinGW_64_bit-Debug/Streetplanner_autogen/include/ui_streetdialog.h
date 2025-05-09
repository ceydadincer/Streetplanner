/********************************************************************************
** Form generated from reading UI file 'streetdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STREETDIALOG_H
#define UI_STREETDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_StreetDialog
{
public:
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEditCity1;
    QLineEdit *lineEditCity2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *StreetDialog)
    {
        if (StreetDialog->objectName().isEmpty())
            StreetDialog->setObjectName("StreetDialog");
        StreetDialog->resize(272, 221);
        formLayout = new QFormLayout(StreetDialog);
        formLayout->setObjectName("formLayout");
        label = new QLabel(StreetDialog);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(StreetDialog);
        label_2->setObjectName("label_2");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        lineEditCity1 = new QLineEdit(StreetDialog);
        lineEditCity1->setObjectName("lineEditCity1");

        formLayout->setWidget(1, QFormLayout::SpanningRole, lineEditCity1);

        lineEditCity2 = new QLineEdit(StreetDialog);
        lineEditCity2->setObjectName("lineEditCity2");

        formLayout->setWidget(3, QFormLayout::SpanningRole, lineEditCity2);

        buttonBox = new QDialogButtonBox(StreetDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout->setWidget(4, QFormLayout::FieldRole, buttonBox);


        retranslateUi(StreetDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, StreetDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, StreetDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(StreetDialog);
    } // setupUi

    void retranslateUi(QDialog *StreetDialog)
    {
        StreetDialog->setWindowTitle(QCoreApplication::translate("StreetDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("StreetDialog", "City 1:", nullptr));
        label_2->setText(QCoreApplication::translate("StreetDialog", "City 2:", nullptr));
        lineEditCity1->setPlaceholderText(QCoreApplication::translate("StreetDialog", "Accepted: A-Z / a-z / - / \\n", nullptr));
        lineEditCity2->setPlaceholderText(QCoreApplication::translate("StreetDialog", "Accepted: A-Z / a-z / - / \\n", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StreetDialog: public Ui_StreetDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STREETDIALOG_H
