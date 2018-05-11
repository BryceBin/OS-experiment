#include "memory_block.h"

block::block(){
    start_add = -1;
    size = 0;
    used = false;
    pre = NULL;
    next = NULL;
    pcb = NULL;
}

bool block::isused(){
    return used;
}

int block::getSize(){
    return size;
}

int block::getStartAdd(){
    return start_add;
}

PCB* block::getPCB(){
    return pcb;
}

block* block::getPre(){
    return pre;
}

block* block::getNext(){
    return next;
}

void block::set_start_add(int add){
    start_add = add;
}

void block::set_size(int t_size){
    size = t_size;
}

void block::set_used(bool use){
    used = use;
}

void block::set_pre(block* p){
    pre = p;
}

void block::set_next(block* p){
    next = p;
}

void block::set_PCB(PCB* p){
    pcb = p;
}
