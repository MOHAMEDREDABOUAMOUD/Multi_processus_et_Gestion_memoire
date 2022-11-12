#include "algo.h"
#include "ui_algo.h"
#include <QStringListModel>
int ntask=1;
int nblock=1;
bool mempleine=false;
algo::algo(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::algo)
{
    ui->setupUi(this);
    init_listmem();
    connect(ui->import_2,&QPushButton::clicked,this,&algo::clicked_);
    connect(ui->execute,&QPushButton::clicked,this,&algo::clicked_);
    connect(ui->pushButton,&QPushButton::clicked,this,&algo::clicked_);
    connect(ui->pushButton_2,&QPushButton::clicked,this,&algo::clicked_);
    connect(ui->pushButton_3,&QPushButton::clicked,this,&algo::clicked_);
    connect(ui->pushButton_4,&QPushButton::clicked,this,&algo::clicked_);
    connect(ui->pushButton_5,&QPushButton::clicked,this,&algo::clicked_);
    connect(ui->pushButton_6,&QPushButton::clicked,this,&algo::clicked_);
    connect(ui->pushButton_7,&QPushButton::clicked,this,&algo::clicked_);
    connect(ui->pushButton_8,&QPushButton::clicked,this,&algo::clicked_);
    connect(ui->pushButton_9,&QPushButton::clicked,this,&algo::clicked_);
    connect(ui->pushButton_10,&QPushButton::clicked,this,&algo::clicked_);
    connect(ui->pushButton_11,&QPushButton::clicked,this,&algo::clicked_);
    connect(ui->pushButton_12,&QPushButton::clicked,this,&algo::clicked_);
    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_7->setEnabled(false);
    ui->pushButton_8->setEnabled(false);
    ui->pushButton_9->setEnabled(false);
    ui->pushButton_10->setEnabled(false);
    ui->pushButton_11->setEnabled(false);
    ui->pushButton_12->setEnabled(false);
    ifstream f("C:/Users/hp/Desktop/2eme annee/QT/algo/msg.txt",ios::in);
    string s;
    if(f.good())
    {
        for(int j=0;j<100;j++)
        {
            getline(f,s);
            t[j]=QString::fromStdString(s);
        }
        f.close();
    }
     thr=new my_thread(this);
     thr2=new my_thread(this);
     thr3=new my_thread(this);
     thr4=new my_thread(this);
     thr5=new my_thread(this);
     thr6=new my_thread(this);
     thr7=new my_thread(this);
     thr8=new my_thread(this);
     thr9=new my_thread(this);
     thr10=new my_thread(this);
     thr11=new my_thread(this);
     thr12=new my_thread(this);

     connect(thr,SIGNAL(Tfreeblock(int,QString,int)),this,SLOT(freeblock(int,QString,int)));
     connect(thr2,SIGNAL(Tfreeblock(int,QString,int)),this,SLOT(freeblock(int,QString,int)));
     connect(thr3,SIGNAL(Tfreeblock(int,QString,int)),this,SLOT(freeblock(int,QString,int)));
     connect(thr4,SIGNAL(Tfreeblock(int,QString,int)),this,SLOT(freeblock(int,QString,int)));
     connect(thr5,SIGNAL(Tfreeblock(int,QString,int)),this,SLOT(freeblock(int,QString,int)));
     connect(thr6,SIGNAL(Tfreeblock(int,QString,int)),this,SLOT(freeblock(int,QString,int)));
     connect(thr7,SIGNAL(Tfreeblock(int,QString,int)),this,SLOT(freeblock(int,QString,int)));
     connect(thr8,SIGNAL(Tfreeblock(int,QString,int)),this,SLOT(freeblock(int,QString,int)));
     connect(thr9,SIGNAL(Tfreeblock(int,QString,int)),this,SLOT(freeblock(int,QString,int)));
     connect(thr10,SIGNAL(Tfreeblock(int,QString,int)),this,SLOT(freeblock(int,QString,int)));
     connect(thr11,SIGNAL(Tfreeblock(int,QString,int)),this,SLOT(freeblock(int,QString,int)));
     connect(thr12,SIGNAL(Tfreeblock(int,QString,int)),this,SLOT(freeblock(int,QString,int)));

     connect(thr,SIGNAL(change(QTextEdit*,QString)),this,SLOT(onchange(QTextEdit*,QString)));
     connect(thr2,SIGNAL(change(QTextEdit*,QString)),this,SLOT(onchange(QTextEdit*,QString)));
     connect(thr3,SIGNAL(change(QTextEdit*,QString)),this,SLOT(onchange(QTextEdit*,QString)));
     connect(thr4,SIGNAL(change(QTextEdit*,QString)),this,SLOT(onchange(QTextEdit*,QString)));
     connect(thr5,SIGNAL(change(QTextEdit*,QString)),this,SLOT(onchange(QTextEdit*,QString)));
     connect(thr6,SIGNAL(change(QTextEdit*,QString)),this,SLOT(onchange(QTextEdit*,QString)));
     connect(thr7,SIGNAL(change(QTextEdit*,QString)),this,SLOT(onchange(QTextEdit*,QString)));
     connect(thr8,SIGNAL(change(QTextEdit*,QString)),this,SLOT(onchange(QTextEdit*,QString)));
     connect(thr9,SIGNAL(change(QTextEdit*,QString)),this,SLOT(onchange(QTextEdit*,QString)));
     connect(thr10,SIGNAL(change(QTextEdit*,QString)),this,SLOT(onchange(QTextEdit*,QString)));
     connect(thr11,SIGNAL(change(QTextEdit*,QString)),this,SLOT(onchange(QTextEdit*,QString)));
     connect(thr12,SIGNAL(change(QTextEdit*,QString)),this,SLOT(onchange(QTextEdit*,QString)));

     connect(thr9,SIGNAL(resume()),this,SLOT(onresume()));
     connect(thr10,SIGNAL(resume()),this,SLOT(onresume()));
     connect(thr11,SIGNAL(resume()),this,SLOT(onresume()));
     connect(thr12,SIGNAL(resume()),this,SLOT(onresume()));

     f_ord.init_file();
     f_sup.init_file();
     connect(thr,SIGNAL(defi(int)),this,SLOT(ondefi(int)));
     connect(thr2,SIGNAL(defi(int)),this,SLOT(ondefi(int)));
     connect(thr3,SIGNAL(defi(int)),this,SLOT(ondefi(int)));
     connect(thr4,SIGNAL(defi(int)),this,SLOT(ondefi(int)));
     connect(thr5,SIGNAL(defi(int)),this,SLOT(ondefi(int)));
     connect(thr6,SIGNAL(defi(int)),this,SLOT(ondefi(int)));
     connect(thr7,SIGNAL(defi(int)),this,SLOT(ondefi(int)));
     connect(thr8,SIGNAL(defi(int)),this,SLOT(ondefi(int)));
     connect(thr9,SIGNAL(defi(int)),this,SLOT(ondefi(int)));
     connect(thr10,SIGNAL(defi(int)),this,SLOT(ondefi(int)));
     connect(thr11,SIGNAL(defi(int)),this,SLOT(ondefi(int)));
     connect(thr12,SIGNAL(defi(int)),this,SLOT(ondefi(int)));

     connect(thr,SIGNAL(desactiver_but(int)),this,SLOT(ondesactiver_but(int)));
     connect(thr2,SIGNAL(desactiver_but(int)),this,SLOT(ondesactiver_but(int)));
     connect(thr3,SIGNAL(desactiver_but(int)),this,SLOT(ondesactiver_but(int)));
     connect(thr4,SIGNAL(desactiver_but(int)),this,SLOT(ondesactiver_but(int)));
     connect(thr5,SIGNAL(desactiver_but(int)),this,SLOT(ondesactiver_but(int)));
     connect(thr6,SIGNAL(desactiver_but(int)),this,SLOT(ondesactiver_but(int)));
     connect(thr7,SIGNAL(desactiver_but(int)),this,SLOT(ondesactiver_but(int)));
     connect(thr8,SIGNAL(desactiver_but(int)),this,SLOT(ondesactiver_but(int)));
     connect(thr9,SIGNAL(desactiver_but(int)),this,SLOT(ondesactiver_but(int)));
     connect(thr10,SIGNAL(desactiver_but(int)),this,SLOT(ondesactiver_but(int)));
     connect(thr11,SIGNAL(desactiver_but(int)),this,SLOT(ondesactiver_but(int)));
     connect(thr12,SIGNAL(desactiver_but(int)),this,SLOT(ondesactiver_but(int)));
     ui->listView_41->setModel(new QStringListModel(list_ord));
     ui->listView->setModel(new QStringListModel(list_sup));
     thr->set_etat(true);
     thr2->set_etat(true);
     thr3->set_etat(true);
     thr4->set_etat(true);
     thr5->set_etat(true);
     thr6->set_etat(true);
     thr7->set_etat(true);
     thr8->set_etat(true);
     thr9->set_etat(true);
     thr10->set_etat(true);
     thr11->set_etat(true);
     thr12->set_etat(true);

     thr->set_nb(1);
     thr2->set_nb(2);
     thr3->set_nb(3);
     thr4->set_nb(4);
     thr5->set_nb(5);
     thr6->set_nb(6);
     thr7->set_nb(7);
     thr8->set_nb(8);
     thr9->set_nb(9);
     thr10->set_nb(10);
     thr11->set_nb(11);
     thr12->set_nb(12);

     etat=true;
     etat2=true;
     etat3=true;
     etat4=true;
     etat5=true;
     etat6=true;
     etat7=true;
     etat8=true;
     paused=false;
}

