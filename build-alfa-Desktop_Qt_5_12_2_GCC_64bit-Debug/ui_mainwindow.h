/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QFrame *line;
    QGroupBox *groupBox;
    QTextBrowser *textBrowser;
    QScrollBar *verticalScrollBar;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;
    QToolButton *toolButton_4;
    QFrame *line_2;
    QGroupBox *groupBox_3;
    QToolButton *toolButton_9;
    QToolButton *toolButton_10;
    QToolButton *toolButton_11;
    QToolButton *toolButton_12;
    QTextBrowser *textBrowser_2;
    QComboBox *comboBox;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuLabBot;
    QMenu *menuFerramentas;
    QMenu *menuConfigura_es;
    QMenu *menuBot_es_de_Controle;
    QMenu *menuHelp;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(815, 532);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, -10, 821, 20));
        line->setStyleSheet(QString::fromUtf8("background-color: rgb(238, 238, 236);"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(420, 10, 381, 321));
        groupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(186, 189, 182);"));
        textBrowser = new QTextBrowser(groupBox);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(40, 20, 331, 251));
        textBrowser->setStyleSheet(QString::fromUtf8("background-color: rgb(238, 238, 236);"));
        textBrowser->setReadOnly(false);
        verticalScrollBar = new QScrollBar(groupBox);
        verticalScrollBar->setObjectName(QString::fromUtf8("verticalScrollBar"));
        verticalScrollBar->setGeometry(QRect(360, 20, 16, 251));
        verticalScrollBar->setOrientation(Qt::Vertical);
        toolButton = new QToolButton(groupBox);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(10, 30, 26, 24));
        toolButton_2 = new QToolButton(groupBox);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        toolButton_2->setGeometry(QRect(10, 60, 26, 24));
        toolButton_3 = new QToolButton(groupBox);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        toolButton_3->setGeometry(QRect(10, 90, 26, 24));
        toolButton_4 = new QToolButton(groupBox);
        toolButton_4->setObjectName(QString::fromUtf8("toolButton_4"));
        toolButton_4->setGeometry(QRect(10, 120, 26, 24));
        line_2 = new QFrame(groupBox);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(-17, 0, 20, 281));
        line_2->setStyleSheet(QString::fromUtf8("background-color: rgb(238, 238, 236);"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 10, 411, 321));
        groupBox_3->setStyleSheet(QString::fromUtf8("background-color: rgb(186, 189, 182);"));
        toolButton_9 = new QToolButton(groupBox_3);
        toolButton_9->setObjectName(QString::fromUtf8("toolButton_9"));
        toolButton_9->setGeometry(QRect(10, 30, 26, 24));
        toolButton_10 = new QToolButton(groupBox_3);
        toolButton_10->setObjectName(QString::fromUtf8("toolButton_10"));
        toolButton_10->setGeometry(QRect(10, 60, 26, 24));
        toolButton_11 = new QToolButton(groupBox_3);
        toolButton_11->setObjectName(QString::fromUtf8("toolButton_11"));
        toolButton_11->setGeometry(QRect(10, 90, 26, 24));
        toolButton_12 = new QToolButton(groupBox_3);
        toolButton_12->setObjectName(QString::fromUtf8("toolButton_12"));
        toolButton_12->setGeometry(QRect(10, 120, 26, 24));
        textBrowser_2 = new QTextBrowser(groupBox_3);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(40, 20, 361, 251));
        textBrowser_2->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        comboBox = new QComboBox(groupBox_3);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(160, 280, 111, 25));
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 815, 22));
        menuLabBot = new QMenu(menuBar);
        menuLabBot->setObjectName(QString::fromUtf8("menuLabBot"));
        menuFerramentas = new QMenu(menuBar);
        menuFerramentas->setObjectName(QString::fromUtf8("menuFerramentas"));
        menuConfigura_es = new QMenu(menuBar);
        menuConfigura_es->setObjectName(QString::fromUtf8("menuConfigura_es"));
        menuBot_es_de_Controle = new QMenu(menuBar);
        menuBot_es_de_Controle->setObjectName(QString::fromUtf8("menuBot_es_de_Controle"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuLabBot->menuAction());
        menuBar->addAction(menuFerramentas->menuAction());
        menuBar->addAction(menuConfigura_es->menuAction());
        menuBar->addAction(menuBot_es_de_Controle->menuAction());
        menuBar->addAction(menuHelp->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "   Editor de Programas", nullptr));
        toolButton->setText(QApplication::translate("MainWindow", "C", nullptr));
        toolButton_2->setText(QApplication::translate("MainWindow", "D", nullptr));
        toolButton_3->setText(QApplication::translate("MainWindow", "U", nullptr));
        toolButton_4->setText(QApplication::translate("MainWindow", "L", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "  Terminal do Controlador TIPO B", nullptr));
        toolButton_9->setText(QApplication::translate("MainWindow", "C", nullptr));
        toolButton_10->setText(QApplication::translate("MainWindow", "D", nullptr));
        toolButton_11->setText(QApplication::translate("MainWindow", "U", nullptr));
        toolButton_12->setText(QApplication::translate("MainWindow", "L", nullptr));
        menuLabBot->setTitle(QApplication::translate("MainWindow", "Arquivo", nullptr));
        menuFerramentas->setTitle(QApplication::translate("MainWindow", "Ferramentas", nullptr));
        menuConfigura_es->setTitle(QApplication::translate("MainWindow", "Configura\303\247\303\265es", nullptr));
        menuBot_es_de_Controle->setTitle(QApplication::translate("MainWindow", "Bot\303\265es de Controle", nullptr));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
