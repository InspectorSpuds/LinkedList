#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct node 
{
  int data;
  node* next;
};

class LinkedList {
  public:
    LinkedList(); 
    ~LinkedList();
    void add(int item); 
    int remove(int index);
    int remove();
    int get(int index); 
    int getSize(); 
    void printAll();
  private: 
    node* head; //starting node
    node* tail; //end node
    int size; 
    void deleteNodes(node* head);
};

#endif 