algo::~algo()
{
    delete ui;
}

void algo::ramasse_miette()
{
    mem *p,*q,*pred;bool trouve;
    p=tete;
    for(int i=1;i<=24;i++)
    {
        if(p->info=="")
        {
            q=p->suiv;trouve=false;
            for(int j=i;j<=24;j++)
            {
                if(q->info!="")
                {
                    trouve=true;
                }
                if(q!=NULL) q=q->suiv;
            }
            if(trouve==true)
            {
                while(p->info=="")
                {
                    pred=p;q=p->suiv;
                    for(int j=i;j<24;j++)
                    {
                        pred->info=q->info;
                        pred->text->setText(q->info);
                        pred->text->setStyleSheet(q->text->styleSheet());
                        pred=pred->suiv;
                        if(q!=NULL) q=q->suiv;
                    }
                    pred->info="";pred->text->setText("");pred->text->setStyleSheet("background-color: white");
                }
            }
        }
        if(p!=NULL) p=p->suiv;
    }
}

int algo::memspace(int ran)
{
    mem* p=tete;mem* q;int cp;
    for(int i=1;i<=24;i++)
    {
        if(p!=NULL)
        {
            if(p->info=="")
            {
                q=p;cp=0;
                for(int j=1;j<=ran;j++)
                {
                    if(q!=NULL)
                    {
                        if(q->info=="")
                        {
                            cp=cp+1;
                        }
                        q=q->suiv;
                    }
                }
                if(cp==ran) return i;
            }
            p=p->suiv;
        }
    }
    return -1;
}

