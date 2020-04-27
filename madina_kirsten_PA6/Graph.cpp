/* Name: Kirsten Madina
kirsten.madina
Section 502
email kirsten.madina@tamu.edu 
*/



#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Graph.h"
#include <stack>
#include <iterator>
#include <algorithm>
#include <utility>
using namespace std;

stack<int> S;

void Graph::addEdge(int a, int b) {
	adj[a].push_back(b);
	adj[b].push_back(a);
}

void Graph::print() {
	//print function
	for (int i = 1; i <= vertices; i++) {
		cout << i;
		for (auto it : adj[i]) {
			cout << "-->" << it;
		}
		cout << endl;
	}
}

void Graph::delEdge(int u, int v) {
	remove(adj[u].begin(), adj[u].end(), v);
	adj[u].pop_back();
	remove(adj[v].begin(), adj[v].end(), u);
	adj[v].pop_back();
}

void Graph::draw(bool b) {
	if (b) {
		bool possible = false;
		int i = 5;
		while (possible != true) {
			Search(i);
			if (S.size() >= edges+1) { possible = true; }
			i++;
		}
		
		while (!S.empty()) {
			cout << S.top() << "-->";
			//pair<int, int> e = make_pair(S.top(), S.top());
			//cout << "(" << e.first << "," << e.second << ")";
			S.pop();
		}

		
		
	}
	else if (!b) {
		cout << "Drawing this graph in one stroke is not possible." << endl;
	}
}

bool Graph::Search(int u) {
	S.push(u);
	if (adj[u].empty()) {
		return true; //if no edges available return true;
	}
	else {
		for (int v: adj[u]) {
			//remove v from matrix
			delEdge(u, v);
			bool f = Search(v);
			if (f==true) { 
				return true; 
			}
			else{
				addEdge(u, v);
			}
		}
		S.pop();
		return false;
	}
}

bool Graph::draw_in_one_line() {
	bool b;
	int odd = 0;
	for (int i = 0; i < get_vertices(); i++) {
		if (adj[i].size() & 1) { odd++; }
	}
	if (odd > 2) {
		b = false;
	}
	else { b = true; }
	return b;
}

int main(int argc, char **argv) {
		cout << "Creating Graph for data file: " << argv[1] << endl;
		ifstream ifs(argv[1]);
		int n, m;
		ifs >> n >> m;
		Graph g1(n, m);
		//num of vertices and edges;
		int u, v;
		for (int i = 0; i < m; i++) {
			ifs >> u >> v;
			g1.addEdge(u, v);
		}
		g1.print();
		bool possible = g1.draw_in_one_line(); 
		g1.draw(possible);
	

	return 0;
}