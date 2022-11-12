#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QTextEdit>

class mythread : public QThread
{
    Q_OBJECT
public:
    mythread();
    void run();
    void set_text(QTextEdit*);
    void set_msg(QString);
private:
    QTextEdit* text;
    QString s;
};

#endif // MYTHREAD_H