void algo::init_listmem()
{
    mem *p,*q;
    p=new mem();
    p->info="";
    p->text=ui->block1;
    p->suiv=NULL;
    tete=p;
    q=p;
    for(int i=1;i<=24;i++)
    {
        p=new mem();
        p->info="";
        p->suiv=NULL;
        q->suiv=p;
        q=p;
    }
    p=tete;
    p->text=ui->block1;
    p=p->suiv;
    p->text=ui->block2;
    p=p->suiv;
    p->text=ui->block3;
    p=p->suiv;
    p->text=ui->block4;
    p=p->suiv;
    p->text=ui->block5;
    p=p->suiv;
    p->text=ui->block6;
    p=p->suiv;
    p->text=ui->block7;
    p=p->suiv;
    p->text=ui->block8;
    p=p->suiv;
    p->text=ui->block9;
    p=p->suiv;
    p->text=ui->block10;
    p=p->suiv;
    p->text=ui->block11;
    p=p->suiv;
    p->text=ui->block12;
    p=p->suiv;
    p->text=ui->block13;
    p=p->suiv;
    p->text=ui->block14;
    p=p->suiv;
    p->text=ui->block15;
    p=p->suiv;
    p->text=ui->block16;
    p=p->suiv;
    p->text=ui->block17;
    p=p->suiv;
    p->text=ui->block18;
    p=p->suiv;
    p->text=ui->block19;
    p=p->suiv;
    p->text=ui->block20;
    p=p->suiv;
    p->text=ui->block21;
    p=p->suiv;
    p->text=ui->block22;
    p=p->suiv;
    p->text=ui->block23;
    p=p->suiv;
    p->text=ui->block24;
    p=p->suiv;
}

void algo::freeblock(int ran,QString nmr,int debblock)
{
    mem * p=tete;
    for(int i=1;i<debblock;i++)
    {
        if(p!=NULL) p=p->suiv;
    }
    for(int i=1;i<=ran;i++)
    {
        if(p!=NULL)
        {
            p->info="";
            p->text->setText(nmr);p->text->setStyleSheet("background-color: white");
            p=p->suiv;
        }
    }
}

void algo::getblock(QString c,int debblock,int ran,QString nmr)
{
    mem * p=tete;
    for(int i=1;i<debblock;i++)
    {
        if(p!=NULL) p=p->suiv;
    }
    for(int i=1;i<=ran;i++)
    {
        if(p!=NULL)
        {
            p->info=nmr;
            p->text->setText(nmr);p->text->setStyleSheet("background-color: "+c);
            p=p->suiv;
        }
    }
}

void algo::onchange(QTextEdit* a,QString s){
   a->setText(s);
}
void algo::ondesactiver_but(int nb){
    if(nb==1){
        ui->pushButton->setEnabled(false);etatb=false;
    }
    if(nb==2){
         ui->pushButton_2->setEnabled(false);etatb2=false;
    }
    if(nb==3){
         ui->pushButton_3->setEnabled(false);etatb3=false;
    }
    if(nb==4){
         ui->pushButton_4->setEnabled(false);etatb4=false;
    }
    if(nb==5){
         ui->pushButton_5->setEnabled(false);etatb5=false;
    }
    if(nb==6){
         ui->pushButton_6->setEnabled(false);etatb6=false;
    }
    if(nb==7){
         ui->pushButton_7->setEnabled(false);etatb7=false;
    }
    if(nb==8){
         ui->pushButton_8->setEnabled(false);etatb8=false;
    }
    if(nb==9) ui->pushButton_9->setEnabled(false);
    if(nb==10) ui->pushButton_10->setEnabled(false);
    if(nb==11) ui->pushButton_11->setEnabled(false);
    if(nb==12) ui->pushButton_12->setEnabled(false);
}

