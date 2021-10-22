#ifndef LINKEDLIST_VERTEX_H
#define LINKEDLIST_VERTEX_H

#include <iostream>

using namespace std;

template<typename T>
class vertex {
public:
    vertex<T> *next;
    T data;

    vertex(T, vertex *);

    vertex(T);

    template<typename Type>
    friend ostream &operator<<(ostream &, const vertex<Type> &);


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

template<typename T>
ostream& operator<<(ostream& out, const vertex<T>& a) {
    out << a.data;
    return out;
}

#endif
