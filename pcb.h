#ifndef PCB_H
#define PCB_H
#include "string.h"
#include <iostream>
using namespace std;

class PCB{
public:
    string name;
    long pid;
    long start_memory;
    long memory;//内存大小
    int time;//运行时间
    int pri;//优先权
    //int state;//0表示后备，1表示就绪，2表示运行，3表示挂起
};


#endif // PCB_H
