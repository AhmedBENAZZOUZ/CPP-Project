/********************************************************************************
** Form generated from reading UI file 'modifyNote.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFYNOTE_H
#define UI_MODIFYNOTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_modifyNote
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *updateNoteButton;
    QPushButton *deleteNoteButton;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *clearNoteButton;
    QPushButton *cancelNoteButton;
    QLabel *title;
    QTableView *tableUpdateNote;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLineEdit *etu;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QLineEdit *mat;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;
    QLineEdit *type;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_4;
    QDoubleSpinBox *note;

    void setupUi(QWidget *modifyNote)
    {
        if (modifyNote->objectName().isEmpty())
            modifyNote->setObjectName("modifyNote");
        modifyNote->resize(700, 500);
        layoutWidget = new QWidget(modifyNote);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(480, 340, 170, 60));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        updateNoteButton = new QPushButton(layoutWidget);
        updateNoteButton->setObjectName("updateNoteButton");

        horizontalLayout->addWidget(updateNoteButton);

        deleteNoteButton = new QPushButton(layoutWidget);
        deleteNoteButton->setObjectName("deleteNoteButton");

        horizontalLayout->addWidget(deleteNoteButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        clearNoteButton = new QPushButton(layoutWidget);
        clearNoteButton->setObjectName("clearNoteButton");

        horizontalLayout_2->addWidget(clearNoteButton);

        cancelNoteButton = new QPushButton(layoutWidget);
        cancelNoteButton->setObjectName("cancelNoteButton");

        horizontalLayout_2->addWidget(cancelNoteButton);


        verticalLayout->addLayout(horizontalLayout_2);

        title = new QLabel(modifyNote);
        title->setObjectName("title");
        title->setGeometry(QRect(160, 10, 291, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("Candara")});
        font.setPointSize(32);
        font.setBold(true);
        title->setFont(font);
        title->setStyleSheet(QString::fromUtf8("QLabel{color: rgb(198, 0, 0);}"));
        tableUpdateNote = new QTableView(modifyNote);
        tableUpdateNote->setObjectName("tableUpdateNote");
        tableUpdateNote->setGeometry(QRect(10, 80, 410, 400));
        tableUpdateNote->verticalHeader()->setVisible(false);
        layoutWidget1 = new QWidget(modifyNote);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(430, 180, 230, 109));
        verticalLayout_6 = new QVBoxLayout(layoutWidget1);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label = new QLabel(layoutWidget1);
        label->setObjectName("label");

        verticalLayout_2->addWidget(label);

        etu = new QLineEdit(layoutWidget1);
        etu->setObjectName("etu");
        etu->setEnabled(false);

        verticalLayout_2->addWidget(etu);


        horizontalLayout_3->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName("label_2");

        verticalLayout_3->addWidget(label_2);

        mat = new QLineEdit(layoutWidget1);
        mat->setObjectName("mat");
        mat->setEnabled(false);
        mat->setMinimumSize(QSize(100, 0));

        verticalLayout_3->addWidget(mat);


        horizontalLayout_3->addLayout(verticalLayout_3);


        verticalLayout_6->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName("label_3");

        verticalLayout_4->addWidget(label_3);

        type = new QLineEdit(layoutWidget1);
        type->setObjectName("type");
        type->setEnabled(false);

        verticalLayout_4->addWidget(type);


        horizontalLayout_4->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName("label_4");

        verticalLayout_5->addWidget(label_4);

        note = new QDoubleSpinBox(layoutWidget1);
        note->setObjectName("note");
        note->setMinimumSize(QSize(110, 0));

        verticalLayout_5->addWidget(note);


        horizontalLayout_4->addLayout(verticalLayout_5);


        verticalLayout_6->addLayout(horizontalLayout_4);


        retranslateUi(modifyNote);

        QMetaObject::connectSlotsByName(modifyNote);
    } // setupUi

    void retranslateUi(QWidget *modifyNote)
    {
        modifyNote->setWindowTitle(QCoreApplication::translate("modifyNote", "Form", nullptr));
        updateNoteButton->setText(QCoreApplication::translate("modifyNote", "Update", nullptr));
        deleteNoteButton->setText(QCoreApplication::translate("modifyNote", "Delete", nullptr));
        clearNoteButton->setText(QCoreApplication::translate("modifyNote", "Clear", nullptr));
        cancelNoteButton->setText(QCoreApplication::translate("modifyNote", "Cancel", nullptr));
        title->setText(QCoreApplication::translate("modifyNote", "Modify Note", nullptr));
        label->setText(QCoreApplication::translate("modifyNote", "Id Student :", nullptr));
        label_2->setText(QCoreApplication::translate("modifyNote", "Id Matiere :", nullptr));
        label_3->setText(QCoreApplication::translate("modifyNote", "Type :", nullptr));
        label_4->setText(QCoreApplication::translate("modifyNote", "Note :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class modifyNote: public Ui_modifyNote {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFYNOTE_H
