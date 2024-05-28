#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "databasemanager.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //********* Welcome :
    show();
    ui->lineEdit->hide();
    ui->lineDeleteETU->hide();
    ui->lineDeleteETU_2->hide();
    ui->lineDeleteGM->hide();
    ui->lineDeleteGM_2->hide();
    ui->lineDeleteGRP->hide();
    ui->stackedWidget->setCurrentIndex(0);
    setWindowTitle("Grade managment");
    setWindowIcon(QIcon("D:/Pi/CPP/qt/logopi.jpg"));
    QPixmap pix("D:/Pi/CPP/qt/pilogo.png");
    int w = ui->logoPi->width();
    int h = ui->logoPi->height();
    ui->logoPi->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    // ui->welcomeButton->setStyleSheet("QPushButton:hover { color: white; background-color: red; }");
    //********* Menu :
    ui->student->setIcon(QIcon("D:/Pi/CPP/qt/student.svg"));
    ui->teacher->setIcon(QIcon("D:/Pi/CPP/qt/teacher.svg"));
    ui->matiere->setIcon(QIcon("D:/Pi/CPP/qt/subject.svg"));
    ui->gm->setIcon(QIcon("D:/Pi/CPP/qt/gm2.svg"));
    //********* Student :
    populateTableWithStudents();
    ui->returnBack->setIcon(QIcon("D:/Pi/CPP/qt/returnback.svg"));
    ui->addStudent->setIcon(QIcon("D:/Pi/CPP/qt/add.svg"));
    ui->searchBar->setClearButtonEnabled(true);
    ui->searchBar->setPlaceholderText("Search student");
    connect(ui->searchBar, &QLineEdit::textChanged, this, &MainWindow::onSearchBarTextChanged);
    //********* Teacher :
    populateTableWithTeachears();
    ui->returnBackProf->setIcon(QIcon("D:/Pi/CPP/qt/returnback.svg"));
    ui->addTeacher->setIcon(QIcon("D:/Pi/CPP/qt/add.svg"));
    ui->searchBarTeacher->setClearButtonEnabled(true);
    ui->searchBarTeacher->setPlaceholderText("Search teacher");
    connect(ui->searchBarTeacher, &QLineEdit::textChanged, this, &MainWindow::on_searchBarTeacher_textChanged);
    //********* Matiere :
    populateTableWithMat();
    ui->returnBackMat->setIcon(QIcon("D:/Pi/CPP/qt/returnback.svg"));
    ui->addMat->setIcon(QIcon("D:/Pi/CPP/qt/add.svg"));
    ui->searchBarMat->setClearButtonEnabled(true);
    ui->searchBarMat->setPlaceholderText("Search Matiere");
    connect(ui->searchBarMat, &QLineEdit::textChanged, this, &MainWindow::on_searchBarMat_textChanged);
    //********* Groupe Module :
    populateTableWithGM();
    ui->returnBackGM->setIcon(QIcon("D:/Pi/CPP/qt/returnback.svg"));
    ui->modifyGM->setIcon(QIcon("D:/Pi/CPP/qt/delete.svg"));
    ui->searchBarGM->setClearButtonEnabled(true);
    ui->searchBarGM->setPlaceholderText("Search Groupe Module");
    // connect(ui->searchBarTeacher, &QLineEdit::textChanged, this, &MainWindow::on_searchBarTeacher_textChanged);
    connect(ui->tableViewGM, &QTableView::doubleClicked, this, &MainWindow::ToListeMat);
    connect(ui->tableViewGM, &QTableView::clicked, this, &MainWindow::displayselectedgm);
    connect(ui->modifyGM, &QPushButton::clicked, this, &MainWindow::deleteGm);
    //********* Groupe :
    populateTableWithGRP();
    populateTableWithGRPGM();
    populateTableWithGRPETU();
    ui->returnBackGRP->setIcon(QIcon("D:/Pi/CPP/qt/returnback.svg"));
    ui->modifyGRP->setIcon(QIcon("D:/Pi/CPP/qt/delete.svg"));
    ui->searchBarGRP->setClearButtonEnabled(true);
    ui->searchBarGRP->setPlaceholderText("Search Groupe");
    connect(ui->tableViewGRP, &QTableView::clicked, this, &MainWindow::displayselectedgrp);
    connect(ui->modifyGRP, &QPushButton::clicked, this, &MainWindow::deleteGrp);
    connect(ui->tableViewGRPGM, &QTableView::clicked, this, &MainWindow::displayselectedgrpgm);
    connect(ui->tableViewGRPGM, &QTableView::clicked, this, &MainWindow::displayselectedgmgrp);
    connect(ui->deleteGRPGM, &QPushButton::clicked, this, &MainWindow::deleteGmgrp);
    connect(ui->tableViewGRPETU, &QTableView::clicked, this, &MainWindow::displayselectedgrpetu);
    connect(ui->tableViewGRPETU, &QTableView::clicked, this, &MainWindow::displayselectedetugrp);
    connect(ui->deleteGRPETU, &QPushButton::clicked, this, &MainWindow::deleteetugrp);
    //********* Note :
    populateTableNote();
    ui->returnBackNote->setIcon(QIcon("D:/Pi/CPP/qt/returnback.svg"));
    ui->addNote->setIcon(QIcon("D:/Pi/CPP/qt/add.svg"));
    ui->searchBarNote->setClearButtonEnabled(true);
    ui->searchBarNote->setPlaceholderText("Search Note");
    //********* PV :
    ui->returnBackPV->setIcon(QIcon("D:/Pi/CPP/qt/returnback.svg"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//********************************* Connection Database *******************************************
void MainWindow::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event);


    QSqlDatabase db = DatabaseManager::instance().database();
    if (!db.isOpen()) {
        qDebug() << "Database not open!";
        // ui->status->setText("Database not open!");
    }else{
        qDebug() << "Connected...!";
        // ui->status->setText("Connected...!");
    }
}
//********************************* Welcome *******************************************************
void MainWindow::on_welcomeButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
//********************************* Menu **********************************************************
void MainWindow::on_student_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_teacher_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_matiere_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_gm_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_groupe_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}
void MainWindow::on_note_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_pv_clicked()
{
    CalculMoyMat();
    CalculMoyGM();
    CalculMoyG();
    ui->stackedWidget->setCurrentIndex(8);
}

//********************************* Student *******************************************************
void MainWindow::on_returnBack_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::customizeTableView()
{
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    ui->tableWidget->horizontalHeader()->resizeSection(0, 80);

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
    ui->tableWidget->horizontalHeader()->resizeSection(1, 200);

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed);
    ui->tableWidget->horizontalHeader()->resizeSection(2, 200);

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Fixed);
    ui->tableWidget->horizontalHeader()->resizeSection(3, 298);
}


void MainWindow::populateTableWithStudents()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM Etudiant");
    ui->tableWidget->setModel(model);
    customizeTableView();
}

void MainWindow::on_addStudent_clicked()
{
    QDialog dialog;
    addStudentUi.setupUi(&dialog);
    dialog.setWindowTitle("Grade managment");
    dialog.setWindowIcon(QIcon("D:/Pi/CPP/qt/logopi.jpg"));
    connect(addStudentUi.addButton, &QPushButton::clicked, this, &MainWindow::on_addButton_clicked);
    connect(addStudentUi.cancelButton, &QPushButton::clicked, &dialog, &QDialog::reject);

    if (dialog.exec() == QDialog::Accepted) {

    } else {
        // Handle the rejected action or do nothing
        // This block of code will be executed if the user closes the dialog without accepting it
    }
}

void MainWindow::on_addButton_clicked()
{
    QSqlQuery createTableQuery;
    if (!createTableQuery.exec("CREATE TABLE IF NOT EXISTS Etudiant ("
                               "num_insc number(5) PRIMARY KEY,"
                               "nom varchar2(20) NOT NULL COLLATE NOCASE,"
                               "prenom varchar2(20) NOT NULL COLLATE NOCASE,"
                               "mail varchar2(30) NOT NULL COLLATE NOCASE);")) {
        qDebug() << "Error creating table:" << createTableQuery.lastError().text();
        return;
    } else {
        qDebug() << "Table created successfully";
    }

    int numInsc = addStudentUi.numinsc->text().toInt();
    QString name = addStudentUi.name->text();
    QString surname = addStudentUi.surname->text();
    QString mail = addStudentUi.mail->text();

    QString numinscString =addStudentUi.numinsc->text();
    if (numinscString.isEmpty()) {
        QMessageBox::critical(this, "Error", "Student number cannot be empty");
        return;
    }
    bool ok;
    numinscString.toInt(&ok);
    if (!ok) {
        QMessageBox::critical(this, "Error", "Invalid student number");
        return;
    }


    // Validate input
    if (name.isEmpty() || surname.isEmpty() || mail.isEmpty()) {
        QMessageBox::critical(this, "Error", "Please fill in all fields");
        return;
    }

    QSqlQuery insertQuery;
    insertQuery.prepare("INSERT INTO Etudiant (num_insc, nom, prenom, mail) VALUES (:num_insc, :nom, :prenom, :mail)");
    insertQuery.bindValue(":num_insc", numInsc);
    insertQuery.bindValue(":nom", name);
    insertQuery.bindValue(":prenom", surname);
    insertQuery.bindValue(":mail", mail);

    if (!insertQuery.exec()) {
        qDebug() << "Error inserting data:" << insertQuery.lastError().text();
    } else {
        qDebug() << "Data inserted successfully";
        QDialog* dialog = qobject_cast<QDialog*>(sender()->parent());
        if (dialog)
            dialog->accept();
        populateTableWithStudents();
        QMessageBox::information(this, "Success", "Student added successfully");
    }
}

void MainWindow::searchStudents(const QString &text)
{
    QSqlQuery query;
    QString queryString = "SELECT * FROM Etudiant WHERE num_insc LIKE :search OR nom LIKE :search OR prenom LIKE :search OR mail LIKE :search";
    query.prepare(queryString);
    query.bindValue(":search", "%" + text + "%");

    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return;
    }

    QSqlQueryModel *model = new QSqlQueryModel(); // Create a new model
    model->setQuery(std::move(query)); // Move the query to setQuery

    // Set the model to the TableView
    ui->tableWidget->setModel(model);
}

void MainWindow::onSearchBarTextChanged(const QString &text)
{
    searchStudents(text);
}

void MainWindow::populateTableUpdateStudent() {
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM Etudiant");

    modifyStudentUi.tableUpdateStudent->setModel(model);
}

void MainWindow::customizeTableViewUpdate() {
    modifyStudentUi.tableUpdateStudent->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    modifyStudentUi.tableUpdateStudent->horizontalHeader()->resizeSection(0, 60);

    modifyStudentUi.tableUpdateStudent->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
    modifyStudentUi.tableUpdateStudent->horizontalHeader()->resizeSection(1, 80);

    modifyStudentUi.tableUpdateStudent->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed);
    modifyStudentUi.tableUpdateStudent->horizontalHeader()->resizeSection(2, 80);

    modifyStudentUi.tableUpdateStudent->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Fixed);
    modifyStudentUi.tableUpdateStudent->horizontalHeader()->resizeSection(3, 188);
}

void MainWindow::on_modifyStudent_clicked()
{
    //tableUpdateStudent
    QDialog dialog2;
    modifyStudentUi.setupUi(&dialog2);
    populateTableUpdateStudent();
    customizeTableViewUpdate();
    dialog2.setWindowTitle("Grade managment");
    dialog2.setWindowIcon(QIcon("D:/Pi/CPP/qt/logopi.jpg"));
    connect(modifyStudentUi.updateButton, &QPushButton::clicked, this, &MainWindow::on_updateButton_clicked);
    connect(modifyStudentUi.deleteButton, &QPushButton::clicked, this, &MainWindow::on_deleteButton_clicked);
    connect(modifyStudentUi.clearButton, &QPushButton::clicked, this, &MainWindow::on_clearButton_clicked);
    connect(modifyStudentUi.cancelButton, &QPushButton::clicked, &dialog2, &QDialog::reject);
    connect(modifyStudentUi.tableUpdateStudent, &QTableView::clicked, this, &MainWindow::displaySelectedStudent);
    modifyStudentUi.updateButton->hide();
    modifyStudentUi.deleteButton->hide();
    modifyStudentUi.clearButton->hide();
    if (dialog2.exec() == QDialog::Accepted) {

    } else {
        // Handle the rejected action or do nothing
        // This block of code will be executed if the user closes the dialog without accepting it
    }
}

void MainWindow::displaySelectedStudent(const QModelIndex &index) {
    int row = index.row();

    QSqlQueryModel *model = qobject_cast<QSqlQueryModel*>( modifyStudentUi.tableUpdateStudent->model());
    QString numinsc = model->data(model->index(row, 0)).toString();
    QString nom = model->data(model->index(row, 1)).toString();
    QString prenom = model->data(model->index(row, 2)).toString();
    QString mail = model->data(model->index(row, 3)).toString();



    modifyStudentUi.numi->setText(numinsc);
    modifyStudentUi.name->setText(nom);
    modifyStudentUi.surname->setText(prenom);
    modifyStudentUi.mail->setText(mail);

    modifyStudentUi.updateButton->show();
    modifyStudentUi.deleteButton->show();
    modifyStudentUi.clearButton->show();
    modifyStudentUi.deleteButton->setIcon(QIcon("D:/Pi/CPP/qt/delete.svg"));
    modifyStudentUi.deleteButton->setStyleSheet("QPushButton:hover { color: black; background-color: red; }");
    modifyStudentUi.updateButton->setIcon(QIcon("D:/Pi/CPP/qt/edit.svg"));
    modifyStudentUi.clearButton->setIcon(QIcon("D:/Pi/CPP/qt/clear.svg"));
}

