/* 
 *  main function
 */

#include "BTree.h"
#include <string>
#include <iostream>
#include <fstream>


BTree read_file(string file_name)
{
  BTree tree;
  /*
    open the file and use the input operator (operator>>)
    to construct a new tree
  */
  ifstream ifs;
  ifs.open(file_name);
  ifs >> tree;
  return tree;
}


int main()
{
  /*
    write main function
  */
	bool cont = true; //Boolean to loop the main

		// get file
		cout << "Enter File Name with Tree Data: " << endl;
		string fname;
		cin >> fname;
		cout << "Enter Output FIle Name: " << endl;
		string ofname;
		cin >> ofname;
		ofstream ofs1(ofname.c_str());
		if (!ofs1) {
			cout << "cannot open output file " << ofname << endl;
			return -1;
		}
		cout << "Building tree1 from file: " << endl;
		BTree tree1 = read_file(fname);

		cout << "File read." << endl;

		//testing functions
		cout << "Printing Tree1" << endl;
		cout << tree1 << endl << endl; //tests print_level_by_level
		cout << "Copying Tree1 to Tree2: " << endl;
		BTree tree2(tree1); //tests copy constructor;
		cout << "Printing Tree2" << endl;
		cout << tree2 << endl << endl;

		//tests inorder()
		cout << "Testing inorder(): " << endl;
		cout << "Tree1: ";
		tree1.inorder(cout, *(tree1.get_root()));
		//tests search
		cout << endl << endl;
		cout << "Input number to be searched: " << endl;
		int input; 
		cin >> input;
		cout << "Searching in tree1 for value " << input << ": " << endl;
		tree1.search(input);
		cout << endl << endl;

		cout << "Average Search Cost: ";
		int avg = avg_search_cost(tree1);
		cout << avg;
		
	return 0;
}

