#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class QAction;
class QMenu;
class QPlainTextEdit;
class QSessionManager;
class QLineEdit;
class QDialog;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    void loadFile(const QString &fileName);

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void newFile();
    void open();
    bool save();
    bool saveAs();
    void about();
    void close();
    void find();
    void showFindText(); //Find Next按钮的槽

private:
    void createActions();
    void createStatusBar();

    bool maybeSave();
    bool saveFile(const QString &fileName);
    void setCurrentFile(const QString &fileName);

    void readSettings();
    void writeSettings();

    QString curFile;
    QPlainTextEdit *textEdit;
    bool isUntitled; //文件存在状态，为true时表示当前编辑内容没有对应的文件

    //查找界面有关对象
    QLineEdit *findLineEdit;
    QDialog *findDlg;
};

#endif // MAINWINDOW_H
