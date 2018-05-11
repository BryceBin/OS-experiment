#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QHeaderView>
#include <QTableView>
#include <QMutex>

#include <queue>
#include <time.h>
#include "pcb.h"
#include "thread.h"
#include "memory_block.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
class Thread_c1;
}


struct cmp{
    bool operator ()(PCB* &a,PCB* &b){
        return a->pri<b->pri;//最大值优先
    }
};

typedef class Thread_cl Thread;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    friend class Thread_cl;


private slots:
    void on_start_clicked();

    void on_pause_clicked();
    
    void on_addprocess_clicked();

    void on_tosuspend_clicked();


    void on_awake_clicked();


private:
    Ui::MainWindow *ui;
    Thread *thread;
    QStandardItemModel *pcb_backup = new QStandardItemModel();
    QStandardItemModel *pcb_running = new QStandardItemModel();
    QStandardItemModel *pcb_suspend = new QStandardItemModel();
    QStandardItemModel *pcb_ready = new QStandardItemModel();

    //内存管理
    block* head;
    void init();
    bool assign_memory(PCB* pcb);
    bool recover_memory(PCB* pcb);
    void combine_memory(block* b);
    void update_memory();

    //最大进程数
    int maxLengthOfPCBs = 4;

    //内存块总大小
    int maxSizeOfMemory = 1024;
    int block_count = 1;
    //获得唯一识别符号pid
    long getPid();
    long pids[10000];

    long start_memory = 0;
    long max_memory = 5000;

    PCB* selectPCB = NULL;
    PCB* runningPCB = NULL;
    PCB* lastRunningPCB = NULL;

    priority_queue<PCB*,vector<PCB*>,cmp> backup;//backup queue
    priority_queue<PCB*,vector<PCB*>,cmp> ready;//ready queue
    priority_queue<PCB*,vector<PCB*>,cmp> running;//running queue;
    priority_queue<PCB*,vector<PCB*>,cmp> suspend;//suspend queue;
    priority_queue<PCB*,vector<PCB*>,cmp> dead;//dead queue;

    PCB* addPCB(QString& name,QString& time,QString& pri,QString &memory);

    PCB* findPCB_from_ready(long id);
    PCB* findPCB_from_suspend(long id);

    bool deleteReadyPCB(PCB* pcb);
    bool deletSuspendPCB(PCB* pcb);

    bool addSuspend(PCB* pcb);
    void addBackup(PCB* pcb);
    void addReady(PCB* pcb);
    void addDead(PCB* pcb);

    void updateReadyList();

    void updateBackup();
    void updateReady();
    void updateSuspend();
    void updateDead();

    void runPCB();

    void showRunningPCB();

    PCB* selectRunningProcess();

    void setHeader();

    QColor randomColor();

};

#endif // MAINWINDOW_H
