/********************************************************************************
** Form generated from reading UI file 'addGRP.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDGRP_H
#define UI_ADDGRP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addGroupe
{
public:
    QGroupBox *idgm_2;
    QLineEdit *idgm;
    QGroupBox *niveau_2;
    QComboBox *niveau;
    QPushButton *cancelGRPButton;
    QLabel *title;
    QGroupBox *gm;
    QPushButton *addGRPGM;
    QGroupBox *diplome_2;
    QComboBox *diplome;
    QGroupBox *specialite_2;
    QComboBox *specialite;
    QGroupBox *numg_2;
    QComboBox *numg;
    QGroupBox *std;
    QPushButton *addGRPETU;
    QTableView *tableViewUpdateGRP;
    QPushButton *modifyGRPButton;
    QPushButton *clearGRPButton;

    void setupUi(QWidget *addGroupe)
    {
        if (addGroupe->objectName().isEmpty())
            addGroupe->setObjectName("addGroupe");
        addGroupe->resize(700, 500);
        idgm_2 = new QGroupBox(addGroupe);
        idgm_2->setObjectName("idgm_2");
        idgm_2->setGeometry(QRect(390, 160, 261, 51));
        QFont font;
        font.setPointSize(12);
        idgm_2->setFont(font);
        idgm_2->setStyleSheet(QString::fromUtf8("QGroupBox { border: 0; }"));
        idgm = new QLineEdit(idgm_2);
        idgm->setObjectName("idgm");
        idgm->setGeometry(QRect(0, 20, 261, 24));
        idgm->setStyleSheet(QString::fromUtf8("border-radius: 7px;\n"
"border: 1px solid #555555;"));
        niveau_2 = new QGroupBox(addGroupe);
        niveau_2->setObjectName("niveau_2");
        niveau_2->setGeometry(QRect(390, 220, 121, 51));
        QFont font1;
        font1.setPointSize(12);
        font1.setItalic(true);
        niveau_2->setFont(font1);
        niveau_2->setStyleSheet(QString::fromUtf8("QGroupBox { border: 0; }"));
        niveau = new QComboBox(niveau_2);
        niveau->addItem(QString());
        niveau->addItem(QString());
        niveau->addItem(QString());
        niveau->setObjectName("niveau");
        niveau->setGeometry(QRect(0, 20, 121, 24));
        niveau->setStyleSheet(QString::fromUtf8("border-radius: 7px;\n"
"border: 1px solid #555555;"));
        cancelGRPButton = new QPushButton(addGroupe);
        cancelGRPButton->setObjectName("cancelGRPButton");
        cancelGRPButton->setGeometry(QRect(290, 460, 80, 24));
        cancelGRPButton->setStyleSheet(QString::fromUtf8("border-radius: 7px;\n"
"border: 1px solid #555555;"));
        title = new QLabel(addGroupe);
        title->setObjectName("title");
        title->setGeometry(QRect(180, 30, 261, 51));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Candara")});
        font2.setPointSize(36);
        font2.setBold(true);
        title->setFont(font2);
        title->setStyleSheet(QString::fromUtf8("QLabel{color: rgb(198, 0, 0);}"));
        gm = new QGroupBox(addGroupe);
        gm->setObjectName("gm");
        gm->setGeometry(QRect(530, 280, 121, 51));
        gm->setFont(font1);
        gm->setStyleSheet(QString::fromUtf8("QGroupBox { border: 0; }"));
        addGRPGM = new QPushButton(gm);
        addGRPGM->setObjectName("addGRPGM");
        addGRPGM->setGeometry(QRect(0, 20, 121, 24));
        addGRPGM->setStyleSheet(QString::fromUtf8("border-radius: 7px;\n"
"border: 1px solid #555555;"));
        diplome_2 = new QGroupBox(addGroupe);
        diplome_2->setObjectName("diplome_2");
        diplome_2->setGeometry(QRect(390, 280, 121, 51));
        diplome_2->setFont(font1);
        diplome_2->setStyleSheet(QString::fromUtf8("QGroupBox { border: 0; }"));
        diplome = new QComboBox(diplome_2);
        diplome->addItem(QString());
        diplome->addItem(QString());
        diplome->addItem(QString());
        diplome->setObjectName("diplome");
        diplome->setGeometry(QRect(0, 20, 121, 24));
        diplome->setStyleSheet(QString::fromUtf8("border-radius: 7px;\n"
"border: 1px solid #555555;"));
        specialite_2 = new QGroupBox(addGroupe);
        specialite_2->setObjectName("specialite_2");
        specialite_2->setGeometry(QRect(390, 340, 121, 51));
        specialite_2->setFont(font1);
        specialite_2->setStyleSheet(QString::fromUtf8("QGroupBox { border: 0; }"));
        specialite = new QComboBox(specialite_2);
        specialite->addItem(QString());
        specialite->addItem(QString());
        specialite->addItem(QString());
        specialite->setObjectName("specialite");
        specialite->setGeometry(QRect(0, 20, 121, 24));
        specialite->setStyleSheet(QString::fromUtf8("border-radius: 7px;\n"
"border: 1px solid #555555;"));
        numg_2 = new QGroupBox(addGroupe);
        numg_2->setObjectName("numg_2");
        numg_2->setGeometry(QRect(530, 220, 121, 51));
        numg_2->setFont(font1);
        numg_2->setStyleSheet(QString::fromUtf8("QGroupBox { border: 0; }"));
        numg = new QComboBox(numg_2);
        numg->addItem(QString());
        numg->addItem(QString());
        numg->addItem(QString());
        numg->setObjectName("numg");
        numg->setGeometry(QRect(0, 20, 121, 24));
        numg->setStyleSheet(QString::fromUtf8("border-radius: 7px;\n"
"border: 1px solid #555555;"));
        std = new QGroupBox(addGroupe);
        std->setObjectName("std");
        std->setGeometry(QRect(530, 340, 121, 51));
        std->setFont(font1);
        std->setStyleSheet(QString::fromUtf8("QGroupBox { border: 0; }"));
        addGRPETU = new QPushButton(std);
        addGRPETU->setObjectName("addGRPETU");
        addGRPETU->setGeometry(QRect(0, 20, 121, 24));
        addGRPETU->setStyleSheet(QString::fromUtf8("border-radius: 7px;\n"
"border: 1px solid #555555;"));
        tableViewUpdateGRP = new QTableView(addGroupe);
        tableViewUpdateGRP->setObjectName("tableViewUpdateGRP");
        tableViewUpdateGRP->setGeometry(QRect(10, 90, 361, 351));
        tableViewUpdateGRP->verticalHeader()->setVisible(false);
        modifyGRPButton = new QPushButton(addGroupe);
        modifyGRPButton->setObjectName("modifyGRPButton");
        modifyGRPButton->setGeometry(QRect(390, 460, 80, 24));
        modifyGRPButton->setStyleSheet(QString::fromUtf8("border-radius: 7px;\n"
"border: 1px solid #555555;"));
        clearGRPButton = new QPushButton(addGroupe);
        clearGRPButton->setObjectName("clearGRPButton");
        clearGRPButton->setGeometry(QRect(480, 460, 80, 24));
        clearGRPButton->setStyleSheet(QString::fromUtf8("border-radius: 7px;\n"
"border: 1px solid #555555;"));

        retranslateUi(addGroupe);

        QMetaObject::connectSlotsByName(addGroupe);
    } // setupUi

    void retranslateUi(QWidget *addGroupe)
    {
        addGroupe->setWindowTitle(QCoreApplication::translate("addGroupe", "Form", nullptr));
        idgm_2->setTitle(QCoreApplication::translate("addGroupe", "Id Groupe :", nullptr));
        niveau_2->setTitle(QCoreApplication::translate("addGroupe", "Niveau :", nullptr));
        niveau->setItemText(0, QCoreApplication::translate("addGroupe", "1er", nullptr));
        niveau->setItemText(1, QCoreApplication::translate("addGroupe", "2eme", nullptr));
        niveau->setItemText(2, QCoreApplication::translate("addGroupe", "3eme", nullptr));

        cancelGRPButton->setText(QCoreApplication::translate("addGroupe", "Continue", nullptr));
        title->setText(QCoreApplication::translate("addGroupe", "Add Groupe", nullptr));
        gm->setTitle(QCoreApplication::translate("addGroupe", "Groupe Module  :", nullptr));
        addGRPGM->setText(QCoreApplication::translate("addGroupe", "Include Groupe M", nullptr));
        diplome_2->setTitle(QCoreApplication::translate("addGroupe", "Dipl\303\264me :", nullptr));
        diplome->setItemText(0, QCoreApplication::translate("addGroupe", "ING", nullptr));
        diplome->setItemText(1, QCoreApplication::translate("addGroupe", "Master", nullptr));
        diplome->setItemText(2, QCoreApplication::translate("addGroupe", "LMD", nullptr));

        specialite_2->setTitle(QCoreApplication::translate("addGroupe", "Sp\303\251cialit\303\251 :", nullptr));
        specialite->setItemText(0, QCoreApplication::translate("addGroupe", "INF", nullptr));
        specialite->setItemText(1, QCoreApplication::translate("addGroupe", "INDUS", nullptr));
        specialite->setItemText(2, QCoreApplication::translate("addGroupe", "MATH", nullptr));

        numg_2->setTitle(QCoreApplication::translate("addGroupe", "Num\303\251ro Groupe :", nullptr));
        numg->setItemText(0, QCoreApplication::translate("addGroupe", "1", nullptr));
        numg->setItemText(1, QCoreApplication::translate("addGroupe", "2", nullptr));
        numg->setItemText(2, QCoreApplication::translate("addGroupe", "3", nullptr));

        std->setTitle(QCoreApplication::translate("addGroupe", "Student  :", nullptr));
        addGRPETU->setText(QCoreApplication::translate("addGroupe", "Include Student", nullptr));
        modifyGRPButton->setText(QCoreApplication::translate("addGroupe", "Modify", nullptr));
        clearGRPButton->setText(QCoreApplication::translate("addGroupe", "Clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addGroupe: public Ui_addGroupe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDGRP_H
