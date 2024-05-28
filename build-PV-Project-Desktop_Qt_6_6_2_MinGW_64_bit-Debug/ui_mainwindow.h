/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *Welcome;
    QLabel *title;
    QLabel *logoPi;
    QPushButton *welcomeButton;
    QWidget *Menu;
    QPushButton *student;
    QPushButton *teacher;
    QPushButton *matiere;
    QPushButton *gm;
    QPushButton *groupe;
    QPushButton *note;
    QPushButton *pv;
    QWidget *Std_mgt;
    QPushButton *addStudent;
    QLineEdit *searchBar;
    QPushButton *returnBack;
    QPushButton *modifyStudent;
    QTableView *tableWidget;
    QWidget *TeacherMgt;
    QPushButton *addTeacher;
    QPushButton *modifyTeacher;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *returnBackProf;
    QLabel *label_2;
    QLineEdit *searchBarTeacher;
    QTableView *tableWidgetTeacher;
    QWidget *matMgt;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QPushButton *returnBackMat;
    QLabel *label;
    QLineEdit *searchBarMat;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *addMat;
    QPushButton *modifyMat;
    QTableView *tableViewMat;
    QWidget *GM_mgt;
    QWidget *layoutWidget_7;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *addGM;
    QPushButton *modifyGM;
    QTableView *tableViewGM;
    QWidget *layoutWidget_6;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *returnBackGM;
    QLabel *label_6;
    QLineEdit *searchBarGM;
    QLineEdit *lineEdit;
    QWidget *GRP_mgt;
    QTableView *tableViewGRP;
    QWidget *layoutWidget_8;
    QHBoxLayout *horizontalLayout_12;
    QPushButton *returnBackGRP;
    QLabel *label_8;
    QLineEdit *searchBarGRP;
    QWidget *layoutWidget_9;
    QHBoxLayout *horizontalLayout_13;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *addGRP;
    QPushButton *modifyGRP;
    QTableView *tableViewGRPGM;
    QTableView *tableViewGRPETU;
    QPushButton *deleteGRPGM;
    QPushButton *deleteGRPETU;
    QLineEdit *lineDeleteGM;
    QLineEdit *lineDeleteETU;
    QLineEdit *lineDeleteGRP;
    QLineEdit *lineDeleteGM_2;
    QLineEdit *lineDeleteETU_2;
    QWidget *Note_mgt;
    QWidget *layoutWidget_10;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *returnBackNote;
    QLabel *label_7;
    QLineEdit *searchBarNote;
    QWidget *layoutWidget_11;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *addNote;
    QPushButton *modifyNote;
    QTableView *tableViewNote;
    QWidget *PV;
    QTableView *MoyMat;
    QPushButton *returnBackPV;
    QTableView *MoyGM;
    QTableView *MoyG;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 0, 800, 600));
        Welcome = new QWidget();
        Welcome->setObjectName("Welcome");
        title = new QLabel(Welcome);
        title->setObjectName("title");
        title->setGeometry(QRect(70, 180, 670, 70));
        QFont font;
        font.setFamilies({QString::fromUtf8("Candara")});
        font.setPointSize(42);
        font.setBold(true);
        title->setFont(font);
        title->setStyleSheet(QString::fromUtf8("QLabel{\n"
"rgb(255, 0, 0)\n"
"}"));
        logoPi = new QLabel(Welcome);
        logoPi->setObjectName("logoPi");
        logoPi->setGeometry(QRect(260, 40, 250, 70));
        logoPi->setPixmap(QPixmap(QString::fromUtf8("../../qt/pilogo.png")));
        logoPi->setScaledContents(true);
        welcomeButton = new QPushButton(Welcome);
        welcomeButton->setObjectName("welcomeButton");
        welcomeButton->setGeometry(QRect(320, 340, 150, 40));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Terminal")});
        font1.setPointSize(14);
        font1.setBold(true);
        welcomeButton->setFont(font1);
        welcomeButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius: 7px;\n"
"border: 1px solid #555555;\n"
"}\n"
"QPushButton:hover { color: white; background-color: red; }"));
        stackedWidget->addWidget(Welcome);
        Menu = new QWidget();
        Menu->setObjectName("Menu");
        student = new QPushButton(Menu);
        student->setObjectName("student");
        student->setGeometry(QRect(90, 120, 171, 61));
        QFont font2;
        font2.setPointSize(12);
        student->setFont(font2);
        student->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius: 7px;\n"
