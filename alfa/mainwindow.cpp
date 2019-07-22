#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow), serial(new SerialCom){

    ui->setupUi(this);
    this->startTimer(200); //Timer usado para checar se houve mudaça na lista de portas COM.

    QList<QString> listaAtualPortas = serial->getCOMList();
    ui->comboBox->clear();
    foreach( QString nome, listaAtualPortas ) ui->comboBox->addItem(nome);

    QObject::connect( serial, & SerialCom::readyRead,
                     [&]{ //Função lambda chamada pelo sinal de informção no buffer de leitura.
        ui->textBrowser_2->moveCursor (QTextCursor::End);
        ui->textBrowser_2->insertPlainText (serial->read());
        ui->textBrowser_2->moveCursor (QTextCursor::End);
    }
    );

    QObject::connect(ui->lineEdit, & QLineEdit::returnPressed,
                     [&]{//Função lambda chamada quando é pressionado o return no LineEdit
        if(serial->send( ui->lineEdit->text() )){
            ui->lineEdit->setText("");
        }else{
            ui->lineEdit->setText("Erro ao enviar");
        }
    }
    );
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_comboBox_activated(const QString & arg1){ //É chamada quando seleciona um item da comboBox
    serial->connect( arg1 );
}

void MainWindow::timerEvent(QTimerEvent * a){
    if(serial->portListChanged()){
        QList<QString> listaAtualPortas = serial->getCOMList();
        ui->comboBox->clear();
        foreach( QString nome, listaAtualPortas ) ui->comboBox->addItem(nome);
    }
}

//void MainWindow::saveFile(string )

void MainWindow::on_save_button_clicked()
{
    files = new aclFiles();
    files->setFilename();
    if(files->saveToFile(ui->text_edition->toPlainText())){
        ui->textEdit->setPlainText("Arquivo salvo com sucesso");
    } else {
        ui->textEdit->setPlainText("Falha ao salvar arquivo.");
    }
    delete files;
}
