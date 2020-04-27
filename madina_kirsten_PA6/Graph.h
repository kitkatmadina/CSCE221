#pragma once
#include <list>
#include <iostream>

using namespace std;

class Graph {
	int vertices; //number of vertices
	int edges; //number of edges
	vector<int> adj[100]; //matrix
public:
	Graph(int V, int E) : vertices(V), edges(E){}
	int get_vertices() { return vertices; }
	int get_edges() { return edges; }
	void addEdge(int start, int dest); //start and end points
	void print();
	bool Search(int a); // integer representing vertex
	void delEdge(int start, int dest);
	void draw(bool b);
	bool draw_in_one_line();
};

