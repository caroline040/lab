/********************************************************************************
** Form generated from reading UI file 'httpinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HTTPINFO_H
#define UI_HTTPINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HttpInfo
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *dataLebel;
    QSpacerItem *horizontalSpacer;
    QLabel *label_4;
    QLabel *timeLabel;
    QPushButton *getTimeBt;
    QHBoxLayout *horizontalLayout_3;
    QTextEdit *textEdit;
    QPushButton *getWeatherBt;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLabel *addressLabel;
    QPushButton *getAddressBt;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *HttpInfo)
    {
        if (HttpInfo->objectName().isEmpty())
            HttpInfo->setObjectName(QStringLiteral("HttpInfo"));
        HttpInfo->resize(762, 435);
        centralWidget = new QWidget(HttpInfo);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        dataLebel = new QLabel(centralWidget);
        dataLebel->setObjectName(QStringLiteral("dataLebel"));

        horizontalLayout->addWidget(dataLebel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout->addWidget(label_4);

        timeLabel = new QLabel(centralWidget);
        timeLabel->setObjectName(QStringLiteral("timeLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(timeLabel->sizePolicy().hasHeightForWidth());
        timeLabel->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(timeLabel);


        horizontalLayout_2->addLayout(horizontalLayout);

        getTimeBt = new QPushButton(centralWidget);
        getTimeBt->setObjectName(QStringLiteral("getTimeBt"));

        horizontalLayout_2->addWidget(getTimeBt);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        horizontalLayout_3->addWidget(textEdit);

        getWeatherBt = new QPushButton(centralWidget);
        getWeatherBt->setObjectName(QStringLiteral("getWeatherBt"));

        horizontalLayout_3->addWidget(getWeatherBt);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_4->addWidget(label_5);

        addressLabel = new QLabel(centralWidget);
        addressLabel->setObjectName(QStringLiteral("addressLabel"));

        horizontalLayout_4->addWidget(addressLabel);

        getAddressBt = new QPushButton(centralWidget);
        getAddressBt->setObjectName(QStringLiteral("getAddressBt"));

        horizontalLayout_4->addWidget(getAddressBt);


        verticalLayout->addLayout(horizontalLayout_4);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        HttpInfo->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(HttpInfo);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 762, 23));
        HttpInfo->setMenuBar(menuBar);
        mainToolBar = new QToolBar(HttpInfo);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        HttpInfo->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(HttpInfo);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        HttpInfo->setStatusBar(statusBar);

        retranslateUi(HttpInfo);

        QMetaObject::connectSlotsByName(HttpInfo);
    } // setupUi

    void retranslateUi(QMainWindow *HttpInfo)
    {
        HttpInfo->setWindowTitle(QApplication::translate("HttpInfo", "HttpInfo", 0));
        label->setText(QApplication::translate("HttpInfo", "\346\227\245\346\234\237\357\274\232", 0));
        dataLebel->setText(QApplication::translate("HttpInfo", "2016-5-25", 0));
        label_4->setText(QApplication::translate("HttpInfo", "\346\227\266\351\227\264\357\274\232", 0));
        timeLabel->setText(QApplication::translate("HttpInfo", "00\357\274\23200\357\274\23200", 0));
        getTimeBt->setText(QApplication::translate("HttpInfo", "getTime", 0));
        getWeatherBt->setText(QApplication::translate("HttpInfo", "getWeather", 0));
        label_5->setText(QApplication::translate("HttpInfo", "\345\237\216\345\270\202\357\274\232", 0));
        addressLabel->setText(QApplication::translate("HttpInfo", "----------------------", 0));
        getAddressBt->setText(QApplication::translate("HttpInfo", "getAddress", 0));
    } // retranslateUi

};

namespace Ui {
    class HttpInfo: public Ui_HttpInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HTTPINFO_H
