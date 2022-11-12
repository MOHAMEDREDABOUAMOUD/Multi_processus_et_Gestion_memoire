#ifndef ALGO_H
#define ALGO_H

#include <QMainWindow>
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "file.h"
#include <QTextStream>
#include <QMessageBox>
#include <QTextEdit>
#include <QStringList>
#include "my_thread.h"
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class algo; }
QT_END_NAMESPACE

struct mem{
    QString info;
    QTextEdit* text;
    mem *suiv;
};

class algo : public QMainWindow
{
    Q_OBJECT

public:
    algo(QWidget *parent = nullptr);
    ~algo();
    void clicked_();
    void exec(QTextEdit*,QString);
    void getblock(QString,int,int,QString);
    void init_listmem();
    void ramasse_miette();
    void pause();
    void complete();
    int memspace(int);
private:
    Ui::algo *ui;
    task T_sup[5],T_ord[10];
    file f_ord,f_sup;
    QString t[100];
    int cp1=1;
    bool paused;
    my_thread *thr,*thr2,*thr3,*thr4,*thr5,*thr6,*thr7,*thr8,*thr9,*thr10,*thr11,*thr12;
    bool etat,etat2,etat3,etat4,etat5,etat6,etat7,etat8,etatb,etatb2,etatb3,etatb4,etatb5,etatb6,etatb7,etatb8;
    QStringList list_ord,list_sup;
    mem *tete=NULL;
public slots:
    void onchange(QTextEdit*,QString);
    void ondefi(int);
    void ondesactiver_but(int);
    void freeblock(int,QString,int);
    void onresume();
private slots:
    void on_checkBox_stateChanged(int arg1);
};
#endif // ALGO_H
