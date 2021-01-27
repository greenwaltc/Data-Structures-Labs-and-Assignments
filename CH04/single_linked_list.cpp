/** Program to demonstrate a single linked list structure */
#include <string>
#include <iostream>
using std::string;
using std::endl;

namespace KW {
  /** A template class to encapsulate the single-linked list node */
  template <typename Item_Type>
  struct SLL {
#include "Node.h"
  };
  
  typedef SLL<string>::Node Node;
  
}

void print_list(KW::Node* node) {
  if (node) {
    std::cout << node->data;
    if (node->next) {
      std::cout << "->";
      print_list(node->next);
    } else {
      std::cout << std::endl;
    }
  } else {
    std::cout << "NULL\n";
  }
}

void test1()
{
  using KW::Node;
  using std::cout;
  Node* tom = new Node("Tom");
  Node* dick = new Node("Dick");
  Node* harry = new Node("Harry");
  Node* sam = new Node("Sam");
  tom->next = dick;
  dick->next = harry;
  harry->next = sam;
  print_list(tom);
  Node* bob = new Node("Bob");
  bob->next = harry->next;    // Step 1
  harry->next = bob;          // Step 2
  print_list(tom);
  Node* ptr = tom->next;       // Pointer to Node to be deleted
  tom->next = tom->next->next; // Remove Node from list
  delete ptr;                  // Delete Node to free storage
  
  Node* node_ptr = tom;
  node_ptr = tom;   //tom points to the first node
  while (node_ptr != NULL) {
    cout << node_ptr->data;
    if (node_ptr->next != NULL) {
      cout << " ==> ";
    }
    node_ptr = node_ptr->next;
  }
  cout << endl;
  
  Node* p = tom;
  while (p) {
    tom = tom->next;
    delete p;
    p = tom;
  }
  
}  

void test2()
{
  using KW::Node;
  Node* head = new Node("Tom");
  head->next = new Node("Dick");
  head->next->next = new Node("Harry");
  head->next->next->next = new Node("Sam");
  print_list(head);
  Node* ptr = head;
  while (ptr) {
    head = head->next;
    delete ptr;
    ptr = head;
  }
}

void test3()
{
  using KW::Node;
  Node* head = new Node("Sam");
  head = new Node("Harry", head);
  head = new Node("Dick", head);
  head = new Node("Tom", head);
  print_list(head);
  Node* ptr = head;
  while (ptr) {
    head = head->next;
    delete ptr;
    ptr = head;
  }
}

void exercise()
{
  using KW::Node;
  using std::cout;
  Node* head = new Node("Sam");
  Node* tail = head;
  head = new Node("Harry", head);
  head = new Node("Dick", head);
  head = new Node("Tom", head);
  cout << "Inital list\n";
  print_list(head);
  }


 

int main()
{
  test1();
  test2();
  test3();
  exercise();
}
