#ifndef DLQUEUE_H
#define DLQUEUE_H
#include "DoublyLinkedList.h"
#include <iostream>

template <typename T>
class DLQueue
{
public:
    DLQueue();
    DLQueue(int maxSize);
    ~DLQueue();
    DoublyLinkedList<T> *theList;

    void enqueue(T i);
    T dequeue();

    T peek();
    // bool isFull();
    bool isEmpty();
    int getSize();

    int numElements;

};
template <typename T>
DLQueue<T>::DLQueue()
{
    theList = new DoublyLinkedList<T>();
    numElements = 0;
}
template <typename T>
DLQueue<T>::DLQueue(int maxSize)
{
//   myQueue = new T[maxSize];
//   size = maxSize;
    theList = new DoublyLinkedList<T>();
    numElements = 0;
}
template <typename T>
DLQueue<T>::~DLQueue()
{
    delete theList;
}
template <typename T>
void DLQueue<T>::enqueue(T i)
{
    //do we even need this?
    // if(isFull())
    //     throw std::runtime_error("Queue is full");
    theList -> insertBack(i);
    ++numElements;
}
template <typename T>
T DLQueue<T>::dequeue()
{
    if(isEmpty())
        throw std::runtime_error("Queue is empty, unable to dequeue");
    T returner;
    returner = theList -> removeFront();
    --numElements;
    return returner;
}
template <typename T>
T DLQueue<T>::peek()
{
    if(isEmpty())
        throw std::runtime_error("Queue is empty, nothing to peek at");
    return theList -> getFront();
}
// template <typename T>
// bool DLQueue<T>::isFull()
// {
//   return (numElements == size);
// }
template <typename T>
bool DLQueue<T>::isEmpty()
{
  return(numElements == 0);
}
template <typename T>
int DLQueue<T>::getSize()
{
  return numElements;
}
#endif