void MainWindow::clearLineEdits() {
    modifyStudentUi.numi->clear();
    modifyStudentUi.name->clear();
    modifyStudentUi.surname->clear();
    modifyStudentUi.mail->clear();
}

void MainWindow::UpdateStudent() {
    int numinsc = modifyStudentUi.numi->text().toInt();
    QString nom = modifyStudentUi.name->text();
    QString prenom = modifyStudentUi.surname->text();
    QString mail = modifyStudentUi.mail->text();

    if (nom.isEmpty() || prenom.isEmpty() || mail.isEmpty()) {
        QMessageBox::critical(this, "Error", "Please fill in all fields");
        return;
    }

    QSqlQuery updateQuery;
    updateQuery.prepare("UPDATE Etudiant SET nom = :nom, prenom = :prenom, mail = :mail WHERE num_insc = :num_insc");
    updateQuery.bindValue(":num_insc", numinsc);
    updateQuery.bindValue(":nom", nom);
    updateQuery.bindValue(":prenom", prenom);
    updateQuery.bindValue(":mail", mail);

    if (!updateQuery.exec()) {
        qDebug() << "Error updating data:" << updateQuery.lastError().text();
    } else {
        qDebug() << "Data updated successfully";
        populateTableUpdateStudent();
        clearLineEdits();
    }
}

void MainWindow::on_updateButton_clicked()
{
    UpdateStudent();
    populateTableWithStudents();
    modifyStudentUi.updateButton->hide();
    modifyStudentUi.deleteButton->hide();
    modifyStudentUi.clearButton->hide();
}

void MainWindow::deleteStudent() {
    int numinsc = modifyStudentUi.numi->text().toInt();

    QMessageBox::StandardButton reply = QMessageBox::critical(this, "Delete Student",
                                                              "Are you sure you want to delete this student?",
                                                              QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::No){
        return;
    }

    QSqlQuery deleteQuery;
    deleteQuery.prepare("DELETE FROM Etudiant WHERE num_insc = :num_insc");
    deleteQuery.bindValue(":num_insc", numinsc);

    if (!deleteQuery.exec()) {
        qDebug() << "Error deleting data:" << deleteQuery.lastError().text();
    } else {
        qDebug() << "Data deleted successfully";
        populateTableUpdateStudent();
        clearLineEdits();
    }
}

void MainWindow::on_deleteButton_clicked()
{
    deleteStudent();
    populateTableWithStudents();
    modifyStudentUi.updateButton->hide();
    modifyStudentUi.deleteButton->hide();
    modifyStudentUi.clearButton->hide();
}


void MainWindow::on_clearButton_clicked()
{
    clearLineEdits();
    modifyStudentUi.updateButton->hide();
    modifyStudentUi.deleteButton->hide();
    modifyStudentUi.clearButton->hide();
}

//********************************* Teacher *******************************************************
void MainWindow::on_returnBackProf_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::customizeTableViewTeacher()
{
    ui->tableWidgetTeacher->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    ui->tableWidgetTeacher->horizontalHeader()->resizeSection(0, 80);

    ui->tableWidgetTeacher->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
    ui->tableWidgetTeacher->horizontalHeader()->resizeSection(1, 200);

    ui->tableWidgetTeacher->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed);
    ui->tableWidgetTeacher->horizontalHeader()->resizeSection(2, 200);

    ui->tableWidgetTeacher->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Fixed);
    ui->tableWidgetTeacher->horizontalHeader()->resizeSection(3, 298);
}


void MainWindow::populateTableWithTeachears()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM Enseignant");

    ui->tableWidgetTeacher->setModel(model);
    customizeTableViewTeacher();
}

void MainWindow::on_addTeacher_clicked()
{
    QDialog dialog;
    addTeeacherUi.setupUi(&dialog);
    dialog.setWindowTitle("Grade managment");
    dialog.setWindowIcon(QIcon("D:/Pi/CPP/qt/logopi.jpg"));
    connect(addTeeacherUi.addTeacherButton, &QPushButton::clicked, this, &MainWindow::on_addTeacherButton_clicked);
    connect(addTeeacherUi.cancelTeacherButton, &QPushButton::clicked, &dialog, &QDialog::reject);

    if (dialog.exec() == QDialog::Accepted) {

    } else {
        // Handle the rejected action or do nothing
        // This block of code will be executed if the user closes the dialog without accepting it
    }
}


void MainWindow::on_addTeacherButton_clicked()
{
    QSqlQuery createTableQuery;
    if (!createTableQuery.exec("CREATE TABLE IF NOT EXISTS Enseignant ("
                               "cnss number(5) PRIMARY KEY,"
                               "nom varchar2(20) NOT NULL COLLATE NOCASE,"
                               "prenom varchar2(20) NOT NULL COLLATE NOCASE,"
                               "mail varchar2(30) NOT NULL COLLATE NOCASE);")) {
        qDebug() << "Error creating table:" << createTableQuery.lastError().text();
        return;
    } else {
        qDebug() << "Table Enseignant created successfully";
    }

    int cnss = addTeeacherUi.cnss->text().toInt();
    QString name = addTeeacherUi.name->text();
    QString surname = addTeeacherUi.surname->text();
    QString mail = addTeeacherUi.mail->text();

    QString cnssString =addTeeacherUi.cnss->text();
    if (cnssString.isEmpty()) {
        QMessageBox::critical(this, "Error", "Cnss number cannot be empty");
        return;
    }
    bool ok;
    cnssString.toInt(&ok);
    if (!ok) {
        QMessageBox::critical(this, "Error", "Invalid teacher number");
        return;
    }


    // Validate input
    if (name.isEmpty() || surname.isEmpty() || mail.isEmpty()) {
        QMessageBox::critical(this, "Error", "Please fill in all fields");
        return;
    }

    QSqlQuery insertQuery;
    insertQuery.prepare("INSERT INTO Enseignant (cnss, nom, prenom, mail) VALUES (:cnss, :nom, :prenom, :mail)");
    insertQuery.bindValue(":cnss", cnss);
    insertQuery.bindValue(":nom", name);
    insertQuery.bindValue(":prenom", surname);
    insertQuery.bindValue(":mail", mail);

    if (!insertQuery.exec()) {
        qDebug() << "Error inserting data:" << insertQuery.lastError().text();
    } else {
        qDebug() << "Data inserted successfully";
        QDialog* dialog = qobject_cast<QDialog*>(sender()->parent());
        if (dialog)
            dialog->accept();
        populateTableWithTeachears();
        QMessageBox::information(this, "Success", "Teacher added successfully");
    }
}

void MainWindow::searchTeacher(const QString &text)
{
    QSqlQuery query;
    QString queryString = "SELECT * FROM Enseignant WHERE cnss LIKE :search OR nom LIKE :search OR prenom LIKE :search OR mail LIKE :search";
    query.prepare(queryString);
    query.bindValue(":search", "%" + text + "%");

    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return;
    }

    QSqlQueryModel *model = new QSqlQueryModel(); // Create a new model
    model->setQuery(std::move(query)); // Move the query to setQuery

    // Set the model to the TableView
    ui->tableWidgetTeacher->setModel(model);
}

void MainWindow::on_searchBarTeacher_textChanged(const QString &text)
{
    searchTeacher(text);
}

void MainWindow::populateTableUpdateTeacher() {
    //tableViewUpdateTeacher
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM Enseignant");

    modifyTeacherUi.tableViewUpdateTeacher->setModel(model);
}

void MainWindow::customizeTableViewUpdateTeacher() {
    modifyTeacherUi.tableViewUpdateTeacher->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    modifyTeacherUi.tableViewUpdateTeacher->horizontalHeader()->resizeSection(0, 60);

    modifyTeacherUi.tableViewUpdateTeacher->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
    modifyTeacherUi.tableViewUpdateTeacher->horizontalHeader()->resizeSection(1, 80);

    modifyTeacherUi.tableViewUpdateTeacher->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed);
    modifyTeacherUi.tableViewUpdateTeacher->horizontalHeader()->resizeSection(2, 80);

    modifyTeacherUi.tableViewUpdateTeacher->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Fixed);
    modifyTeacherUi.tableViewUpdateTeacher->horizontalHeader()->resizeSection(3, 188);
}

void MainWindow::on_modifyTeacher_clicked()
{
    QDialog dialog2;
    modifyTeacherUi.setupUi(&dialog2);
    populateTableUpdateTeacher();
    customizeTableViewUpdateTeacher();
    dialog2.setWindowTitle("Grade managment");
    dialog2.setWindowIcon(QIcon("D:/Pi/CPP/qt/logopi.jpg"));
    connect(modifyTeacherUi.updateTeacherButton, &QPushButton::clicked, this, &MainWindow::on_updateTeacherButton_clicked);
    connect(modifyTeacherUi.deleteTeacherButton, &QPushButton::clicked, this, &MainWindow::on_deleteTeacherButton_clicked);
    connect(modifyTeacherUi.clearTeacherButton, &QPushButton::clicked, this, &MainWindow::on_clearTeacherButton_clicked);
    connect(modifyTeacherUi.cancelTeacherButton, &QPushButton::clicked, &dialog2, &QDialog::reject);
    connect(modifyTeacherUi.tableViewUpdateTeacher, &QTableView::clicked, this, &MainWindow::displaySelectedTeacher);
    modifyTeacherUi.updateTeacherButton->hide();
    modifyTeacherUi.deleteTeacherButton->hide();
    modifyTeacherUi.clearTeacherButton->hide();
    if (dialog2.exec() == QDialog::Accepted) {

    } else {
        // Handle the rejected action or do nothing
        // This block of code will be executed if the user closes the dialog without accepting it
    }
}

void MainWindow::displaySelectedTeacher(const QModelIndex &index) {
    int row = index.row();

    QSqlQueryModel *model = qobject_cast<QSqlQueryModel*>( modifyTeacherUi.tableViewUpdateTeacher->model());
    QString cnss = model->data(model->index(row, 0)).toString();
    QString nom = model->data(model->index(row, 1)).toString();
    QString prenom = model->data(model->index(row, 2)).toString();
    QString mail = model->data(model->index(row, 3)).toString();



    modifyTeacherUi.cnss->setText(cnss);
    modifyTeacherUi.name->setText(nom);
    modifyTeacherUi.surname->setText(prenom);
    modifyTeacherUi.mail->setText(mail);

    modifyTeacherUi.updateTeacherButton->show();
    modifyTeacherUi.deleteTeacherButton->show();
    modifyTeacherUi.clearTeacherButton->show();
    modifyTeacherUi.deleteTeacherButton->setIcon(QIcon("D:/Pi/CPP/qt/delete.svg"));
    modifyTeacherUi.deleteTeacherButton->setStyleSheet("QPushButton:hover { color: black; background-color: red; }");
    modifyTeacherUi.updateTeacherButton->setIcon(QIcon("D:/Pi/CPP/qt/edit.svg"));
    modifyTeacherUi.clearTeacherButton->setIcon(QIcon("D:/Pi/CPP/qt/clear.svg"));
}

void MainWindow::clearLineEditsTeacher() {
    modifyTeacherUi.cnss->clear();
    modifyTeacherUi.name->clear();
    modifyTeacherUi.surname->clear();
    modifyTeacherUi.mail->clear();
}

void MainWindow::UpdateTeacher() {
    int cnss = modifyTeacherUi.cnss->text().toInt();
    QString nom = modifyTeacherUi.name->text();
    QString prenom = modifyTeacherUi.surname->text();
    QString mail = modifyTeacherUi.mail->text();

    if (nom.isEmpty() || prenom.isEmpty() || mail.isEmpty()) {
        QMessageBox::critical(this, "Error", "Please fill in all fields");
        return;
    }

    QSqlQuery updateQuery;
    updateQuery.prepare("UPDATE Enseignant SET nom = :nom, prenom = :prenom, mail = :mail WHERE cnss = :cnss");
    updateQuery.bindValue(":cnss", cnss);
    updateQuery.bindValue(":nom", nom);
    updateQuery.bindValue(":prenom", prenom);
    updateQuery.bindValue(":mail", mail);

    if (!updateQuery.exec()) {
        qDebug() << "Error updating data:" << updateQuery.lastError().text();
    } else {
        qDebug() << "Data updated successfully";
        populateTableUpdateTeacher();
        clearLineEditsTeacher();
    }
}

void MainWindow::on_updateTeacherButton_clicked()
{
    UpdateTeacher();
    populateTableWithTeachears();
    modifyTeacherUi.updateTeacherButton->hide();
    modifyTeacherUi.deleteTeacherButton->hide();
    modifyTeacherUi.clearTeacherButton->hide();
}

