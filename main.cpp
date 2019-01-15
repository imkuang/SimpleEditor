#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator translator;
    translator.load(":/i18n/zh_CN");
    a.installTranslator(&translator);
    QCoreApplication::setApplicationName("Simple Editor");

    MainWindow w;
    w.show();

    return a.exec();
}
