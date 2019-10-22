#ifndef _NODE_H
#define _NODE_H

template <class T>
class Node
{
private:
    T item_;
    Node<T> *next_;

public:
    Node() {}
    Node(const T &anItem, Node<T>* const nextNodePtr = nullptr);
    void item(const T &anItem);
    void next(Node<T>* const nextNodePtr);
    T item() const;
    Node<T> *next() const;
};

#include "Node.cpp"
#endif // _NODE_H
