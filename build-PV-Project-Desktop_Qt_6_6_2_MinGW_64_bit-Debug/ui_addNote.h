/********************************************************************************
** Form generated from reading UI file 'addNote.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDNOTE_H
#define UI_ADDNOTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addNote
{
public:
    QPushButton *addNoteButton;
    QLabel *title;
    QPushButton *cancelNoteButton;
    QComboBox *groupeNote;
    QComboBox *GMNote;
    QComboBox *MatNote;
    QComboBox *EtuNote;
    QComboBox *TypeNote;
    QGroupBox *note_2;
    QDoubleSpinBox *note;

    void setupUi(QWidget *addNote)
    {
        if (addNote->objectName().isEmpty())
            addNote->setObjectName("addNote");
        addNote->resize(700, 500);
        addNoteButton = new QPushButton(addNote);
        addNoteButton->setObjectName("addNoteButton");
        addNoteButton->setGeometry(QRect(250, 430, 80, 24));
        addNoteButton->setStyleSheet(QString::fromUtf8("border-radius: 7px;\n"
"border: 1px solid #555555;"));
        title = new QLabel(addNote);
        title->setObjectName("title");
        title->setGeometry(QRect(230, 40, 211, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("Candara")});
        font.setPointSize(38);
        font.setBold(true);
        title->setFont(font);
        title->setStyleSheet(QString::fromUtf8("QLabel{color: rgb(198, 0, 0);}"));
        cancelNoteButton = new QPushButton(addNote);
        cancelNoteButton->setObjectName("cancelNoteButton");
        cancelNoteButton->setGeometry(QRect(360, 430, 80, 24));
        cancelNoteButton->setStyleSheet(QString::fromUtf8("border-radius: 7px;\n"
"border: 1px solid #555555;"));
        groupeNote = new QComboBox(addNote);
        groupeNote->setObjectName("groupeNote");
        groupeNote->setGeometry(QRect(170, 120, 331, 24));
        GMNote = new QComboBox(addNote);
        GMNote->setObjectName("GMNote");
        GMNote->setGeometry(QRect(170, 220, 331, 24));
        MatNote = new QComboBox(addNote);
        MatNote->setObjectName("MatNote");
        MatNote->setGeometry(QRect(170, 270, 331, 24));
        EtuNote = new QComboBox(addNote);
        EtuNote->setObjectName("EtuNote");
        EtuNote->setGeometry(QRect(170, 170, 331, 24));
        EtuNote->setStyleSheet(QString::fromUtf8(""));
        TypeNote = new QComboBox(addNote);
        TypeNote->addItem(QString());
        TypeNote->addItem(QString());
        TypeNote->addItem(QString());
        TypeNote->addItem(QString());
        TypeNote->setObjectName("TypeNote");
        TypeNote->setGeometry(QRect(170, 320, 331, 24));
        note_2 = new QGroupBox(addNote);
        note_2->setObjectName("note_2");
        note_2->setGeometry(QRect(170, 350, 331, 51));
        QFont font1;
        font1.setPointSize(12);
        font1.setItalic(true);
        note_2->setFont(font1);
        note_2->setStyleSheet(QString::fromUtf8("QGroupBox { border: 0; }"));
        note = new QDoubleSpinBox(note_2);
        note->setObjectName("note");
        note->setGeometry(QRect(0, 20, 331, 25));
        note->setMaximum(20.000000000000000);
        note->setSingleStep(0.250000000000000);

        retranslateUi(addNote);

        QMetaObject::connectSlotsByName(addNote);
    } // setupUi

    void retranslateUi(QWidget *addNote)
    {
        addNote->setWindowTitle(QCoreApplication::translate("addNote", "Form", nullptr));
        addNoteButton->setText(QCoreApplication::translate("addNote", "Add Note", nullptr));
        title->setText(QCoreApplication::translate("addNote", "Add Note", nullptr));
        cancelNoteButton->setText(QCoreApplication::translate("addNote", "Cancel", nullptr));
        TypeNote->setItemText(0, QCoreApplication::translate("addNote", "Select Type", nullptr));
        TypeNote->setItemText(1, QCoreApplication::translate("addNote", "DS", nullptr));
        TypeNote->setItemText(2, QCoreApplication::translate("addNote", "TP", nullptr));
        TypeNote->setItemText(3, QCoreApplication::translate("addNote", "EXAMEN", nullptr));

        note_2->setTitle(QCoreApplication::translate("addNote", "Enter Note  :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addNote: public Ui_addNote {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDNOTE_H
