#ifndef MY_THREAD_H
#define MY_THREAD_H

#include <QThread>
#include<QTextEdit>
#include "file.h"

class my_thread : public QThread
{
    Q_OBJECT
public:
    explicit my_thread(QObject *parent = nullptr);
    void run();
    void set_text(QTextEdit*);
    void set_msg(QString);
    void set_file(file);
    void set_etat(bool);
    void set_nb(int);
    void set_mem_task(int);
    bool get_etat();
    void set_debblock(int);
    void set_vit(int);
signals:
    void change(QTextEdit*,QString);
    void defi(int);
    void desactiver_but(int);
    void Tfreeblock(int,QString,int);
    void resume();
private:
        QTextEdit* text;
        QString s;
        file f;
        bool etat;
        int nb,vitesse=1000;
        int mem_task;
        int debblock;
};

#endif // MY_THREAD_H
