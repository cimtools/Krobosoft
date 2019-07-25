#ifndef SERIALCOM_H
#define SERIALCOM_H

#include <QQuickItem>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QTextEdit>
#include <QLineEdit>

class SerialTerminal: public QTextEdit
{
    Q_OBJECT
signals:
    /**
     * @brief Signal emitted when user press Enter or Return.
     * @param data const QString & The String that is to be sent out of the terminal.
     */
    void emitDataReady( const QString & data );
    /**
     * @brief Sgnal emitted user press a single key.
     * @param byte char & byte to be sent.
     */
    void emitByteReady( const char & byte );
    /**
     * @brief Requests the log object to send a log line.
     * @param linesFromEnd const int & Position of the desired line. Counting from the end of the file (where is the last entry).
     */
    void emitGetLog( const int & linesFromEnd );
    /**
     * @brief emitStoreCommand Signal to store a command in the log.
     * @param command const QString & Referenc to the command string to be stored on the log.
     */
    void emitStoreCommand( const QString & command );
public:
    /**
     * @brief Sets the color of the terminal.
     */
    SerialTerminal();
    /**
     * @brief Used to return the string to be sent to the serial Port.
     * @return Qstring String to be sent out of the terminal.
     */
    QString getCommand(){ return command; }

public slots:
    /**
     * @brief It change the current command to be sent. Used to iterate through the log entries.
     * @param newCommand const QString & The new value for the command.
     */
    void setCommand( const QString & newCommand );
protected:
    /**
     * @brief Override function, that listens for Enter or Return presses.
     */
    void keyPressEvent( QKeyEvent * e ) override;
    /**
     * @brief QString that holds the command typed.
     */
    QString command;
    /**
     * @brief Holds the last edition position. When the user presses a key is treated as if the cursor is in this position.
     * This is set eatch time the writing capability is enable, and when the user presses arrow keys.
     */
    int lastEditPosition=0;
    /**
     * @brief logLine int Holds the position of the line requested to the logger.
     */
    int logLine=0;
};

class SerialCom : public QQuickItem
{
    Q_OBJECT
public:
    /**
     * @brief Constructor function, it reeds all COM ports, stores it's names, then configure the instance of QSerialPort to future use.
     * Whit exception of baudRate, all other parameters are enums defined in QSerialPort class.
     * @param baudRate qint32 Baud rate of the port.
     * @param dataBytes QSerialPort::DataBits Number of data bits.
     * @param parity QSerialPort::Parity Parity type.
     * @param flowControl QSerialPort::FlowControl Type of flow control.
     * @param stopBit QSerialPort::StopBits Set stop bit configuration.
     */
    SerialCom( qint32 baudRate = QSerialPort::Baud9600, QSerialPort::DataBits dataBytes = QSerialPort::Data8,
                QSerialPort::Parity parity = QSerialPort::NoParity, QSerialPort::FlowControl flowControl = QSerialPort::NoFlowControl,
                QSerialPort::StopBits stopBit = QSerialPort::OneStop );
    ~SerialCom();
    /**
     * @brief Reads the open COM ports, iterates through them and extracts it's names.
     * @return QList<QString> Return the list of COM ports existents.
     */
    QList<QString> getCOMList();
    /**
     * @brief Closes the COM port.
     */
    void close();
    /**
     * @brief Reads all available data on the current COM port.
     * @return Return COM buffer data.
     */
    QString read();
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
    /**
     * @brief Sends a QString to the open COM port.
     * @param msg const QString & The QString to be sent.
     * @return int Returns true if it succeeds is sending the message, false otherwise.
     */
    int send( const QString & msg);
    /**
     * @brief sendByte
     * @param byte const char & Byte to be sent.
     * @return
     */
    int sendByte( const char & byte);
    /**
     * @brief Used to open communication with a COM port.
     * @param COMName const QString & Qstring that contain the name of the desired COM port.
     * @return Returns true if it succeeds in establish the connection, false otherwise.
     */
    bool connect( const QString & COMName);
};

#endif // SERIALCOM_H
