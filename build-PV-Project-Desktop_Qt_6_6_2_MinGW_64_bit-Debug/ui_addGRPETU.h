/********************************************************************************
** Form generated from reading UI file 'addGRPETU.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDGRPETU_H
#define UI_ADDGRPETU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addGRPETU
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QTableView *tableViewGRPETU;

    void setupUi(QWidget *addGRPETU)
    {
        if (addGRPETU->objectName().isEmpty())
            addGRPETU->setObjectName("addGRPETU");
        addGRPETU->resize(500, 300);
        layoutWidget = new QWidget(addGRPETU);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(50, 259, 444, 38));
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

        lineEdit = new QLineEdit(addGRPETU);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(10, 259, 41, 24));
        tableViewGRPETU = new QTableView(addGRPETU);
        tableViewGRPETU->setObjectName("tableViewGRPETU");
        tableViewGRPETU->setGeometry(QRect(10, 10, 481, 241));
        tableViewGRPETU->verticalHeader()->setVisible(false);

        retranslateUi(addGRPETU);

        QMetaObject::connectSlotsByName(addGRPETU);
    } // setupUi

    void retranslateUi(QWidget *addGRPETU)
    {
        addGRPETU->setWindowTitle(QCoreApplication::translate("addGRPETU", "Form", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("addGRPETU", "Double click on student to add it to the groupe", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addGRPETU: public Ui_addGRPETU {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDGRPETU_H
