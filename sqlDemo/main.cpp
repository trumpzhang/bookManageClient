#include <QApplication>
#include"test.h"
#include"login.h"


#include<QSqlDatabase>
#include<QDebug>
#include<QMessageBox>
#include<QSqlError>
#include<QSqlTableModel>
#include<QSqlRecord>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    test t;
//    t.show();
    login l;
    l.show();

    return a.exec();
}
