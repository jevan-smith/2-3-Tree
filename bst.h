// Assignment: 		Project 3
// Created By: 		Jevan Smith, Isaac Davidson
// Course: 				CS 415
// Date: 					April 16, 2019
// Descriptions:	A simple Binary Search Tree, and 2-3 Tree
//								implementation supporting features like
//								search, insert and inorder traversal.

#ifndef BST_H
#define BST_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class BST{
    public: 
        BST();
        void contains() const;
        bool isEmpty();
        void printTree(ostream & out = cout) const;
        void buildTree(ifstream & input);
		void timeTaken();
    private:
		struct node{
			node(const string &x, node *l, node *r)
			:key(x), left(l), right(r){
					lines.resize(0);
			}
			string key;
			node * left;
			node * right;
			vector<int> lines;
		};
		node * root;
		vector<string> words;
		void insertHelper(const string &X, int line, node *& t, int &distWords);
		bool containsHelper(const string & x, node * t, node* &result) const;
		void printTreeHelper(node *t, ostream & out) const;
		int findHeight(node *t);
};
	
#endif	
    
	

