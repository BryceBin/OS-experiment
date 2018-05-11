#ifndef MEMORY_BLOCK
#define MEMORY_BLOCK
#include "pcb.h"


class block{
public:
    block();
    bool isused();
    int getSize();
    int getStartAdd();
    PCB* getPCB();
    block* getPre();
    block* getNext();
    void set_start_add(int add);
    void set_size(int size);
    void set_used(bool use);
    void set_pre(block* p);
    void set_next(block* p);
    void set_PCB(PCB* p);
private:
    int start_add;
    int size;
    bool used;
    block* head;
    block* pre;
    block* next;
    PCB* pcb;
};


#endif // MEMORY_BLOCK

