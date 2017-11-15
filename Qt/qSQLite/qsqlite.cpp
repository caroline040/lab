#include "qsqlite.h"
#include "ui_qsqlite.h"

qSQLite::qSQLite(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::qSQLite)
{
    ui->setupUi(this);
}

qSQLite::~qSQLite()
{
    delete ui;
}