void MainWindow::deleteTeacher() {
    int cnss = modifyTeacherUi.cnss->text().toInt();

    QMessageBox::StandardButton reply = QMessageBox::critical(this, "Delete Teacher",
                                                              "Are you sure you want to delete this teacher?",
                                                              QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::No){
        return;
    }

    QSqlQuery deleteQuery;
    deleteQuery.prepare("DELETE FROM Enseignant WHERE cnss = :cnss");
    deleteQuery.bindValue(":cnss", cnss);

    if (!deleteQuery.exec()) {
        qDebug() << "Error deleting data:" << deleteQuery.lastError().text();
    } else {
        qDebug() << "Data deleted successfully";
        populateTableUpdateTeacher();
        clearLineEditsTeacher();
    }
}

void MainWindow::on_deleteTeacherButton_clicked()
{
    deleteTeacher();
    populateTableWithTeachears();
    modifyTeacherUi.updateTeacherButton->hide();
    modifyTeacherUi.deleteTeacherButton->hide();
    modifyTeacherUi.clearTeacherButton->hide();
}

void MainWindow::on_clearTeacherButton_clicked()
{
    clearLineEditsTeacher();
    modifyTeacherUi.updateTeacherButton->hide();
    modifyTeacherUi.deleteTeacherButton->hide();
    modifyTeacherUi.clearTeacherButton->hide();
}
//********************************* Matiere *******************************************************
void MainWindow::on_returnBackMat_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::customizeTableViewMat()
{
    ui->tableViewMat->setColumnWidth(0, 120);
    ui->tableViewMat->setColumnWidth(1, 240);
    ui->tableViewMat->setColumnWidth(2, 80);
    ui->tableViewMat->setColumnWidth(3, 80);
    ui->tableViewMat->setColumnWidth(4, 130);
    ui->tableViewMat->setColumnWidth(5, 128);
}

void MainWindow::populateTableWithMat()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select m.idmat , m.nom , m.coef, e.cnss , e.prenom , e.nom from Matiere m , Enseignant e where m.teacher=e.cnss;");

    ui->tableViewMat->setModel(model);
    customizeTableViewMat();
}

void MainWindow::PopulateTeacher() {
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT cnss, nom, prenom FROM Enseignant");

    addMatUi.teacher->clear();

    addMatUi.teacher->addItem("Select Teacher");

    int rowCount = model->rowCount();
    for (int i = 0; i < rowCount; ++i) {
        int teacherId = model->record(i).value("CNSS").toInt();
        QString teacherName = model->record(i).value("nom").toString();
        QString teacherLastName = model->record(i).value("prenom").toString();
        addMatUi.teacher->addItem(QString("%1 - %2 %3").arg(teacherId).arg(teacherName).arg(teacherLastName));
    }
}

void MainWindow::on_addMat_clicked()
{
    QDialog dialog;
    addMatUi.setupUi(&dialog);
    dialog.setWindowTitle("Grade managment");
    dialog.setWindowIcon(QIcon("D:/Pi/CPP/qt/logopi.jpg"));
    connect(addMatUi.addMatButton, &QPushButton::clicked, this, &MainWindow::on_addMatButton_clicked);
    connect(addMatUi.cancelMatButton, &QPushButton::clicked, &dialog, &QDialog::reject);
    PopulateTeacher();

    if (dialog.exec() == QDialog::Accepted) {

    } else {
        // Handle the rejected action or do nothing
        // This block of code will be executed if the user closes the dialog without accepting it
    }
}

void MainWindow::on_addMatButton_clicked()
{
    QSqlQuery createTableQuery;
    if (!createTableQuery.exec("CREATE TABLE IF NOT EXISTS Matiere ("
                               "idmat varchar2(20) PRIMARY KEY,"
                               "nom varchar2(20) NOT NULL COLLATE NOCASE,"
                               "coef number(3.2) NOT NULL COLLATE NOCASE,"
                               "teacher number(5) NOT NULL COLLATE NOCASE);")) {
        qDebug() << "Error creating table:" << createTableQuery.lastError().text();
        return;
    } else {
        qDebug() << "Table Matiere created successfully";
    }

    QString idMat = addMatUi.idmat->text();
    QString name = addMatUi.name->text();
    float coef = addMatUi.coef->text().toFloat();
    QString selectedText = addMatUi.teacher->currentText();
    int cnss = selectedText.section(" - ", 0, 0).toInt();

    if (idMat.isEmpty()) {
        QMessageBox::critical(this, "Error", "Id matiere cannot be empty");
        return;
    }

    if (name.isEmpty()) {
        QMessageBox::critical(this, "Error", "Please fill name fields");
        return;
    }

    if (selectedText=="Select Teacher") {
        QMessageBox::critical(this, "Error", "Please select a teacher");
        return;
    }

    QSqlQuery insertQuery;
    insertQuery.prepare("INSERT INTO Matiere (idmat, nom, coef, teacher) VALUES (:idmat, :nom, :coef, :teacher)");
    insertQuery.bindValue(":idmat", idMat);
    insertQuery.bindValue(":nom", name);
    insertQuery.bindValue(":coef", coef);
    insertQuery.bindValue(":teacher", cnss);

    if (!insertQuery.exec()) {
        qDebug() << "Error inserting data:" << insertQuery.lastError().text();
    } else {
        qDebug() << "Data inserted successfully";
        QDialog* dialog = qobject_cast<QDialog*>(sender()->parent());
        if (dialog)
            dialog->accept();
        populateTableWithMat();
        QMessageBox::information(this, "Success", "Matiere added successfully");
    }
}

void MainWindow::searchMat(const QString &text)
{
    QSqlQuery query;
    QString queryString = "select m.idmat , m.nom , m.coef, e.cnss , e.prenom , e.nom from Matiere m , Enseignant e where (m.teacher=e.cnss) AND (m.idmat LIKE :search OR m.nom LIKE :search OR m.coef LIKE :search OR e.cnss LIKE :search OR e.nom LIKE :search OR e.prenom LIKE :search);";
    query.prepare(queryString);
    query.bindValue(":search", "%" + text + "%");

    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return;
    }

    QSqlQueryModel *model = new QSqlQueryModel(); // Create a new model
    model->setQuery(std::move(query)); // Move the query to setQuery

    // Set the model to the TableView
    ui->tableViewMat->setModel(model);

}

void MainWindow::on_searchBarMat_textChanged(const QString &arg1)
{
    searchMat(arg1);
}

void MainWindow::customizeTableViewUpdateMat() {
    modifyMatUi.tableViewUpdateMat->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    modifyMatUi.tableViewUpdateMat->horizontalHeader()->resizeSection(0, 60);

    modifyMatUi.tableViewUpdateMat->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
    modifyMatUi.tableViewUpdateMat->horizontalHeader()->resizeSection(1, 70);

    modifyMatUi.tableViewUpdateMat->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed);
    modifyMatUi.tableViewUpdateMat->horizontalHeader()->resizeSection(2, 70);

    modifyMatUi.tableViewUpdateMat->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Fixed);
    modifyMatUi.tableViewUpdateMat->horizontalHeader()->resizeSection(3, 70);

    modifyMatUi.tableViewUpdateMat->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Fixed);
    modifyMatUi.tableViewUpdateMat->horizontalHeader()->resizeSection(4, 70);

    modifyMatUi.tableViewUpdateMat->horizontalHeader()->setSectionResizeMode(5, QHeaderView::Fixed);
    modifyMatUi.tableViewUpdateMat->horizontalHeader()->resizeSection(5, 68);

}

void MainWindow::populateTableUpdateMat() {
    //tableViewUpdateTeacher
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select m.idmat , m.nom , m.coef, e.cnss , e.prenom , e.nom from Matiere m , Enseignant e where m.teacher=e.cnss;");

    modifyMatUi.tableViewUpdateMat->setModel(model);
    customizeTableViewUpdateMat();
}

void MainWindow::on_modifyMat_clicked()
{
    QDialog dialog2;
    modifyMatUi.setupUi(&dialog2);
    populateTableUpdateMat();
    dialog2.setWindowTitle("Grade managment");
    dialog2.setWindowIcon(QIcon("D:/Pi/CPP/qt/logopi.jpg"));
    connect(modifyMatUi.updateMatButton, &QPushButton::clicked, this, &MainWindow::on_updateMatButton_clicked);
    connect(modifyMatUi.deleteMatButton, &QPushButton::clicked, this, &MainWindow::on_deleteMatButton_clicked);
    connect(modifyMatUi.clearMatButton, &QPushButton::clicked, this, &MainWindow::on_clearMatButton_clicked);
    connect(modifyMatUi.cancelMatButton, &QPushButton::clicked, &dialog2, &QDialog::reject);
    connect(modifyMatUi.tableViewUpdateMat, &QTableView::clicked, this, &MainWindow::displaySelectedMat);
    modifyMatUi.updateMatButton->hide();
    modifyMatUi.deleteMatButton->hide();
    modifyMatUi.clearMatButton->hide();
    if (dialog2.exec() == QDialog::Accepted) {

    } else {
        // Handle the rejected action or do nothing
        // This block of code will be executed if the user closes the dialog without accepting it
    }
}

void MainWindow::displaySelectedMat(const QModelIndex &index) {
    int row = index.row();
    // ui->clear_pushButton->show();

    // Retrieve the data of the selected matiere
    QSqlQueryModel *model = qobject_cast<QSqlQueryModel*>(modifyMatUi.tableViewUpdateMat->model());
    QString idMat = model->data(model->index(row, 0)).toString(); // Assuming the first column contains IdMat
    QString nomMat = model->data(model->index(row, 1)).toString(); // Assuming the second column contains NomMat
    double coef = model->data(model->index(row, 2)).toDouble(); // Assuming the third column contains Coef
    int enseignantId = model->data(model->index(row, 3)).toInt(); // Assuming the fourth column contains Ens
    QString enseignantNom = model->data(model->index(row, 4)).toString();
    QString enseignantPrenom = model->data(model->index(row, 5)).toString();

    // Populate line edits with the selected matiere's information
    modifyMatUi.idMat->setText(idMat);
    modifyMatUi.name->setText(nomMat);
    modifyMatUi.coef->setValue(coef);

    QSqlQueryModel *mod = new QSqlQueryModel();
    mod->setQuery("SELECT cnss, nom, prenom FROM Enseignant");

    modifyMatUi.teacher->clear();

    modifyMatUi.teacher->addItem(QString("%1 - %2 %3").arg(enseignantId).arg(enseignantNom).arg(enseignantPrenom));

    int rowCount = mod->rowCount();
    for (int i = 0; i < rowCount; ++i) {
        int teacherId = mod->record(i).value("cnss").toInt();
        QString teacherName = mod->record(i).value("nom").toString();
        QString teacherLastName = mod->record(i).value("prenom").toString();
        if(enseignantId!=teacherId){
            modifyMatUi.teacher->addItem(QString("%1 - %2 %3").arg(teacherId).arg(teacherName).arg(teacherLastName));
        }
    }
    modifyMatUi.deleteMatButton->setIcon(QIcon("D:/Pi/CPP/qt/delete.svg"));
    modifyMatUi.deleteMatButton->setStyleSheet("QPushButton:hover { color: black; background-color: red; }");
    modifyMatUi.updateMatButton->setIcon(QIcon("D:/Pi/CPP/qt/edit.svg"));
    modifyMatUi.clearMatButton->setIcon(QIcon("D:/Pi/CPP/qt/clear.svg"));
    modifyMatUi.updateMatButton->show();
    modifyMatUi.deleteMatButton->show();
    modifyMatUi.clearMatButton->show();
}

void MainWindow::clearLineEditsMat() {
    modifyMatUi.idMat->clear();
    modifyMatUi.name->clear();
    modifyMatUi.coef->clear();
    modifyMatUi.teacher->clear();
}

void MainWindow::on_clearMatButton_clicked()
{
    clearLineEditsMat();
    modifyMatUi.updateMatButton->hide();
    modifyMatUi.deleteMatButton->hide();
    modifyMatUi.clearMatButton->hide();
}


void MainWindow::deleteMat() {
    QString idMat = modifyMatUi.idMat->text();

    QMessageBox::StandardButton reply = QMessageBox::critical(this, "Delete Matiere",
                                                              "Are you sure you want to delete this Matiere?",
                                                              QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::No){
        return;
    }

    QSqlQuery deleteQuery;
    deleteQuery.prepare("DELETE FROM Matiere WHERE idmat = :idmat");
    deleteQuery.bindValue(":idmat", idMat);

    if (!deleteQuery.exec()) {
        qDebug() << "Error deleting data:" << deleteQuery.lastError().text();
    } else {
        qDebug() << "Data deleted successfully";
        populateTableUpdateMat();
        clearLineEditsMat();
    }
}

void MainWindow::on_deleteMatButton_clicked()
{
    deleteMat();
    clearLineEditsMat();
    populateTableWithMat();
    modifyMatUi.updateMatButton->hide();
    modifyMatUi.deleteMatButton->hide();
    modifyMatUi.clearMatButton->hide();
}

