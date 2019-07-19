#ifndef ACLFILES_H
#define ACLFILES_H

#include <QMainWindow>
#include <QObject>
#include <QFile>
#include <QFileDialog>
#include <QDir>
#include <QTextStream>
class aclFiles
{
private:
    QStringList filenames;
    QString filename;
    QFileDialog *fileDialog;
    QFile *file;
public:
    aclFiles();
    void setFilename();
    QString getFilename();
    bool saveToFile(QString content);
    bool openFile();
    bool openFiles();
};

#endif // ACLFILES_H
