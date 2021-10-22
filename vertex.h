#ifndef LINKEDLIST_VERTEX_H
#define LINKEDLIST_VERTEX_H

#include <iostream>

using namespace std;

template<typename T>
class vertex {
public:
    vertex *next;
    T data;

    vertex(T, vertex *);

    vertex(T);
};

template<typename T>
vertex<T>::vertex(T m,vertex* m1) {
    data = m;
    next = m1;
}

template<typename T>
vertex<T>::vertex(T m) {
    data = m;
    next = nullptr;
}



#endif
