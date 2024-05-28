/********************************************************************************
** Form generated from reading UI file 'addGM.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDGM_H
#define UI_ADDGM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addGM
{
public:
    QPushButton *cancelGMButton;
    QLabel *label;
    QDoubleSpinBox *coef;
    QLabel *title;
    QGroupBox *idgm_2;
    QLineEdit *idgm;
    QGroupBox *mat;
    QPushButton *addMatGM;
    QGroupBox *name_2;
    QLineEdit *name;
    QPushButton *modifyGMButton;
    QPushButton *clearGMButton;
    QTableView *tableViewGM;

    void setupUi(QWidget *addGM)
    {
        if (addGM->objectName().isEmpty())
            addGM->setObjectName("addGM");
        addGM->resize(700, 500);
        cancelGMButton = new QPushButton(addGM);
        cancelGMButton->setObjectName("cancelGMButton");
        cancelGMButton->setGeometry(QRect(340, 440, 80, 24));
        cancelGMButton->setStyleSheet(QString::fromUtf8("border-radius: 7px;\n"
"border: 1px solid #555555;"));
        label = new QLabel(addGM);
        label->setObjectName("label");
        label->setGeometry(QRect(450, 270, 101, 21));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        coef = new QDoubleSpinBox(addGM);
        coef->setObjectName("coef");
        coef->setGeometry(QRect(560, 270, 62, 25));
        coef->setFont(font);
        coef->setStyleSheet(QString::fromUtf8("border-radius: 7px;\n"
"border: 1px solid #555555;"));
        coef->setDecimals(1);
        coef->setMinimum(1.000000000000000);
        coef->setMaximum(20.000000000000000);
        coef->setSingleStep(0.500000000000000);
        title = new QLabel(addGM);
        title->setObjectName("title");
        title->setGeometry(QRect(200, 20, 261, 51));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Candara")});
        font1.setPointSize(22);
        font1.setBold(true);
        title->setFont(font1);
        title->setStyleSheet(QString::fromUtf8("QLabel{color: rgb(198, 0, 0);}"));
        idgm_2 = new QGroupBox(addGM);
        idgm_2->setObjectName("idgm_2");
        idgm_2->setGeometry(QRect(440, 140, 201, 51));
        idgm_2->setFont(font);
        idgm_2->setStyleSheet(QString::fromUtf8("QGroupBox { border: 0; }"));
        idgm = new QLineEdit(idgm_2);
        idgm->setObjectName("idgm");
        idgm->setGeometry(QRect(0, 20, 201, 24));
        idgm->setStyleSheet(QString::fromUtf8("border-radius: 7px;\n"
"border: 1px solid #555555;"));
        mat = new QGroupBox(addGM);
        mat->setObjectName("mat");
        mat->setGeometry(QRect(440, 310, 201, 51));
        QFont font2;
        font2.setPointSize(12);
        font2.setItalic(true);
        mat->setFont(font2);
        mat->setStyleSheet(QString::fromUtf8("QGroupBox { border: 0; }"));
        addMatGM = new QPushButton(mat);
        addMatGM->setObjectName("addMatGM");
        addMatGM->setGeometry(QRect(0, 20, 201, 24));
        name_2 = new QGroupBox(addGM);
        name_2->setObjectName("name_2");
        name_2->setGeometry(QRect(440, 200, 201, 51));
        name_2->setFont(font2);
        name_2->setStyleSheet(QString::fromUtf8("QGroupBox { border: 0; }"));
        name = new QLineEdit(name_2);
        name->setObjectName("name");
        name->setGeometry(QRect(0, 20, 201, 24));
        name->setStyleSheet(QString::fromUtf8("border-radius: 7px;\n"
"border: 1px solid #555555;"));
        modifyGMButton = new QPushButton(addGM);
        modifyGMButton->setObjectName("modifyGMButton");
        modifyGMButton->setGeometry(QRect(450, 440, 80, 24));
        modifyGMButton->setStyleSheet(QString::fromUtf8("border-radius: 7px;\n"
"border: 1px solid #555555;"));
        clearGMButton = new QPushButton(addGM);
        clearGMButton->setObjectName("clearGMButton");
        clearGMButton->setGeometry(QRect(540, 440, 80, 24));
        clearGMButton->setStyleSheet(QString::fromUtf8("border-radius: 7px;\n"
"border: 1px solid #555555;"));
        tableViewGM = new QTableView(addGM);
        tableViewGM->setObjectName("tableViewGM");
        tableViewGM->setGeometry(QRect(20, 90, 371, 321));
        tableViewGM->verticalHeader()->setVisible(false);

        retranslateUi(addGM);

        QMetaObject::connectSlotsByName(addGM);
    } // setupUi

    void retranslateUi(QWidget *addGM)
    {
        addGM->setWindowTitle(QCoreApplication::translate("addGM", "Form", nullptr));
        cancelGMButton->setText(QCoreApplication::translate("addGM", "Continue", nullptr));
        label->setText(QCoreApplication::translate("addGM", "Coefficient   :", nullptr));
        title->setText(QCoreApplication::translate("addGM", "Add Groupe Module", nullptr));
        idgm_2->setTitle(QCoreApplication::translate("addGM", "Id Matiere :", nullptr));
        mat->setTitle(QCoreApplication::translate("addGM", "Teacher  :", nullptr));
        addMatGM->setText(QCoreApplication::translate("addGM", "Include Matiere", nullptr));
        name_2->setTitle(QCoreApplication::translate("addGM", "Name :", nullptr));
        modifyGMButton->setText(QCoreApplication::translate("addGM", "Modify", nullptr));
        clearGMButton->setText(QCoreApplication::translate("addGM", "Clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addGM: public Ui_addGM {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDGM_H