"border: 1px solid #555555;\n"
"}"));
        student->setIconSize(QSize(24, 24));
        teacher = new QPushButton(Menu);
        teacher->setObjectName("teacher");
        teacher->setGeometry(QRect(490, 120, 171, 61));
        teacher->setFont(font2);
        teacher->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius: 7px;\n"
"border: 1px solid #555555;\n"
"}"));
        teacher->setIconSize(QSize(24, 24));
        matiere = new QPushButton(Menu);
        matiere->setObjectName("matiere");
        matiere->setGeometry(QRect(90, 240, 171, 61));
        matiere->setFont(font2);
        matiere->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius: 7px;\n"
"border: 1px solid #555555;\n"
"}"));
        matiere->setIconSize(QSize(24, 24));
        gm = new QPushButton(Menu);
        gm->setObjectName("gm");
        gm->setGeometry(QRect(490, 240, 171, 61));
        gm->setFont(font2);
        gm->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius: 7px;\n"
"border: 1px solid #555555;\n"
"}"));
        gm->setIconSize(QSize(24, 24));
        groupe = new QPushButton(Menu);
        groupe->setObjectName("groupe");
        groupe->setGeometry(QRect(90, 340, 171, 61));
        groupe->setFont(font2);
        groupe->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius: 7px;\n"
"border: 1px solid #555555;\n"
"}"));
        groupe->setIconSize(QSize(24, 24));
        note = new QPushButton(Menu);
        note->setObjectName("note");
        note->setGeometry(QRect(490, 340, 171, 61));
        note->setFont(font2);
        note->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius: 7px;\n"
"border: 1px solid #555555;\n"
"}"));
        note->setIconSize(QSize(24, 24));
        pv = new QPushButton(Menu);
        pv->setObjectName("pv");
        pv->setGeometry(QRect(290, 430, 171, 61));
        pv->setFont(font2);
        pv->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius: 7px;\n"
"border: 1px solid #555555;\n"
"}"));
        pv->setIconSize(QSize(24, 24));
        stackedWidget->addWidget(Menu);
        Std_mgt = new QWidget();
        Std_mgt->setObjectName("Std_mgt");
        addStudent = new QPushButton(Std_mgt);
        addStudent->setObjectName("addStudent");
        addStudent->setGeometry(QRect(520, 530, 120, 30));
        addStudent->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius: 7px;\n"
"border: 1px solid #555555;\n"
"}"));
        searchBar = new QLineEdit(Std_mgt);
        searchBar->setObjectName("searchBar");
        searchBar->setGeometry(QRect(580, 10, 210, 24));
        searchBar->setStyleSheet(QString::fromUtf8("QLineEdit { padding-left: 20px; background-image: url(D:/Pi/CPP/qt/search.svg); background-position: left center; background-repeat: no-repeat; \n"
"border-radius: 7px;\n"
"border: 1px solid #555555;\n"
"}"));
        returnBack = new QPushButton(Std_mgt);
        returnBack->setObjectName("returnBack");
        returnBack->setGeometry(QRect(10, 10, 40, 24));
        returnBack->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius: 7px;\n"
"border: 1px solid #555555;\n"
"}"));
        returnBack->setIconSize(QSize(20, 20));
        modifyStudent = new QPushButton(Std_mgt);
        modifyStudent->setObjectName("modifyStudent");
        modifyStudent->setGeometry(QRect(649, 530, 141, 30));
        modifyStudent->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius: 7px;\n"
"border: 1px solid #555555;\n"
"}"));
        tableWidget = new QTableView(Std_mgt);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(10, 60, 780, 460));
        tableWidget->verticalHeader()->setVisible(false);
        stackedWidget->addWidget(Std_mgt);
        TeacherMgt = new QWidget();
        TeacherMgt->setObjectName("TeacherMgt");
        addTeacher = new QPushButton(TeacherMgt);
        addTeacher->setObjectName("addTeacher");
        addTeacher->setGeometry(QRect(520, 530, 120, 30));
        addTeacher->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius: 7px;\n"
