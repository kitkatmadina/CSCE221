#pragma once

#include <iostream>
#include <list>
#include <vector>
#include <iterator>
#include <climits>

using namespace std;

int inf = INT_MAX;

struct Node {
	int key;
	list<Node>::iterator down;
	Node(int k, list<Node>::iterator i) : key(k), down (i) {}; 
};


class SkipList {
private:
	vector<list<Node>> skiplist;
	vector<int> searchcosts;
	vector<int> deletioncosts;
	vector<int> insertioncosts;
public: 
	SkipList() {
		skiplist.push_back(list<Node>());
		skiplist[0].push_back(Node(-inf, skiplist[0].end()));
		skiplist[0].push_back(Node(inf, skiplist[0].end()));
		for (int i = 1; i < 10; i++) {
			skiplist.push_back(list<Node>());
			skiplist[i].push_back(Node(-inf, skiplist[i - 1].begin()));
			skiplist[i].push_back(Node(inf, --skiplist[i - 1].end()));
		}
	}
	void insert(int a);
	list<Node>::iterator search(int a);
	int remove(int a);
	void printskiplist();
	void avgcost();


};
int coinflip();
int average(vector<int> v);
