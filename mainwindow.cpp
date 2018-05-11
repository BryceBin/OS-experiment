#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("OS experiment");

    ui->backup->setColumnCount(5);
    ui->backup->setColumnWidth(0,ui->backup->width()/5-1);
    ui->backup->setColumnWidth(1,ui->backup->width()/5-1);
    ui->backup->setColumnWidth(2,ui->backup->width()/5-1);
    ui->backup->setColumnWidth(3,ui->backup->width()/5-1);
    ui->backup->setColumnWidth(4,ui->backup->width()/5-1);
    ui->backup->verticalHeader()->setHidden(true);

    ui->ready->setColumnCount(5);
    ui->ready->setColumnWidth(0,ui->ready->width()/5-1);
    ui->ready->setColumnWidth(1,ui->ready->width()/5-1);
    ui->ready->setColumnWidth(2,ui->ready->width()/5-1);
    ui->ready->setColumnWidth(3,ui->ready->width()/5-1);
    ui->ready->setColumnWidth(4,ui->ready->width()/5-1);
    ui->ready->setRowCount(maxLengthOfPCBs);
    ui->ready->verticalHeader()->setHidden(true);

    ui->suspend->setColumnCount(5);
    ui->suspend->setColumnWidth(0,ui->suspend->width()/5-1);
    ui->suspend->setColumnWidth(1,ui->suspend->width()/5-1);
    ui->suspend->setColumnWidth(2,ui->suspend->width()/5-1);
    ui->suspend->setColumnWidth(3,ui->suspend->width()/5-1);
    ui->suspend->setColumnWidth(4,ui->suspend->width()/5-1);
    ui->suspend->verticalHeader()->setHidden(true);

    ui->dead->setColumnCount(3);
    ui->dead->setColumnWidth(0,ui->dead->width()/3-1);
    ui->dead->setColumnWidth(1,ui->dead->width()/3-1);
    ui->dead->setColumnWidth(2,ui->dead->width()/3-1);
    ui->dead->setColumnWidth(3,ui->dead->width()/3-1);
    ui->dead->setColumnWidth(4,ui->dead->width()/3-1);
    ui->dead->verticalHeader()->setHidden(true);

    ui->memory->setColumnCount(4);
    ui->memory->setColumnWidth(0,ui->memory->width()/4);
    ui->memory->setColumnWidth(1,ui->memory->width()/4);
    ui->memory->setColumnWidth(2,ui->memory->width()/4);
    ui->memory->setColumnWidth(3,ui->memory->width()/4);
    ui->memory->setRowHeight(0,30);
    ui->memory->verticalHeader()->setHidden(true);

    //设置表格头部信息
    setHeader();

    head = new block();
    head->set_used(true);
    //内存管理初始化
    init();

    update_memory();



    //以时间为种子
    srand( (unsigned)time( NULL ) );

    memset(pids,0,sizeof(pids));

    //实例化线程对象并启动线程
    thread = new Thread(this);
    thread->start();

}

