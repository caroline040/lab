#ifndef FILEATTRIBUTE_H
#define FILEATTRIBUTE_H

#include <QDialog>

namespace Ui {
class fileAttribute;
}

class fileAttribute : public QDialog
{
    Q_OBJECT

public:
    explicit fileAttribute(QWidget *parent = 0);
    ~fileAttribute();

private:
    Ui::fileAttribute *ui;

private slots:
    void getFileName();
    void getFileAttr();
};

#endif // FILEATTRIBUTE_H
