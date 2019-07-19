#include "serialcom.h"

SerialCom::SerialCom(){
    QObject::connect(&currentCOM, &QSerialPort::readyRead , this, &SerialCom::readyRead );

    COMList = QSerialPortInfo::availablePorts();

    if(!currentCOM.setBaudRate(QSerialPort::Baud9600))
    qDebug() << currentCOM.errorString();
    if(!currentCOM.setDataBits(QSerialPort::Data8))
    qDebug() << currentCOM.errorString();
    if(!currentCOM.setParity(QSerialPort::NoParity))
    qDebug() << currentCOM.errorString();
    if(!currentCOM.setFlowControl(QSerialPort::NoFlowControl))
    qDebug() << currentCOM.errorString();
    if(!currentCOM.setStopBits(QSerialPort::OneStop))
    qDebug() << currentCOM.errorString();
}

QList<QString> SerialCom::getCOMList(){
    QList<QString> portNames;
    foreach(QSerialPortInfo info, COMList) portNames.append(info.portName());
    return portNames;
}


QString SerialCom::read(){
    qDebug() << "Quantidade de bytes disponíveis para leitura: " << currentCOM.bytesAvailable();
    QString datas = currentCOM.readAll();
    qDebug() <<"Dados lidos: "<< datas;
    return datas;
}

int SerialCom::connect(const QString & COMName){
    QTextStream(stdout)<<"A porta selecionada eh " << COMName << "\n";
    currentCOM.close();
    currentCOM.setPortName(COMName);
    if(!currentCOM.open(QIODevice::ReadWrite)){
        qDebug() << currentCOM.errorString();
        return false;
    }else {
        return true;
    }
}

int SerialCom::send(const QString & msg){
    static QString buffer;
    buffer = msg + "\r";
    qDebug() << "Enviando pela serial: " << buffer ;
    return ( currentCOM.write( buffer.toStdString().c_str(), buffer.size() ) )? true : false;
}

bool SerialCom::portListChanged(){
    QList<QSerialPortInfo> currentPortList = QSerialPortInfo::availablePorts();
    return (
        std::equal( COMList.begin(), COMList.end(), currentPortList.begin(),
            []( const QSerialPortInfo & a, const QSerialPortInfo & b ){
                return (a.portName() == b.portName())? true: false;
            }
        )
   )? false: true;
}

SerialCom::~SerialCom(){
    currentCOM.close();
}
