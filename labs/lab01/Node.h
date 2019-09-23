#ifndef _NODE_H
#define _NODE_H

template<typename T>
struct Node
{
    Node(T d) : data(d), next(nullptr) {}
    T data;
    Node* next;
};

#endif // _NODE_H
