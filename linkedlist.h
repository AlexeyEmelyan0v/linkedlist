#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

#include <iostream>
#include "vertex.h"
#include <cassert>

using namespace std;

template<typename T>
class linkedlist {
public:
    vertex<T> *head;
    vertex<T> *tail;

    linkedlist() {
        head = nullptr;
        tail = nullptr;
    }

    bool empty() {
        if (head == nullptr) {
            return true;
        }
        return false;
    }

    void begpush(T v) {
        vertex<T> *vtx = new vertex(v);
        if (head == nullptr) {
            tail = vtx;
            head = vtx;
            tail->next = nullptr;
        } else {
            vtx->next = head;
            head = vtx;
        }
    }

    void endpush(T v) {
        vertex<T> *vtx = new vertex(v);
        if (head == nullptr) {
            head = vtx;
            tail = vtx;
            tail->next = nullptr;
        } else {
            tail->next = vtx;
            tail = vtx;
        }
    }

    void pospush(T v, int pos) {
        vertex<T> *vtx = new vertex(v);
        vertex<T> *wh = head;
        if (pos == 1) {
            begpush(v);
        } else {
            for (int i = 2; i < pos; i++) {
                if(wh == nullptr){
                    throw "Bad index";
                }else {
                    wh = wh->next;
                }
            }
            vtx->next = wh->next;
            wh->next = vtx;
        }
    }

    void begdel() {
        if (!empty()) {
            vertex<T> *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void enddel() {
        if (!empty()) {
            vertex<T> *pre = head;
            vertex<T> *temp = head->next;
            if (temp != nullptr) {
                while (temp->next != nullptr && temp != nullptr) {
                    pre = pre->next;
                    temp = temp->next;
                }
                pre->next = nullptr;
                delete temp;
                tail = pre;
            } else {
                head = nullptr;
                tail = nullptr;
            }
        }
    }

    void posdel(int pos) {
        vertex<T> *wh = head;
        if (!empty()) {
            if (pos == 1) {
                begdel();
            }
            for (int i = 2; i < pos; i++) {
                wh = wh->next;
            }
            vertex<T> *del = wh->next;
            vertex<T> *aft = wh->next->next;
            wh->next = aft;
            delete del;
        }
    }

    void valuedel(int value) {
        int pos = 1;
        vertex<T> *wh = head;
        while (wh != nullptr) {
            if (wh->data == value) {
                wh = wh->next;
                posdel(pos);
            }else{
                wh = wh->next;
                pos++;
            }
        }
    }

    int valuesearch(int value){
        int pos = 1;
        vertex<T> *wh = head;
        while (wh != nullptr) {
            if (wh->data == value) {
                return pos;
            }
            wh=wh->next;
            pos++;
        }
        return -1;
    }

    T &operator[](int i) const{
        vertex<T> *wh = head;
        for(int j=0;j<i;j++){
            if(wh==nullptr){
                throw "Wrong index";
            }else{
                wh=wh->next;
            }
        }
        return wh->data;
    }

    template<typename Type>
    friend ostream &operator<<(ostream &, const linkedlist<Type> &);
};

template<typename T>
ostream& operator<<(ostream& out, const linkedlist<T>& a) {
    vertex<T> *wh = a.head;
    while (wh != nullptr) {
        out << *wh << " ";
        wh = wh->next;
    }
    return out;
}

#endif //LINKEDLIST_LINKEDLIST_H
