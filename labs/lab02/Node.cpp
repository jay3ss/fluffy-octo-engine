#include "Node.h"

template<class T>
Node<T>::Node(const T& anEntry) : entry(anEntry), next(nullptr) {}

template <class T>
Node<T>::Node(const T &anEntry, Node<T> *nextNodePtr) :
    entry(anEntry), next(nextNodePtr) {}

template<class T>
void Node<T>::setEntry(const T& anEntry)
{
    entry = anEntry;
}

template<class T>
void Node<T>::setNext(Node<T>* nextNodePtr)
{
    next = nextNodePtr;
}

template<class T>
T Node<T>::getEntry() const
{
    return entry;
}

template<class T>
Node<T>* Node<T>::getNext() const
{
    return next;
}