void MainWindow::UpdateMat() {
    QString idMat = modifyMatUi.idMat->text();
    QString name = modifyMatUi.name->text();
    float coef = modifyMatUi.coef->text().toFloat();
    QString selectedText = modifyMatUi.teacher->currentText();
    int teacher = selectedText.section(" - ", 0, 0).toInt();

    if (idMat.isEmpty()) {
        QMessageBox::critical(this, "Error", "Id matiere cannot be empty");
        return;
    }

    if (name.isEmpty()) {
        QMessageBox::critical(this, "Error", "Please fill name field");
        return;
    }

    // if (selectedText=="Select Teacher") {
    //     QMessageBox::critical(this, "Error", "Please select a teacher");
    //     return;
    // }

    QSqlQuery updateQuery;
    updateQuery.prepare("UPDATE Matiere SET nom = :nom, coef = :coef, teacher = :teacher WHERE idmat = :idmat");
    updateQuery.bindValue(":idmat", idMat);
    updateQuery.bindValue(":nom", name);
    updateQuery.bindValue(":coef", coef);
    updateQuery.bindValue(":teacher", teacher);

    if (!updateQuery.exec()) {
        qDebug() << "Error updating data:" << updateQuery.lastError().text();
    } else {
        qDebug() << "Data updated successfully";
        populateTableUpdateMat();
        clearLineEditsMat();
    }
}

void MainWindow::on_updateMatButton_clicked()
{
    UpdateMat();
    populateTableWithMat();
    modifyMatUi.updateMatButton->hide();
    modifyMatUi.deleteMatButton->hide();
    modifyMatUi.clearMatButton->hide();
}

//********************************* Groupe Module *************************************************
void MainWindow::on_returnBackGM_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::customizeTableViewGM()
{
    ui->tableViewGM->setColumnWidth(0, 260);
    ui->tableViewGM->setColumnWidth(1, 260);
    ui->tableViewGM->setColumnWidth(2, 260);
}

void MainWindow::populateTableWithGM()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * FROM GroupeModule;");

    ui->tableViewGM->setModel(model);
    customizeTableViewGM();
}

void MainWindow::customizeTableViewUpdateGM()
{
    addGmUi.tableViewGM->setColumnWidth(0, 124);
    addGmUi.tableViewGM->setColumnWidth(1, 124);
    addGmUi.tableViewGM->setColumnWidth(2, 120);
}

void MainWindow::populateTableUpdateGM()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * FROM GroupeModule;");

    addGmUi.tableViewGM->setModel(model);
    customizeTableViewUpdateGM();
}

void MainWindow::on_addGM_clicked()
{
    QDialog dialog;
    addGmUi.setupUi(&dialog);
    dialog.setWindowTitle("Grade managment");
    dialog.setWindowIcon(QIcon("D:/Pi/CPP/qt/logopi.jpg"));
    // connect(addGmUi.addGMButton, &QPushButton::clicked, this, &MainWindow::on_addMatButton_clicked);
    connect(addGmUi.addMatGM, &QPushButton::clicked, this, &MainWindow::on_addMatGM_clicked);
    connect(addGmUi.clearGMButton, &QPushButton::clicked, this, &MainWindow::clearLineEditsGM);
    connect(addGmUi.modifyGMButton, &QPushButton::clicked, this, &MainWindow::UpdateGM);
    connect(addGmUi.cancelGMButton, &QPushButton::clicked, &dialog, &QDialog::reject);
    connect(addGmUi.tableViewGM, &QTableView::clicked, this, &MainWindow::displaySelectedGM);
    populateTableUpdateGM();
    if (dialog.exec() == QDialog::Accepted) {

    } else {
        // Handle the rejected action or do nothing
        // This block of code will be executed if the user closes the dialog without accepting it
    }
}

void MainWindow::displaySelectedGM(const QModelIndex &index)
{
    int row = index.row();
    QSqlQueryModel *model = qobject_cast<QSqlQueryModel*>(addGmUi.tableViewGM->model());
    QString idMat = model->data(model->index(row, 0)).toString();
    QString nomMat = model->data(model->index(row, 1)).toString();
    double coef = model->data(model->index(row, 2)).toDouble();

    addGmUi.idgm->setText(idMat);
    addGmUi.name->setText(nomMat);
    addGmUi.coef->setValue(coef);
}

void MainWindow::clearLineEditsGM()
{
    addGmUi.idgm->clear();
    addGmUi.name->clear();
    addGmUi.coef->clear();
}

void MainWindow::UpdateGM()
{
    QString idGm = addGmUi.idgm->text();
    QString nomGm = addGmUi.name->text();
    double coefGm = addGmUi.coef->value();

    if (idGm.isEmpty() || nomGm.isEmpty()) {
        QMessageBox::critical(this, "Error", "Please fill in all fields");
        return;
    }

    QSqlQuery updateQuery;
    updateQuery.prepare("UPDATE GroupeModule SET NomGm = :nomgm, CoefGm = :coefgm WHERE IdGm = :idgm");
    updateQuery.bindValue(":idgm", idGm);
    updateQuery.bindValue(":nomgm", nomGm);
    updateQuery.bindValue(":coefgm", coefGm);

    if (!updateQuery.exec()) {
        qDebug() << "Error updating data:" << updateQuery.lastError().text();
    } else {
        qDebug() << "Data updated successfully";
        populateTableWithGM();
        populateTableUpdateGM();
        clearLineEditsGM();
    }
}

void MainWindow::on_addMatGM_clicked()
{
    QDialog dialog;
    addMatGMUi.setupUi(&dialog);
    dialog.setWindowTitle("Add Matiere to GM");
    dialog.setWindowIcon(QIcon("D:/Pi/CPP/qt/logopi.jpg"));
    connect(addMatGMUi.tableViewMatGM, &QTableView::doubleClicked, this, &MainWindow::displayselectedmat);
    connect(addMatGMUi.tableViewMatGM, &QTableView::doubleClicked, this, &MainWindow::ajoutGM);
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * FROM Matiere;");

    addMatGMUi.tableViewMatGM->setModel(model);
    if (dialog.exec() == QDialog::Accepted) {

    } else {
        // Handle the rejected action or do nothing
        // This block of code will be executed if the user closes the dialog without accepting it
    }
}

void MainWindow::displayselectedmat(const QModelIndex &index){
    // Retrieve the data of the selected matiere
    int row = index.row();
    QSqlQueryModel *model = qobject_cast<QSqlQueryModel*>(addMatGMUi.tableViewMatGM->model());
    QString idMat = model->data(model->index(row, 0)).toString(); // Assuming the first column contains IdMat

    qDebug() << "Selected Matiere ID:" << idMat;

    addMatGMUi.lineEdit->setText(idMat);
}
void MainWindow::searchGM(const QString &text)
{
    QSqlQuery query;
    QString queryString = "SELECT * FROM GroupeModule WHERE IdGm LIKE :search OR NomGm LIKE :search OR CoefGm LIKE :search;";
    query.prepare(queryString);
    query.bindValue(":search", "%" + text + "%");

    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return;
    }

    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(std::move(query));

    ui->tableViewGM->setModel(model);

}
void MainWindow::on_searchBarGM_textChanged(const QString &arg1)
{
    searchGM(arg1);
}
void MainWindow::ajoutGM()
{
    QSqlQuery createGMQuery;
    if (!createGMQuery.exec("CREATE TABLE IF NOT EXISTS GroupeModule ("
                            "IdGm TEXT PRIMARY KEY,"
                            "NomGm TEXT NOT NULL,"
                            "CoefGm REAL)")) { // Added closing parenthesis for the CREATE TABLE statement
        qDebug() << "Error creating table:" << createGMQuery.lastError().text();
        return;
    } else {
        qDebug() << "Table Groupe Module created successfully";
    }

    QSqlQuery createLMQuery;
    if (!createLMQuery.exec("CREATE TABLE IF NOT EXISTS Liste_Matiere ("
                            "IdGm TEXT,"
                            "IdMat INTEGER,"
                            "PRIMARY KEY (IdGm, IdMat),"
                            "FOREIGN KEY (IdGm) REFERENCES GroupeModule(IdGm),"
                            "FOREIGN KEY (IdMat) REFERENCES Matiere(idmat))")) { // Added closing parenthesis for the CREATE TABLE statement
        qDebug() << "Error creating table LISTEMAT:" << createLMQuery.lastError().text();
        return;
    } else {
        qDebug() << "Table Liste Matiere created successfully";
    }


    QString idGm = addGmUi.idgm->text();
    QString nomGm = addGmUi.name->text();
    double coefGm = addGmUi.coef->value();

    if (idGm.isEmpty()) {
        QMessageBox::critical(this, "Error", "Groupe Module id cannot be empty");
        return;
    }

    if (nomGm.isEmpty()) {
        QMessageBox::critical(this, "Error", "Groupe Module name cannot be empty");
        return;
    }

    if (coefGm==0) {
        QMessageBox::critical(this, "Error", "Matiere coefGm number cannot 0");
        return;
    }


    // Insert data into the database
    QSqlQuery insertGMQuery;
    insertGMQuery.prepare("INSERT INTO GroupeModule VALUES (:IdGm,:nomMat, :coefGm)");
    insertGMQuery.bindValue(":IdGm", idGm);
    insertGMQuery.bindValue(":nomMat", nomGm);
    insertGMQuery.bindValue(":coefGm", coefGm);

    if (!insertGMQuery.exec()) {
        qDebug() << "Error inserting data:" << insertGMQuery.lastError().text();
    } else {
        qDebug() << "Data inserted in groupe module successfully";
        // clearLineEdits();
        // Optionally, you can update your UI or perform any other action here
    }
    // PopulateMatiere();



    QString id = addMatGMUi.lineEdit->text();

    if (id.isEmpty()) {
        QMessageBox::critical(this, "Error", "Select Matiere !!!");
        return;
    }

    // Insert data into the database
    QSqlQuery insertLMQuery;
    insertLMQuery.prepare("INSERT INTO Liste_Matiere (IdGm, IdMat) VALUES (:IdGm, :IdMat)");
    insertLMQuery.bindValue(":IdGm", idGm);
    insertLMQuery.bindValue(":IdMat", id);

    if (!insertLMQuery.exec()) {
        qDebug() << "Error inserting data:" << insertLMQuery.lastError().text();
        QMessageBox::critical(this, "Error", "UNIQUE constraint failed: Liste_Matiere.IdGm, Liste_Matiere.IdMat Unable to fetch row");
    } else {
        qDebug() << "Data inserted successfully";
        addMatGMUi.lineEdit->clear();
        // clearLineEdits();
        // Optionally, you can update your UI or perform any other action here
    }
    populateTableWithGM();
}

void MainWindow::ToListeMat(const QModelIndex &index) {

    int row = index.row();

    // Get the model from the table view
    QSqlQueryModel *model = qobject_cast<QSqlQueryModel*>(ui->tableViewGM->model());

    // Get the IdGm value from the selected row
    QString idGm = model->data(model->index(row, 0)).toString();

    qDebug() << "Selected IdGm:" << idGm; // Debug output to check the selected IdGm value

    // Prepare SQL query to retrieve material data associated with the selected GroupeModule
    QSqlQuery query;
    query.prepare("SELECT m.idmat, m.nom, m.coef "
                  "FROM Matiere AS m "
                  "INNER JOIN Liste_Matiere AS lm ON m.idmat = lm.IdMat "
                  "WHERE lm.IdGm = :idGm");
    query.bindValue(":idGm", idGm);

    // Execute the SQL query
    if (!query.exec()) {
        // If an error occurs while executing the query, print an error message
        qDebug() << "Error executing query:" << query.lastError().text();
        return;
    }

    QDialog dialog;
    listeMatUi.setupUi(&dialog);
    dialog.setWindowTitle("Matieres From GM");
    dialog.setWindowIcon(QIcon("D:/Pi/CPP/qt/logopi.jpg"));
    // connect(addMatGMUi.tableViewMatGM, &QTableView::doubleClicked, this, &MainWindow::displayselectedmat);
    // connect(addMatGMUi.tableViewMatGM, &QTableView::doubleClicked, this, &MainWindow::ajoutGM);
    QSqlQueryModel *mod = new QSqlQueryModel();
    mod->setQuery(std::move(query));

    listeMatUi.tableViewlisteMat->setModel(mod);
    connect(listeMatUi.deleteMatGM, &QPushButton::clicked, this, [=]() {
        // Get the currently selected row index from the tableView
        int selectedRow = listeMatUi.tableViewlisteMat->currentIndex().row();

        // Check if a row is selected
        if (selectedRow >= 0) {
            // Get the IdMat value from the selected row
            QString idMat = mod->data(mod->index(selectedRow, 0)).toString();
            qDebug() << "Selected Matiere ID:" << idMat;

            // Prepare SQL query to delete the selected row from Liste_Matiere
            QSqlQuery deleteQuery;
            deleteQuery.prepare("DELETE FROM Liste_Matiere WHERE IdGm = :idGm AND IdMat = :idMat");
            deleteQuery.bindValue(":idGm", idGm);
            deleteQuery.bindValue(":idMat", idMat);

            // Execute the delete query
            if (!deleteQuery.exec()) {
                // If an error occurs while executing the query, print an error message
                qDebug() << "Error deleting row from Liste_Matiere:" << deleteQuery.lastError().text();
                return;
            }

            // Remove the row from the table view
            mod->removeRow(selectedRow);


            // Prepare the SQL query
            QSqlQuery query;
            query.prepare("SELECT m.idmat, m.nom, m.coef "
                          "FROM Matiere AS m "
                          "INNER JOIN Liste_Matiere AS lm ON m.idmat = lm.IdMat "
                          "WHERE lm.IdGm = :idGm");

            // Bind the value of idGm to the placeholder
            query.bindValue(":idGm", idGm);

            // Execute the query
            if (!query.exec()) {
                // If an error occurs while executing the query, print an error message
                qDebug() << "Error executing query:" << query.lastError().text();
                return;
            }

            // Set the query model for the table view
            QSqlQueryModel *mod = new QSqlQueryModel();
            mod->setQuery(std::move(query));
            listeMatUi.tableViewlisteMat->setModel(mod);
        } else {
            qDebug() << "No rows selected"; // Debug output to indicate that no rows are selected
        }

    });
    if (dialog.exec() == QDialog::Accepted) {

    } else {
        // Handle the rejected action or do nothing
        // This block of code will be executed if the user closes the dialog without accepting it
    }
}