"border: 1px solid #555555;\n"
"}"));
        modifyTeacher = new QPushButton(TeacherMgt);
        modifyTeacher->setObjectName("modifyTeacher");
        modifyTeacher->setGeometry(QRect(649, 530, 141, 30));
        modifyTeacher->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius: 7px;\n"
"border: 1px solid #555555;\n"
"}"));
        layoutWidget = new QWidget(TeacherMgt);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 10, 784, 26));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        returnBackProf = new QPushButton(layoutWidget);
        returnBackProf->setObjectName("returnBackProf");
        returnBackProf->setMinimumSize(QSize(40, 24));
        returnBackProf->setMaximumSize(QSize(40, 24));
        returnBackProf->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border-radius: 10px;\n"
"border: 1px solid #555555;\n"
"}"));

        horizontalLayout_3->addWidget(returnBackProf);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(520, 0));

        horizontalLayout_3->addWidget(label_2);

        searchBarTeacher = new QLineEdit(layoutWidget);
        searchBarTeacher->setObjectName("searchBarTeacher");
        searchBarTeacher->setMinimumSize(QSize(210, 24));
        searchBarTeacher->setMaximumSize(QSize(210, 24));
        searchBarTeacher->setStyleSheet(QString::fromUtf8("QLineEdit { padding-left: 20px; background-image: url(D:/Pi/CPP/qt/search.svg); background-position: left center; background-repeat: no-repeat; border-radius:10px;border: 1px solid #555555;}"));

        horizontalLayout_3->addWidget(searchBarTeacher);

        tableWidgetTeacher = new QTableView(TeacherMgt);
        tableWidgetTeacher->setObjectName("tableWidgetTeacher");
        tableWidgetTeacher->setGeometry(QRect(10, 60, 780, 460));
        tableWidgetTeacher->verticalHeader()->setVisible(false);
        stackedWidget->addWidget(TeacherMgt);
        matMgt = new QWidget();
        matMgt->setObjectName("matMgt");
        layoutWidget1 = new QWidget(matMgt);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(10, 10, 784, 26));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        returnBackMat = new QPushButton(layoutWidget1);
        returnBackMat->setObjectName("returnBackMat");
        returnBackMat->setMinimumSize(QSize(40, 24));
        returnBackMat->setMaximumSize(QSize(40, 24));
        returnBackMat->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border-radius: 7px;\n"
"border: 1px solid #555555;\n"
"}"));
        returnBackMat->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(returnBackMat);

        label = new QLabel(layoutWidget1);
        label->setObjectName("label");
        label->setMinimumSize(QSize(520, 0));

        horizontalLayout->addWidget(label);

        searchBarMat = new QLineEdit(layoutWidget1);
        searchBarMat->setObjectName("searchBarMat");
        searchBarMat->setMinimumSize(QSize(210, 24));
        searchBarMat->setMaximumSize(QSize(210, 24));
        searchBarMat->setStyleSheet(QString::fromUtf8("QLineEdit { \n"
"padding-left: 20px;\n"
"background-image: url(D:/Pi/CPP/qt/search.svg);\n"
"background-position: left center;\n"
"background-repeat: no-repeat;\n"
"/*background-size: 10px 10px;*/\n"
"border-radius: 7px;\n"
"border: 1px solid #555555;\n"
"}"));

        horizontalLayout->addWidget(searchBarMat);

        layoutWidget2 = new QWidget(matMgt);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(20, 530, 771, 32));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        addMat = new QPushButton(layoutWidget2);
        addMat->setObjectName("addMat");
        addMat->setMinimumSize(QSize(120, 30));
        addMat->setMaximumSize(QSize(120, 30));
        addMat->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border-radius: 7px;\n"
"border: 1px solid #555555;\n"
"}"));

        horizontalLayout_2->addWidget(addMat);

        modifyMat = new QPushButton(layoutWidget2);
        modifyMat->setObjectName("modifyMat");
        modifyMat->setMinimumSize(QSize(140, 30));
        modifyMat->setMaximumSize(QSize(140, 30));
        modifyMat->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border-radius: 7px;\n"
