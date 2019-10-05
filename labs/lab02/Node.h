#ifndef _NODE_H
#define _NODE_H

template<class T>
class Node
{
private:
    T        entry;
    Node<T>* next;

public:
    Node() {}
    Node(const T& anEntry);
    Node(const T &anEntry, Node<T> *nextNodePtr);
    void setEntry(const T& anEntry);
    void setNext(Node<T>* nextNodePtr);
    T getEntry() const;
    Node<T>* getNext() const;
};

#include "Node.cpp"
#endif // _NODE_H
