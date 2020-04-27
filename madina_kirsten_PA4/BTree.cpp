/*
 * Binary Tree - source file (functions implementation)
 */

#include "BTree.h"
#include <queue>

ostream& operator<<(ostream& out, BTree& tree)
{
  tree.print_level_by_level(out);
  return out;
}

ostream& operator<<(ostream& out, Node& node)
{
  out << "( "
      << node.value
      << ", "
      << node.search_cost
      << " )";
  return out;
}

istream& operator>>(istream& in, BTree& tree)
{
  /*
    take input from the in stream, and build your tree

    input will look like
    4 
    2 
    6 
    1 
    3 
    5 
    7
  */
	int val;
	in >> val;
	Node* rt = new Node(val);
	rt->search_cost = 1;
	tree.set_root(rt);
	while (in >> val) {
		tree.insert(val, rt);
	}

  return in;
}

BTree::BTree(const BTree& other)
{
  /*
    complete this copy constructor
    make sure when copying nodes to copy
    - value
    - left and right children
  */
	root = other.root;
	preordercopy(other.root);
	
}

BTree::BTree(BTree&& other)
{
  /*
    complete this move constructor */
  
	root->value = other.root->value;
	root->left = other.root->left;
	root->right = other.root->right;
	size = other.size;
	other.root = nullptr;
	other.size = 0;
}

BTree& BTree::operator=(const BTree& other)
{
  if (this != &other) {
    /*
      complete this assignment operator
      make sure when copying nodes to copy
      - value
      - left and right children
    */
	  this->preordercopy(other.root);
  }
  return *this;
}

BTree& BTree::operator=(BTree&& other)
{
  if (this != &other) {
    /*
      complete this move assignment operator*/
    
	  root->value = other.root->value;
	  root->left = other.root->left;
	  root->right = other.root->right;
	  size = other.size;
	  other.root = nullptr;
	  other.size = 0;
	  
  }
  return *this;
}

Node* BTree::insert(int obj, Node *node)
{
  /*
    insert a node into the tree
    - first find where the node should go
    - then modify pointers to connect your new node 
  */
	//recursively traverse the tree to find where node should go.
	if (node == nullptr) node = new Node(obj); //if tree is empty, return the new node;
	//recur down the tree
	if (obj < node->value) { 
		node->left = insert(obj, node->left); 
	} //smaller values go to the left
	else if (obj > node->value) { node->right = insert(obj, node->right); }//larger values go to the right
	this->update_search_cost();
	return node;
}

Node* BTree::search(int obj) //implemented iteratively
{
  /*
    recursivly search down the tree to find the node that contains obj
    - if you don't find anything return nullptr
  */
	Node* t = root; //node which traverses the tree. Starts at the root.
	while (t != nullptr) {
		if (obj < t->value) t = t->left;
		else if (obj > t->value) t = t->right; 
		else {
			cout << "Found at Node: " << *t;
			return t; //found
		}
	}
	cout << "Not Found";
  return nullptr;
}

void BTree::update_search_cost() {
  /*
    do a BFS of your tree and update the search cost of all nodes
  */
	if (root!=nullptr){
		search_cost_help(root);
	}

}

void BTree::inorder(ostream& out, const Node& tree)
{
  /*
    print your nodes in infix order

    if our tree looks like 

    4
    2 6
    1 3 5 7

    we should get

    1 2 3 4 5 6 7 
  */
	inorderprint(root);
	
  return;
}

void BTree::print_level_by_level(ostream& out)
{
  /*
    print the tree using a BFS 

    output should look like this if we dont have a full tree

    4
    2 6
    1 X 5 7
    X X X X X X X 9

    it will be helpfull to do this part iterativly, 
    so do the BFS with the std stack data structure.

    it may also be helpfull to put the entire tree into a vector 
    (probably google this if you dont know how to do it)
  */
	if (root == nullptr) return;

	//update_search_cost()


	queue<Node *> v;
	v.push(root);
	while (v.empty() == false) {
		int count = v.size();
		while (count > 0) {
			Node* n = v.front();
			if (n->is_leaf() && n->value == -1) { cout << "X "; }
			else{cout << n->value << '[' << n->search_cost << "] "; }
			if (n->left==nullptr && n->value != -1) { v.push(new Node(-1)); }
			if (n->right == nullptr && n->value != -1) { v.push(new Node(-1)); }
			
			v.pop();
			if (n->left != nullptr) {
				v.push(n->left);
			}
			if (n->right != nullptr) {
				v.push(n->right);
			}
			
			
			count--;
		}
		cout << endl;

	}

  return;
}

void BTree::preordercopy(Node* t) 
{
	 if (t != nullptr) {
		 
		 if (t->left != nullptr) preordercopy(t->left);
		 insert(t->value, this->root);
		 if (t->right != nullptr) preordercopy(t->right);
	 }

}

void BTree::inorderprint(Node* t)
{
	if (t != nullptr) {
		if (t->left) inorderprint(t->left);
		cout << t->value << " ";
		if (t->right) inorderprint(t->right);
	}

}
void BTree::search_cost_help(Node * n) {
	if (n->left != nullptr) {
		n->left->search_cost = n->search_cost + 1;
		search_cost_help(n->left);
		
	}
	if (n->right != nullptr) {
		n->right->search_cost = n->search_cost + 1;
		search_cost_help(n->right);
	}
}

void avg_sc_recur(Node* n, int sum, int num) {
	if (n != nullptr) {
		
		if (n->left) { avg_sc_recur(n->left, sum, num); }
		num++;
		sum = sum + n->search_cost;
		if (n->right) { avg_sc_recur(n->right, sum, num); }

	}
}

int avg_search_cost(BTree b) {
	Node* curr = b.get_root();
	int sum = curr->search_cost;
	int num_of_nodes = 1;
	avg_sc_recur(curr, sum, num_of_nodes);
	int avg = sum / num_of_nodes;
	return avg;
}

