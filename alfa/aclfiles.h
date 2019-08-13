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
    QStringList filePaths;
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
     * @brief setFilename setFilename open a pop-up windows to select a file. The name is stored at filename.
     * @param type bool Decide if the dialog will be for openning (allow multiple files) ou saving (one file only)
     */
    void setFilename(bool type=0);
    /**
     * @brief getFilename Getter for the private attribute filename.
     * @return QString The content of the attribute filename.
     */
    QString getFilename();
    /**
     * @brief getFilename Getter for the base name of a file pointed by filepath
     * @param filepath QString The path for a file
     * @return QString the base name of the file pointed by filepath
     */
    QString getFilename(QString filepath);
    /**
     * @brief getFilenames Getter for the private attribute filenames
     * @return QStringList the content of the attribute filenames
     */
    QStringList getFilenames();
    /**
     * @brief getFilePath Getter for the private attribute filePath
     * @return QString the content of the attribute filePath
     */

    QString getFilePath();

    /**
     * @brief getFilePaths Getter for the private attribute filePaths
     * @return QStringList the content of the attribute filePaths
     */
    QStringList getFilePaths();
    /**
    * @brief Save content of QString into the file pointed by filename.
    * @param content QString The content of the text-edit object to be saved.
    * @return bool Confirms if the saving has occurrely succesfully.
    */
    bool saveToFile(QString content);

    void openFiles();
    /**
     * @brief openFile Gets the content of a file pointed by filepath
     * @param filepath The path to a given file
     * @return QString the content of a file
     */
    QString openFile(QString filepath);

};

#endif // ACLFILES_H