void MainWindow::displayselectedgm(const QModelIndex &index)
{
    // Retrieve the data of the selected matiere
    int row = index.row();
    QSqlQueryModel *model = qobject_cast<QSqlQueryModel*>(ui->tableViewGM->model());
    QString idGm = model->data(model->index(row, 0)).toString(); // Assuming the first column contains IdMat

    qDebug() << "Selected Matiere ID:" << idGm;

    ui->lineEdit->setText(idGm);
}


void MainWindow::deleteGm()
{
    QString idGm = ui->lineEdit->text();
    QMessageBox::StandardButton reply = QMessageBox::critical(this, "Delete GM",
                                                              "Are you sure you want to delete this GroupeModule?",
                                                              QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::No)
        return;

    // Delete student information from the database
    QSqlQuery deleteQuery;
    deleteQuery.prepare("DELETE FROM GroupeModule WHERE IdGm = :idGm");
    deleteQuery.bindValue(":idGm", idGm);

    if (!deleteQuery.exec()) {
        qDebug() << "Error deleting data:" << deleteQuery.lastError().text();
    } else {
        qDebug() << "Data deleted successfully";
        ui->lineEdit->clear();
            // Refresh the table view to reflect changes
        // clearLineEdits(); // Optionally clear the line edits after deletion
    }


    QSqlQuery deleteLMQuery;
    deleteLMQuery.prepare("DELETE FROM Liste_Matiere WHERE IdGm = :idGm");
    deleteLMQuery.bindValue(":idGm", idGm);
    if (!deleteLMQuery.exec()) {
        qDebug() << "Error deleting row from Liste_Matiere:" << deleteLMQuery.lastError().text();
        return;
    }
    populateTableWithGM();
}
//********************************* Groupe ********************************************************

void MainWindow::on_returnBackGRP_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::customizeTableViewGRP()
{
    ui->tableViewGRP->setColumnWidth(0, 155);
    ui->tableViewGRP->setColumnWidth(1, 155);
    ui->tableViewGRP->setColumnWidth(2, 155);
    ui->tableViewGRP->setColumnWidth(3, 155);
    ui->tableViewGRP->setColumnWidth(4, 155);
}

void MainWindow::populateTableWithGRP()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * FROM Groupe;");

    ui->tableViewGRP->setModel(model);
    customizeTableViewGRP();
}

void MainWindow::customizeTableViewUpdateGRP()
{
    addGRPUi.tableViewUpdateGRP->setColumnWidth(0, 71);
    addGRPUi.tableViewUpdateGRP->setColumnWidth(1, 71);
    addGRPUi.tableViewUpdateGRP->setColumnWidth(2, 71);
    addGRPUi.tableViewUpdateGRP->setColumnWidth(3, 71);
    addGRPUi.tableViewUpdateGRP->setColumnWidth(4, 71);
}

void MainWindow::populateTableWithUpdateGRP()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * FROM Groupe;");

    addGRPUi.tableViewUpdateGRP->setModel(model);
    customizeTableViewUpdateGRP();
}

void MainWindow::customizeTableViewGRPGM()
{
    ui->tableViewGRPGM->setColumnWidth(0, 126);
    ui->tableViewGRPGM->setColumnWidth(1, 126);
    ui->tableViewGRPGM->setColumnWidth(2, 126);
}

void MainWindow::populateTableWithGRPGM()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT Groupe.IdGRP, Liste_Groupe_GM.IdGm, GroupeModule.NomGm "
                    "FROM Groupe "
                    "INNER JOIN Liste_Groupe_GM ON Groupe.IdGRP = Liste_Groupe_GM.IdGRP "
                    "INNER JOIN GroupeModule ON Liste_Groupe_GM.IdGm = GroupeModule.IdGm;");

    ui->tableViewGRPGM->setModel(model);
    customizeTableViewGRPGM();
}

void MainWindow::customizeTableViewGRPETU()
{
    ui->tableViewGRPETU->setColumnWidth(0, 126);
    ui->tableViewGRPETU->setColumnWidth(1, 126);
    ui->tableViewGRPETU->setColumnWidth(2, 126);
}

void MainWindow::populateTableWithGRPETU()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT Groupe.IdGRP, Liste_Groupe_ETU.numinsc, Etudiant.prenom "
                    "FROM Groupe "
                    "INNER JOIN Liste_Groupe_ETU ON Groupe.IdGRP = Liste_Groupe_ETU.IdGRP "
                    "INNER JOIN Etudiant ON Liste_Groupe_ETU.numinsc = Etudiant.num_insc;");

    ui->tableViewGRPETU->setModel(model);
    customizeTableViewGRPETU();
}

void MainWindow::on_addGRP_clicked()
{
    QDialog dialog;
    addGRPUi.setupUi(&dialog);
    dialog.setWindowTitle("Grade managment");
    dialog.setWindowIcon(QIcon("D:/Pi/CPP/qt/logopi.jpg"));
    connect(addGRPUi.addGRPETU, &QPushButton::clicked, this, &MainWindow::on_addGRPETU_clicked);
    connect(addGRPUi.addGRPGM, &QPushButton::clicked, this, &MainWindow::on_addGRPGM_clicked);
    connect(addGRPUi.cancelGRPButton, &QPushButton::clicked, &dialog, &QDialog::reject);
    connect(addGRPUi.tableViewUpdateGRP, &QTableView::clicked, this, &MainWindow::displaySelectedG);
    connect(addGRPUi.modifyGRPButton, &QPushButton::clicked, this, &MainWindow::on_modifyGRPButton_clicked);
    connect(addGRPUi.clearGRPButton, &QPushButton::clicked, this, &MainWindow::on_clearGRPButton_clicked);
    populateTableWithUpdateGRP();

    if (dialog.exec() == QDialog::Accepted) {

    } else {

    }
}

void MainWindow::displaySelectedG(const QModelIndex &index)
{
    int row = index.row();
    // ui->clear_pushButton->show();

    // Retrieve the data of the selected matiere
    QSqlQueryModel *model = qobject_cast<QSqlQueryModel*>(addGRPUi.tableViewUpdateGRP->model());
    QString idG = model->data(model->index(row, 0)).toString(); // Assuming the first column contains IdMat
    QString niv = model->data(model->index(row, 1)).toString(); // Assuming the second column contains NomMat
    QString dip = model->data(model->index(row, 2)).toString(); // Assuming the second column contains NomMat
    QString spec = model->data(model->index(row, 3)).toString(); // Assuming the second column contains NomMat
    QString numg = model->data(model->index(row, 4)).toString(); // Assuming the second column contains NomMat

    addGRPUi.idgm->setText(idG);
    addGRPUi.niveau->setCurrentText(niv);
    addGRPUi.diplome->setCurrentText(dip);
    addGRPUi.specialite->setCurrentText(spec);
    addGRPUi.numg->setCurrentText(numg);
}

void MainWindow::on_modifyGRPButton_clicked()
{
    QString idGrp = addGRPUi.idgm->text();
    QString niv =addGRPUi.niveau->currentText();
    QString dip =addGRPUi.diplome->currentText();
    QString spec = addGRPUi.specialite->currentText();
    int numg = addGRPUi.numg->currentText().toInt();

    QSqlQuery updateQuery;
    updateQuery.prepare("UPDATE Groupe SET Niveau = :niv, Diplôme = :dip, Spécialité = :spec ,Num_G =:numg WHERE IdGRP = :idGrp");
    updateQuery.bindValue(":idGrp", idGrp);
    updateQuery.bindValue(":niv", niv);
    updateQuery.bindValue(":dip", dip);
    updateQuery.bindValue(":spec", spec);
    updateQuery.bindValue(":numg", numg);

    if (!updateQuery.exec()) {
        qDebug() << "Error updating data:" << updateQuery.lastError().text();
    } else {
        qDebug() << "Data updated successfully";
        populateTableWithUpdateGRP();
        populateTableWithGRP();
    }
    populateTableWithUpdateGRP();
    populateTableWithGRP();
}

void MainWindow::on_addGRPGM_clicked()
{
    QDialog dialog;
    addGRPGMUi.setupUi(&dialog);
    dialog.setWindowTitle("Add GM to Groupe");
    dialog.setWindowIcon(QIcon("D:/Pi/CPP/qt/logopi.jpg"));
    connect(addGRPGMUi.tableViewGRPGM, &QTableView::doubleClicked, this, &MainWindow::displayselectedGMGRP);
    connect(addGRPGMUi.tableViewGRPGM, &QTableView::doubleClicked, this, &MainWindow::ajoutGMGRP);
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * FROM GroupeModule;");

    addGRPGMUi.tableViewGRPGM->setModel(model);
    if (dialog.exec() == QDialog::Accepted) {

    } else {
        // Handle the rejected action or do nothing
        // This block of code will be executed if the user closes the dialog without accepting it
    }
}

void MainWindow::displayselectedGMGRP(const QModelIndex &index)
{
    // Retrieve the data of the selected matiere
    int row = index.row();
    QSqlQueryModel *model = qobject_cast<QSqlQueryModel*>(addGRPGMUi.tableViewGRPGM->model());
    QString idGM = model->data(model->index(row, 0)).toString();

    qDebug() << "Selected Groupe Module ID:" << idGM;

    addGRPGMUi.lineEdit->setText(idGM);
}

void MainWindow::ajoutGMGRP()
{

    QSqlQuery createGMQuery;
    if (!createGMQuery.exec("CREATE TABLE IF NOT EXISTS Groupe ("
                            "IdGRP TEXT PRIMARY KEY,"
                            "Niveau TEXT,"
                            "Diplôme TEXT,"
                            "Spécialité TEXT,"
                            "Num_G INTEGER)")) {
        qDebug() << "Error creating table:" << createGMQuery.lastError().text();
        return;
    } else {
        qDebug() << "Table Groupe created successfully";
    }
    QSqlQuery createLMQuery;
    if (!createLMQuery.exec("CREATE TABLE IF NOT EXISTS Liste_Groupe_GM ("
                            "IdGRP TEXT,"
                            "IdGm TEXT,"
                            "PRIMARY KEY (IdGRP, IdGm),"
                            "FOREIGN KEY (IdGRP) REFERENCES Groupe(IdGRP),"
                            "FOREIGN KEY (IdGm) REFERENCES GroupeModule(IdGm))")) {
        qDebug() << "Error creating table LISTEGRP:" << createLMQuery.lastError().text();
        return;
    } else {
        qDebug() << "Table created successfully";
    }


    QString idGRP = addGRPUi.idgm->text();
    QString niv = addGRPUi.niveau->currentText();
    QString dip = addGRPUi.diplome->currentText();
    QString spec = addGRPUi.specialite->currentText();
    int numg = addGRPUi.numg->currentText().toInt();


    // Insert data into the database
    QSqlQuery insertGMQuery;
    insertGMQuery.prepare("INSERT INTO Groupe VALUES (:IdGRP,:niv,:dip,:spec,:numg)");
    insertGMQuery.bindValue(":IdGRP", idGRP);
    insertGMQuery.bindValue(":niv", niv);
    insertGMQuery.bindValue(":dip", dip);
    insertGMQuery.bindValue(":spec", spec);
    insertGMQuery.bindValue(":numg", numg);

    if (!insertGMQuery.exec()) {
        qDebug() << "Error inserting data:" << insertGMQuery.lastError().text();
    } else {
        qDebug() << "Data inserted successfully";
        // clearLineEdits();
        // Optionally, you can update your UI or perform any other action here
    }
    populateTableWithGRP();
    populateTableWithUpdateGRP();



    QString idgm = addGRPGMUi.lineEdit->text();

    if (idgm.isEmpty()) {
        QMessageBox::critical(this, "Error", "Select GroupeModule !!!");
        return;
    }

    // Insert data into the database
    QSqlQuery insertLMQuery;
    insertLMQuery.prepare("INSERT INTO Liste_Groupe_GM (IdGRP,IdGm) VALUES (:IdGRP,:IdGm)");
    insertLMQuery.bindValue(":IdGRP", idGRP);
    insertLMQuery.bindValue(":IdGm", idgm);

    if (!insertLMQuery.exec()) {
        qDebug() << "Error inserting data:" << insertLMQuery.lastError().text();
        QMessageBox::critical(this, "Error", "UNIQUE constraint failed: Liste_Groupe.IdGm, Liste_Matiere.IdMat Unable to fetch row");
    } else {
        qDebug() << "Data inserted successfully";
    }
    populateTableWithGRPGM();
}