"border: 1px solid #555555;\n"
"}"));

        horizontalLayout_2->addWidget(modifyMat);

        tableViewMat = new QTableView(matMgt);
        tableViewMat->setObjectName("tableViewMat");
        tableViewMat->setGeometry(QRect(10, 50, 780, 460));
        tableViewMat->setStyleSheet(QString::fromUtf8(""));
        tableViewMat->verticalHeader()->setVisible(false);
        stackedWidget->addWidget(matMgt);
        GM_mgt = new QWidget();
        GM_mgt->setObjectName("GM_mgt");
        layoutWidget_7 = new QWidget(GM_mgt);
        layoutWidget_7->setObjectName("layoutWidget_7");
        layoutWidget_7->setGeometry(QRect(20, 530, 771, 32));
        horizontalLayout_9 = new QHBoxLayout(layoutWidget_7);
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_3);

        addGM = new QPushButton(layoutWidget_7);
        addGM->setObjectName("addGM");
        addGM->setMinimumSize(QSize(150, 30));
        addGM->setMaximumSize(QSize(150, 30));
        addGM->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border-radius: 7px;\n"
"border: 1px solid #555555;\n"
"}"));

        horizontalLayout_9->addWidget(addGM);

        modifyGM = new QPushButton(layoutWidget_7);
        modifyGM->setObjectName("modifyGM");
        modifyGM->setMinimumSize(QSize(180, 30));
        modifyGM->setMaximumSize(QSize(180, 30));
        modifyGM->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border-radius: 7px;\n"
"border: 1px solid #555555;\n"
"}\n"
"QPushButton:hover { color: black; background-color: red; }"));

        horizontalLayout_9->addWidget(modifyGM);

        tableViewGM = new QTableView(GM_mgt);
        tableViewGM->setObjectName("tableViewGM");
        tableViewGM->setGeometry(QRect(10, 50, 780, 460));
        tableViewGM->setStyleSheet(QString::fromUtf8(""));
        tableViewGM->verticalHeader()->setVisible(false);
        layoutWidget_6 = new QWidget(GM_mgt);
        layoutWidget_6->setObjectName("layoutWidget_6");
        layoutWidget_6->setGeometry(QRect(10, 10, 784, 26));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget_6);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        returnBackGM = new QPushButton(layoutWidget_6);
        returnBackGM->setObjectName("returnBackGM");
        returnBackGM->setMinimumSize(QSize(40, 24));
        returnBackGM->setMaximumSize(QSize(40, 24));
        returnBackGM->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border-radius: 7px;\n"
"border: 1px solid #555555;\n"
"}"));
        returnBackGM->setIconSize(QSize(20, 20));

        horizontalLayout_8->addWidget(returnBackGM);

        label_6 = new QLabel(layoutWidget_6);
        label_6->setObjectName("label_6");
        label_6->setMinimumSize(QSize(520, 0));

        horizontalLayout_8->addWidget(label_6);

        searchBarGM = new QLineEdit(layoutWidget_6);
        searchBarGM->setObjectName("searchBarGM");
        searchBarGM->setMinimumSize(QSize(210, 24));
        searchBarGM->setMaximumSize(QSize(210, 24));
        searchBarGM->setStyleSheet(QString::fromUtf8("QLineEdit { \n"
"padding-left: 20px;\n"
"background-image: url(D:/Pi/CPP/qt/search.svg);\n"
"background-position: left center;\n"
"background-repeat: no-repeat;\n"
"/*background-size: 10px 10px;*/\n"
"border-radius: 7px;\n"
"border: 1px solid #555555;\n"
"}"));

        horizontalLayout_8->addWidget(searchBarGM);

        lineEdit = new QLineEdit(GM_mgt);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(190, 510, 61, 24));
        stackedWidget->addWidget(GM_mgt);
        GRP_mgt = new QWidget();
        GRP_mgt->setObjectName("GRP_mgt");
        tableViewGRP = new QTableView(GRP_mgt);
        tableViewGRP->setObjectName("tableViewGRP");
        tableViewGRP->setGeometry(QRect(10, 320, 780, 210));
        tableViewGRP->setStyleSheet(QString::fromUtf8(""));
        tableViewGRP->verticalHeader()->setVisible(false);
        layoutWidget_8 = new QWidget(GRP_mgt);
        layoutWidget_8->setObjectName("layoutWidget_8");
        layoutWidget_8->setGeometry(QRect(10, 10, 784, 26));
        horizontalLayout_12 = new QHBoxLayout(layoutWidget_8);
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        returnBackGRP = new QPushButton(layoutWidget_8);
        returnBackGRP->setObjectName("returnBackGRP");
        returnBackGRP->setMinimumSize(QSize(40, 24));
        returnBackGRP->setMaximumSize(QSize(40, 24));
        returnBackGRP->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border-radius: 7px;\n"
