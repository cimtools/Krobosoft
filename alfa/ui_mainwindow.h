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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QTextEdit *text_edition;
    QToolButton *new_button;
    QToolButton *save_button;
    QToolButton *download_button;
    QToolButton *list_button;
    QGroupBox *groupBox_3;
    QToolButton *toolButton_9;
    QToolButton *toolButton_10;
    QToolButton *toolButton_11;
    QToolButton *toolButton_12;
    QTextEdit *textBrowser_2;
    QLineEdit *lineEdit;
    QComboBox *comboBox;
    QGroupBox *groupBox_2;
    QTextEdit *textEdit;
    QFrame *line;
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
        MainWindow->resize(954, 479);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(0, 0));
        MainWindow->setMaximumSize(QSize(954, 479));
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(85, 87, 83);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(478, 9, 463, 291));
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(123, 123));
        groupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(186, 189, 182);"));
        text_edition = new QTextEdit(groupBox);
        text_edition->setObjectName(QString::fromUtf8("text_edition"));
        text_edition->setGeometry(QRect(40, 20, 421, 251));
        text_edition->setStyleSheet(QString::fromUtf8("background-color: rgb(238, 238, 236);\n"
"color: rgb(0, 0, 0);\n"
""));
        text_edition->setReadOnly(false);
        new_button = new QToolButton(groupBox);
        new_button->setObjectName(QString::fromUtf8("new_button"));
        new_button->setGeometry(QRect(10, 30, 26, 24));
        new_button->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        save_button = new QToolButton(groupBox);
        save_button->setObjectName(QString::fromUtf8("save_button"));
        save_button->setGeometry(QRect(10, 60, 26, 24));
        save_button->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        download_button = new QToolButton(groupBox);
        download_button->setObjectName(QString::fromUtf8("download_button"));
        download_button->setGeometry(QRect(10, 90, 26, 24));
        download_button->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        list_button = new QToolButton(groupBox);
        list_button->setObjectName(QString::fromUtf8("list_button"));
        list_button->setGeometry(QRect(10, 120, 26, 24));
        list_button->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(9, 9, 463, 291));
        sizePolicy.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy);
        groupBox_3->setMinimumSize(QSize(123, 123));
        groupBox_3->setAutoFillBackground(false);
        groupBox_3->setStyleSheet(QString::fromUtf8("background-color: rgb(186, 189, 182);"));
        toolButton_9 = new QToolButton(groupBox_3);
        toolButton_9->setObjectName(QString::fromUtf8("toolButton_9"));
        toolButton_9->setGeometry(QRect(10, 30, 26, 24));
        toolButton_9->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        toolButton_10 = new QToolButton(groupBox_3);
        toolButton_10->setObjectName(QString::fromUtf8("toolButton_10"));
        toolButton_10->setGeometry(QRect(10, 60, 26, 24));
        toolButton_10->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        toolButton_11 = new QToolButton(groupBox_3);
        toolButton_11->setObjectName(QString::fromUtf8("toolButton_11"));
        toolButton_11->setGeometry(QRect(10, 90, 26, 24));
        toolButton_11->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        toolButton_12 = new QToolButton(groupBox_3);
        toolButton_12->setObjectName(QString::fromUtf8("toolButton_12"));
        toolButton_12->setGeometry(QRect(10, 120, 26, 24));
        toolButton_12->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        textBrowser_2 = new QTextEdit(groupBox_3);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(40, 20, 401, 221));
        textBrowser_2->setMinimumSize(QSize(1, 1));
        textBrowser_2->setMaximumSize(QSize(401, 231));
        textBrowser_2->setSizeIncrement(QSize(0, 2));
        QFont font;
        font.setItalic(true);
        font.setStyleStrategy(QFont::PreferAntialias);
        textBrowser_2->setFont(font);
        textBrowser_2->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: rgb(78, 154, 6)"));
        textBrowser_2->setReadOnly(true);
        lineEdit = new QLineEdit(groupBox_3);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(40, 250, 401, 25));
        lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: rgb(78, 154, 6)"));
        comboBox = new QComboBox(groupBox_3);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(0, 0, 111, 21));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 320, 932, 161));
        groupBox_2->setStyleSheet(QString::fromUtf8("background-color: rgb(186, 189, 182);"));
        textEdit = new QTextEdit(groupBox_2);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 29, 911, 81));
        textEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(238, 238, 236);"));
        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 300, 951, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 954, 20));
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
        new_button->setText(QApplication::translate("MainWindow", "new", nullptr));
        save_button->setText(QApplication::translate("MainWindow", "sv", nullptr));
        download_button->setText(QApplication::translate("MainWindow", "d", nullptr));
        list_button->setText(QApplication::translate("MainWindow", "L", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "                               Terminal do Controlador TIPO B", nullptr));
        toolButton_9->setText(QApplication::translate("MainWindow", "C", nullptr));
        toolButton_10->setText(QApplication::translate("MainWindow", "D", nullptr));
        toolButton_11->setText(QApplication::translate("MainWindow", "U", nullptr));
        toolButton_12->setText(QApplication::translate("MainWindow", "L", nullptr));
#ifndef QT_NO_TOOLTIP
        textBrowser_2->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ce5c00;\">ni</span></p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        textBrowser_2->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:italic;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu'; font-size:11pt;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu'; font-size:11pt;\"><br /></p></body></html>", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Controle do Download", nullptr));
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
