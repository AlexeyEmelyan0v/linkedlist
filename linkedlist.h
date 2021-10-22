#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

#include <iostream>
#include "vertex.h"
using namespace std;

template<typename T>
class linkedlist{
    vertex<T> *head;
    vertex<T> *tail;
public:
    linkedlist() {
        head= nullptr;
        tail= nullptr;
    }
    bool empty(){
        if(head== nullptr){
            return true;
        }
        return false;
    }
    void begpush(T v){
        vertex<T>* vtx=new vertex(v);
        (*vtx).next=head;
        head=vtx;
    }
    void endpush(T v){
        vertex<T>* vtx=new vertex(v);
    }
};

#endif //LINKEDLIST_LINKEDLIST_H
