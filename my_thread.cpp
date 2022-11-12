#include "my_thread.h"

my_thread::my_thread(QObject *parent)
    : QThread{parent}
{

}
#include <iostream>

void my_thread::run()
{
    QChar c;
    QString ss;
    //task t;
    // label:
    QList<QString> list;
    //list.clear();
    list.push_back(s);
    for(int i=0;i<s.size()/* && !isInterruptionRequested()*/;i++)
    {
        if(etat==true)
        {
            c=list[0][i].toLatin1();
            ss=text->toPlainText();
            ss.append(c);
            emit change(text,ss);
            QThread::msleep(100);
        }
        else
        {
            QThread::msleep(50);
            i--;
        }
    }//cout<<"end tache";
   // cout<<mem_task<<" "<<debblock;
    text->setStyleSheet("background-color: white");
    emit Tfreeblock(mem_task,"",debblock);
    emit change(text,"");
    emit desactiver_but(nb);
    if(nb>=9 && nb<=12) emit resume();
    if(f.file_vide_()==false && nb<9) emit defi(1);
    else if(f.file_vide_()==false && nb>=9) emit defi(2);
}
void my_thread::set_text(QTextEdit* a){
    text=a;
}
void my_thread::set_file(file a){
    f=a;
}
void my_thread::set_msg(QString a){
    s=a;
}
void my_thread::set_etat(bool a){
    etat=a;
}
bool my_thread::get_etat(){
    return etat;
}
void my_thread::set_nb(int a){
    nb=a;
}
void my_thread::set_mem_task(int a)
{
    mem_task=a;
}
void my_thread::set_debblock(int a)
{
    debblock=a;
}
