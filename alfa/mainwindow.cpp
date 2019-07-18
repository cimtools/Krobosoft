#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);
    listaPortasCOM = QSerialPortInfo::availablePorts();
    foreach(QSerialPortInfo info, listaPortasCOM) ui->comboBox->addItem(info.portName());
    this->startTimer(200); //Timer usado para checar se houve mudaça na lista de portas COM.
    if(!serial.setBaudRate(QSerialPort::Baud9600))
        qDebug() << serial.errorString();
    if(!serial.setDataBits(QSerialPort::Data8))
        qDebug() << serial.errorString();
    if(!serial.setParity(QSerialPort::NoParity))
        qDebug() << serial.errorString();
    if(!serial.setFlowControl(QSerialPort::NoFlowControl))
        qDebug() << serial.errorString();
    if(!serial.setStopBits(QSerialPort::OneStop))
        qDebug() << serial.errorString();
    QObject::connect(&serial, &QSerialPort::readyRead,
        [&]{ //Função lambda chamada pelo sinal de informção no buffer de leitura.
            qDebug() << "Quantidade de bytes disponíveis para leitura: " << serial.bytesAvailable();
            QString datas = serial.readAll();
            qDebug() <<"Dados lidos: "<< datas;
            //ui->textBrowser_2->append(datas);
            ui->textBrowser_2->moveCursor (QTextCursor::End);
            ui->textBrowser_2->insertPlainText (datas);
            ui->textBrowser_2->moveCursor (QTextCursor::End);
        }
    );//Fim dos argumentos do connect.

    QObject::connect(ui->lineEdit, &QLineEdit::returnPressed,
        [&]{//Função lambda chamada quando é pressionado o return no LineEdit
            static QString buffer;
            buffer = ui->lineEdit->text() + "\r";
            qDebug() << "Enviando pela serial: " << buffer ;
            serial.write( buffer.toStdString().c_str(), buffer.size() );
            ui->lineEdit->setText("");
        }
    );
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_comboBox_activated(const QString &arg1){ //É chamada quando seleciona um item da comboBox
    QTextStream(stdout)<<"A porta selecionada eh " << arg1 << "\n";
    serial.close();
    serial.setPortName(arg1);
    if(!serial.open(QIODevice::ReadWrite))
        qDebug() << serial.errorString();
}

void MainWindow::timerEvent(QTimerEvent *a){
    //Se a lista atual de portas COM for diferente da armazenada, atualizar a lista tanto na GUI quanto a armazenada na classe.
    QList<QSerialPortInfo> listaAtualPortas = QSerialPortInfo::availablePorts();
    if(
        !std::equal( listaPortasCOM.begin(), listaPortasCOM.end(), listaAtualPortas.begin(),
            []( const QSerialPortInfo & a, const QSerialPortInfo & b ){//Função lambda que implementa o critério de comparação.
                return (a.portName() == b.portName())? true: false;
            }
        )//Fim dos argumentos do std::equal.
    ){ //Fim dos argumentos do if, início do bloco.
        ui->comboBox->clear();
        foreach(QSerialPortInfo info, listaAtualPortas) ui->comboBox->addItem(info.portName());
        listaPortasCOM = listaAtualPortas;
    }//Fim do bloco if.
}