void algo::ondefi(int a){
   task t;
   if(a==1 && memspace(6)!=-1)
   {
       if(ui->textEdit->toPlainText()=="" && thr->get_etat()==true && f_ord.file_vide_()==false)
       {
           ui->textEdit->setStyleSheet("background-color: red");
           t=f_ord.defiler();
           list_ord.removeAt(0);
           ((QStringListModel*) ui->listView_41->model())->setStringList(list_ord);
           thr->set_file(f_ord);
           thr2->set_file(f_ord);
           thr3->set_file(f_ord);
           thr4->set_file(f_ord);
           thr5->set_file(f_ord);
           thr6->set_file(f_ord);
           thr7->set_file(f_ord);
           thr8->set_file(f_ord);
           ui->pushButton->setEnabled(true);
           thr->set_msg(t.content);
           thr->set_text(ui->textEdit);
           thr->set_mem_task(t.mem_task);
           int debblock=memspace(t.mem_task);
           thr->set_debblock(debblock);
           getblock("red",debblock,t.mem_task,QString::number(ntask));
           ntask++;
           thr->start();
       }
       if(ui->textEdit_2->toPlainText()=="" && thr2->get_etat()==true && f_ord.file_vide_()==false)
       {
           ui->textEdit_2->setStyleSheet("background-color: blue");
           t=f_ord.defiler();
           list_ord.removeAt(0);
           ((QStringListModel*) ui->listView_41->model())->setStringList(list_ord);
           thr->set_file(f_ord);
           thr2->set_file(f_ord);
           thr3->set_file(f_ord);
           thr4->set_file(f_ord);
           thr5->set_file(f_ord);
           thr6->set_file(f_ord);
           thr7->set_file(f_ord);
           thr8->set_file(f_ord);
           ui->pushButton_2->setEnabled(true);
           thr2->set_msg(t.content);
           thr2->set_text(ui->textEdit_2);
           thr2->set_mem_task(t.mem_task);
           int debblock=memspace(t.mem_task);
           thr2->set_debblock(debblock);
           getblock("blue",debblock,t.mem_task,QString::number(ntask));
           ntask++;
           thr2->start();
       }
       if(ui->textEdit_3->toPlainText()=="" && thr3->get_etat()==true && f_ord.file_vide_()==false)
       {
           ui->textEdit_3->setStyleSheet("background-color: yellow");
           t=f_ord.defiler();
           list_ord.removeAt(0);
           ((QStringListModel*) ui->listView_41->model())->setStringList(list_ord);
           thr->set_file(f_ord);
           thr2->set_file(f_ord);
           thr3->set_file(f_ord);
           thr4->set_file(f_ord);
           thr5->set_file(f_ord);
           thr6->set_file(f_ord);
           thr7->set_file(f_ord);
           thr8->set_file(f_ord);
           ui->pushButton_3->setEnabled(true);
           thr3->set_msg(t.content);
           thr3->set_text(ui->textEdit_3);
           thr3->set_mem_task(t.mem_task);
           int debblock=memspace(t.mem_task);
           thr3->set_debblock(debblock);
           getblock("yellow",debblock,t.mem_task,QString::number(ntask));
           ntask++;
           thr3->start();
       }
       if(ui->textEdit_4->toPlainText()=="" && thr4->get_etat()==true && f_ord.file_vide_()==false){
           ui->textEdit_4->setStyleSheet("background-color: green");
           t=f_ord.defiler();
           list_ord.removeAt(0);
           ((QStringListModel*) ui->listView_41->model())->setStringList(list_ord);
           thr->set_file(f_ord);
           thr2->set_file(f_ord);
           thr3->set_file(f_ord);
           thr4->set_file(f_ord);
           thr5->set_file(f_ord);
           thr6->set_file(f_ord);
           thr7->set_file(f_ord);
           thr8->set_file(f_ord);
           ui->pushButton_4->setEnabled(true);
           thr4->set_msg(t.content);
           thr4->set_text(ui->textEdit_4);
           thr4->set_mem_task(t.mem_task);
           int debblock=memspace(t.mem_task);
           thr4->set_debblock(debblock);
           getblock("green",debblock,t.mem_task,QString::number(ntask));
           ntask++;
           thr4->start();
       }
       if(ui->textEdit_5->toPlainText()=="" && thr5->get_etat()==true && f_ord.file_vide_()==false){
           ui->textEdit_5->setStyleSheet("background-color: gray");
           t=f_ord.defiler();
           list_ord.removeAt(0);
           ((QStringListModel*) ui->listView_41->model())->setStringList(list_ord);
           thr->set_file(f_ord);
           thr2->set_file(f_ord);
           thr3->set_file(f_ord);
           thr4->set_file(f_ord);
           thr5->set_file(f_ord);
           thr6->set_file(f_ord);
           thr7->set_file(f_ord);
           thr8->set_file(f_ord);
           ui->pushButton_5->setEnabled(true);
           thr5->set_msg(t.content);
           thr5->set_text(ui->textEdit_5);
           thr5->set_mem_task(t.mem_task);
           int debblock=memspace(t.mem_task);
           thr5->set_debblock(debblock);
           getblock("gray",debblock,t.mem_task,QString::number(ntask));
           ntask++;
           thr5->start();
       }
       if(ui->textEdit_6->toPlainText()=="" && thr6->get_etat()==true && f_ord.file_vide_()==false){
           ui->textEdit_6->setStyleSheet("background-color: brown");
           t=f_ord.defiler();
           list_ord.removeAt(0);
           ((QStringListModel*) ui->listView_41->model())->setStringList(list_ord);
           thr->set_file(f_ord);
           thr2->set_file(f_ord);
           thr3->set_file(f_ord);
           thr4->set_file(f_ord);
           thr5->set_file(f_ord);
           thr6->set_file(f_ord);
           thr7->set_file(f_ord);
           thr8->set_file(f_ord);
           ui->pushButton_6->setEnabled(true);
           thr6->set_msg(t.content);
           thr6->set_text(ui->textEdit_6);
           thr6->set_mem_task(t.mem_task);
           int debblock=memspace(t.mem_task);
           thr6->set_debblock(debblock);
           getblock("brown",debblock,t.mem_task,QString::number(ntask));
           ntask++;
           thr6->start();
       }
       if(ui->textEdit_7->toPlainText()=="" && thr7->get_etat()==true && f_ord.file_vide_()==false){
           ui->textEdit_7->setStyleSheet("background-color: pink");
           t=f_ord.defiler();
           list_ord.removeAt(0);
           ((QStringListModel*) ui->listView_41->model())->setStringList(list_ord);
           thr->set_file(f_ord);
           thr2->set_file(f_ord);
           thr3->set_file(f_ord);
           thr4->set_file(f_ord);
           thr5->set_file(f_ord);
           thr6->set_file(f_ord);
           thr7->set_file(f_ord);
           thr8->set_file(f_ord);
           ui->pushButton_7->setEnabled(true);
           thr7->set_msg(t.content);
           thr7->set_text(ui->textEdit_7);
           thr7->set_mem_task(t.mem_task);
           int debblock=memspace(t.mem_task);
           thr7->set_debblock(debblock);
           getblock("pink",debblock,t.mem_task,QString::number(ntask));
           ntask++;
           thr7->start();
       }
       if(ui->textEdit_8->toPlainText()=="" && thr8->get_etat()==true && f_ord.file_vide_()==false){
           ui->textEdit_8->setStyleSheet("background-color: purple");
           t=f_ord.defiler();
           list_ord.removeAt(0);
           ((QStringListModel*) ui->listView_41->model())->setStringList(list_ord);
           thr->set_file(f_ord);
           thr2->set_file(f_ord);
           thr3->set_file(f_ord);
           thr4->set_file(f_ord);
           thr5->set_file(f_ord);
           thr6->set_file(f_ord);
           thr7->set_file(f_ord);
           thr8->set_file(f_ord);
           ui->pushButton_8->setEnabled(true);
           thr8->set_msg(t.content);
           thr8->set_text(ui->textEdit_8);
           thr8->set_mem_task(t.mem_task);
           int debblock=memspace(t.mem_task);
           thr8->set_debblock(debblock);
           getblock("purple",debblock,t.mem_task,QString::number(ntask));
           ntask++;
           thr8->start();
       }
   }
   else if(a==0 && memspace(6)!=-1)
   {
       if(ui->textEdit_9->toPlainText()=="" && thr9->get_etat()==true && f_sup.file_vide_()==false){
           ui->textEdit_9->setStyleSheet("background-color: red");
           t=f_sup.defiler();
           list_sup.removeAt(0);
           ((QStringListModel*) ui->listView->model())->setStringList(list_sup);
           thr9->set_file(f_sup);
           thr10->set_file(f_sup);
           thr11->set_file(f_sup);
           thr12->set_file(f_sup);
           ui->pushButton_9->setEnabled(true);
           thr9->set_msg(t.content);
           thr9->set_text(ui->textEdit_9);
           thr9->set_mem_task(t.mem_task);
           int debblock=memspace(t.mem_task);
           thr9->set_debblock(debblock);
           getblock("red",debblock,t.mem_task,QString::number(ntask));
           ntask++;
           thr9->start();
           if(paused==false){
                pause();
                paused=true;
           }
       }
       if(ui->textEdit_10->toPlainText()=="" && thr10->get_etat()==true && f_sup.file_vide_()==false){
           ui->textEdit_10->setStyleSheet("background-color: red");
           t=f_sup.defiler();
           list_sup.removeAt(0);
           ((QStringListModel*) ui->listView->model())->setStringList(list_sup);
           thr9->set_file(f_sup);
           thr10->set_file(f_sup);
           thr11->set_file(f_sup);
           thr12->set_file(f_sup);
           ui->pushButton_10->setEnabled(true);
           thr10->set_msg(t.content);
           thr10->set_text(ui->textEdit_10);
           thr10->set_mem_task(t.mem_task);
           int debblock=memspace(t.mem_task);
           thr10->set_debblock(debblock);
           getblock("red",debblock,t.mem_task,QString::number(ntask));
           ntask++;
           thr10->start();
           if(paused==false){
                pause();
                paused=true;
           }
       }
       if(ui->textEdit_11->toPlainText()=="" && thr11->get_etat()==true && f_sup.file_vide_()==false){
           ui->textEdit_11->setStyleSheet("background-color: red");
           t=f_sup.defiler();
           list_sup.removeAt(0);
           ((QStringListModel*) ui->listView->model())->setStringList(list_sup);
           thr9->set_file(f_sup);
           thr10->set_file(f_sup);
           thr11->set_file(f_sup);
           thr12->set_file(f_sup);
           ui->pushButton_11->setEnabled(true);
           thr11->set_msg(t.content);
           thr11->set_text(ui->textEdit_11);
           thr11->set_mem_task(t.mem_task);
           int debblock=memspace(t.mem_task);
           thr11->set_debblock(debblock);
           getblock("red",debblock,t.mem_task,QString::number(ntask));
           ntask++;
           thr11->start();
           if(paused==false){
                pause();
                paused=true;
           }
       }
       if(ui->textEdit_12->toPlainText()=="" && thr12->get_etat()==true && f_sup.file_vide_()==false){
           ui->textEdit_12->setStyleSheet("background-color: red");
           t=f_sup.defiler();
           list_sup.removeAt(0);
           ((QStringListModel*) ui->listView->model())->setStringList(list_sup);
           thr9->set_file(f_sup);
           thr10->set_file(f_sup);
           thr11->set_file(f_sup);
           thr12->set_file(f_sup);
           ui->pushButton_12->setEnabled(true);
           thr12->set_msg(t.content);
           thr12->set_text(ui->textEdit_12);
           thr12->set_mem_task(t.mem_task);
           int debblock=memspace(t.mem_task);
           thr12->set_debblock(debblock);
           getblock("red",debblock,t.mem_task,QString::number(ntask));
           ntask++;
           thr12->start();
           if(paused==false){
                pause();
                paused=true;
           }
       }
   }
}

