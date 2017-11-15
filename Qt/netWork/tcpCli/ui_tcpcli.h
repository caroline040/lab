/********************************************************************************
** Form generated from reading UI file 'tcpcli.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPCLI_H
#define UI_TCPCLI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tcpCli
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *lineEditServerIP;
    QLineEdit *lineEdit;
    QLabel *label;
    QPushButton *pushButtonSend;
    QLineEdit *lineEditPort;
    QLabel *label_2;
    QLabel *label_3;
    QListWidget *listWidget;
    QLineEdit *lineEditUsername;
    QPushButton *pushButtonEnter;

    void setupUi(QDialog *tcpCli)
    {
        if (tcpCli->objectName().isEmpty())
            tcpCli->setObjectName(QStringLiteral("tcpCli"));
        tcpCli->resize(432, 363);
        gridLayoutWidget = new QWidget(tcpCli);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 411, 341));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lineEditServerIP = new QLineEdit(gridLayoutWidget);
        lineEditServerIP->setObjectName(QStringLiteral("lineEditServerIP"));

        gridLayout->addWidget(lineEditServerIP, 3, 1, 1, 1);

        lineEdit = new QLineEdit(gridLayoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout->addWidget(lineEdit, 1, 0, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 2, 0, 1, 1, Qt::AlignHCenter);

        pushButtonSend = new QPushButton(gridLayoutWidget);
        pushButtonSend->setObjectName(QStringLiteral("pushButtonSend"));

        gridLayout->addWidget(pushButtonSend, 1, 1, 1, 1);

        lineEditPort = new QLineEdit(gridLayoutWidget);
        lineEditPort->setObjectName(QStringLiteral("lineEditPort"));

        gridLayout->addWidget(lineEditPort, 4, 1, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 3, 0, 1, 1, Qt::AlignHCenter);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 4, 0, 1, 1, Qt::AlignHCenter);

        listWidget = new QListWidget(gridLayoutWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        gridLayout->addWidget(listWidget, 0, 0, 1, 2);

        lineEditUsername = new QLineEdit(gridLayoutWidget);
        lineEditUsername->setObjectName(QStringLiteral("lineEditUsername"));

        gridLayout->addWidget(lineEditUsername, 2, 1, 1, 1);

        pushButtonEnter = new QPushButton(gridLayoutWidget);
        pushButtonEnter->setObjectName(QStringLiteral("pushButtonEnter"));

        gridLayout->addWidget(pushButtonEnter, 5, 0, 1, 2);


        retranslateUi(tcpCli);

        QMetaObject::connectSlotsByName(tcpCli);
    } // setupUi

    void retranslateUi(QDialog *tcpCli)
    {
        tcpCli->setWindowTitle(QApplication::translate("tcpCli", "tcpCli", 0));
        label->setText(QApplication::translate("tcpCli", "\347\224\250\346\210\267\345\220\215", 0));
        pushButtonSend->setText(QApplication::translate("tcpCli", "\345\217\221\351\200\201", 0));
        label_2->setText(QApplication::translate("tcpCli", "\346\234\215\345\212\241\345\231\250\345\234\260\345\235\200", 0));
        label_3->setText(QApplication::translate("tcpCli", "\347\253\257\345\217\243\345\217\267", 0));
        pushButtonEnter->setText(QApplication::translate("tcpCli", "\350\277\233\347\276\244", 0));
    } // retranslateUi

};

namespace Ui {
    class tcpCli: public Ui_tcpCli {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPCLI_H
