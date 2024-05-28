/********************************************************************************
** Form generated from reading UI file 'addGRPGM.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDGRPGM_H
#define UI_ADDGRPGM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addGRPGM
{
public:
    QTableView *tableViewGRPGM;
    QLineEdit *lineEdit;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *addGRPGM)
    {
        if (addGRPGM->objectName().isEmpty())
            addGRPGM->setObjectName("addGRPGM");
        addGRPGM->resize(500, 300);
        tableViewGRPGM = new QTableView(addGRPGM);
        tableViewGRPGM->setObjectName("tableViewGRPGM");
        tableViewGRPGM->setGeometry(QRect(10, 11, 481, 241));
        tableViewGRPGM->verticalHeader()->setVisible(false);
        lineEdit = new QLineEdit(addGRPGM);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(10, 260, 41, 24));
        layoutWidget = new QWidget(addGRPGM);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(50, 260, 444, 38));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName("label");
        label->setPixmap(QPixmap(QString::fromUtf8("../../qt/warning.svg")));
        label->setScaledContents(true);

        horizontalLayout->addWidget(label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(400, 0));
        label_2->setMaximumSize(QSize(400, 16777215));
        QFont font;
        font.setPointSize(11);
        label_2->setFont(font);

        horizontalLayout->addWidget(label_2);


        retranslateUi(addGRPGM);

        QMetaObject::connectSlotsByName(addGRPGM);
    } // setupUi

    void retranslateUi(QWidget *addGRPGM)
    {
        addGRPGM->setWindowTitle(QCoreApplication::translate("addGRPGM", "Form", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("addGRPGM", "Double click on groupe module to add it to the groupe", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addGRPGM: public Ui_addGRPGM {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDGRPGM_H
