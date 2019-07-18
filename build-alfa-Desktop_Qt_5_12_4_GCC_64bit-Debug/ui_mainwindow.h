/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QTextBrowser *textBrowser;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;
    QToolButton *toolButton_4;
    QGroupBox *groupBox_3;
    QToolButton *toolButton_9;
    QToolButton *toolButton_10;
    QToolButton *toolButton_11;
    QToolButton *toolButton_12;
    QTextEdit *textEdit_2;
    QComboBox *comboBox;
    QLineEdit *lineEdit;
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
        MainWindow->resize(12312311, 12123123);
        MainWindow->setMinimumSize(QSize(123, 123));
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(85, 87, 83);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(470, 10, 471, 321));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(123, 123));
        groupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(186, 189, 182);"));
        textBrowser = new QTextBrowser(groupBox);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(40, 20, 421, 251));
        textBrowser->setStyleSheet(QString::fromUtf8("background-color: rgb(238, 238, 236);"));
        textBrowser->setReadOnly(false);
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
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 10, 451, 325));
        sizePolicy.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy);
        groupBox_3->setMinimumSize(QSize(123, 123));
        groupBox_3->setAutoFillBackground(false);
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
        textEdit_2 = new QTextEdit(groupBox_3);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(40, 20, 401, 231));
        textEdit_2->setMinimumSize(QSize(1, 1));
        textEdit_2->setMaximumSize(QSize(401, 231));
        textEdit_2->setSizeIncrement(QSize(0, 2));
        QFont font;
        font.setItalic(true);
        font.setStyleStrategy(QFont::PreferAntialias);
        textEdit_2->setFont(font);
        textEdit_2->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: rgb(78, 154, 6)"));
        textEdit_2->setReadOnly(true);
        comboBox = new QComboBox(groupBox_3);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(160, 280, 111, 25));
        lineEdit = new QLineEdit(groupBox_3);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(40, 250, 401, 25));
        lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: rgb(78, 154, 6)"));
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 12312311, 22));
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
        groupBox->setTitle(QApplication::translate("MainWindow", "                                                 Editor de Programas", nullptr));
        toolButton->setText(QApplication::translate("MainWindow", "C", nullptr));
        toolButton_2->setText(QApplication::translate("MainWindow", "D", nullptr));
        toolButton_3->setText(QApplication::translate("MainWindow", "U", nullptr));
        toolButton_4->setText(QApplication::translate("MainWindow", "L", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "                               Terminal do Controlador TIPO B", nullptr));
        toolButton_9->setText(QApplication::translate("MainWindow", "C", nullptr));
        toolButton_10->setText(QApplication::translate("MainWindow", "D", nullptr));
        toolButton_11->setText(QApplication::translate("MainWindow", "U", nullptr));
        toolButton_12->setText(QApplication::translate("MainWindow", "L", nullptr));
#ifndef QT_NO_TOOLTIP
        textEdit_2->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ce5c00;\">ni</span></p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        textEdit_2->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:italic;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
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
