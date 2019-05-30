// Assignment: 		Project 3
// Created By: 		Jevan Smith, Isaac Davidson
// Course: 			CS 415
// Date: 			April 16, 2019
// Descriptions:	A simple Binary Search Tree, and 2-3 Tree
//					implementation supporting features like
//					search, insert and inorder traversal.

#ifndef TTTREE_H
#define TTTREE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class ttTree {
public:
    ttTree();
    void printTree(ostream & out = cout);
    void contains();
    void buildTree(ifstream & input);
    void timeTaken();
private:
    struct node {
        node * left;
        node * middle;
        node * right;
        string leftKey;
        string rightKey;
        vector<int> leftLines;
        vector<int> rightLines;
    };
    node * root;
    vector<string> words;
    node * createNode(const string x, node * left, node * middle, node * right);
    bool isLeafNode(node * x);
    node * add(node * x, node * n);
    node * insert(const string &key, int line, node * root, int &distWord);
    bool searchTreeHelper(node * x, string value, vector<int> &lines);
    void printLines(node * x, bool isLeft, ostream & out);
    void print(node * x, ostream & out);
    void printTreeHelper(node * x, ostream & out);
    int findHeight(node * x);
};

#endif