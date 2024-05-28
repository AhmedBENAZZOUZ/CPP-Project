#pragma once
#include <QMainWindow>
#include <QtWidgets>
#include <QPixmap>
#include <QtSql>
#include "ui_addStudent.h"
#include "ui_modifyStudent.h"
#include "ui_addTeacher.h"
#include "ui_modifyTeacher.h"
#include "ui_addMat.h"
#include "ui_modifyMat.h"
#include "ui_addGM.h"
#include "ui_addMatGM.h"
#include "ui_listeMat.h"
#include "ui_addGRP.h"
#include "ui_addGRPGM.h"
#include "ui_addGRPETU.h"
#include "ui_addNote.h"
#include "ui_modifyNote.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //********* Constructor && Destructor :
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //********* Connection database :
    void showEvent(QShowEvent *event);
    //********* Student :
    void on_addButton_clicked();
    void on_clearButton_clicked();
    void on_updateButton_clicked();
    void on_deleteButton_clicked();
    //********* Teacher :
    void on_addTeacherButton_clicked();
    void on_clearTeacherButton_clicked();
    void on_deleteTeacherButton_clicked();
    void on_updateTeacherButton_clicked();
    //********* Matiere :
    void on_addMatButton_clicked();
    void on_clearMatButton_clicked();
    void on_deleteMatButton_clicked();
    void on_updateMatButton_clicked();
    //********* Groupe Module :
    void on_addMatGM_clicked();
    //********* Groupe :
    void on_addGRPGM_clicked();
    void on_addGRPETU_clicked();
    void on_modifyGRPButton_clicked();
    void on_clearGRPButton_clicked();
    //********* Note :
    void on_addNoteButton_clicked();
    void on_clearNoteButton_clicked();
    void on_deleteNoteButton_clicked();
    void on_updateNoteButton_clicked();
private slots:
    //********* Welcome Page :
    void on_welcomeButton_clicked();
    //********* Menu :
    void on_student_clicked();
    void on_teacher_clicked();
    void on_matiere_clicked();
    void on_groupe_clicked();
    void on_gm_clicked();
    //********* Student :
    void populateTableWithStudents();
    void customizeTableView() ;
    void searchStudents(const QString &);
    void onSearchBarTextChanged(const QString &);
    void on_addStudent_clicked();
    void on_returnBack_clicked();
    void on_modifyStudent_clicked();
    void populateTableUpdateStudent();
    void customizeTableViewUpdate();
    void displaySelectedStudent(const QModelIndex &);
    void UpdateStudent();
    void deleteStudent();
    void clearLineEdits();
    //********* Teacher :
    void populateTableWithTeachears();
    void customizeTableViewTeacher();
    void searchTeacher(const QString &);
    void on_searchBarTeacher_textChanged(const QString &);
    void on_addTeacher_clicked();
    void on_returnBackProf_clicked();
    void on_modifyTeacher_clicked();
    void populateTableUpdateTeacher();
    void customizeTableViewUpdateTeacher();
    void displaySelectedTeacher(const QModelIndex &);
    void UpdateTeacher();
    void deleteTeacher();
    void clearLineEditsTeacher();
    //********* Matiere :
    void populateTableWithMat();
    void customizeTableViewMat();
    void searchMat(const QString &);
    void on_searchBarMat_textChanged(const QString &);
    void on_addMat_clicked();
    void on_returnBackMat_clicked();
    void PopulateTeacher();
    void customizeTableViewUpdateMat();
    void populateTableUpdateMat();
    void on_modifyMat_clicked();
    void clearLineEditsMat();
    void displaySelectedMat(const QModelIndex &);
    void deleteMat();
    void UpdateMat();
    //***** Groupe Module :
    void on_returnBackGM_clicked();
    void customizeTableViewGM();
    void populateTableWithGM();
    void customizeTableViewUpdateGM();
    void populateTableUpdateGM();
    void on_addGM_clicked();
    void displaySelectedGM(const QModelIndex &index);
    void clearLineEditsGM();
    void UpdateGM();
    void ajoutGM();
    void displayselectedmat(const QModelIndex &);
    void ToListeMat(const QModelIndex &);
    void deleteGm();
    void displayselectedgm(const QModelIndex &);
    void searchGM(const QString &text);
    void on_searchBarGM_textChanged(const QString &arg1);
    //***** Groupe :
    void on_returnBackGRP_clicked();
    void populateTableWithGRP();
    void customizeTableViewGRP();
    void on_addGRP_clicked();
    void ajoutGMGRP();
    void displayselectedGMGRP(const QModelIndex &index);
    void populateTableWithGRPGM();
    void customizeTableViewGRPGM();
    void ajoutETUGRP();
    void displayselectedETUGRP(const QModelIndex &index);
    void populateTableWithGRPETU();
    void customizeTableViewGRPETU();
    void displaySelectedG(const QModelIndex &index);
    void populateTableWithUpdateGRP();
    void customizeTableViewUpdateGRP();
    void deleteGrp();
    void displayselectedgrp(const QModelIndex &index);
    void deleteGmgrp();
    void displayselectedgrpgm(const QModelIndex &index);
    void displayselectedgmgrp(const QModelIndex &index);
    void deleteetugrp();
    void displayselectedgrpetu(const QModelIndex &index);
    void displayselectedetugrp(const QModelIndex &index);
    //***** Note :
    void on_returnBackNote_clicked();
    void on_note_clicked();
    void on_addNote_clicked();
    void populateTableNote();
    void customizeTableViewNote();
    void populateGrpNote();
    void populateGroupeModuleComboBox(const QString &selectedText);
    void populateMatiereComboBox(const QString &selectedText);
    void populateStudentComboBox(const QString &selectedText);
    void populateTypeComboBox(const QString &selectedText);
    void on_modifyNote_clicked();
    void searchNote(const QString &text);
    void on_searchBarNote_textChanged(const QString &arg1);
    void customizeTableViewUpdateNote();
    void populateTableUpdateNote();
    void displaySelectedNote(const QModelIndex &index);
    void clearLineEditsNote();
    void deleteNote();
    void UpdateNote();
    //***** Moyenne :
    void CalculMoyMat();
    void CalculMoyGM();
    void CalculMoyG();
    //***** PV :
    void on_pv_clicked();
    void on_returnBackPV_clicked();
    void customizeTableViewMoyMat();
    void populateTableWithMoyMat();
    void customizeTableViewMoyGM();
    void populateTableWithMoyGM();
    void populateTableWithMoyG();
    void customizeTableViewMoyG();

private:
    //********* Main Window :
    Ui::MainWindow *ui;
    //********* Student :
    Ui::AddStudent addStudentUi;
    Ui::ModifyStudent modifyStudentUi;
    //********* Teacher :
    Ui::addTeacher addTeeacherUi;
    Ui::modifyTeacher modifyTeacherUi;
    //********* Matiere :
    Ui::addMat addMatUi;
    Ui::modifyMat modifyMatUi;
    //********* Groupe Module :
    Ui::addGM addGmUi;
    Ui::addMatGM addMatGMUi;
    Ui::listeMat listeMatUi;
    //********* Groupe :
    Ui::addGroupe addGRPUi;
    Ui::addGRPGM addGRPGMUi;
    Ui::addGRPETU addGRPETUUi;
    //********* Note :
    Ui::addNote addNoteUi;
    Ui::modifyNote modifyNoteUi;
};
