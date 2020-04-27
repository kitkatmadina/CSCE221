/*
 * Binary Tree - header file
 */

#ifndef BTREE_H
#define BTREE_H

#include <iostream>
using namespace std;

struct Node
{
  int value;
  Node* left;
  Node* right;
  int search_cost;

  // constructor
  Node(int val = 0, Node* l = nullptr, Node* r = nullptr)
    : value(val), left(l), right(r), search_cost(0) {}

  // query
  bool is_leaf() { return (left == nullptr && right == nullptr); }
};

class BTree
{
private:
  int size;
  Node* root;

public:
  // constructors

  BTree() : root(nullptr), size(0) {} // default constructor; done
  BTree(const BTree& other); // copy constructor, implemented
  BTree(BTree&& other); // move constructor, implemented
  // assignment and move assignment operator
  
  BTree& operator=(const BTree& other); //implemented
  BTree& operator=(BTree&& other);//implemented

  //getter functions; done
  int get_size() { return size; }
  Node* get_root() { return root; } // should not be used unless it is really necessary
  
  //more functions
  void set_root(Node* node) { root = node; } //done
  Node* insert(int obj, Node* node); //done
  Node* search(int obj); //done
  void update_search_cost();
  void inorder(ostream& out, const Node& tree);
  void print_level_by_level(ostream& out);


  void preordercopy(Node* n);//helper function
  void inorderprint(Node*n);
  void search_cost_help(Node* n); //helper function
};

ostream& operator<<(ostream& out, BTree& tree);
ostream& operator<<(ostream& out, Node& node);
istream& operator>>(istream& in, BTree& tree);

int avg_search_cost(BTree b);

#endif
