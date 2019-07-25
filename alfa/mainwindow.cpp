#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow), serial(new SerialCom){

    ui->setupUi(this);
    terminal = new SerialTerminal();
    ui->terminalLayout->addWidget( terminal );

    this->startTimer(200); //Timer usado para checar se houve mudaça na lista de portas COM.

    openTab();

    QList<QString> listaAtualPortas = serial->getCOMList();
    ui->comboBox->clear();
    ui->comboBox->addItem("");
    foreach( QString nome, listaAtualPortas ) ui->comboBox->addItem(nome);

    QObject::connect( serial, &SerialCom::emitReadReady, [=](){ terminal->insertPlainText( serial->read() ); } );
    QObject::connect( terminal, &SerialTerminal::emitDataReady, serial, &SerialCom::send );
    //QObject::connect( terminal, &SerialTerminal::emitByteReady, serial, &SerialCom::sendByte );

}

MainWindow::~MainWindow(){
    delete ui;
    delete terminal;
}

void MainWindow::on_comboBox_activated(const QString & arg1){ //É chamada quando seleciona um item da comboBox
    serial->close();
    serial->connect( arg1 );
}

void MainWindow::timerEvent(QTimerEvent * a){
    if(serial->portListChanged()){
        QList<QString> listaAtualPortas = serial->getCOMList();
        ui->comboBox->clear();
        foreach( QString nome, listaAtualPortas ) ui->comboBox->addItem(nome);
    }
}

//New button
void MainWindow::on_new_button_clicked(){
    openTab();
}
//New action
void MainWindow::on_actionNovo_triggered(){
    openTab();
}
//Save as button
void MainWindow::on_save_button_clicked(){
    saveFileAs();
}
//Save as action
void MainWindow::on_actionSalvar_Como_triggered(){
    saveFileAs();
}
//Open button
void MainWindow::on_openButton_clicked(){
    openFile();
}
//Open action
void MainWindow::on_actionAbrir_triggered(){
    openFile();
}



//####################################################################### FUNCTIONS

void MainWindow::saveFileAs(){
    files = new aclFiles();
    files->setFilename(1);
    QTextEdit * temp = (QTextEdit *) ui->tabWidget->currentWidget();

    if(files->saveToFile(temp->toPlainText())){
        ui->textEdit->setPlainText("Arquivo salvo com sucesso");
    } else {
        ui->textEdit->setPlainText("Falha ao salvar arquivo.");
    }
    delete files;
}

void MainWindow::openTab(const QString name, QString content){
    int i = ui->tabWidget->currentIndex() +1;
    QTextEdit * temp = new QTextEdit();
    temp->setPlainText(content);
    ui->tabWidget->insertTab(i, temp, name);
    ui->tabWidget->widget(i)->setStyleSheet("background-color: rgb(255, 255, 255); \n color: rgb(0, 0, 0); \n");
    temp = nullptr;
}

void MainWindow::openFile(){
    files = new aclFiles();
    files->setFilename();
    foreach(QString filepath, files->getFilePaths()){
        //qDebug() << filepath;
        openTab(files->getFilename(filepath), files->openFile(filepath));
    }
    delete files;
}



