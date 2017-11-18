/********************************************************************************
** Form generated from reading UI file 'controller.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLLER_H
#define UI_CONTROLLER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_controller
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *btnF1;
    QPushButton *btnStart1;
    QPlainTextEdit *plainTextEdit;
    QPushButton *btnF3;
    QProgressBar *progressBar1;
    QLabel *label;
    QPushButton *btnF2;
    QPushButton *btnTerm1;
    QPushButton *btnF4;
    QPushButton *btnTerm2;
    QProgressBar *progressBar2;
    QPushButton *btnStart2;

    void setupUi(QWidget *controller)
    {
        if (controller->objectName().isEmpty())
            controller->setObjectName(QStringLiteral("controller"));
        controller->resize(431, 308);
        gridLayoutWidget = new QWidget(controller);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 0, 414, 301));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        btnF1 = new QPushButton(gridLayoutWidget);
        btnF1->setObjectName(QStringLiteral("btnF1"));

        gridLayout->addWidget(btnF1, 0, 3, 1, 1);

        btnStart1 = new QPushButton(gridLayoutWidget);
        btnStart1->setObjectName(QStringLiteral("btnStart1"));

        gridLayout->addWidget(btnStart1, 0, 0, 2, 1);

        plainTextEdit = new QPlainTextEdit(gridLayoutWidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));

        gridLayout->addWidget(plainTextEdit, 5, 0, 1, 4);

        btnF3 = new QPushButton(gridLayoutWidget);
        btnF3->setObjectName(QStringLiteral("btnF3"));

        gridLayout->addWidget(btnF3, 2, 3, 1, 1);

        progressBar1 = new QProgressBar(gridLayoutWidget);
        progressBar1->setObjectName(QStringLiteral("progressBar1"));
        progressBar1->setValue(24);

        gridLayout->addWidget(progressBar1, 0, 1, 2, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 4, 0, 1, 4);

        btnF2 = new QPushButton(gridLayoutWidget);
        btnF2->setObjectName(QStringLiteral("btnF2"));

        gridLayout->addWidget(btnF2, 1, 3, 1, 1);

        btnTerm1 = new QPushButton(gridLayoutWidget);
        btnTerm1->setObjectName(QStringLiteral("btnTerm1"));

        gridLayout->addWidget(btnTerm1, 0, 2, 2, 1);

        btnF4 = new QPushButton(gridLayoutWidget);
        btnF4->setObjectName(QStringLiteral("btnF4"));

        gridLayout->addWidget(btnF4, 3, 3, 1, 1);

        btnTerm2 = new QPushButton(gridLayoutWidget);
        btnTerm2->setObjectName(QStringLiteral("btnTerm2"));

        gridLayout->addWidget(btnTerm2, 2, 2, 2, 1);

        progressBar2 = new QProgressBar(gridLayoutWidget);
        progressBar2->setObjectName(QStringLiteral("progressBar2"));
        progressBar2->setValue(24);

        gridLayout->addWidget(progressBar2, 2, 1, 2, 1);

        btnStart2 = new QPushButton(gridLayoutWidget);
        btnStart2->setObjectName(QStringLiteral("btnStart2"));

        gridLayout->addWidget(btnStart2, 2, 0, 2, 1);


        retranslateUi(controller);

        QMetaObject::connectSlotsByName(controller);
    } // setupUi

    void retranslateUi(QWidget *controller)
    {
        controller->setWindowTitle(QApplication::translate("controller", "controller", 0));
        btnF1->setText(QApplication::translate("controller", "\345\212\237\350\203\2751", 0));
        btnStart1->setText(QApplication::translate("controller", "\347\272\277\347\250\2131\345\274\200\345\247\213", 0));
        btnF3->setText(QApplication::translate("controller", "\345\212\237\350\203\2751", 0));
        label->setText(QApplication::translate("controller", "\345\220\216\345\217\260\344\277\241\346\201\257", 0));
        btnF2->setText(QApplication::translate("controller", "\345\212\237\350\203\2752(run)", 0));
        btnTerm1->setText(QApplication::translate("controller", "\345\274\272\345\210\266\347\273\210\346\255\242", 0));
        btnF4->setText(QApplication::translate("controller", "\345\212\237\350\203\2752(run)", 0));
        btnTerm2->setText(QApplication::translate("controller", "\346\255\243\345\270\270\347\273\210\346\255\242", 0));
        btnStart2->setText(QApplication::translate("controller", "\347\272\277\347\250\2132\345\274\200\345\247\213", 0));
    } // retranslateUi

};

namespace Ui {
    class controller: public Ui_controller {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLLER_H
