#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
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

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_comboBox_activated(const QString &arg1);

    void timerEvent(QTimerEvent *a);

    void on_save_button_clicked();

private:
    Ui::MainWindow * ui;
    int timerId =0;
    QList<QSerialPortInfo> listaPortasCOM = QSerialPortInfo::availablePorts();
    QSerialPort serial;
};

#endif // MAINWINDOW_H