"border: 1px solid #555555;\n"
"}"));
        returnBackGRP->setIconSize(QSize(20, 20));

        horizontalLayout_12->addWidget(returnBackGRP);

        label_8 = new QLabel(layoutWidget_8);
        label_8->setObjectName("label_8");
        label_8->setMinimumSize(QSize(520, 0));

        horizontalLayout_12->addWidget(label_8);

        searchBarGRP = new QLineEdit(layoutWidget_8);
        searchBarGRP->setObjectName("searchBarGRP");
        searchBarGRP->setMinimumSize(QSize(210, 24));
        searchBarGRP->setMaximumSize(QSize(210, 24));
        searchBarGRP->setStyleSheet(QString::fromUtf8("QLineEdit { \n"
"padding-left: 20px;\n"
"background-image: url(D:/Pi/CPP/qt/search.svg);\n"
"background-position: left center;\n"
"background-repeat: no-repeat;\n"
"/*background-size: 10px 10px;*/\n"
"border-radius: 7px;\n"
"border: 1px solid #555555;\n"
"}"));

        horizontalLayout_12->addWidget(searchBarGRP);

        layoutWidget_9 = new QWidget(GRP_mgt);
        layoutWidget_9->setObjectName("layoutWidget_9");
        layoutWidget_9->setGeometry(QRect(20, 540, 771, 32));
        horizontalLayout_13 = new QHBoxLayout(layoutWidget_9);
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        horizontalLayout_13->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_5);

        addGRP = new QPushButton(layoutWidget_9);
        addGRP->setObjectName("addGRP");
        addGRP->setMinimumSize(QSize(150, 30));
        addGRP->setMaximumSize(QSize(150, 30));
        addGRP->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border-radius: 7px;\n"
"border: 1px solid #555555;\n"
"}"));

        horizontalLayout_13->addWidget(addGRP);

        modifyGRP = new QPushButton(layoutWidget_9);
        modifyGRP->setObjectName("modifyGRP");
        modifyGRP->setMinimumSize(QSize(180, 30));
        modifyGRP->setMaximumSize(QSize(180, 30));
        modifyGRP->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border-radius: 7px;\n"
"border: 1px solid #555555;\n"
"}\n"
"QPushButton:hover { color: black; background-color: red; }"));

        horizontalLayout_13->addWidget(modifyGRP);

        tableViewGRPGM = new QTableView(GRP_mgt);
        tableViewGRPGM->setObjectName("tableViewGRPGM");
        tableViewGRPGM->setGeometry(QRect(10, 70, 380, 210));
        tableViewGRPGM->setStyleSheet(QString::fromUtf8(""));
        tableViewGRPGM->verticalHeader()->setVisible(false);
        tableViewGRPETU = new QTableView(GRP_mgt);
        tableViewGRPETU->setObjectName("tableViewGRPETU");
        tableViewGRPETU->setGeometry(QRect(410, 70, 380, 210));
        tableViewGRPETU->setStyleSheet(QString::fromUtf8(""));
        tableViewGRPETU->verticalHeader()->setVisible(false);
        deleteGRPGM = new QPushButton(GRP_mgt);
        deleteGRPGM->setObjectName("deleteGRPGM");
        deleteGRPGM->setGeometry(QRect(20, 290, 191, 24));
        deleteGRPGM->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius: 7px;\n"
"border: 1px solid #555555;\n"
"}"));
        deleteGRPETU = new QPushButton(GRP_mgt);
        deleteGRPETU->setObjectName("deleteGRPETU");
        deleteGRPETU->setGeometry(QRect(420, 290, 191, 24));
        deleteGRPETU->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius: 7px;\n"
