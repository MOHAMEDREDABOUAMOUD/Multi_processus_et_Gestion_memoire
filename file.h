#ifndef FILE_H
#define FILE_H
#include <iostream>
#include <QMainWindow>
using namespace std;
const int n=100;
const int bloc=512000;
struct task{
    QString lib_task,content;
    int time_task,mem_task,level_task;//en sec
    bool state_task;
};
struct file_{
    task T[n];
    int tete,queue;
    bool file_vide,file_pleine;
};
class file
{
public:
    file();
    void init_file();
    void emfiler(task);
    bool file_vide_();
    task defiler();
private:
    file_ f;
};

#endif // FILE_H
