#include "serialcom.h"
#include <stdio.h>

SerialTerminal::SerialTerminal(){
    setStyleSheet("background-color: rgb(0, 0, 0); color: rgb(78,154,6)");
    setReadOnly(true);
}
SerialTerminal::SerialTerminal(QString pathToLog): logDirectory(pathToLog){
    setStyleSheet("background-color: rgb(0, 0, 0); color: rgb(78,154,6)");
    setReadOnly(true);

    logFile = new QFile(logDirectory);
    //file.setFileName("readme.txt");//QT example
    if ( !logFile->open( QIODevice::ReadWrite ) )
        logDirectory = "";
    else
        logFile->close();
}

void SerialTerminal::keyPressEvent( QKeyEvent * e ){
    ensureCursorVisible();
    switch (e->key()) {
    case Qt::Key_Return:
    case Qt::Key_Enter:
        command += e->text();
        //insertPlainText(e->text());//Comment this line too to stop echo on terminal.

        emit emitDataReady(command);
        emit emitByteReady('\n');

        qDebug() << "Store command: " << command;
        emit emitStoreCommand( command );

        if(logFile!=nullptr){
            if ( !logFile->open( QIODevice::WriteOnly | QIODevice::Append) ){
                qDebug()<< "Error loging commands. Could not open log file.\n";
            }else{
                qDebug()<<"Loging command to file\n";
                logFile->write( command.toStdString().c_str() );
                logFile->close();
            }
        }

        for( int i = 0; i < command.size()-1 ; i++ ){
            textCursor().deletePreviousChar();
        }

        command = "";
        logLine = 0;
        break;
    case Qt::Key_Backspace:
    case Qt::Key_Delete:
        if(command.size()>0){
            textCursor().deletePreviousChar();
            command.chop(1);
        }
        return;
    case Qt::Key_Up:
        qDebug() << "Key up pressed\n";
        logLine ++;

        if( logFile!=nullptr ){
            setCommand( getLogLine( logLine ) );
        }else{
            emit emitGetLog( logLine );//Change the current command, doing GUI treatment.
        }

        break;
    case Qt::Key_Down:
        qDebug() << "Key up down\n";
        if(logLine > 1){
            logLine--;
            if( logFile!=nullptr ){
                setCommand( getLogLine( logLine ) );
            }else{
                emit emitGetLog( logLine );
            }
        }else if(logLine == 1){
            logLine--;
            setCommand(" ");
        }else {
            logLine =0;
        }
        break;
    default:
        command += e->text();
        if(e->text().toStdString().size()>0)
        emit emitByteReady( e->text().toStdString().at(0) );
        insertPlainText(e->text()); //Comment this line too to stop echo on terminal.
        break;
    }
    qDebug() << logLine;
}

QString SerialTerminal::getLogLine( int line ){
    if( logFile->open(QIODevice::ReadOnly) ){
        logFile->seek(logFile->size());
        int lineCount = 0;
        int lineCharCount =0;
        while( lineCount < line  ){//TODO Fix loop sintax.
            if(logFile->pos() ==1 ){
                logFile->seek(logFile->pos()-1);
                logLine = lineCount;
                //TODO, ignore the next arrow up presse. preformance gain. multiple arrow up presses impact performance.
                break;
            }
            logFile->seek(logFile->pos()-2);
            QString readChar = logFile->read(1);//Reads a char
            if ( readChar == "\n" || readChar == "\r" ){
                lineCount++;
                if(lineCount < line)
                    lineCharCount=0;
            }else{
                lineCharCount++;
            }
        }
        QString returnHold = logFile->read( lineCharCount );
        logFile->close();
        return returnHold;
    }else{
        qDebug() << "Could not open log file to load commands.\n";
    }
    return "";
}

void SerialTerminal::setCommand(const QString & newCommand ){
    for( auto i = command.begin(); i < command.end(); i++ ){
        textCursor().deletePreviousChar();
    }
    insertPlainText( newCommand );
    command = newCommand;
}

SerialCom::SerialCom( qint32 baudRate , QSerialPort::DataBits dataBytes ,
                      QSerialPort::Parity parity , QSerialPort::FlowControl flowControl ,
                      QSerialPort::StopBits stopBit ){
    QObject::connect(&currentCOM, &QSerialPort::readyRead , this, &SerialCom::emitReadReady );

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
void SerialCom::close(){
    currentCOM.close();
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
    QString buffer = msg;
    qDebug() << "Enviando pela serial: " << buffer ;
    return ( currentCOM.write( buffer.toStdString().c_str(), buffer.size()) )? true : false;
}

int SerialCom::sendByte(const char & byte){
    qDebug() << "Enviando pela serial: " << byte ;
    char a = byte;
    return ( currentCOM.write( &a ) )? true : false;
}


bool SerialCom::portListChanged(){
    QList<QSerialPortInfo> currentPortList = QSerialPortInfo::availablePorts();
    if(
        std::equal( COMList.begin(), COMList.end(), currentPortList.begin(),
            []( const QSerialPortInfo & a, const QSerialPortInfo & b ){
                return (a.portName() == b.portName())? true: false;
            }
        )
    ){
        return false;
    }else{
        COMList = currentPortList;
        return true;
    }
}

SerialCom::~SerialCom(){
    currentCOM.close();
}
