#include "serialcom.h"

SerialCom::SerialCom(){
    QObject::connect(&portaAtual, &QSerialPort::readyRead , this, &SerialCom::readyRead );

    listaDePortas = QSerialPortInfo::availablePorts();

    if(!portaAtual.setBaudRate(QSerialPort::Baud9600))
    qDebug() << portaAtual.errorString();
    if(!portaAtual.setDataBits(QSerialPort::Data8))
    qDebug() << portaAtual.errorString();
    if(!portaAtual.setParity(QSerialPort::NoParity))
    qDebug() << portaAtual.errorString();
    if(!portaAtual.setFlowControl(QSerialPort::NoFlowControl))
    qDebug() << portaAtual.errorString();
    if(!portaAtual.setStopBits(QSerialPort::OneStop))
    qDebug() << portaAtual.errorString();
}

QList<QString> SerialCom::getListaDePortas(){
    QList<QString> nomesPortas;
    foreach(QSerialPortInfo info, listaDePortas) nomesPortas.append(info.portName());
    return nomesPortas;
}


QString SerialCom::lerDados(){
    qDebug() << "Quantidade de bytes disponíveis para leitura: " << portaAtual.bytesAvailable();
    QString datas = portaAtual.readAll();
    qDebug() <<"Dados lidos: "<< datas;
    return datas;
}

int SerialCom::conectar(const QString & nomeDaPorta){
    QTextStream(stdout)<<"A porta selecionada eh " << nomeDaPorta << "\n";
    portaAtual.close();
    portaAtual.setPortName(nomeDaPorta);
    if(!portaAtual.open(QIODevice::ReadWrite)){
        qDebug() << portaAtual.errorString();
        return false;
    }else {
        return true;
    }
}

int SerialCom::enviar(const QString & mensagem){
    static QString buffer;
    buffer = mensagem + "\r";
    qDebug() << "Enviando pela serial: " << buffer ;
    return ( portaAtual.write( buffer.toStdString().c_str(), buffer.size() ) )? true : false;
}

bool SerialCom::houveMudancaPortas(){
    QList<QSerialPortInfo> listaPortasMomento = QSerialPortInfo::availablePorts();
    return (
        std::equal( listaDePortas.begin(), listaDePortas.end(), listaPortasMomento.begin(),
            []( const QSerialPortInfo & a, const QSerialPortInfo & b ){
                return (a.portName() == b.portName())? true: false;
            }
        )
   )? false: true;
}

SerialCom::~SerialCom(){
    portaAtual.close();
}
