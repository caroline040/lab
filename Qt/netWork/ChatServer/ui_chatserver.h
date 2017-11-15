/********************************************************************************
** Form generated from reading UI file 'chatserver.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATSERVER_H
#define UI_CHATSERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatServer
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QToolBox *toolBox;
    QWidget *page;
    QListWidget *onLineList;
    QWidget *page_2;
    QListWidget *offLineList;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QListWidget *recvList;
    QTextEdit *sendEidt;
    QHBoxLayout *horizontalLayout;
    QPushButton *sendBt;
    QSpacerItem *horizontalSpacer;
    QPushButton *clearBt;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ChatServer)
    {
        if (ChatServer->objectName().isEmpty())
            ChatServer->setObjectName(QStringLiteral("ChatServer"));
        ChatServer->resize(638, 508);
        centralWidget = new QWidget(ChatServer);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        toolBox = new QToolBox(centralWidget);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        toolBox->setMaximumSize(QSize(200, 16777215));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        page->setGeometry(QRect(0, 0, 200, 404));
        onLineList = new QListWidget(page);
        onLineList->setObjectName(QStringLiteral("onLineList"));
        onLineList->setGeometry(QRect(0, 0, 200, 401));
        toolBox->addItem(page, QStringLiteral("OnLine"));
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        page_2->setGeometry(QRect(0, 0, 200, 404));
        offLineList = new QListWidget(page_2);
        offLineList->setObjectName(QStringLiteral("offLineList"));
        offLineList->setGeometry(QRect(0, 0, 200, 400));
        toolBox->addItem(page_2, QStringLiteral("OffLine"));

        horizontalLayout_2->addWidget(toolBox);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        recvList = new QListWidget(centralWidget);
        recvList->setObjectName(QStringLiteral("recvList"));

        verticalLayout->addWidget(recvList);

        sendEidt = new QTextEdit(centralWidget);
        sendEidt->setObjectName(QStringLiteral("sendEidt"));

        verticalLayout->addWidget(sendEidt);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        sendBt = new QPushButton(centralWidget);
        sendBt->setObjectName(QStringLiteral("sendBt"));

        horizontalLayout->addWidget(sendBt);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        clearBt = new QPushButton(centralWidget);
        clearBt->setObjectName(QStringLiteral("clearBt"));

        horizontalLayout->addWidget(clearBt);


        verticalLayout_2->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout_2);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        ChatServer->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ChatServer);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ChatServer->setStatusBar(statusBar);

        retranslateUi(ChatServer);

        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ChatServer);
    } // setupUi

    void retranslateUi(QMainWindow *ChatServer)
    {
        ChatServer->setWindowTitle(QApplication::translate("ChatServer", "ChatServer", 0));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("ChatServer", "OnLine", 0));
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("ChatServer", "OffLine", 0));
        sendBt->setText(QApplication::translate("ChatServer", "send", 0));
        clearBt->setText(QApplication::translate("ChatServer", "clear", 0));
    } // retranslateUi

};

namespace Ui {
    class ChatServer: public Ui_ChatServer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATSERVER_H
