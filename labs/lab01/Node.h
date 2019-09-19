#ifndef _NODE_H
#define _NODE_H

template<typename T>
struct Node
{
    Node(T d, Node<T> *n = nullptr) : data(d), next(n) {}
    T data;
    Node* next;
};

#endif // _NODE_H
