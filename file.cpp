#include "file.h"

file::file()
{
}
void file::init_file(){
    f.tete=0;
    f.queue=-1;
    f.file_pleine=false;
    f.file_vide=true;
}
task file::defiler(){
    task t;
    t.content = "";
    if(f.file_vide==false){
        t=f.T[f.tete];
        if(f.tete<n-1) f.tete=f.tete+1;
        else f.tete=0;
        f.file_pleine=false;
        if((f.tete==0 && f.queue==n-1) || f.tete==f.queue+1) f.file_vide=true;
        else f.file_vide=false;
    }
    return t;
}

void file::emfiler(task t){
    if(f.file_pleine==false){
        if(f.tete<n-1) f.queue=f.queue+1;
        else f.queue=0;
        f.T[f.queue]=t;
        f.file_vide=false;
        if((f.tete==0 && f.queue==n-1) || f.tete==f.queue+1) f.file_pleine=true;
        else f.file_pleine=false;
    }
}
bool file::file_vide_(){
    return f.file_vide;
}