"border: 1px solid #555555;\n"
"}"));
        lineDeleteGM = new QLineEdit(GRP_mgt);
        lineDeleteGM->setObjectName("lineDeleteGM");
        lineDeleteGM->setGeometry(QRect(220, 280, 41, 24));
        lineDeleteETU = new QLineEdit(GRP_mgt);
        lineDeleteETU->setObjectName("lineDeleteETU");
        lineDeleteETU->setGeometry(QRect(662, 280, 41, 24));
        lineDeleteGRP = new QLineEdit(GRP_mgt);
        lineDeleteGRP->setObjectName("lineDeleteGRP");
        lineDeleteGRP->setGeometry(QRect(160, 530, 81, 24));
        lineDeleteGM_2 = new QLineEdit(GRP_mgt);
        lineDeleteGM_2->setObjectName("lineDeleteGM_2");
        lineDeleteGM_2->setGeometry(QRect(270, 280, 41, 24));
        lineDeleteETU_2 = new QLineEdit(GRP_mgt);
        lineDeleteETU_2->setObjectName("lineDeleteETU_2");
        lineDeleteETU_2->setGeometry(QRect(710, 280, 41, 24));
        stackedWidget->addWidget(GRP_mgt);
        Note_mgt = new QWidget();
        Note_mgt->setObjectName("Note_mgt");
        layoutWidget_10 = new QWidget(Note_mgt);
        layoutWidget_10->setObjectName("layoutWidget_10");
        layoutWidget_10->setGeometry(QRect(10, 10, 784, 26));
        horizontalLayout_10 = new QHBoxLayout(layoutWidget_10);
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        returnBackNote = new QPushButton(layoutWidget_10);
        returnBackNote->setObjectName("returnBackNote");
        returnBackNote->setMinimumSize(QSize(40, 24));
        returnBackNote->setMaximumSize(QSize(40, 24));
        returnBackNote->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border-radius: 7px;\n"
"border: 1px solid #555555;\n"
"}"));
        returnBackNote->setIconSize(QSize(20, 20));

        horizontalLayout_10->addWidget(returnBackNote);

        label_7 = new QLabel(layoutWidget_10);
        label_7->setObjectName("label_7");
        label_7->setMinimumSize(QSize(520, 0));

        horizontalLayout_10->addWidget(label_7);

        searchBarNote = new QLineEdit(layoutWidget_10);
        searchBarNote->setObjectName("searchBarNote");
        searchBarNote->setMinimumSize(QSize(210, 24));
        searchBarNote->setMaximumSize(QSize(210, 24));
        searchBarNote->setStyleSheet(QString::fromUtf8("QLineEdit { \n"
"padding-left: 20px;\n"
"background-image: url(D:/Pi/CPP/qt/search.svg);\n"
"background-position: left center;\n"
"background-repeat: no-repeat;\n"
"/*background-size: 10px 10px;*/\n"
"border-radius: 7px;\n"
"border: 1px solid #555555;\n"
"}"));

        horizontalLayout_10->addWidget(searchBarNote);

        layoutWidget_11 = new QWidget(Note_mgt);
        layoutWidget_11->setObjectName("layoutWidget_11");
        layoutWidget_11->setGeometry(QRect(20, 530, 771, 32));
        horizontalLayout_11 = new QHBoxLayout(layoutWidget_11);
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_4);

        addNote = new QPushButton(layoutWidget_11);
        addNote->setObjectName("addNote");
        addNote->setMinimumSize(QSize(150, 30));
        addNote->setMaximumSize(QSize(150, 30));
        addNote->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border-radius: 7px;\n"
"border: 1px solid #555555;\n"
"}"));

        horizontalLayout_11->addWidget(addNote);

        modifyNote = new QPushButton(layoutWidget_11);
        modifyNote->setObjectName("modifyNote");
        modifyNote->setMinimumSize(QSize(180, 30));
        modifyNote->setMaximumSize(QSize(180, 30));
        modifyNote->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border-radius: 7px;\n"
