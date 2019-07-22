#ifndef SERIALCOM_H
#define SERIALCOM_H

#include <QQuickItem>
#include <QSerialPort>
#include <QSerialPortInfo>

class SerialCom : public QQuickItem
{
    Q_OBJECT
public:
    /**
     * @brief Constructor function, it reeds all COM ports, stores it's names, then configure the instance of QSerialPort to future use.
     * @param Get as parameters the configurations for the COM communication.
     */
    SerialCom( qint32 baudRate = QSerialPort::Baud9600, QSerialPort::DataBits dataBytes = QSerialPort::Data8,
                QSerialPort::Parity parity = QSerialPort::NoParity, QSerialPort::FlowControl flowControl = QSerialPort::NoFlowControl,
                QSerialPort::StopBits stopBit = QSerialPort::OneStop );
    ~SerialCom();
    /**
     * @brief Reads the open COM ports, iterates through them and extracts it's names.
     * @return Return the list of COM ports existents.
     */
    QList<QString> getCOMList();
    /**
     * @brief Reads all available data on the current COM port.
     * @return Return COM buffer data.
     */
    QString read();
    /**
     * @brief Used to open communication with a COM port.
     * @param Qstring that contain the name of the desired COM port.
     * @return Returns true if it succeeds in establish the connection, false otherwise.
     */
    bool connect( const QString & COMName);
    /**
     * @brief Sends a QString to the open COM port.
     * @param The QString to be sent.
     * @return Returns true if it succeeds is sending the message, false otherwise.
     */
    int send( const QString & msg);
    /**
     * @brief Function used to know if changes in the list of COM ports occurred.
     * @return Returns true if COM ports were added or subtracted, false otherwise.
     */
    bool portListChanged();

private:
    /**
     * @brief List of all available COM ports.
     */
    QList<QSerialPortInfo> COMList;
    /**
     * @brief Used to hold the communication with the active COM port.
     */
    QSerialPort currentCOM;
signals:
    /**
     * @brief Used as Signal to know when Serial data are available to read.
     */
    void readyRead();
public slots:
};

#endif // SERIALCOM_H
