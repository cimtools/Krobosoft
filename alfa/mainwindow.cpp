#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);
    listaPortasCOM = QSerialPortInfo::availablePorts();
    foreach(QSerialPortInfo info, listaPortasCOM) ui->comboBox->addItem(info.portName());
    this->startTimer(200); //Timer usado para checar se houve mudaça na lista de portas COM.
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_comboBox_activated(const QString &arg1){ //quando selecionar uma das opções da lista
    QTextStream(stdout)<<"A porta selecionada eh " << arg1;
}

void MainWindow::timerEvent(QTimerEvent *a){
    //Se a lista atual de portas COM for diferente da armazenada, atualizar a lista tanto na GUI quanto a armazenada na classe.
    QList<QSerialPortInfo> listaAtualPortas = QSerialPortInfo::availablePorts();
    if( !std::equal( listaPortasCOM.begin(), listaPortasCOM.end(),
                    listaAtualPortas.begin(),
                    []( const QSerialPortInfo & a, const QSerialPortInfo & b ){
                        return (a.portName() == b.portName())? true: false;
                    }
                    ) ) {
        ui->comboBox->clear();
        foreach(QSerialPortInfo info, listaAtualPortas) ui->comboBox->addItem(info.portName());
        listaPortasCOM = listaAtualPortas;
    }
}

