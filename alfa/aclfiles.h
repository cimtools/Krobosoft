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
    /**
    * @brief Save content of QString into the file pointed by filename
    * @param content QString The content of the text-edit object to be saved
    * @return bool Confirms if the saving has occurrely succesfully
    */
    bool saveToFile(QString content);
    bool openFile();
    bool openFiles();
};

#endif // ACLFILES_H
