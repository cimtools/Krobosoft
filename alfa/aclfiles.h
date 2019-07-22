#ifndef ACLFILES_H
#define ACLFILES_H

#include <QMainWindow>
#include <QObject>
#include <QFile>
#include <QFileDialog>
#include <QDir>
#include <QTextStream>
#include <QFileInfo>
class aclFiles
{
private:

    QStringList filenames;
    QString filename;
    QString filePath;
    QFileDialog *fileDialog;
    QFile *file;
public:
    /**
     * @brief aclFiles Constructor for the class.
     */
    aclFiles();

    /**
    * @brief ~aclFiles Destructor for the class.
    */
    ~aclFiles();
    /**
     * @brief setFilename open a pop-up windows to select a file. The name is stored at filename.
     */
    void setFilename();
    /**
     * @brief getFilename Returns the name of the file stored at filename.
     * @return QString The content of the attribute filename.
     */
    QString getFilename();
    /**
     * @brief getFilePath
     * @return
     */
    QString getFilePath();
    /**
    * @brief Save content of QString into the file pointed by filename.
    * @param content QString The content of the text-edit object to be saved.
    * @return bool Confirms if the saving has occurrely succesfully.
    */
    bool saveToFile(QString content);
    /**
     * @brief openFile Open a file and show it at a text-edit tab
     * @return bool Confirms if the file has been opened.
     */
    QString openFile();
    /**
     * @brief openFiles Open multiples files, each one in a differently text-edit tab.
     * @return bool Confirms if all the files opened correctly.
     */
    bool openFiles();
};

#endif // ACLFILES_H