void algo::pause(){
    etat=thr->get_etat();
    etat2=thr2->get_etat();
    etat3=thr3->get_etat();
    etat4=thr4->get_etat();
    etat5=thr5->get_etat();
    etat6=thr6->get_etat();
    etat7=thr7->get_etat();
    etat8=thr8->get_etat();
    thr->set_etat(false);
    thr2->set_etat(false);
    thr3->set_etat(false);
    thr4->set_etat(false);
    thr5->set_etat(false);
    thr6->set_etat(false);
    thr7->set_etat(false);
    thr8->set_etat(false);
    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_7->setEnabled(false);
    ui->pushButton_8->setEnabled(false);
}

void algo::onresume(){
    if(ui->textEdit_9->toPlainText()=="" && ui->textEdit_10->toPlainText()=="" && ui->textEdit_11->toPlainText()=="" && ui->textEdit_12->toPlainText()=="" && f_sup.file_vide_()==true){
        paused=false;
        thr->set_etat(etat);
        thr2->set_etat(etat2);
        thr3->set_etat(etat3);
        thr4->set_etat(etat4);
        thr5->set_etat(etat5);
        thr6->set_etat(etat6);
        thr7->set_etat(etat7);
        thr8->set_etat(etat8);
        ui->pushButton->setEnabled(etatb);
        ui->pushButton_2->setEnabled(etatb2);
        ui->pushButton_3->setEnabled(etatb3);
        ui->pushButton_4->setEnabled(etatb4);
        ui->pushButton_5->setEnabled(etatb5);
        ui->pushButton_6->setEnabled(etatb6);
        ui->pushButton_7->setEnabled(etatb7);
        ui->pushButton_8->setEnabled(etatb8);
        if(f_ord.file_vide_()==false) ondefi(1);
    }

}