void MainWindow::on_addGRPETU_clicked()
{
    QDialog dialog;
    addGRPETUUi.setupUi(&dialog);
    dialog.setWindowTitle("Add Student to Groupe");
    dialog.setWindowIcon(QIcon("D:/Pi/CPP/qt/logopi.jpg"));
    connect(addGRPETUUi.tableViewGRPETU, &QTableView::doubleClicked, this, &MainWindow::displayselectedETUGRP);
    connect(addGRPETUUi.tableViewGRPETU, &QTableView::doubleClicked, this, &MainWindow::ajoutETUGRP);
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * FROM Etudiant;");

    addGRPETUUi.tableViewGRPETU->setModel(model);
    if (dialog.exec() == QDialog::Accepted) {

    } else {
        // Handle the rejected action or do nothing
        // This block of code will be executed if the user closes the dialog without accepting it
    }
}

void MainWindow::displayselectedETUGRP(const QModelIndex &index)
{
    // Retrieve the data of the selected matiere
    int row = index.row();
    QSqlQueryModel *model = qobject_cast<QSqlQueryModel*>(addGRPETUUi.tableViewGRPETU->model());
    QString idETU = model->data(model->index(row, 0)).toString();

    qDebug() << "Selected Student ID:" << idETU;

    addGRPETUUi.lineEdit->setText(idETU);
}

void MainWindow::ajoutETUGRP()
{

    QSqlQuery createGMQuery;
    if (!createGMQuery.exec("CREATE TABLE IF NOT EXISTS Groupe ("
                            "IdGRP TEXT PRIMARY KEY,"
                            "Niveau TEXT,"
                            "Diplôme TEXT,"
                            "Spécialité TEXT,"
                            "Num_G INTEGER)")) {
        qDebug() << "Error creating table:" << createGMQuery.lastError().text();
        return;
    } else {
        qDebug() << "Table Groupe created successfully";
    }
    QSqlQuery createLMQuery;
    if (!createLMQuery.exec("CREATE TABLE IF NOT EXISTS Liste_Groupe_ETU ("
                            "IdGRP TEXT,"
                            "numinsc number(5),"
                            "PRIMARY KEY (IdGRP, numinsc),"
                            "FOREIGN KEY (IdGRP) REFERENCES Groupe(IdGRP),"
                            "FOREIGN KEY (numinsc) REFERENCES Etudiant(num_insc))")) {
        qDebug() << "Error creating table LISTEGRP:" << createLMQuery.lastError().text();
        return;
    } else {
        qDebug() << "Table created successfully";
    }


    QString idGRP = addGRPUi.idgm->text();
    QString niv = addGRPUi.niveau->currentText();
    QString dip = addGRPUi.diplome->currentText();
    QString spec = addGRPUi.specialite->currentText();
    int numg = addGRPUi.numg->currentText().toInt();


    // Insert data into the database
    QSqlQuery insertGMQuery;
    insertGMQuery.prepare("INSERT INTO Groupe VALUES (:IdGRP,:niv,:dip,:spec,:numg)");
    insertGMQuery.bindValue(":IdGRP", idGRP);
    insertGMQuery.bindValue(":niv", niv);
    insertGMQuery.bindValue(":dip", dip);
    insertGMQuery.bindValue(":spec", spec);
    insertGMQuery.bindValue(":numg", numg);

    if (!insertGMQuery.exec()) {
        qDebug() << "Error inserting data:" << insertGMQuery.lastError().text();
    } else {
        qDebug() << "Data inserted successfully";
        // clearLineEdits();
        // Optionally, you can update your UI or perform any other action here
    }
    populateTableWithGRP();
    populateTableWithUpdateGRP();



    QString idET = addGRPETUUi.lineEdit->text();

    if (idET.isEmpty()) {
        QMessageBox::critical(this, "Error", "Select Etudiant !!!");
        return;
    }
    int idETU = idET.toInt();
    // Insert data into the database
    QSqlQuery insertLMQuery;
    insertLMQuery.prepare("INSERT INTO Liste_Groupe_ETU (IdGRP,numinsc) VALUES (:IdGRP,:numinsc)");
    insertLMQuery.bindValue(":IdGRP", idGRP);
    insertLMQuery.bindValue(":numinsc", idETU);

    if (!insertLMQuery.exec()) {
        qDebug() << "Error inserting data:" << insertLMQuery.lastError().text();
        QMessageBox::critical(this, "Error", "UNIQUE constraint failed: Liste_Groupe.IdGm, Liste_Matiere.IdMat Unable to fetch row");
    } else {
        qDebug() << "Data inserted successfully";
    }
    populateTableWithGRPETU();
}


void MainWindow::on_clearGRPButton_clicked()
{
    addGRPUi.idgm->clear();
    addGRPUi.niveau->setCurrentIndex(0);
    addGRPUi.diplome->setCurrentIndex(0);
    addGRPUi.specialite->setCurrentIndex(0);
    addGRPUi.numg->setCurrentIndex(0);
}

void MainWindow::displayselectedgrp(const QModelIndex &index)
{
    // Retrieve the data of the selected matiere
    int row = index.row();
    QSqlQueryModel *model = qobject_cast<QSqlQueryModel*>(ui->tableViewGRP->model());
    QString idGm = model->data(model->index(row, 0)).toString(); // Assuming the first column contains IdMat

    qDebug() << "Selected Matiere ID:" << idGm;

    ui->lineDeleteGRP->setText(idGm);
}


void MainWindow::deleteGrp()
{
    QString idGm = ui->lineDeleteGRP->text();
    QMessageBox::StandardButton reply = QMessageBox::critical(this, "Delete Groupe",
                                                              "Are you sure you want to delete this Groupe?",
                                                              QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::No)
        return;

    // Delete student information from the database
    QSqlQuery deleteQuery;
    deleteQuery.prepare("DELETE FROM Groupe WHERE IdGRP = :idGrp");
    deleteQuery.bindValue(":idGrp", idGm);

    if (!deleteQuery.exec()) {
        qDebug() << "Error deleting data:" << deleteQuery.lastError().text();
    } else {
        qDebug() << "Data deleted successfully";

        // Refresh the table view to reflect changes
        // clearLineEdits(); // Optionally clear the line edits after deletion
    }
    QSqlQuery deleteQueryGM;
    deleteQueryGM.prepare("DELETE FROM Liste_Groupe_GM WHERE IdGRP = :idGrp");
    deleteQueryGM.bindValue(":idGrp", idGm);

    if (!deleteQueryGM.exec()) {
        qDebug() << "Error deleting data:" << deleteQueryGM.lastError().text();
    } else {
        qDebug() << "Data deleted successfully";

        // Refresh the table view to reflect changes
        // clearLineEdits(); // Optionally clear the line edits after deletion
    }
    QSqlQuery deleteQueryETU;
    deleteQueryETU.prepare("DELETE FROM Liste_Groupe_ETU WHERE IdGRP = :idGrp");
    deleteQueryETU.bindValue(":idGrp", idGm);

    if (!deleteQueryETU.exec()) {
        qDebug() << "Error deleting data:" << deleteQueryETU.lastError().text();
    } else {
        qDebug() << "Data deleted successfully";

        // Refresh the table view to reflect changes
        // clearLineEdits(); // Optionally clear the line edits after deletion
    }
    populateTableWithGRP();
    populateTableWithGRPETU();
    populateTableWithGRPGM();
}

void MainWindow::displayselectedgrpgm(const QModelIndex &index)
{
    // Retrieve the data of the selected matiere
    int row = index.row();
    QSqlQueryModel *model = qobject_cast<QSqlQueryModel*>(ui->tableViewGRPGM->model());
    QString idGm = model->data(model->index(row, 0)).toString(); // Assuming the first column contains IdMat

    qDebug() << "Selected Groupe ID:" << idGm;

    ui->lineDeleteGM_2->setText(idGm);
}

void MainWindow::displayselectedgmgrp(const QModelIndex &index)
{
    // Retrieve the data of the selected matiere
    int row = index.row();
    QSqlQueryModel *model = qobject_cast<QSqlQueryModel*>(ui->tableViewGRPGM->model());
    QString idGm = model->data(model->index(row, 1)).toString(); // Assuming the first column contains IdMat

    qDebug() << "Selected Groupe Module ID:" << idGm;

    ui->lineDeleteGM->setText(idGm);
}


void MainWindow::deleteGmgrp()
{
    QString idGm = ui->lineDeleteGM->text();
    QString idGrp= ui->lineDeleteGM_2->text();
    QMessageBox::StandardButton reply = QMessageBox::critical(this, "Delete GM",
                                                              "Are you sure you want to delete this GroupeModule?",
                                                              QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::No)
        return;

    // Delete student information from the database
    QSqlQuery deleteQuery;
    deleteQuery.prepare("DELETE FROM Liste_Groupe_GM WHERE IdGm = :idGm AND IdGRP = :idGrp");
    deleteQuery.bindValue(":idGm", idGm);
    deleteQuery.bindValue(":idGrp", idGrp);

    if (!deleteQuery.exec()) {
        qDebug() << "Error deleting data:" << deleteQuery.lastError().text();
    } else {
        qDebug() << "Data deleted successfully";

        // Refresh the table view to reflect changes
        // clearLineEdits(); // Optionally clear the line edits after deletion
    }
    populateTableWithGRPGM();
}

void MainWindow::displayselectedgrpetu(const QModelIndex &index)
{
    // Retrieve the data of the selected matiere
    int row = index.row();
    QSqlQueryModel *model = qobject_cast<QSqlQueryModel*>(ui->tableViewGRPETU->model());
    QString idGm = model->data(model->index(row, 0)).toString(); // Assuming the first column contains IdMat

    qDebug() << "Selected Groupe ID:" << idGm;

    ui->lineDeleteETU_2->setText(idGm);
}

void MainWindow::displayselectedetugrp(const QModelIndex &index)
{
    // Retrieve the data of the selected matiere
    int row = index.row();
    QSqlQueryModel *model = qobject_cast<QSqlQueryModel*>(ui->tableViewGRPETU->model());
    QString idGm = model->data(model->index(row, 1)).toString(); // Assuming the first column contains IdMat

    qDebug() << "Selected Student ID:" << idGm;

    ui->lineDeleteETU->setText(idGm);
}


void MainWindow::deleteetugrp()
{
    QString numinsc = ui->lineDeleteETU->text();
    QString idGrp = ui->lineDeleteETU_2->text();
    QMessageBox::StandardButton reply = QMessageBox::critical(this, "Delete Student",
                                                              "Are you sure you want to delete this Student?",
                                                              QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::No)
        return;

    // Delete student information from the database
    QSqlQuery deleteQuery;
    deleteQuery.prepare("DELETE FROM Liste_Groupe_ETU WHERE numinsc = :numinsc AND IdGRP = :idGrp");
    deleteQuery.bindValue(":numinsc", numinsc);
    deleteQuery.bindValue(":idGrp", idGrp);

    if (!deleteQuery.exec()) {
        qDebug() << "Error deleting data:" << deleteQuery.lastError().text();
    } else {
        qDebug() << "Data deleted successfully";
            // Refresh the table view to reflect changes
        // clearLineEdits(); // Optionally clear the line edits after deletion
    }
    populateTableWithGRPETU();
}

//********************************* Note **********************************************************

void MainWindow::on_returnBackNote_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}



void MainWindow::customizeTableViewNote()
{
    ui->tableViewNote->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    ui->tableViewNote->horizontalHeader()->resizeSection(0, 80);

    ui->tableViewNote->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
    ui->tableViewNote->horizontalHeader()->resizeSection(1, 200);

    ui->tableViewNote->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed);
    ui->tableViewNote->horizontalHeader()->resizeSection(2, 200);

    ui->tableViewNote->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Fixed);
    ui->tableViewNote->horizontalHeader()->resizeSection(3, 298);
}


void MainWindow::populateTableNote()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM Note");
    ui->tableViewNote->setModel(model);
    customizeTableViewNote();
}

