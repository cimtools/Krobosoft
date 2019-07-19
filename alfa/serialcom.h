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
    QList<QString> getListaDePortas();
    QString lerDados();
    int conectar(const QString & nomeDaPorta);
    int enviar(const QString & mensagem);
    bool houveMudancaPortas();

private:
    QList<QSerialPortInfo> listaDePortas;
    QSerialPort portaAtual;
signals:
    void readyRead();
public slots:
};

#endif // SERIALCOM_H
