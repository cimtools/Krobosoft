#include "serialcom.h"

SerialCom::SerialCom( qint32 baudRate , QSerialPort::DataBits dataBytes ,
                      QSerialPort::Parity parity , QSerialPort::FlowControl flowControl ,
                      QSerialPort::StopBits stopBit ){
    QObject::connect(&currentCOM, &QSerialPort::readyRead , this, &SerialCom::readyRead );

    COMList = QSerialPortInfo::availablePorts();

    if(!currentCOM.setBaudRate(baudRate))
    qDebug() << currentCOM.errorString();
    if(!currentCOM.setDataBits(dataBytes))
    qDebug() << currentCOM.errorString();
    if(!currentCOM.setParity(parity))
    qDebug() << currentCOM.errorString();
    if(!currentCOM.setFlowControl(flowControl))
    qDebug() << currentCOM.errorString();
    if(!currentCOM.setStopBits(stopBit))
    qDebug() << currentCOM.errorString();
}

QList<QString> SerialCom::getCOMList(){
    QList<QString> portNames;
    foreach(QSerialPortInfo info, COMList) portNames.append(info.portName());
    return portNames;
}


QString SerialCom::read(){
    QString datas = currentCOM.readAll();
    qDebug() <<"Dados lidos: "<< datas;
    return datas;
}

bool SerialCom::connect(const QString & COMName){
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
    static QString buffer = msg + '\r';
    qDebug() << "Enviando pela serial: " << buffer ;
    return ( currentCOM.write( buffer.toStdString().c_str(), buffer.size()) )? true : false;
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
