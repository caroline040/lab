#ifndef QSQLITE_H
#define QSQLITE_H

#include <QMainWindow>

namespace Ui {
class qSQLite;
}

class qSQLite : public QMainWindow
{
    Q_OBJECT

public:
    explicit qSQLite(QWidget *parent = 0);
    ~qSQLite();

private:
    Ui::qSQLite *ui;
};

#endif // QSQLITE_H
