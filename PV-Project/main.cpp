#include "mainwindow.h"
#include "databasemanager.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    // w.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    // w.showFullScreen();
    QObject::connect(&a, &QApplication::aboutToQuit, [&]() {
        QSqlDatabase db = DatabaseManager::instance().database();
        if (db.isOpen()) {
            db.close();
            qDebug() << "Database connection closed";
        } else {
            qDebug() << "Database connection already closed";
        }
    });
    // QSqlQuery createleQuery;
    // if (!createleQuery.exec("drop table MoyGm ;")) {
    //     qDebug() << "Error creating table:" << createleQuery.lastError().text();

    // } else {
    //     qDebug() << "Table Matiere droped successfully";
    // }

    return a.exec();
}