"border: 1px solid #555555;\n"
"}"));

        horizontalLayout_11->addWidget(modifyNote);

        tableViewNote = new QTableView(Note_mgt);
        tableViewNote->setObjectName("tableViewNote");
        tableViewNote->setGeometry(QRect(10, 50, 780, 460));
        tableViewNote->setStyleSheet(QString::fromUtf8(""));
        tableViewNote->verticalHeader()->setVisible(false);
        stackedWidget->addWidget(Note_mgt);
        PV = new QWidget();
        PV->setObjectName("PV");
        MoyMat = new QTableView(PV);
        MoyMat->setObjectName("MoyMat");
        MoyMat->setGeometry(QRect(20, 50, 371, 220));
        MoyMat->verticalHeader()->setVisible(false);
        returnBackPV = new QPushButton(PV);
        returnBackPV->setObjectName("returnBackPV");
        returnBackPV->setGeometry(QRect(20, 20, 40, 24));
        returnBackPV->setMinimumSize(QSize(40, 24));
        returnBackPV->setMaximumSize(QSize(40, 24));
        returnBackPV->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border-radius: 7px;\n"
"border: 1px solid #555555;\n"
"}"));
        returnBackPV->setIconSize(QSize(20, 20));
        MoyGM = new QTableView(PV);
        MoyGM->setObjectName("MoyGM");
        MoyGM->setGeometry(QRect(419, 50, 361, 220));
        MoyGM->verticalHeader()->setVisible(false);
        MoyG = new QTableView(PV);
        MoyG->setObjectName("MoyG");
        MoyG->setGeometry(QRect(20, 300, 761, 220));
        MoyG->verticalHeader()->setVisible(false);
        stackedWidget->addWidget(PV);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(8);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        title->setText(QCoreApplication::translate("MainWindow", "Student Grade Managment", nullptr));
        logoPi->setText(QString());
        welcomeButton->setText(QCoreApplication::translate("MainWindow", "Welcome!", nullptr));
        student->setText(QCoreApplication::translate("MainWindow", "Students", nullptr));
        teacher->setText(QCoreApplication::translate("MainWindow", "Teachers", nullptr));
        matiere->setText(QCoreApplication::translate("MainWindow", "Matiere", nullptr));
        gm->setText(QCoreApplication::translate("MainWindow", "Groupe Module", nullptr));
        groupe->setText(QCoreApplication::translate("MainWindow", "Groupe", nullptr));
        note->setText(QCoreApplication::translate("MainWindow", "Note", nullptr));
        pv->setText(QCoreApplication::translate("MainWindow", "PV", nullptr));
        addStudent->setText(QCoreApplication::translate("MainWindow", "Add Student", nullptr));
        returnBack->setText(QString());
        modifyStudent->setText(QCoreApplication::translate("MainWindow", "Modify/Delete Student", nullptr));
        addTeacher->setText(QCoreApplication::translate("MainWindow", "Add Teacher", nullptr));
        modifyTeacher->setText(QCoreApplication::translate("MainWindow", "Modify/Delete Teacher", nullptr));
        returnBackProf->setText(QString());
        label_2->setText(QString());
        returnBackMat->setText(QString());
        label->setText(QString());
        addMat->setText(QCoreApplication::translate("MainWindow", "Add Matiere", nullptr));
        modifyMat->setText(QCoreApplication::translate("MainWindow", "Modify/Delete Matiere", nullptr));
        addGM->setText(QCoreApplication::translate("MainWindow", "Add/Modify Groupe M", nullptr));
        modifyGM->setText(QCoreApplication::translate("MainWindow", "Delete Selected Groupe M", nullptr));
        returnBackGM->setText(QString());
        label_6->setText(QString());
        returnBackGRP->setText(QString());
        label_8->setText(QString());
        addGRP->setText(QCoreApplication::translate("MainWindow", "Add/Modify Groupe", nullptr));
        modifyGRP->setText(QCoreApplication::translate("MainWindow", "Delete Selected Groupe", nullptr));
        deleteGRPGM->setText(QCoreApplication::translate("MainWindow", "Delete selected Groupe Module", nullptr));
        deleteGRPETU->setText(QCoreApplication::translate("MainWindow", "Delete selected Student", nullptr));
        returnBackNote->setText(QString());
        label_7->setText(QString());
        addNote->setText(QCoreApplication::translate("MainWindow", "Add Note", nullptr));
        modifyNote->setText(QCoreApplication::translate("MainWindow", "Modify/Delete Note", nullptr));
        returnBackPV->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
