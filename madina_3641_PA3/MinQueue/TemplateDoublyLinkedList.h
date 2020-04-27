#include <cstdlib>
#include <iostream>
using namespace std;
// list node
template<typename T>
struct DListNode {
	T obj;
	DListNode<T> *prev, *next;
	DListNode(T e = T(), DListNode<T> *p = nullptr, DListNode<T> *n = nullptr)
		: obj(e), prev(p), next(n) {}
};

// doubly linked list
template<typename T>
class DoublyLinkedList {
private:
	DListNode<T> header, trailer;
public:
	DoublyLinkedList() : header(T()), trailer(T()) // constructor
	{
		header.next = &trailer; trailer.prev = &header;
	}
	DoublyLinkedList(const DoublyLinkedList<T>& dll); // copy constructor
	DoublyLinkedList(DoublyLinkedList<T>&& dll); // move constructor
	~DoublyLinkedList(); // destructor
	DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>& dll); // assignment operator
	DoublyLinkedList<T>& operator=(DoublyLinkedList<T>&& dll); // move assignment operator
														 // return the pointer to the first node
	DListNode<T> *getFirst() const { return header.next; }
	// return the pointer to the trailer
	const DListNode<T> *getAfterLast() const { return &trailer; }
	// return if the list is empty
	bool isEmpty() const { return header.next == &trailer; }
	T first() const; // return the first object
	T last() const; // return the last object
	void insertFirst(T newobj); // insert to the first of the list
	T removeFirst(); // remove the first node
	void insertLast(T newobj); // insert to the last of the list
	T removeLast(); // remove the last node
	void insertAfter(DListNode<T> &p, T newobj);
	void insertBefore(DListNode<T> &p, T newobj);
	T removeAfter(DListNode<T> &p);
	T removeBefore(DListNode<T> &p);
};

// output operator
template<typename T>
ostream& operator<<(ostream& out, const DoublyLinkedList<T>& dll);
// return the list length
template<typename T>
int DoublyLinkedListLength(DoublyLinkedList<T>& dll);

/*Implementation of class Doubly Linked List*/
// copy constructor
template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& dll)
{
	// Initialize the list
	header.next = &trailer;
	trailer.prev = &header;

	/* Complete this function */
	DListNode<T>* current = dll.getFirst();
	while (current->next != nullptr) {
		insertLast(current->obj);
		current = current->next;
	}
}
// move constructor
template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(DoublyLinkedList<T>&& dll)
{
	// Initialize the list
	header.next = &trailer;
	trailer.prev = &header;

	/* Complete this function */
	DListNode<T>* current = dll.getFirst();
	while (current->next != nullptr) {
		insertLast(current->obj);
		current = current->next;
	}

}

// assignment operator
template<typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& dll)
{
	// use if (this != &dll)
	/* Complete this function */
	if (this != &dll) {
		DListNode<T> *current = dll.getFirst();
		while (current->next != nullptr) {
			insertLast(current->obj);
			current = current->next;
		}
	}
	return *this;
}
// move assignment operator
template<typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(DoublyLinkedList<T>&& dll)
{
	// use if (this != &dll)
	/* Complete this function */
	if (this != &dll) {
		DListNode<T> *current = dll.getFirst();
		while (current->next != nullptr) {
			insertLast(current->obj);
			current = current->next;
		}
	}
	return *this;
}

// insert the new object as the first one
template<typename T>
void DoublyLinkedList<T>::insertFirst(T newobj)
{
	/* Complete this function */
	DListNode<T> *newNode = new DListNode<T>(newobj, &header, header.next);
	header.next->prev = newNode;
	header.next = newNode;
}

// insert the new object as the last one
template<typename T>
void DoublyLinkedList<T>::insertLast(T newobj)
{
	/* Complete this function */
	DListNode<T> *newNode = new DListNode<T>(newobj, trailer.prev, &trailer);
	trailer.prev->next = newNode;
	trailer.prev = newNode;
}

// remove the first object from the list
template<typename T>
T DoublyLinkedList<T>::removeFirst()
{
	/* Complete this function */
	DListNode<T> *node = header.next;
	node->next->prev = &header;
	header.next = node->next;
	T obj = node->obj;
	delete node;
	return obj;
}

// remove the last object from the list
template<typename T>
T DoublyLinkedList<T>::removeLast()
{
	/* Complete this function */
	DListNode<T> *node = trailer.prev;
	node->prev->next = &trailer;
	trailer.prev = node->prev;
	T obj = node->obj;
	delete node;
	return obj;
}

// destructor
template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	/* Complete this function */
	DListNode<T> *prev_node, *node = header.next;
	while (node != &trailer) {
		prev_node = node;
		node = node->next;
		delete prev_node;
	}
	header.next = &trailer;
	trailer.prev = &header;
}

// return the first object
template<typename T>
T DoublyLinkedList<T>::first() const
{
	/* Complete this function */
	return header.next->obj;
}

// return the last object
template<typename T>
T DoublyLinkedList<T>::last() const
{
	/* Complete this function */
	return trailer.prev->obj;
}

// insert the new object after the node p
template<typename T>
void DoublyLinkedList<T>::insertAfter(DListNode<T> &p, T newobj)
{
	/* Complete this function */
	DListNode<T> *newNode = new DListNode<T>(newobj, &p, p.next);
	p.next->prev = newNode;
	p.next = newNode;
}

// insert the new object before the node p
template<typename T>
void DoublyLinkedList<T>::insertBefore(DListNode<T> &p, T newobj)
{
	/* Complete this function */
	DListNode<T> *newNode = new DListNode<T>(newobj, p.prev, &p);
	p.prev->next = newNode;
	p.prev = newNode;
}

// remove the node after the node p
template<typename T>
T DoublyLinkedList<T>::removeAfter(DListNode<T> &p)
{
	/* Complete this function */
	DListNode<T> *after = p.next;
	p.next = after->next;
	after->next->prev = &p;
	T obj = after->obj;
	delete after;
	return obj;
}

// remove the node before the node p
template<typename T>
T DoublyLinkedList<T>::removeBefore(DListNode<T> &p)
{
	/* Complete this function */
	DListNode<T> *before = p.prev;
	p.prev = before->prev;
	before->prev->next = &p;
	T obj = before->obj;
	delete before;
	return obj;
}

// return the list length
template<typename T>
int DoublyLinkedListLength(DoublyLinkedList<T>& dll)
{
	/* Complete this function */
	DListNode<T> *current = dll.getFirst();
	int count = 0;
	while (current != dll.getAfterLast()) {
		current = current->next;
		count++;
	}
	return count;
}

// output operator
template<typename T>
ostream& operator<<(ostream& out, const DoublyLinkedList<T>& dll)
{

	/* Complete this function */
	DListNode<T> *current = dll.getFirst();
	while (current != dll.getAfterLast()) {
		out << current->obj << " ";
		current = current->next;
	}


	return out;
}
