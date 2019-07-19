#ifndef SERIALCOM_H
#define SERIALCOM_H

#include <QQuickItem>
#include <QSerialPort>
#include <QSerialPortInfo>

class SerialCom : public QQuickItem
{
    Q_OBJECT
public:
    SerialCom();
    ~SerialCom();
    QList<QString> getCOMList();
    QString read();
    int connect(const QString & COMName);
    int send(const QString & msg);
    bool portListChanged();

private:
    QList<QSerialPortInfo> COMList;
    QSerialPort currentCOM;
signals:
    void readyRead();
public slots:
};

#endif // SERIALCOM_H
