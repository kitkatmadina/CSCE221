#include "MinQueue.h"
#include <algorithm> // to enqueue rand numbers
using namespace std;

int main() {
	//Create new MinQueue
	cout << "Create a new list of integers: " << endl;
	MinQueue<int> mq;
	cout << "List: " << mq << endl << endl;
	

	//test for enqueue
	cout << "Enqueue 10 nodes with random values: " << endl;
	for (int i = 0; i < 10; i++) {
		mq.enqueue(rand() % 20);
	}
	cout << "List: " << mq << endl;
	cout << "Size of List: " << mq.size() << endl << endl;
	//test for dequeue and min()
	cout << "Dequeue 3 minimum values: " << endl;
	cout << "min: " << mq.min() << endl;
	mq.dequeue();
	cout << "List: " << mq << endl;
	cout << "min: " << mq.min() << endl;
	mq.dequeue();
	cout << "List: " << mq << endl;
	cout << "min: " << mq.min() << endl;
	mq.dequeue();
	cout << "List: " << mq << endl;
	cout << "Size of List: " << mq.size() << endl << endl;


	//Create new MinQueue
	cout << "Create a new list of characters: " << endl;
	MinQueue<char> mq2;
	cout << "List: " << mq2 << endl << endl;
	//test for enqueue
	cout << "Enqueue 10 random letters: " << endl; 
	for (int i = 0; i < 10; i++) {
		int r = rand() % 26;
		char c = 'a' + r;
		mq2.enqueue(c);
	}
	cout << "List: " << endl;
	cout << mq2 << endl << endl;

	//test for dequeue and min()
	cout << "Dequeue 2 minimum values: " << endl;
	cout << "min: " << mq2.min() << endl;
	mq2.dequeue();
	cout << "List: " << mq2 << endl;
	cout << "min: " << mq2.min() << endl;
	mq2.dequeue();
	cout << "List: " << mq2 << endl;
	cout << "Size of List: " << mq2.size() << endl << endl;
}