#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QList<QSerialPortInfo> infoList = QSerialPortInfo::availablePorts();
    //foreach(QSerialPortInfo info, infoList) QTextStream(stdout) << info.portName() << "\n";

    ui->setupUi(this);
    foreach(QSerialPortInfo info, infoList) ui->comboBox->addItem(info.portName());
    this->startTimer(200);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_comboBox_activated(const QString &arg1)//quando selecionar uma das opções da lista
{
    QTextStream(stdout)<<"ativado\n";
}

void MainWindow::timerEvent(QTimerEvent *a)
{

}
