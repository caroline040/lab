#include "qsqlite.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qSQLite w;
    w.show();

    return a.exec();
}
