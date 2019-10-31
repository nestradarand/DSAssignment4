/*
Name: Noah Estrada-Rand
Student ID#: 2272490
Chapman email: estra146@mail.chapman.edu
Course Number and Section: CPSC-350-01
Assignment: Assignment 4 Registrar Simulation
*/
#ifndef DOUBLELISTNODE_H
#define DOUBLELISTNODE_H
#include <cstddef>

//serves as a node to store data for a doubly linked list

template <typename T>
class DoubleListNode
{
public:
  //stores the data and references to previous and next node
  T data;
  DoubleListNode<T> *next;
  DoubleListNode<T> *prev;

  //constructors and destructors
  DoubleListNode();
  DoubleListNode(T data);
  ~DoubleListNode();
};
//constructor
template <typename T>
DoubleListNode<T>::DoubleListNode(){}
//data constructor
template <typename T>
DoubleListNode<T>::DoubleListNode(T newData)
{
  data = newData;
  next = NULL;
  prev = NULL;
}
//destructor
template <typename T>
DoubleListNode<T>::~DoubleListNode()
{
  //check to see if the node is referencing other nodes before deleting the pointers
  if(next == NULL)
    delete next;
  if(prev == NULL)
    delete prev;
}
#endif
