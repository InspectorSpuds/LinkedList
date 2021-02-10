#include <iostream>
#include "linkedlist.h"
using namespace std;

LinkedList::LinkedList() 
{
  head = nullptr;
  tail = nullptr;
  size = 0;
}

LinkedList::~LinkedList() 
{
  deleteNodes(head);
}

void LinkedList::add(int item)
{ 
  //if the linkedlist is empty
  if(size == 0) {
    head = new node();
    head->data = item;
    head->next = nullptr;
    tail = head;
  } else {
    //create and assign value to new node
    tail->next = new node();
    tail->next->next = nullptr;
    tail->next->data = item;
    //assign new tail node and increment size
    tail = tail->next;
  }
  size++;
}

int LinkedList::remove()
{
  int value = 0;
  node* iterate = head;
  if(size == 0) {
    cout<<"Error"<<endl;
    return -1;
  } else if(size == 1) {
    value = head->data;
    delete head;
    head = nullptr;
  } else {
    //get value and get to second to last node
    value = tail->data;
    while(iterate->next->next != nullptr) 
      iterate = iterate->next;

    value = iterate->next->data;
    delete iterate->next;
    iterate->next = nullptr;
    tail = iterate;
  }

  size--;
  return value;
}

int LinkedList::remove(int index)
{
  node* current = head;
  node* rhs = nullptr;
  int value = 0;

  if(size == 0) {
    cout << "Error" << endl;
    return -1;
  } else if(index == 0) { 
    rhs = head->next;
    value = head->data;
    delete head;
    head = rhs;
  } else if(size == 1 || index == size - 1) {
    return remove();
  } else {

    for(int i = 0; i < index -1 ; i++)
      current = current->next;
    
    rhs = current->next->next;
    value = current->next->data;
    delete current->next;
    current->next = rhs;
  }

  size--;
  return value;
}

int LinkedList::get(int index)
{
  node* iterate = head; //iterator pointer
  //if index out of bounds or size is 0
  if(size == 0 || index < 0 || index > size - 1) {
    cout << "Error" << endl;
    return -1;
  } else if(index == 0) {
    return head->data;
  } else if(index == size - 1) {
    return tail->data;
  }

  //get to "index" pointer element
  for(int i = 0; i < index; i++){
    iterate = iterate->next;
  }
  //return the data at the point
  return iterate->data;
}

//private 
void LinkedList::deleteNodes(node* head)
{
  node* iterate = head;
  while(iterate != nullptr) {
    head = iterate->next;
    delete iterate;
    iterate = head;
  }



  //keep going until the next pointer is empty
  if(head != nullptr) {
    //move to next pointer and once done, delete pointers from last to 
    deleteNodes(head->next);
    delete head;
  }
}

int LinkedList::getSize()
{
  return size;
}

void LinkedList::printAll()
{
  node* iterate = head;
  if(head == nullptr) {
    return;
  } else {
    for(int i = 0; i< size; i++) {
      cout << iterate->data << endl;
      iterate = iterate->next;
    }
  }
}