#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);
    this->startTimer(200); //Timer usado para checar se houve mudaça na lista de portas COM.

    QList<QString> listaAtualPortas = serial.getCOMList();
    ui->comboBox->clear();
    foreach( QString nome, listaAtualPortas ) ui->comboBox->addItem(nome);

    QObject::connect( &serial, & SerialCom::readyRead,
                     [&]{ //Função lambda chamada pelo sinal de informção no buffer de leitura.
        ui->textBrowser_2->moveCursor (QTextCursor::End);
        ui->textBrowser_2->insertPlainText (serial.read());
        ui->textBrowser_2->moveCursor (QTextCursor::End);
    }
    );

    QObject::connect(ui->lineEdit, & QLineEdit::returnPressed,
                     [&]{//Função lambda chamada quando é pressionado o return no LineEdit
        if(serial.enviar( ui->lineEdit->text() )){
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
    serial.conectar( arg1 );
}

void MainWindow::timerEvent(QTimerEvent * a){
    if(serial.portListChanged()){
        QList<QString> listaAtualPortas = serial.getCOMList();
        ui->comboBox->clear();
        foreach( QString nome, listaAtualPortas ) ui->comboBox->addItem(nome);
    }
}

//void MainWindow::saveFile(string )

void MainWindow::on_save_button_clicked()
{
    //Pega o conteúdo da caixa de texto
    static QString program;
    program = ui->text_edition->toPlainText();
    //Cria File Dialog próprio
    QFileDialog saveAs(this);
    saveAs.setFileMode(QFileDialog::AnyFile);
    saveAs.setNameFilter(tr("All files(*.acl*);;Text File(*.txt)"));
    saveAs.setViewMode(QFileDialog::Detail);

    QStringList filename;
    if(saveAs.exec()){
        filename = saveAs.selectedFiles();
    }
    QFile file( filename.at(0) );
    if(file.open(QIODevice::ReadWrite)){
        QTextStream content(&file);
        content << program << endl;
        ui->textBrowser_2->insertPlainText("Arquivo salvo");
    } else {
        ui->textBrowser_2->insertPlainText("Não foi possível salvar o arquivo");
    }
    file.close();
}
