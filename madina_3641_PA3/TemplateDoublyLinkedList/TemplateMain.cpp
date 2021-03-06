#include "TemplateDoublyLinkedList.h"
#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>

using namespace std;

int main () {
  // Construct a linked list with header & trailer
  cout << "Create a new list" << endl;
  DoublyLinkedList<string> dll;
  cout << "list: " << dll << endl << endl;

  // Insert 10 nodes at back with value 10,20,30,..,100
  cout << "Insert 10 nodes at back with value 10,20,30,..,100" << endl;
  for (int i=10;i<=100;i+=10) {
    stringstream ss;
    ss << i;
    dll.insertLast(ss.str());
  }
  cout << "list: " << dll << endl << endl;

  // Insert 10 nodes at front with value 10,20,30,..,100
  cout << "Insert 10 nodes at front with value 10,20,30,..,100" << endl;
  for (int i=10;i<=100;i+=10) {
    stringstream ss;
    ss << i;
    dll.insertFirst(ss.str());
  }
  cout << "list: " << dll << endl << endl;
  
  // Copy to a new list
  cout << "Copy to a new list" << endl;
  DoublyLinkedList<string> dll2(dll);
  cout << "list2: " << dll2 << endl << endl;
  
  // Assign to another new list
  cout << "Assign to another new list" << endl;
  DoublyLinkedList<string> dll3;
  dll3=dll;
  cout << "list3: " << dll3 << endl << endl;
  
  // Delete the last 10 nodes
  cout << "Delete the last 10 nodes" << endl;
  for (int i=0;i<10;i++) {
    dll.removeLast();
  }
  cout << "list: " << dll << endl << endl;
  
  // Delete the first 10 nodes
  cout << "Delete the first 10 nodes" << endl;
  for (int i=0;i<10;i++) {
    dll.removeFirst();
  }
  cout << "list: " << dll << endl << endl;
  
  // Check the other two lists
  cout << "Make sure the other two lists are not affected." << endl;
  cout << "list2: " << dll2 << endl;
  cout << "list3: " << dll3 << endl<<endl;

  // more testing...
  DoublyLinkedList<string> dll4;
  for (int i = 1; i < 5; i++) {
	  stringstream ss;
	  ss << i;
	  dll4.insertLast(ss.str());
  }
  cout << "list4:" << dll4 << endl;
  // add tests for insertAfter, insertBefore
  DListNode<string> *insertNode = dll4.getFirst()->next;
  cout << "Insert '20' after second element." << endl;
  dll4.insertAfter(*insertNode, "20");
  cout << "list4: " << dll4 << endl << endl;
  cout << "Insert '10' before second element." << endl;
  dll4.insertBefore(*insertNode, "10");
  cout << "list4: " << dll4 << endl<<endl;
  // add tests for removeAfter, removeBefore
  cout << "Remove '20' after second element." << endl;
  dll4.removeAfter(*insertNode);
  cout << "list4: " << dll4 << endl << endl;
  cout << "Remove '10' before second element." << endl;
  dll4.removeBefore(*insertNode);
  cout << "list4: " << dll4 << endl<<endl;
  // add tests for DoublyLinkedListLength
  cout << "Return the length of Fourth Linked List" << endl;
  cout << DoublyLinkedListLength(dll4);
  return 0;
}
