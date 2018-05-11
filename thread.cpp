#include "thread.h"
#include<iostream>

Thread_cl::Thread_cl(class MainWindow* win):win(win)//构造函数
{
    stopped = false;
    started = false;
    paused = false;
}

void Thread_cl::stop(){
    stopped = true;
}

bool Thread_cl::isStart(){
    return started;
}

void Thread_cl::start(){
    //started = true;
    QThread::start();
}

bool Thread_cl::isStopped(){
    return stopped;
}

void Thread_cl::pause(){
    paused = true;
}

void Thread_cl::continueRun(){
    paused = false;
}

void Thread_cl::run(){
    bool flag = true;
    while(true){
        if(started){
            if(!stopped){
                if(!paused){
                    if(win->backup.empty()&&win->ready.empty()&&win->runningPCB==NULL){
                        msleep(500);
                        std::cout<<"sleep 0.5s here"<<endl;
                        continue;
                    }
                    msleep(1000);
                    if(win->runningPCB!=NULL){
                        std::cout<<"PCB: "<<win->runningPCB->name<<endl;
                        win->showRunningPCB();
                        win->runPCB();
                    }
                    PCB* pcb = win->selectRunningProcess();
                    if(pcb==NULL){
                        std::cout<<"pcb = NULL"<<endl;
                        win->showRunningPCB();
                        continue;
                    }
                    win->runningPCB = pcb;
                }
            }
            else{
                msleep(2000);
                std::cout<<"sleep here"<<endl;
            }
        }


    }
}

