#include "algo.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <iostream>
#include <fstream>
#include "file.h"
using namespace std;

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "algo_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    algo w;

    w.show();
    return a.exec();
}
