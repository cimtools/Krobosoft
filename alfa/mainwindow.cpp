#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow), serial(new SerialCom){

    ui->setupUi(this);
    SerialTerminal * terminal = new SerialTerminal();
    ui->terminalLayout->addWidget( terminal );

    this->startTimer(200); //Timer usado para checar se houve mudaça na lista de portas COM.

    openTab();

    QList<QString> listaAtualPortas = serial->getCOMList();
    ui->comboBox->clear();
    foreach( QString nome, listaAtualPortas ) ui->comboBox->addItem(nome);

    QObject::connect( serial, &SerialCom::readyRead, [=](){ terminal->insertPlainText( serial->read() ); } );
    QObject::connect( terminal, &SerialTerminal::emitDataReady, serial, &SerialCom::send );


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
    /*if(files->saveToFile(ui->text_edition->toPlainText())){
        ui->textEdit->setPlainText("Arquivo salvo com sucesso");
    } else {
        ui->textEdit->setPlainText("Falha ao salvar arquivo.");
    }*/
    delete files;
}

void MainWindow::on_actionSalvar_Como_triggered()
{
    on_save_button_clicked();
}

void MainWindow::on_new_button_clicked()
{
    openTab();
}

void MainWindow::on_toolButton_clicked()
{
    files = new aclFiles();
    files->setFilename();
    openTab(files->getFilename(), files->openFile());
}

//####################################################################### FUNCTIONS
void MainWindow::openTab(const QString name, QString content){
    int i = ui->tabWidget->currentIndex() +1;
    QTextEdit * temp = new QTextEdit();
    temp->setPlainText(content);
    ui->tabWidget->insertTab(i, temp, name);
    ui->tabWidget->widget(i)->setStyleSheet("background-color: rgb(255, 255, 255); \n color: rgb(0, 0, 0); \n");
    temp = nullptr;
}

