#include "mythread.h"
#include "algo.h"
mythread::mythread()
{

}
void mythread::run(){
    QList<QString> list;
    list.push_back(s);
    QChar c;
    QString ss;
    for(int i=0;i<s.size();i++){
        c=list[0][i].toLatin1();
        ss=text->toPlainText();
        ss.append(c);
        //text->setText(ss);

        QThread::msleep(50);
    }

}
void mythread::set_text(QTextEdit* a){
    text=a;
}
void mythread::set_msg(QString a){
    s=a;
}
