/*
Name: Noah Estrada-Rand
Student ID#: 2272490
Chapman email: estra146@mail.chapman.edu
Course Number and Section: CPSC-350-01
Assignment: Assignment 4 Registrar Simulation
*/
#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include "DoubleListNode.h"
#include <cstddef>
#include <iostream>

//serves as a class to store data in a linked manner

template <typename T>
class DoublyLinkedList
{
private:
    //references to the front and back nodes and the size of the entire list
    DoubleListNode<T> *front;
    DoubleListNode<T> *back;
    unsigned int size;
public:
    //constructor and destructor
    DoublyLinkedList();
    ~DoublyLinkedList();
    //insert data to the front or back of the list as a new node
    void insertFront(T newEntry);
    void insertBack(T newEntry);
    //removes the front or back node
    T removeBack();
    T removeFront();
    //returns the data stored in the front or back nodes
    T getFront();
    T getBack();
    //finds index based on the entry
    int find(T entry);
    //removes a node based on the data entered
    bool remove(T entry);
    //returns if the list is empty
    bool isEmpty();
    //prints the list
    void printList();
    //returns the size of the list
    unsigned int getSize();
};

//implementation
//default constructor
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
  size = 0;
  front = NULL;
  back = NULL;
}
//destructor
template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
  while(!isEmpty())
    removeFront();
}
//inserts new data entry to the front of the list as a new node
template <typename T>
void DoublyLinkedList<T>::insertFront(T newEntry)
{
  DoubleListNode<T> *node = new DoubleListNode<T>(newEntry);
  if(size == 0)//empty list
  {
    back = node;
  }
  else//update pointers of the front and the next node in line
  {
    node -> next = front;
    front -> prev = node;
  }
  front = node;

  size ++;

}
//removes the front node
template <typename T>
T DoublyLinkedList<T>::removeFront()
{
  if(isEmpty())
    throw std::runtime_error("List is empty.");    
  T holder = front -> data;
  DoubleListNode<T> *toDelete = front;
  if(size == 1)//only one node in the list
  {
    back = NULL;
  }
  else //more than one node
  {
    front -> next -> prev = NULL;
  }
  //set the front to its next node then delete the original front node
  front = front -> next;
  toDelete -> next = NULL;
  delete toDelete;
  size -- ;
  return holder;
}
//insert data into the back of the list as a new node
template <typename T>
void DoublyLinkedList<T>::insertBack(T newEntry)
{
  DoubleListNode<T> *node = new DoubleListNode<T>(newEntry);
  if(size == 0)//empty list
  {
    front = node;
  }
  else//not an empty list
  {
    node -> prev = back;
    back -> next = node;
  }
  back = node;

  size ++;
}
//removes the last item of the list
template <typename T>
T DoublyLinkedList<T>::removeBack()
{
  if(isEmpty())
    throw std::runtime_error("stack is empty");
  DoubleListNode<T> *backTemp = back;
  if(size == 1)//only one node in the list
  {
    front = NULL;
  }
  else //more than one node
  {
    back -> prev -> next = NULL;
  }
  //update the reference of back to the node before the original back
  back = back -> prev;
  T temp = backTemp -> data;
  backTemp -> prev = NULL;
  delete backTemp;
  size --;

  return temp;
}
//removes a data entry by searching for it then deleting the node and returning the stored data
template <typename T>
bool DoublyLinkedList<T>::remove(T data)
{
  if(isEmpty())
    throw std::runtime_error("stack is empty");
  DoubleListNode<T> *current = front;
  while(current -> data != data)//as long as we dont find the data
  {
    current = current -> next;
    if(current == NULL)//means we didnt find the data
      return false;
  }
  //if we get to here it means we found it
  //check if the node is the front
  if(current == front)
    front  = current -> next;

  else
  {
    //not the front
    //attach previouis to the one in front of the current
    current -> prev -> next = current -> next;
  }
  if(current == back)
    back = current -> prev;
  else //not the back
  {
    current -> next -> prev = current -> prev;
  }
  //detach current
  current -> next = NULL;
  current -> prev = NULL;
  size --;
  delete current;
  return true;
  //doesnt delete the node, just returns it
}
//returns if the list is empty or not
template <typename T>
bool DoublyLinkedList<T>::isEmpty()
{
  return size == 0;
}
//prints the list
template <typename T>
void DoublyLinkedList<T>::printList()
{
  DoubleListNode<T> *current = front;
  while(current != NULL)
  {
    std::cout <<current -> data << std::endl;
    current = current -> next;
  }
}
//returns the size of the list
template <typename T>
unsigned int DoublyLinkedList<T>::getSize()
{
  return size;
}
//finds the index of an entry based on the data to search for
template <typename T>
int DoublyLinkedList<T>::find(T entry)
{
  int index = 0;
  DoubleListNode<T> *current = front;
  //stops if there are no other nodes to search or if it si found
  while(current != NULL)
  {
    if(current -> data == entry)
      break;
    index ++;
    current = current -> next;
  }
  if(current == NULL)
    index = -1;//return negative one if not found
  return index;  
}
//returns the data of the front node
template <typename T>
T DoublyLinkedList<T>::getFront()
{
  return front ->data;
}
//returns the data of the last node
template <typename T>
T DoublyLinkedList<T>::getBack()
{
  return back -> data;
}

#endif