void MainWindow::on_addNote_clicked()
{
    QDialog dialog;
    addNoteUi.setupUi(&dialog);
    dialog.setWindowTitle("Grade management");
    dialog.setWindowIcon(QIcon("D:/Pi/CPP/qt/logopi.jpg"));
    connect(addNoteUi.cancelNoteButton, &QPushButton::clicked, &dialog, &QDialog::reject);
    connect(addNoteUi.groupeNote, &QComboBox::currentTextChanged, this, &MainWindow::populateGroupeModuleComboBox);
    connect(addNoteUi.groupeNote, &QComboBox::currentTextChanged, this, &MainWindow::populateStudentComboBox);
    connect(addNoteUi.GMNote, &QComboBox::currentTextChanged, this, &MainWindow::populateMatiereComboBox);
    connect(addNoteUi.MatNote, &QComboBox::currentTextChanged, this, &MainWindow::populateTypeComboBox);
    connect(addNoteUi.addNoteButton, &QPushButton::clicked, this, &MainWindow::on_addNoteButton_clicked);

    addNoteUi.GMNote->hide();
    addNoteUi.MatNote->hide();
    addNoteUi.EtuNote->hide();
    addNoteUi.TypeNote->hide();
    addNoteUi.note_2->hide();
    populateGrpNote();

    if (dialog.exec() == QDialog::Accepted) {

    } else {

    }
}

void MainWindow::populateGrpNote()
{
    QSqlQueryModel *groupModel = new QSqlQueryModel();
    groupModel->setQuery("SELECT IdGRP FROM Groupe");
    addNoteUi.groupeNote->clear();
    addNoteUi.groupeNote->addItem("Select Groupe");
    int rowCount = groupModel->rowCount();
    for (int i = 0; i < rowCount; ++i) {
        QString idgrp = groupModel->record(i).value("IdGRP").toString();
        addNoteUi.groupeNote->addItem(QString("%1").arg(idgrp));
    }
}

void MainWindow::populateGroupeModuleComboBox(const QString &selectedText)
{
    if (selectedText == "Select Groupe") {
        addNoteUi.GMNote->hide();
    } else {
        // Show the groupeModule combo box
        addNoteUi.GMNote->show();

        QSqlQueryModel *moduleModel = new QSqlQueryModel();
        moduleModel->setQuery("SELECT GroupeModule.IdGm,GroupeModule.NomGm "
                              "FROM GroupeModule "
                              "INNER JOIN Liste_Groupe_GM ON GroupeModule.IdGm = Liste_Groupe_GM.IdGm "
                              "WHERE Liste_Groupe_GM.IdGRP = '" + selectedText + "'");
        addNoteUi.GMNote->clear();
        addNoteUi.GMNote->addItem("Select Groupe Module");
        int rowCount = moduleModel->rowCount();
        qDebug()<<"Row count gm : "<<rowCount;
        for (int i = 0; i < rowCount; ++i) {
            QString idGmN = moduleModel->record(i).value("IdGm").toString();
            QString NomGm = moduleModel->record(i).value("NomGm").toString();
            addNoteUi.GMNote->addItem(QString("%1 - %2").arg(idGmN).arg(NomGm));
        }
    }
}

void MainWindow::populateStudentComboBox(const QString &selectedText)
{
    if (selectedText == "Select Groupe") {
        addNoteUi.EtuNote->hide();
    } else {
        addNoteUi.EtuNote->show();

        QSqlQueryModel *studentModel = new QSqlQueryModel();
        studentModel->setQuery("SELECT Etudiant.num_insc, Etudiant.nom, Etudiant.prenom "
                               "FROM Etudiant "
                               "INNER JOIN Liste_Groupe_ETU ON Etudiant.num_insc = Liste_Groupe_ETU.numinsc "
                               "WHERE Liste_Groupe_ETU.IdGRP = '" + selectedText + "'");
        addNoteUi.EtuNote->clear();
        addNoteUi.EtuNote->addItem("Select Student");
        int rowCount = studentModel->rowCount();
        qDebug() << "Row count student: " << rowCount;
        for (int i = 0; i < rowCount; ++i) {
            int num_insc = studentModel->record(i).value("num_insc").toInt();
            QString nom = studentModel->record(i).value("nom").toString();
            QString prenom = studentModel->record(i).value("prenom").toString();
            addNoteUi.EtuNote->addItem(QString("%1 - %2 %3").arg(num_insc).arg(nom).arg(prenom));
        }
    }
}

void MainWindow::populateMatiereComboBox(const QString &selectedText)
{
    if (selectedText == "Select Groupe Module") {
        addNoteUi.MatNote->hide();
    } else {
        addNoteUi.MatNote->show();
        QString selectedText = addNoteUi.GMNote->currentText();
        QString idGm = selectedText.section(" - ", 0, 0);

        QSqlQueryModel *matiereModel = new QSqlQueryModel();
        matiereModel->setQuery("SELECT Matiere.idmat,Matiere.nom "
                               "FROM Matiere "
                               "INNER JOIN Liste_Matiere ON Matiere.idmat = Liste_Matiere.IdMat "
                               "WHERE Liste_Matiere.IdGm = '" + idGm + "'");
        addNoteUi.MatNote->clear();
        addNoteUi.MatNote->addItem("Select Matiere");
        int rowCount = matiereModel->rowCount();
        qDebug()<<"Row count mat : "<<rowCount;
        for (int i = 0; i < rowCount; ++i) {
            QString matiereid = matiereModel->record(i).value("idmat").toString();
            QString matiereName = matiereModel->record(i).value("nom").toString();
            addNoteUi.MatNote->addItem(QString("%1 - %2").arg(matiereid).arg(matiereName));
        }
    }
}

void MainWindow::populateTypeComboBox(const QString &selectedText)
{
    if (selectedText == "Select Matiere") {
        addNoteUi.TypeNote->hide();
        addNoteUi.note_2->hide();
    } else {
        addNoteUi.TypeNote->show();
        addNoteUi.note_2->show();
    }
}

void MainWindow::on_addNoteButton_clicked()
{
    QSqlQuery createTableQuery;
    if (!createTableQuery.exec("CREATE TABLE IF NOT EXISTS Note ("
                               "Mat TEXT,"
                               "Etu number(5),"
                               "Note REAL,"
                               "Type TEXT,"
                               "PRIMARY KEY (Mat, Etu, Type),"
                               "FOREIGN KEY (Mat) REFERENCES Matiere(idmat),"
                               "FOREIGN KEY (Etu) REFERENCES Etudiant(num_insc));")) {
        qDebug() << "Error creating table:" << createTableQuery.lastError().text();
        return;
    } else {
        qDebug() << "Table Note created successfully";
    }

    QString idGRP =addNoteUi.groupeNote->currentText();
    if (idGRP=="Select Groupe") {
        QMessageBox::critical(this, "Error", "Choose a groupe");
        return;
    }

    QString numinscString =addNoteUi.EtuNote->currentText();
    if (numinscString=="Select Student") {
        QMessageBox::critical(this, "Error", "Choose a student");
        return;
    }
    //numinscString.toInt();

    QString idGmString =addNoteUi.GMNote->currentText();
    if (idGmString=="Select Groupe Module") {
        QMessageBox::critical(this, "Error", "Choose a groupe module");
        return;
    }

    QString idMatString =addNoteUi.MatNote->currentText();
    if (idMatString=="Select Matiere") {
        QMessageBox::critical(this, "Error", "Choose a matiere");
        return;
    }

    QString Type =addNoteUi.TypeNote->currentText();
    qDebug() << "Type:" << Type;
    if (Type=="Select Type") {
        QMessageBox::critical(this, "Error", "Choose a type");
        return;
    }

    double Note =addNoteUi.note->value();
    int numinsc = numinscString.section(" - ", 0, 0).toInt();
    QString idMat = idMatString.section(" - ", 0, 0);
    // QString idGm = idGmString.section(" - ", 0, 0);

    QSqlQuery insertQuery;
    insertQuery.prepare("INSERT INTO Note (Mat, Etu, Note, Type) VALUES (:Mat, :Etu, :Note, :Type)");
    insertQuery.bindValue(":Mat", idMat); // Assuming selectedMat corresponds to Mat
    insertQuery.bindValue(":Etu", numinsc); // Binding student's numinsc
    insertQuery.bindValue(":Note", Note); // Binding entered note value
    insertQuery.bindValue(":Type", Type); // Binding selected note type

    if (!insertQuery.exec()) {
        qDebug() << "Error inserting data:" << insertQuery.lastError().text();
    } else {
        qDebug() << "Note Data inserted successfully";
        // QDialog* dialog = qobject_cast<QDialog*>(sender()->parent());
        // if (dialog)
        //     dialog->accept();
        populateTableNote();
        QMessageBox::information(this, "Success", "Note added successfully");
    }
}


void MainWindow::on_modifyNote_clicked()
{
    QDialog dialog;
    modifyNoteUi.setupUi(&dialog);
    dialog.setWindowTitle("Grade management");
    dialog.setWindowIcon(QIcon("D:/Pi/CPP/qt/logopi.jpg"));
    connect(modifyNoteUi.cancelNoteButton, &QPushButton::clicked, &dialog, &QDialog::reject);
    // connect(addNoteUi.groupeNote, &QComboBox::currentTextChanged, this, &MainWindow::populateGroupeModuleComboBox);
    // connect(addNoteUi.groupeNote, &QComboBox::currentTextChanged, this, &MainWindow::populateStudentComboBox);
    // connect(addNoteUi.GMNote, &QComboBox::currentTextChanged, this, &MainWindow::populateMatiereComboBox);
    // connect(addNoteUi.MatNote, &QComboBox::currentTextChanged, this, &MainWindow::populateTypeComboBox);
    connect(modifyNoteUi.tableUpdateNote, &QTableView::clicked, this, &MainWindow::displaySelectedNote);
    connect(modifyNoteUi.clearNoteButton, &QPushButton::clicked, this, &MainWindow::on_clearNoteButton_clicked);
    connect(modifyNoteUi.deleteNoteButton, &QPushButton::clicked, this, &MainWindow::on_deleteNoteButton_clicked);
    connect(modifyNoteUi.updateNoteButton, &QPushButton::clicked, this, &MainWindow::on_updateNoteButton_clicked);

    populateTableUpdateNote();
    modifyNoteUi.updateNoteButton->hide();
    modifyNoteUi.deleteNoteButton->hide();
    modifyNoteUi.clearNoteButton->hide();
    if (dialog.exec() == QDialog::Accepted) {

    } else {

    }
}

void MainWindow::searchNote(const QString &text)
{
    QSqlQuery query;
    QString queryString = "SELECT * FROM Note WHERE MAT LIKE :search OR ETU LIKE :search OR Note LIKE :search OR Type LIKE :search";
    query.prepare(queryString);
    query.bindValue(":search", "%" + text + "%");

    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return;
    }

    QSqlQueryModel *model = new QSqlQueryModel(); // Create a new model
    model->setQuery(std::move(query)); // Move the query to setQuery

    ui->tableViewNote->setModel(model);
}
void MainWindow::on_searchBarNote_textChanged(const QString &arg1)
{
    searchNote(arg1);
}

void MainWindow::populateTableUpdateNote()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM Note");

    modifyNoteUi.tableUpdateNote->setModel(model);
    customizeTableViewUpdateNote();
}

void MainWindow::customizeTableViewUpdateNote()
{
    modifyNoteUi.tableUpdateNote->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    modifyNoteUi.tableUpdateNote->horizontalHeader()->resizeSection(0, 102);

    modifyNoteUi.tableUpdateNote->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
    modifyNoteUi.tableUpdateNote->horizontalHeader()->resizeSection(1, 102);

    modifyNoteUi.tableUpdateNote->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed);
    modifyNoteUi.tableUpdateNote->horizontalHeader()->resizeSection(2, 102);

    modifyNoteUi.tableUpdateNote->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Fixed);
    modifyNoteUi.tableUpdateNote->horizontalHeader()->resizeSection(3, 102);
}

void MainWindow::displaySelectedNote(const QModelIndex &index)
{
    int row = index.row();

    QSqlQueryModel *model = qobject_cast<QSqlQueryModel*>( modifyNoteUi.tableUpdateNote->model());
    QString idmat = model->data(model->index(row, 0)).toString();
    QString etu = model->data(model->index(row, 1)).toString();
    double note = model->data(model->index(row, 2)).toDouble();
    QString type = model->data(model->index(row, 3)).toString();



    modifyNoteUi.mat->setText(idmat);
    modifyNoteUi.etu->setText(etu);
    modifyNoteUi.type->setText(type);
    modifyNoteUi.note->setValue(note);

    modifyNoteUi.updateNoteButton->show();
    modifyNoteUi.deleteNoteButton->show();
    modifyNoteUi.clearNoteButton->show();
    modifyNoteUi.deleteNoteButton->setIcon(QIcon("D:/Pi/CPP/qt/delete.svg"));
    modifyNoteUi.deleteNoteButton->setStyleSheet("QPushButton:hover { color: black; background-color: red; }");
    modifyNoteUi.updateNoteButton->setIcon(QIcon("D:/Pi/CPP/qt/edit.svg"));
    modifyNoteUi.clearNoteButton->setIcon(QIcon("D:/Pi/CPP/qt/clear.svg"));
}

void MainWindow::clearLineEditsNote()
{
    modifyNoteUi.mat->clear();
    modifyNoteUi.etu->clear();
    modifyNoteUi.type->clear();
    modifyNoteUi.note->clear();
}

void MainWindow::on_clearNoteButton_clicked()
{
    clearLineEditsNote();
    modifyNoteUi.updateNoteButton->hide();
    modifyNoteUi.deleteNoteButton->hide();
    modifyNoteUi.clearNoteButton->hide();
}

