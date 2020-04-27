#pragma once
#include <cstdlib>
#include <iostream>
#include "TemplateDoublyLinkedList.h"
using namespace std;

template<typename T>
class MinQueue{
private:
	DoublyLinkedList<T> dll;
	T minobj;
public:
	MinQueue() : dll(), minobj(T()) {} //constructor
	void enqueue(T obj) { dll.insertLast(obj); }// enqueues T obj into the back of the queue
	T dequeue(); //dequeues the minimum object of the queue.
	int size() { return DoublyLinkedListLength(dll); } //returns the size of the Queue
	bool isEmpty() { return dll.isEmpty(); }//returns if the queue is empty
	T min(); //returns but not deletes the smalles value currently stored in the queue
	DoublyLinkedList<T> getdll() const { return dll; }
};

template<typename T>
T MinQueue<T>::dequeue() {
	//function find the minimum value
	//finds the node that points to the min using minNode->prev
	//uses the removeAfter() function to dequeue the min value
	DListNode<T> *current = dll.getFirst(); //sets the min to the first node
	DListNode<T> *minNode = current;
	while (current->next != dll.getAfterLast()) {
		
		if (current->next->obj < minNode ->obj) {
			minNode = current->next;
			
		}
		current = current->next;
	}
	minobj = minNode->obj;
	dll.removeAfter(*minNode->prev);
	return minobj;
}

template<typename T>
T MinQueue<T>::min() {
	//function sorts through all the nodes' objects to find the minimum
	DListNode<T>* current = dll.getFirst(); //gets the first node (header.next)
	minobj = dll.first(); // assign min to first object
	while(current->next != dll.getAfterLast()){
		if (current->next->obj < minobj) { //compare the current node's object to the next node's object
			minobj = current->next->obj;
		}
		current = current->next;
	}
	return minobj;

}

template<typename T>
ostream& operator<<(ostream& out, const MinQueue<T>& mq) {
	cout << mq.getdll();
	return out;
}