void MainWindow::setHeader(){
    QStringList header,h1,h2;
    header<<"pid"<<"name"<<"time"<<"priority"<<"memory";
    ui->backup->setHorizontalHeaderLabels(header);
    ui->ready->setHorizontalHeaderLabels(header);
    ui->suspend->setHorizontalHeaderLabels(header);
    h2<<"pid"<<"name"<<"memory";
    ui->dead->setHorizontalHeaderLabels(h2);
    h1<<"startAdd"<<"pid"<<"name"<<"memory";
    ui->memory->setHorizontalHeaderLabels(h1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init(){
    block* f_block = new block();
    f_block->set_pre(head);
    f_block->set_size(maxSizeOfMemory);
    f_block->set_start_add(0);
    head->set_next(f_block);
}

bool MainWindow::assign_memory(PCB* pcb){
    if(pcb==NULL)
        return false;
    bool flag = false;
    block* node = head;
    while(node->getNext()){
        node = node->getNext();
        if(!node->isused()&&node->getSize()>pcb->memory){
            flag = true;
            block* tmp = new block();
            tmp->set_size(pcb->memory);
            tmp->set_start_add(node->getStartAdd());
            pcb->start_memory = tmp->getStartAdd();
            tmp->set_used(true);
            tmp->set_PCB(pcb);

            node->set_size(node->getSize()-pcb->memory);
            node->set_start_add(node->getStartAdd()+pcb->memory);

            block* m = node->getPre();
            tmp->set_pre(m);
            m->set_next(tmp);
            node->set_pre(tmp);
            tmp->set_next(node);
            break;
        }
        else if(!node->isused()&&node->getSize()==pcb->memory){
            flag = true;
            node->set_PCB(pcb);
            node->set_used(true);
            break;
        }
    }
    if(flag) update_memory();
    return flag;
}

bool MainWindow::recover_memory(PCB* pcb){
    bool flag = false;
    block* node = head;
    while(node->getNext()){
        node = node->getNext();
        if(node->getPCB()!=NULL&&node->getPCB()==pcb){
            node->set_used(false);
            node->set_PCB(NULL);
            combine_memory(node);
            flag = true;
            break;
        }
    }
    if(flag) update_memory();
    return flag;
}

void MainWindow::combine_memory(block* b){
    block* pre = b->getPre();
    block* next = b->getNext();
    if(!pre->isused()&&!next->isused()){
        pre->set_size(pre->getSize()+b->getSize()+next->getSize());
        pre->set_next(next->getNext());
    }
    else if(pre->isused()&&!next->isused()){
        b->set_size(b->getSize()+next->getSize());
        b->set_next(next->getNext());
    }
    else if(!pre->isused()&&next->isused()){
        pre->set_size(pre->getSize()+b->getSize());
        pre->set_next(next);
    }
}

void MainWindow::update_memory(){////////////////////////////
    block* b = head;
    int index = 0;
    QString str;
    ui->memory->clearContents();
    ui->memory->setRowCount(block_count);
    std::cout<<"block_count = "<<block_count<<endl;
    while(b->getNext()!=NULL){
        b = b->getNext();
        if(b->getPCB()!=NULL){
            QColor color = randomColor();
            ui->memory->setItem(index,0,new QTableWidgetItem(QString::number(b->getStartAdd(),10)));
            ui->memory->setItem(index,1,new QTableWidgetItem(QString::number(b->getPCB()->pid,10)));
            ui->memory->setItem(index,2,new QTableWidgetItem(QString::fromStdString(b->getPCB()->name)));
            ui->memory->setItem(index,3,new QTableWidgetItem(QString::number(b->getPCB()->memory,10)));
            ui->memory->item(index,0)->setBackgroundColor(color);
            ui->memory->item(index,1)->setBackgroundColor(color);
            ui->memory->item(index,2)->setBackgroundColor(color);
            ui->memory->item(index,3)->setBackgroundColor(color);

            //ui->memory->setStyleSheet("QTableView::Item{background-color:#FF3EFF}");
        }
        else{
            ui->memory->setItem(index,0,new QTableWidgetItem(QString::number(b->getStartAdd(),10)));
            ui->memory->setItem(index,1,new QTableWidgetItem(QString::fromStdString("NULL")));
            ui->memory->setItem(index,2,new QTableWidgetItem(QString::fromStdString("NULL")));
            ui->memory->setItem(index,3,new QTableWidgetItem(QString::number(b->getSize(),10)));
        }
        index++;

    }
}

long MainWindow::getPid(){
    long id;
    while(true){
        id=rand()%10000;
        if(pids[id]==0){
            pids[id]=1;
            break;
        }
    }
    return id;
}


PCB* MainWindow::addPCB(QString& name,QString& time,QString& pri,QString &memory){
    bool ok;
    int int_time=time.toInt(&ok,10);
    if(!ok)
        return NULL;
    int int_pri=pri.toInt(&ok,10);
    if(!ok)
        return NULL;
    long long_memory = memory.toLong(&ok,10);
    if(!ok)
        return NULL;
    PCB* pcb = new PCB();
    if(pcb==NULL)
        return NULL;
    pcb->name=name.toStdString();
    pcb->time=int_time;
    pcb->pri=int_pri;
    pcb->memory=long_memory;
    pcb->pid=getPid();
    addBackup(pcb);
    return pcb;
}


void MainWindow::updateBackup(){
    priority_queue<PCB*,vector<PCB*>,cmp> temp_backup=backup;
    PCB *tmp=NULL;
    int index=0;
    ui->backup->clearContents();
    ui->backup->setRowCount(temp_backup.size());
    while(!temp_backup.empty()){
        tmp=temp_backup.top();temp_backup.pop();
        ui->backup->setItem(index,0,new QTableWidgetItem(QString::number(tmp->pid,10)));
        ui->backup->setItem(index,1,new QTableWidgetItem(QString::fromStdString(tmp->name)));
        ui->backup->setItem(index,2,new QTableWidgetItem(QString::number(tmp->time,10)));
        ui->backup->setItem(index,3,new QTableWidgetItem(QString::number(tmp->pri,10)));
        ui->backup->setItem(index,4,new QTableWidgetItem(QString::number(tmp->memory,10)));
        index++;
    }
}

void MainWindow::updateReady(){
    priority_queue<PCB*,vector<PCB*>,cmp> temp_ready=ready;
    PCB *tmp=NULL;
    int index=0;
    ui->ready->clearContents();
    while(!temp_ready.empty()){
        tmp=temp_ready.top();temp_ready.pop();
        ui->ready->setItem(index,0,new QTableWidgetItem(QString::number(tmp->pid,10)));
        ui->ready->setItem(index,1,new QTableWidgetItem(QString::fromStdString(tmp->name)));
        ui->ready->setItem(index,2,new QTableWidgetItem(QString::number(tmp->time,10)));
        ui->ready->setItem(index,3,new QTableWidgetItem(QString::number(tmp->pri,10)));
        ui->ready->setItem(index,4,new QTableWidgetItem(QString::number(tmp->memory,10)));
        index++;
    }
}


void MainWindow::updateSuspend(){
    priority_queue<PCB*,vector<PCB*>,cmp> temp_suspend=suspend;
    PCB *tmp=NULL;
    int index=0;
    ui->suspend->clearContents();
    ui->suspend->setRowCount(temp_suspend.size());
    while(!temp_suspend.empty()){
        tmp=temp_suspend.top();temp_suspend.pop();
        ui->suspend->setItem(index,0,new QTableWidgetItem(QString::number(tmp->pid,10)));
        ui->suspend->setItem(index,1,new QTableWidgetItem(QString::fromStdString(tmp->name)));
        ui->suspend->setItem(index,2,new QTableWidgetItem(QString::number(tmp->time,10)));
        ui->suspend->setItem(index,3,new QTableWidgetItem(QString::number(tmp->pri,10)));
        ui->suspend->setItem(index,4,new QTableWidgetItem(QString::number(tmp->memory,10)));
        index++;
    }
}

void MainWindow::updateDead(){
    priority_queue<PCB*,vector<PCB*>,cmp> temp_dead=dead;
    PCB *tmp=NULL;
    int index=0;
    ui->dead->clearContents();
    ui->dead->setRowCount(temp_dead.size());
    while(!temp_dead.empty()){
        tmp=temp_dead.top();temp_dead.pop();
        ui->dead->setItem(index,0,new QTableWidgetItem(QString::number(tmp->pid,10)));
        ui->dead->setItem(index,1,new QTableWidgetItem(QString::fromStdString(tmp->name)));
        ui->dead->setItem(index,2,new QTableWidgetItem(QString::number(tmp->memory,10)));
        index++;
    }
}


PCB* MainWindow::selectRunningProcess(){
    if(ready.empty()){
        updateReadyList();
    }
    if(ready.empty())
        return NULL;
    PCB* p = ready.top();
    ready.pop();
    updateReadyList();
    lastRunningPCB = p;
    return p;
}


void MainWindow::runPCB(){
    PCB* p = runningPCB;
    if(p){
        p->pri--;
        p->time--;
        if(p->time>0){
            addReady(p);
        }
        else{
            addDead(p);
            block_count--;
            recover_memory(p);
        }
        runningPCB = NULL;
    }
}

void MainWindow::addBackup(PCB *pcb){
    if(pcb==NULL)
        return;
    backup.push(pcb);

    updateBackup();
    if(thread->isStart()){
        updateReadyList();
    }
}


void MainWindow::addDead(PCB *pcb){
    if(pcb==NULL)
        return;
    dead.push(pcb);
    updateDead();
}

void MainWindow::addReady(PCB *pcb){
    if(pcb==NULL)
        return;
    if(ready.size()>maxLengthOfPCBs){
        addSuspend(pcb);
        return;
    }
    ready.push(pcb);
    updateReadyList();
}

void MainWindow::showRunningPCB(){
    if(runningPCB){
        ui->pid->setText(QString::number(runningPCB->pid,10));
        ui->name->setText(QString::fromStdString(runningPCB->name));
        ui->time->setText(QString::number(runningPCB->time,10));
        ui->priority->setText(QString::number(runningPCB->pri,10));
        ui->memory_2->setText(QString::number(runningPCB->memory,10));
    }
    else{
        ui->pid->clear();
        ui->name->clear();
        ui->time->clear();
        ui->priority->clear();
        ui->memory_2->clear();
    }
}

void MainWindow::updateReadyList(){
    PCB *p = NULL;
    priority_queue<PCB*,vector<PCB*>,cmp> tmp;
    while(ready.size()<maxLengthOfPCBs&&!backup.empty()){
        p = backup.top();backup.pop();
        block_count++;
        if(!assign_memory(p)){
            tmp.push(p);
            block_count--;
        }
        else{
            ready.push(p);
        }
    }
    while(!tmp.empty()){
        backup.push(tmp.top());
        tmp.pop();
    }
    updateReady();
    updateBackup();
}

PCB* MainWindow::findPCB_from_ready(long id){
    if(id<0)
        return NULL;
    priority_queue<PCB*,vector<PCB*>,cmp> temp_ready = ready;
    PCB* p = NULL;
    while(!temp_ready.empty()){
        p = temp_ready.top();temp_ready.pop();
        if(p->pid==id){
            return p;
        }
    }
    return NULL;
}

PCB* MainWindow::findPCB_from_suspend(long id){
    if(id<0)
        return NULL;
    priority_queue<PCB*,vector<PCB*>,cmp> temp_suspend = suspend;
    PCB* p = NULL;
    while(!temp_suspend.empty()){
        p = temp_suspend.top();temp_suspend.pop();
        if(p->pid==id){
            return p;
        }
    }
    return NULL;
}

bool MainWindow::deleteReadyPCB(PCB *pcb){
    if(pcb==NULL)
        return false;
    priority_queue<PCB*,vector<PCB*>,cmp>temp_ready = ready;
    while(!ready.empty())ready.pop();
    while(!temp_ready.empty()){
        if(temp_ready.top()!=pcb){
            ready.push(temp_ready.top());
        }
        temp_ready.pop();
    }
    updateReady();
    return true;
}

bool MainWindow::deletSuspendPCB(PCB *pcb){
    if(pcb==NULL)
        return false;
    priority_queue<PCB*,vector<PCB*>,cmp>temp_suspend = suspend;
    while(!suspend.empty())suspend.pop();
    while(!temp_suspend.empty()){
        if(temp_suspend.top()!=pcb){
            suspend.push(temp_suspend.top());
        }
        temp_suspend.pop();
    }
    updateSuspend();
    return true;
}

bool MainWindow::addSuspend(PCB *pcb){
    if(pcb==NULL)
        return false;
    suspend.push(pcb);
    recover_memory(pcb);
    updateSuspend();
}

QColor MainWindow::randomColor(){
    string clist[] = {"#EE6AA7","#EE7600","#CD8162","#76EE00","#D15FEE"};
    QColor c1("#EE6AA7");
    QColor c2("#EE7600");
    QColor c3("#CD8162");
    QColor c4("#76EE00");
    QColor c5("#D15FEE");
    QColor c[] = {c1,c2,c3,c4,c5};

    return c[rand()%5];
}

void MainWindow::on_start_clicked()
{
    if(!thread->isStart()){
        thread->started=true;
        //ui->start->setText("结束");
        if(!backup.empty()){
            updateReadyList();
        }
    }
    else{
        //thread->stop();
    }
}

void MainWindow::on_pause_clicked()
{
    if(!thread->isStopped()){
        thread->stopped=true;
        ui->pause->setText("继续");
    }
    else{
        thread->stopped=false;
        ui->pause->setText("暂停");
    }
}

void MainWindow::on_addprocess_clicked()
{
    QString name = ui->lineEdit_name->text();
    QString pri = ui->lineEdit_pri->text();
    QString time = ui->lineEdit_time->text();
    QString memory = ui->lineEdit_memory->text();
    addPCB(name,time,pri,memory);
    ui->lineEdit_memory->clear();
    ui->lineEdit_name->clear();
    ui->lineEdit_pri->clear();
    ui->lineEdit_time->clear();
}

void MainWindow::on_tosuspend_clicked()
{
    QString str = ui->select_to_aors->text();
    if(str==NULL){
        std::cout<<"未选中任何进程"<<endl;
        return;
    }
    else{
        long id = str.toLong();
        if(id==runningPCB->pid){
            addSuspend(runningPCB);
            //recover_memory(runningPCB);
            runningPCB = NULL;
        }
        else{
            selectPCB = findPCB_from_ready(id);
            if(selectPCB==NULL){
                std::cout<<"无此进程"<<endl;
            }
            else{
                if(selectPCB->time>0){
                    deleteReadyPCB(selectPCB);
                    addSuspend(selectPCB);
                    //recover_memory(selectPCB);
                    selectPCB = NULL;
                }
            }
        }
        ui->select_to_aors->clear();
    }
}


void MainWindow::on_awake_clicked()
{
    QString str = ui->select_to_aors->text();
    if(str==NULL){
        std::cout<<"为选中进程"<<endl;
        return;
    }
    else{
        long id = str.toLong();
        selectPCB = findPCB_from_suspend(id);
        if(selectPCB==NULL){
            std::cout<<"无此进程"<<endl;
            return;
        }
        else{
            if(selectPCB->time>0){
                if(assign_memory(selectPCB)){
                    deletSuspendPCB(selectPCB);
                    addReady(selectPCB);
                }
                selectPCB = NULL;
            }
        }
        ui->select_to_aors->clear();
    }
}

