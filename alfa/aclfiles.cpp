#include "aclfiles.h"

aclFiles::aclFiles()
{
    fileDialog = new QFileDialog();
    fileDialog->setFileMode(QFileDialog::AnyFile);
    fileDialog->setNameFilter(QObject::tr("All files(*.dnl);;Text File(*.txt)"));
    fileDialog->setViewMode(QFileDialog::Detail);
}


aclFiles::~aclFiles(){

}
void aclFiles::setFilename(){
    QFileInfo * Finfo;
    if(fileDialog->exec()){
        filenames = fileDialog->selectedFiles();
        if(filenames[0] != nullptr){
            filePath = filenames[0];
            Finfo = new QFileInfo(QFile(filePath));
            filename = Finfo->baseName();
        }else{
            filePath = nullptr;
            filename = nullptr;
        }
    }
}

QString aclFiles::getFilename(){
    return filename;
}

QString aclFiles::getFilePath(){
    return filePath;
}
bool aclFiles::saveToFile(QString text){
    if(filename != nullptr && filePath != nullptr){
        file = new QFile(filePath);
        if(file->open(QIODevice::ReadWrite)){
            QTextStream content(file);
            content << text << endl;
        }
        delete file;
        return true;
    }
    return false;
}

QString aclFiles::openFile(){
    QString text;
    if(filename != nullptr && filePath != nullptr){
        file = new QFile(filePath);
        if(!file->open(QIODevice::ReadOnly | QIODevice::Text)){
            return nullptr;
        }
        QTextStream in(file);
        while(!in.atEnd()){
            text += in.readLine() + " \n";
        }
        delete file;
        return text;
    }
    return nullptr;
}
