// Assignment: 		Project 3
// Created By: 		Jevan Smith, Isaac Davidson
// Course: 			CS 415
// Date: 			April 16, 2019
// Descriptions:	A simple Binary Search Tree, and 2-3 Tree
//					implementation supporting features like
//					search, insert and inorder traversal.

#include <iostream>
#include <fstream>
#include "bst.h"
#include "ttTree.h"
using namespace std;

int main(int argc, char* argv[]) {
	char choice;
	char option;

	if (argc != 2) {
	    cout << "Incorrect input. Correct format: ./<exectuable.out> <inputtext.txt>\n";
	    return 1;
	}

	ifstream input(argv[1]);

	if(input.is_open()){
			cout << endl;
		    cout << "=====================================================" << endl;
			cout << "- Program Main Menu" << endl;
			cout << "=====================================================" << endl;
			cout << "Options: " << endl;
			cout << "(a) BST " << endl;
			cout << "(b) 2-3 Tree " << endl; 
			cout << "(c) Compare BST and 2-3 Tree" << endl;
			cout << "Choice: ";
			cin >> option;

			if(option == 'a') { // Binary Tree
				BST myTree;
	            myTree.buildTree(input);
	            input.close();
	            while(1) {
		        cout <<"Options: (a) display index, (b) search, (c) save index, (d) quit\n";
		        cin >> choice;

				//Print index
		        if(choice == 'a')
		            myTree.printTree(cout);
		       
				//Search index for a word
				else if(choice == 'b')
			            myTree.contains();

				//Save index
		        else if(choice == 'c'){
			    string outputFile;
		            cout << "Enter a filename to save your index to (Suggested: <filename>.txt) : ";
			    cin >> outputFile;
			    ofstream output(outputFile.c_str());
		            myTree.printTree(output);
		            output.close();
			    cout << "Saved\n";
		        }

				//Quit	
		        else
			    	break;
	            }
        	}

        	if(option == 'b') { // 2-3 Tree
				ttTree myTree;
	            myTree.buildTree(input);
	            input.close();
	            while(1) {
		        choice = 0;
		        cout <<"Options: (a) display index, (b) search, (c) save index, (d) quit\n";
		        cin >> choice;

				//Print index
		        if(choice == 'a')
		            myTree.printTree(cout);
		       
				//Search index for a word
				else if(choice == 'b')
			            myTree.contains();

				//Save index
		        else if(choice == 'c'){
			    string outputFile;
		            cout << "Enter a filename to save your index to (Suggested: <filename>.txt) : ";
			    cin >> outputFile;
			    ofstream output(outputFile.c_str());
		            myTree.printTree(output);
		            output.close();
			    cout << "Saved\n";
		        }

				//Quit	
		        else
			    	break;
	            }
        	}

			if(option == 'c') {
				BST myTree;
				ttTree myTree2;
				ifstream input2(argv[1]);

				myTree.buildTree(input);
				myTree.timeTaken();
				input.close();
				myTree2.buildTree(input2);
				myTree2.timeTaken();
				input2.close();

			}
        }

	else {
		cout << "Invalid File Name. Restart Program.\n";
		return 2;
	}
	cout << endl;
	return 0;
}
