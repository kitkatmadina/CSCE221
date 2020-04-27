#include "SkipList.h"
#include <fstream>

int coinflip() {
	int flip = 0;
	int count = 0;
	while (flip != 1) {
		flip = rand() % 2;
		count++;
	}
	return count;
};




void SkipList::insert(int a) {
	int row_num = coinflip(); //the row where the Node will be inserted;
	
	int comp_num = 0; //number of comparisons
	//instantiate local iterators
	list<Node>::iterator it = skiplist[9].begin();
	list<Node>::iterator temp = skiplist[9].end();
	//insert node
	for (int i = 9; i >= 0; i--) {
		//compare each element
		while (a > it->key) {
			it++;
			comp_num++;
		}//it points to the node in the list with the greatest key value that is still less than a
		//it++; //points to the first element greater than a
		//insert to the left of an element greater than it
		if (i <= row_num) {
			skiplist[row_num].insert(it, Node(a, it));	
		}
		temp->down = it;
		temp = it;
		it = skiplist[i].begin();
		it = it->down;
		//insert element into every row below it
	}
	insertioncosts.push_back(comp_num);
	cout << "Add " << a << " to skip list at level " << row_num << ", " << comp_num << " comparisons" << endl;
};

list<Node>::iterator SkipList::search(int a) {
	
	int comp_num = 0;
	list<Node>::iterator it = skiplist[9].begin(); //points to the -inf in the top level
	
	for (int i = 9; i >= 0; i--) {
		//compare each element
		while (a > it->key) {
			it++;
			comp_num++;
		}
		if (a == it->key) {
			cout << "Successful Search. Key found on row " << i <<"." << endl;
			break;
		}
		else {
			it = --it;
			it = it->down;
		}
		//insert element into every row below it
	}
	searchcosts.push_back(comp_num); 
	return it;
};

int SkipList::remove(int a) {
	//search for element a;
	//find the first list it appears on, f
	//if a does not exist, return an error;
	//use a for loop from skiplist[f] to skiplist.size()-1
	//and std::list::remove() to remove every element a;
	list<Node>::iterator it = skiplist[9].begin(); //points to the -inf in the top level
	int comp_num = 0;
	for (int i = 9; i >= 0; i--) {
		//compare each element
		while (a > it->key) {
			it++;
			comp_num++;
		}
		if (a == it->key) {
			cout << "Deleting " << a <<" from row " << i<< "."<<endl;
			//list<Node>::iterator temp = it->down;
			it = skiplist[i].erase(it);
			
		}
		//insert element into every row below it
		it = --it;
		it = it->down;
	}
	deletioncosts.push_back(comp_num);
};

void SkipList::printskiplist() {
	//print each vector
	for (int i = 9; i >= 0; i--) {
		list<Node>::iterator it = skiplist[i].begin();
		cout << "(";
		while (it != skiplist[i].end()) {
			if (it->key == -inf) {
				cout << "-inf, ";
			}
			else if (it->key == inf) {
				cout << "inf";
			}
			else {
				cout << it->key << ", ";
			}
			it++;
		}
		cout << ")" << endl;

	}
};

void SkipList::avgcost() {
	int avginsertioncost = average(insertioncosts);
	cout << "Average cost of insertion: " << avginsertioncost << endl;
	int avgsearchcost = average(searchcosts);
	cout << "Average cost of search: " << avgsearchcost << endl;
	int avgdeletioncost = average(deletioncosts);
	cout << "Average cost of deletion: " << avgdeletioncost << endl;

};

int average(vector<int> v) {
	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		sum = sum + v[i];
	}
	int avg = sum / v.size();
	return avg;
}

int main(){
	SkipList sl;
	sl.insert(9);
	sl.insert(2);
	sl.insert(7);
	sl.insert(12);
	cout << endl;
	sl.printskiplist();
	cout << endl;
	sl.search(9);
	cout << endl;
	sl.remove(2);
	sl.remove(7);
	sl.remove(9);
	sl.remove(12);
	cout << endl;
	sl.printskiplist();
	cout << endl;
	sl.avgcost();
	cout << endl;

	return 0;
}
