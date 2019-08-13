#include "aclfiles.h"
#include <QDebug>

aclFiles::aclFiles(){
}
aclFiles::~aclFiles(){
}

void aclFiles::setFilename(bool type){
    fileDialog->setNameFilter(QObject::tr("All files(*.dnl);;Text File(*.txt)"));
    fileDialog->setViewMode(QFileDialog::Detail);
    QFileInfo * Finfo;
    if(fileDialog->exec()){
        filePaths = fileDialog->selectedFiles();
        if(filePaths[0] != nullptr){
            if(type){
                filePath = filenames[0];
                Finfo = new QFileInfo(QFile(filePath));
                filename = Finfo->baseName();
            } else {
                foreach(QString filepath, filePaths){
                    Finfo = new QFileInfo(QFile(filePath));
                    filenames << Finfo->baseName();
                }
            }
        }else{
            filePath = nullptr;
            filename = nullptr;
        }
    }
}

QString aclFiles::getFilename(){
    return filename;
}

QString aclFiles::getFilename(QString filepath){
    QFileInfo * Finfo;
    Finfo = new QFileInfo(QFile(filepath));
    return Finfo->baseName();
}

QStringList aclFiles::getFilenames(){
    return filenames;
}

QString aclFiles::getFilePath(){
    return filePath;
}

QStringList aclFiles::getFilePaths(){
    return filePaths;
}

bool aclFiles::saveToFile(QString text){
    filePath = QFileDialog::getSaveFileName(new QWidget,
                                            QObject::tr("Salvar aquivo"), "",
                                            QObject::tr("ACL File (*.dnl);;Text file(*.txt"));
    file = new QFile(filePath);
    QFileInfo * info = new QFileInfo(*file);
    filename = info->baseName();
    if(info->completeSuffix() == nullptr){
        file->setFileName(file->fileName() + ".dnl");
    }
    if(file->open(QIODevice::ReadWrite)){
        QTextStream content(file);
        content << text << endl;
    }
    delete file;
    return true;
}


void aclFiles::openFiles(){
    filePaths = QFileDialog::getOpenFileNames(new QWidget,
                                                QObject::tr("Abrir arquivos"), "",
                                                QObject::tr("ACL File (*.dnl);;Text file(*.txt"));
}

QString aclFiles::openFile(QString filepath){
    QString text;
    if(filepath.isEmpty()){
        return nullptr;
    } else {
        file = new QFile(filepath);
        if(!file->open(QIODevice::ReadOnly | QIODevice::Text)){
            return nullptr;
        }
        QTextStream in(file);
        //qDebug() << in.readLine();
        while(!in.atEnd()){
            text += in.readLine() + " \n";
        }
        delete file;
        return text;
    }
}
