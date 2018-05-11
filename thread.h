#ifndef THREAD_H
#define THREAD_H

#include <QThread>

#ifndef MAINWINDOW_H
#include "mainwindow.h"
#endif

#ifndef PCB_H
#include "pcb.h"
#endif

//extern PCB* runningPCB = NULL;

class Thread_cl : public QThread
{
    Q_OBJECT
public:
    Thread_cl(class MainWindow* win);
    void stop();
    bool isStopped();
    bool isStart();
    void start();
    void pause();
    void continueRun();

protected:
    void run();

public:
    class MainWindow* win;
    bool stopped;
    bool started;
    bool paused;
    PCB* lastPCB=NULL;

};

#endif // THREAD_H
