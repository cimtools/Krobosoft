#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QApplication>
#include <QTextStream>
#include <QComboBox>
#include <QStringList>
#include <QTimer>
#include <QDebug>
#include <QLineEdit>
#include <QFile>
#include <QFileDialog>
#include <QDir>
#include "serialcom.h"
#include "aclfiles.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void openTab(const QString name = "Novo", const QString content = nullptr);

    void openFile();

    void saveFile();

    void saveFileAs();

private slots:
    void on_comboBox_activated(const QString &arg1);

    void timerEvent(QTimerEvent *a);

    void on_save_button_clicked();

    void on_new_button_clicked();

    void on_actionAbrir_triggered();

    void on_actionNovo_triggered();

    void on_openButton_clicked();

private:
    Ui::MainWindow * ui;
    int timerId =0;
    SerialCom * serial;
    SerialTerminal * terminal;
    aclFiles *files;
};

#endif // MAINWINDOW_H