void algo::clicked_()
{
    srand(time(0));
    task k;
    int x;
    QPushButton* but=qobject_cast<QPushButton*>(sender());
    QString task_name="task ";
    if(but==ui->execute)
    {
        if(memspace(6)!=-1)
        {
           task_name.append(QString::number(cp1));
           list_ord.append(task_name);
           ((QStringListModel*) ui->listView_41->model())->setStringList(list_ord);
           cp1++;
           x=rand()%100;
           k.content=t[x];
           k.level_task=0;
           k.lib_task=task_name;
           k.time_task=1;
           int ran;
           srand(time(0));
           ran=rand()%4+3;
           k.mem_task=ran;
           if(cp1%10!=0)
           {
               f_ord.emfiler(k);
               thr->set_file(f_ord);
               thr2->set_file(f_ord);
               thr3->set_file(f_ord);
               thr4->set_file(f_ord);
               thr5->set_file(f_ord);
               thr6->set_file(f_ord);
               thr7->set_file(f_ord);
               thr8->set_file(f_ord);

                if(ui->textEdit->toPlainText()=="" && thr->get_etat()==true){
                    ui->textEdit->setStyleSheet("background-color: red");
                    ui->pushButton->setEnabled(true);etatb=true;
                    k=f_ord.defiler();
                    thr->set_msg(t[x]);
                    thr->set_text(ui->textEdit);
                    thr->set_mem_task(ran);
                    int debblock=memspace(k.mem_task);
                    thr->set_debblock(debblock);
                    getblock("red",debblock,ran,QString::number(ntask));
                    ntask++;
                    thr->start();
                    list_ord.removeAt(0);
                    ((QStringListModel*) ui->listView_41->model())->setStringList(list_ord);
                }
                else if(ui->textEdit_2->toPlainText()=="" && thr2->get_etat()==true){
                    ui->textEdit_2->setStyleSheet("background-color: blue");
                    ui->pushButton_2->setEnabled(true);etatb2=true;
                    k=f_ord.defiler();

                    thr2->set_msg(t[x]);
                    thr2->set_text(ui->textEdit_2);
                    thr2->set_mem_task(ran);
                    int debblock=memspace(k.mem_task);
                    thr2->set_debblock(debblock);
                    ///////////////
                    getblock("blue",debblock,ran,QString::number(ntask));
                    ntask++;
                    ///////////////////
                    thr2->start();
                    list_ord.removeAt(0);
                    ((QStringListModel*) ui->listView_41->model())->setStringList(list_ord);
                }
                else if(ui->textEdit_3->toPlainText()=="" && thr3->get_etat()==true){
                    ui->textEdit_3->setStyleSheet("background-color: yellow");
                    ui->pushButton_3->setEnabled(true);etatb3=true;
                    k=f_ord.defiler();
                    thr3->set_msg(t[x]);
                    thr3->set_text(ui->textEdit_3);
                    thr3->set_mem_task(ran);
                    int debblock=memspace(k.mem_task);
                    thr3->set_debblock(debblock);
                    getblock("yellow",debblock,ran,QString::number(ntask));
                    ntask++;
                    thr3->start();
                    list_ord.removeAt(0);
                    ((QStringListModel*) ui->listView_41->model())->setStringList(list_ord);
                }
                else if(ui->textEdit_4->toPlainText()=="" && thr4->get_etat()==true){
                    ui->textEdit_4->setStyleSheet("background-color: green");
                    ui->pushButton_4->setEnabled(true);etatb4=true;
                    k=f_ord.defiler();
                    thr4->set_msg(t[x]);
                    thr4->set_text(ui->textEdit_4);
                    int debblock=memspace(k.mem_task);
                    thr4->set_debblock(debblock);
                    thr4->set_mem_task(ran);
                    getblock("green",debblock,ran,QString::number(ntask));
                    ntask++;
                    thr4->start();
                    list_ord.removeAt(0);
                    ((QStringListModel*) ui->listView_41->model())->setStringList(list_ord);
                }
                else if(ui->textEdit_5->toPlainText()=="" && thr5->get_etat()==true){
                    ui->textEdit_5->setStyleSheet("background-color: gray");
                    ui->pushButton_5->setEnabled(true);etatb5=true;
                    k=f_ord.defiler();
                    thr5->set_msg(t[x]);
                    thr5->set_text(ui->textEdit_5);
                    int debblock=memspace(k.mem_task);
                    thr5->set_debblock(debblock);
                    thr5->set_mem_task(ran);
                    getblock("gray",debblock,ran,QString::number(ntask));
                    ntask++;
                    thr5->start();
                    list_ord.removeAt(0);
                    ((QStringListModel*) ui->listView_41->model())->setStringList(list_ord);
                }
                else if(ui->textEdit_6->toPlainText()=="" && thr6->get_etat()==true){
                    ui->textEdit_6->setStyleSheet("background-color: brown");
                    ui->pushButton_6->setEnabled(true);etatb6=true;
                    k=f_ord.defiler();
                    thr6->set_msg(t[x]);
                    thr6->set_text(ui->textEdit_6);
                    thr6->set_mem_task(ran);
                    int debblock=memspace(k.mem_task);
                    thr6->set_debblock(debblock);
                    getblock("brown",debblock,ran,QString::number(ntask));
                    ntask++;

                    thr6->start();
                    list_ord.removeAt(0);
                    ((QStringListModel*) ui->listView_41->model())->setStringList(list_ord);
                }
                else if(ui->textEdit_7->toPlainText()=="" && thr7->get_etat()==true){
                    ui->textEdit_7->setStyleSheet("background-color: pink");
                    ui->pushButton_7->setEnabled(true);etatb7=true;
                    k=f_ord.defiler();
                    thr7->set_msg(t[x]);
                    thr7->set_text(ui->textEdit_7);
                    thr7->set_mem_task(ran);
                    int debblock=memspace(k.mem_task);
                    thr7->set_debblock(debblock);
                    getblock("pink",debblock,ran,QString::number(ntask));
                    ntask++;

                    thr7->start();
                    list_ord.removeAt(0);
                    ((QStringListModel*) ui->listView_41->model())->setStringList(list_ord);
                }
                else if(ui->textEdit_8->toPlainText()=="" && thr8->get_etat()==true){
                    ui->textEdit_8->setStyleSheet("background-color: purple");
                    ui->pushButton_8->setEnabled(true);etatb8=true;
                    k=f_ord.defiler();
                    thr8->set_msg(t[x]);
                    thr8->set_text(ui->textEdit_8);
                    thr8->set_mem_task(ran);
                    int debblock=memspace(k.mem_task);
                    thr8->set_debblock(debblock);
                    getblock("purple",debblock,ran,QString::number(ntask));
                    ntask++;

                    thr8->start();
                    list_ord.removeAt(0);
                    ((QStringListModel*) ui->listView_41->model())->setStringList(list_ord);
                }

           }
           else
           {
               list_sup.append(task_name);
               ((QStringListModel*) ui->listView->model())->setStringList(list_sup);
               f_sup.emfiler(k);
               thr9->set_file(f_sup);
               thr10->set_file(f_sup);
               thr11->set_file(f_sup);
               thr12->set_file(f_sup);
               if(ui->textEdit_9->toPlainText()=="" && thr9->get_etat()==true){
                   ui->textEdit_9->setStyleSheet("background-color: red");
                   ui->pushButton_9->setEnabled(true);
                   k=f_sup.defiler();
                   thr9->set_msg(t[x]);
                   thr9->set_text(ui->textEdit_9);
                   thr9->set_mem_task(ran);
                   int debblock=memspace(k.mem_task);
                   thr9->set_debblock(debblock);
                   getblock("red",debblock,ran,QString::number(ntask));
                   ntask++;
                   thr9->start();
                   list_sup.removeAt(0);
                   ((QStringListModel*) ui->listView->model())->setStringList(list_sup);
                   if(paused==false){
                        pause();
                        paused=true;
                   }
               }
               else if(ui->textEdit_10->toPlainText()=="" && thr10->get_etat()==true){
                   ui->textEdit_10->setStyleSheet("background-color: red");
                   ui->pushButton_10->setEnabled(true);
                   k=f_sup.defiler();
                   thr10->set_msg(t[x]);
                   thr10->set_text(ui->textEdit_10);
                   thr10->set_mem_task(ran);
                   int debblock=memspace(k.mem_task);
                   thr10->set_debblock(debblock);
                   getblock("red",debblock,ran,QString::number(ntask));
                   ntask++;
                   thr10->start();
                   list_sup.removeAt(0);
                   ((QStringListModel*) ui->listView->model())->setStringList(list_sup);
                   if(paused==false){
                        pause();
                        paused=true;
                   }
               }
               else if(ui->textEdit_11->toPlainText()=="" && thr11->get_etat()==true){
                   ui->textEdit_11->setStyleSheet("background-color: red");
                   ui->pushButton_11->setEnabled(true);
                   k=f_sup.defiler();
                   thr11->set_msg(t[x]);
                   thr11->set_text(ui->textEdit_11);
                   thr11->set_mem_task(ran);
                   int debblock=memspace(k.mem_task);
                   thr11->set_debblock(debblock);
                   getblock("red",debblock,ran,QString::number(ntask));
                   ntask++;
                   thr11->start();
                   list_sup.removeAt(0);
                   ((QStringListModel*) ui->listView->model())->setStringList(list_sup);
                   if(paused==false){
                        pause();
                        paused=true;
                   }
               }
               else if(ui->textEdit_12->toPlainText()=="" && thr12->get_etat()==true){
                   ui->textEdit_12->setStyleSheet("background-color: red");
                   ui->pushButton_11->setEnabled(true);
                   k=f_sup.defiler();
                   thr12->set_msg(t[x]);
                   thr12->set_text(ui->textEdit_12);
                   thr12->set_mem_task(ran);
                   int debblock=memspace(k.mem_task);
                   thr12->set_debblock(debblock);
                   getblock("red",debblock,ran,QString::number(ntask));
                   ntask++;
                   thr12->start();
                   list_sup.removeAt(0);
                   ((QStringListModel*) ui->listView->model())->setStringList(list_sup);
                   if(paused==false){
                        pause();
                        paused=true;
                   }
               }
           }
        }
        else if(ui->checkBox_2->isChecked())
        {
            QMessageBox msgBox;
            msgBox.setText("la memoire est pleine");
            msgBox.exec();
            ui->execute->setEnabled(false);
        }
        else if(ui->checkBox->isChecked())
        {
            ui->execute->setEnabled(true);
            ramasse_miette();
        }
        else
        {
            QMessageBox msgBox;
            msgBox.setText("la memoire est pleine");
            msgBox.exec();
            ui->execute->setEnabled(false);
        }
    }
    if(but==ui->pushButton){
        thr->set_etat(!thr->get_etat());
    }
    if(but==ui->pushButton_2){
        thr2->set_etat(!thr2->get_etat());
    }
    if(but==ui->pushButton_3){
        thr3->set_etat(!thr3->get_etat());
    }
    if(but==ui->pushButton_4){
        thr4->set_etat(!thr4->get_etat());
    }
    if(but==ui->pushButton_5){
        thr5->set_etat(!thr5->get_etat());
    }
    if(but==ui->pushButton_6){
        thr6->set_etat(!thr6->get_etat());
    }
    if(but==ui->pushButton_7){
        thr7->set_etat(!thr7->get_etat());
    }
    if(but==ui->pushButton_8){
        thr8->set_etat(!thr8->get_etat());
    }
    if(but==ui->pushButton_9){
        thr9->set_etat(!thr9->get_etat());
    }
    if(but==ui->pushButton_10){
        thr10->set_etat(!thr10->get_etat());
    }
    if(but==ui->pushButton_11){
        thr11->set_etat(!thr11->get_etat());
    }
    if(but==ui->pushButton_12){
        thr12->set_etat(!thr12->get_etat());
    }
}


void algo::on_checkBox_stateChanged(int arg1)
{
    if(ui->checkBox->isChecked())
    {
        ui->execute->setEnabled(true);
        ramasse_miette();
    }
}