void MainWindow::deleteNote()
{
    int numinsc = modifyNoteUi.etu->text().toInt();
    QString idMat = modifyNoteUi.mat->text();
    QString type = modifyNoteUi.type->text();

    QMessageBox::StandardButton reply = QMessageBox::critical(this, "Delete Note",
                                                              "Are you sure you want to delete this note?",
                                                              QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::No){
        return;
    }

    QSqlQuery deleteQuery;
    deleteQuery.prepare("DELETE FROM Note WHERE ETU = :num_insc AND Type=:type AND MAT=:idmat");
    deleteQuery.bindValue(":num_insc", numinsc);
    deleteQuery.bindValue(":type", type);
    deleteQuery.bindValue(":idmat", idMat);

    if (!deleteQuery.exec()) {
        qDebug() << "Error deleting data:" << deleteQuery.lastError().text();
    } else {
        qDebug() << "Note Data deleted successfully";
        CalculMoyMat();
        populateTableNote();
        populateTableUpdateNote();
        clearLineEditsNote();
    }
}

void MainWindow::on_deleteNoteButton_clicked()
{
    deleteNote();
    modifyNoteUi.updateNoteButton->hide();
    modifyNoteUi.deleteNoteButton->hide();
    modifyNoteUi.clearNoteButton->hide();
}

void MainWindow::UpdateNote() {
    int etu = modifyNoteUi.etu->text().toInt();
    QString mat = modifyNoteUi.mat->text();
    QString type = modifyNoteUi.type->text();
    double note =modifyNoteUi.note->value();

    // if (nom.isEmpty() || prenom.isEmpty() || mail.isEmpty()) {
    //     QMessageBox::critical(this, "Error", "Please fill in all fields");
    //     return;
    // }

    QSqlQuery updateQuery;
    updateQuery.prepare("UPDATE Note SET Note = :note WHERE Etu = :etu AND Mat =:mat AND Type =:type");
    updateQuery.bindValue(":etu", etu);
    updateQuery.bindValue(":mat", mat);
    updateQuery.bindValue(":type", type);
    updateQuery.bindValue(":note", note);

    if (!updateQuery.exec()) {
        qDebug() << "Error updating data:" << updateQuery.lastError().text();
    } else {
        qDebug() << "Data updated successfully";
        CalculMoyMat();
        populateTableNote();
        populateTableUpdateNote();
        clearLineEditsNote();
    }
}

void MainWindow::on_updateNoteButton_clicked()
{
    UpdateNote();
    modifyNoteUi.updateNoteButton->hide();
    modifyNoteUi.deleteNoteButton->hide();
    modifyNoteUi.clearNoteButton->hide();
}

//********************************* Moyenne **********************************************************

void MainWindow::CalculMoyMat()
{
    QSqlQuery clearQuery("DELETE FROM moyMat");
    if (!clearQuery.exec()) {
        qDebug() << "Error clearing MoyMat table:" << clearQuery.lastError().text();
        return;
    }
    QSqlQuery query;
    query.prepare("CREATE TABLE IF NOT EXISTS moyMat ("
                  "numinsc INTEGER,"
                  "IdMat TEXT,"
                  "Moy REAL,"
                  "PRIMARY KEY (numinsc, IdMat),"
                  "FOREIGN KEY (numinsc) REFERENCES Etudiant(num_insc),"
                  "FOREIGN KEY (IdMat) REFERENCES Matiere(idmat)"
                  ")");
    if (!query.exec()) {
        qDebug() << "Error creating table MoyMat:" << query.lastError().text();
        return; // Exit if table creation fails
    } else {
        qDebug() << "MoyMat table created successfully!";
    }

    QSqlQuery updateQuery;
    updateQuery.prepare("INSERT OR REPLACE INTO moyMat (numinsc, IdMat, Moy) "
                        "SELECT Etu, Mat, round(AVG(Note),2) "
                        "FROM Note "
                        "GROUP BY Etu, Mat");

    if (!updateQuery.exec()) {
        qDebug() << "Error updating average MoyMat for all students:" << updateQuery.lastError().text();
    } else {
        qDebug() << "Average MoyMat updated successfully for all students";
    }
    // Create the moyMat table if it doesn't exist
    /*QSqlQuery createTableQuery("CREATE TABLE IF NOT EXISTS moyMat (Mat TEXT, Etu INTEGER, Average REAL)");
    if (!createTableQuery.exec()) {
        qDebug() << "Error creating moyMat table:" << createTableQuery.lastError().text();
        return; // Exit the function if table creation fails
    }

    QSqlQuery distinctQuery("SELECT DISTINCT Mat, Etu FROM Note");

    while (distinctQuery.next()) {
        QString mat = distinctQuery.value(0).toString();
        int etu = distinctQuery.value(1).toInt();

        QSqlQuery avgQuery;
        avgQuery.prepare("SELECT AVG(Note) FROM Note WHERE Mat = :mat AND Etu = :etu");
        avgQuery.bindValue(":mat", mat);
        avgQuery.bindValue(":etu", etu);
        if (!avgQuery.exec()) {
            qDebug() << "Error calculating average:" << avgQuery.lastError().text();
            continue; // Skip to the next combination if an error occurs
        }

        if (avgQuery.next()) {
            double average = avgQuery.value(0).toDouble();
            qDebug() << "Mat:" << mat;
            qDebug() << "Etu:" << etu;
            qDebug() << "Average:" << average;

            // Check if the combination of Mat and Etu already exists in moyMat table
            QSqlQuery checkQuery;
            checkQuery.prepare("SELECT COUNT(*) FROM moyMat WHERE Mat = :mat AND Etu = :etu");
            checkQuery.bindValue(":mat", mat);
            checkQuery.bindValue(":etu", etu);
            if (!checkQuery.exec()) {
                qDebug() << "Error checking for existing row in moyMat:" << checkQuery.lastError().text();
                continue; // Skip to the next combination if an error occurs
            }

            checkQuery.next();
            int rowCount = checkQuery.value(0).toInt();
            if (rowCount > 0) {
                // If the row already exists, update the existing row
                QSqlQuery updateQuery;
                updateQuery.prepare("UPDATE moyMat SET Average = :average WHERE Mat = :mat AND Etu = :etu");
                updateQuery.bindValue(":average", average);
                updateQuery.bindValue(":mat", mat);
                updateQuery.bindValue(":etu", etu);
                if (!updateQuery.exec()) {
                    qDebug() << "Error updating moyMat:" << updateQuery.lastError().text();
                    continue; // Skip to the next combination if an error occurs
                }
            } else {
                // If the row doesn't exist, insert a new row
                QSqlQuery insertQuery;
                insertQuery.prepare("INSERT INTO moyMat (Mat, Etu, Average) VALUES (:mat, :etu, :average)");
                insertQuery.bindValue(":mat", mat);
                insertQuery.bindValue(":etu", etu);
                insertQuery.bindValue(":average", average);
                if (!insertQuery.exec()) {
                    qDebug() << "Error inserting average into moyMat:" << insertQuery.lastError().text();
                    continue; // Skip to the next combination if an error occurs
                }
            }
        }
    }*/
    populateTableWithMoyMat();
}

void MainWindow::CalculMoyGM()
{
    QSqlQuery clearQuery("DELETE FROM MoyGm");
    if (!clearQuery.exec()) {
        qDebug() << "Error clearing MoyGm table:" << clearQuery.lastError().text();
        return;
    }
    QSqlQuery query;
    query.prepare("CREATE TABLE IF NOT EXISTS MoyGm ("
                  "numinsc INTEGER,"
                  "IdGm TEXT,"
                  "Moy REAL,"
                  "PRIMARY KEY (numinsc, IdGm),"
                  "FOREIGN KEY (numinsc) REFERENCES Etudiant(num_insc),"
                  "FOREIGN KEY (IdGm) REFERENCES GroupeModule(IdGm)"
                  ")");
    if (!query.exec()) {
        qDebug() << "Error creating table MoyGm:" << query.lastError().text();
        return;
    } else {
        qDebug() << "MoyGm table created successfully!";
    }

    QSqlQuery updateQuery;
    updateQuery.prepare("INSERT OR REPLACE INTO MoyGm (numinsc, IdGm, Moy) "
                        "SELECT LG.numinsc, LM.IdGm, round(SUM(MM.Moy * M.coef) / SUM(M.coef),2) "
                        "FROM Liste_Groupe_ETU AS LG "
                        "JOIN moyMat AS MM ON LG.numinsc = MM.numinsc "
                        "JOIN Matiere AS M ON MM.IdMat = M.idmat "
                        "JOIN Liste_Matiere AS LM ON MM.IdMat = LM.IdMat "
                        "GROUP BY LG.numinsc, LM.IdGm");
    if (!updateQuery.exec()) {
        qDebug() << "Error updating average MoyGm for all students:" << updateQuery.lastError().text();
    } else {
        qDebug() << "Average MoyGm updated successfully for all students";
    }
    populateTableWithMoyGM();
}

void MainWindow::CalculMoyG()
{
    QSqlQuery clearQuery("DELETE FROM MoyGenerale");
    if (!clearQuery.exec()) {
        qDebug() << "Error clearing MoyGenerale table:" << clearQuery.lastError().text();
        return;
    }
    QSqlQuery query;
    query.prepare("CREATE TABLE IF NOT EXISTS MoyGenerale ("
                  "numinsc INTEGER,"
                  "Moy REAL,"
                  "Resultat TEXT,"
                  "Mention TEXT,"
                  "PRIMARY KEY (numinsc),"
                  "FOREIGN KEY (numinsc) REFERENCES Etudiant(num_insc)"
                  ")");
    if (!query.exec()) {
        qDebug() << "Error creating table MoyGenerale:" << query.lastError().text();
        return; // Exit if table creation fails
    } else {
        qDebug() << "MoyGenerale table created successfully!";
    }

    // Prepare SQL query to calculate and update the general average MoyGenerale for each student
    QSqlQuery updateQuery;
    updateQuery.prepare("INSERT OR REPLACE INTO MoyGenerale (numinsc, Moy, Resultat, Mention) "
                        "SELECT numinsc, round(SUM(Moy * CoefGm) / SUM(CoefGm),2), "
                        "CASE WHEN SUM(Moy * CoefGm) / SUM(CoefGm) > 10 THEN 'Admis' ELSE 'Ajourné' END, "
                        "CASE "
                        "WHEN SUM(Moy * CoefGm) / SUM(CoefGm) >= 18 THEN 'Excellent' "
                        "WHEN SUM(Moy * CoefGm) / SUM(CoefGm) >= 16 THEN 'Très Bien' "
                        "WHEN SUM(Moy * CoefGm) / SUM(CoefGm) >= 14 THEN 'Bien' "
                        "WHEN SUM(Moy * CoefGm) / SUM(CoefGm) >= 12 THEN 'Assez Bien' "
                        "WHEN SUM(Moy * CoefGm) / SUM(CoefGm) >= 10 THEN 'Passable' "
                        "ELSE '' END "
                        "FROM MoyGm "
                        "JOIN GroupeModule ON MoyGm.IdGm = GroupeModule.IdGm "
                        "GROUP BY numinsc");

    if (!updateQuery.exec()) {
        // If an error occurs while executing the query, print an error message
        qDebug() << "Error updating general average MoyGenerale for all students:" << updateQuery.lastError().text();
    } else {
        qDebug() << "General average MoyGenerale updated successfully for all students";
    }
    populateTableWithMoyG();
}

//********************************* PV *******************************************************
void MainWindow::on_returnBackPV_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::customizeTableViewMoyMat()
{
    ui->MoyMat->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    ui->MoyMat->horizontalHeader()->resizeSection(0, 123);

    ui->MoyMat->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
    ui->MoyMat->horizontalHeader()->resizeSection(1, 123);

    ui->MoyMat->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed);
    ui->MoyMat->horizontalHeader()->resizeSection(2, 123);
}

void MainWindow::populateTableWithMoyMat()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM moyMat");
    ui->MoyMat->setModel(model);
    customizeTableViewMoyMat();
}

void MainWindow::customizeTableViewMoyGM()
{
    ui->MoyGM->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    ui->MoyGM->horizontalHeader()->resizeSection(0, 120);

    ui->MoyGM->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
    ui->MoyGM->horizontalHeader()->resizeSection(1, 120);

    ui->MoyGM->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed);
    ui->MoyGM->horizontalHeader()->resizeSection(2, 119);
}

void MainWindow::populateTableWithMoyGM()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM MoyGM");
    ui->MoyGM->setModel(model);
    customizeTableViewMoyGM();
}

void MainWindow::customizeTableViewMoyG()
{
    ui->MoyG->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    ui->MoyG->horizontalHeader()->resizeSection(0, 190);

    ui->MoyG->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
    ui->MoyG->horizontalHeader()->resizeSection(1, 190);

    ui->MoyG->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed);
    ui->MoyG->horizontalHeader()->resizeSection(2, 190);

    ui->MoyG->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Fixed);
    ui->MoyG->horizontalHeader()->resizeSection(3, 189);
}

void MainWindow::populateTableWithMoyG()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM MoyGenerale");
    ui->MoyG->setModel(model);
    customizeTableViewMoyG();
}
