#include "aclfiles.h"

aclFiles::aclFiles()
{
    fileDialog = new QFileDialog();
    fileDialog->setFileMode(QFileDialog::AnyFile);
    fileDialog->setNameFilter(QObject::tr("All files(*->acl*);;Text File(*->txt)"));
    fileDialog->setViewMode(QFileDialog::Detail);
}


aclFiles::~aclFiles(){

}
void aclFiles::setFilename(){
    if(fileDialog->exec()){
        filenames = fileDialog->selectedFiles();
        if(filenames[0] != nullptr)
            filename = filenames[0];
        else
            filename = nullptr;
    }
}

QString aclFiles::getFilename(){
    return filename;
}

bool aclFiles::saveToFile(QString text){
    if(filename != nullptr){
        file = new QFile(filename);
        if(file->open(QIODevice::ReadWrite)){
            QTextStream content(file);
            content << text << endl;
        }
        delete file;
        return true;
    }
    return false;
}
