// Assignment: 		Project 3
// Created By: 		Jevan Smith, Isaac Davidson
// Course: 			CS 415
// Date: 			April 16, 2019
// Descriptions:	A simple Binary Search Tree, and 2-3 Tree
//					implementation supporting features like
//					search, insert and inorder traversal.

#include "ttTree.h"
#include "time.h"
#include <iomanip>
#include <sstream>

ttTree::ttTree(){
    root = NULL;
}

void ttTree::printTree(ostream & out) {
    out << "2-3 Tree Index:\n-------------------------\n";
    printTreeHelper(root, out);
}

void ttTree::contains() {
    vector<int> lines;
    string input;
    cout << "Search word: ";
    cin >> input;
    bool found = searchTreeHelper(root, input, lines);
    if(found) {
        cout << "Line Numbers:";
        cout << " " << lines[0];
        for (int i = 1; i < lines.size(); i++)
            cout << ", " << lines[i];
    }
    else {
        cout << "\"" << input << "\" " << "is not in the document";
    }
    cout << endl;
}

void ttTree::buildTree(ifstream & input) {
    cout << "-----------------------------------------------------" << endl;
    cout << "[MSG] BUILDING 2-3 TREE..." << endl;
    int line = 1, numWords = 0, distWords = 0, treeHeight = 0;
    string tempLine, tempWord;
    double totalTime, finishTime, startTime = clock();
    while (!input.eof()) {

        //Read a whole line of text from the file
        getline(input, tempLine);
        for (int i = 0; i < tempLine.length(); i++) {
            //Insert valid chars into tempWord until a delimiter( newline or space) is found
            while (tempLine[i] != ' ' && tempLine[i] != '\n' && i < tempLine.length() ) {
                tempWord.insert(tempWord.end(), tempLine[i]);
                i++;
            }

            //Trim any punctuation off end of word. Will leave things like apostrophes
            //and decimal points
            while(tempWord.length() > 0 && !isalnum(tempWord[tempWord.length() - 1]))
                tempWord.resize(tempWord.size() - 1);

            if (tempWord.length() > 0)
            {
                words.push_back(tempWord);
                //Once word is formatted, call insert with the word, the line of the input
                //file it came from, the root of our tree, and the distinct word counter
                root = insert(tempWord, line, root, distWords);
                //Increment our total number of words inserted
                numWords++;
                //Clear out tempWord so we can use it again
                tempWord.clear();
            }
        }
        line++;
    }

    //Do time and height calculation
    finishTime = clock();
    totalTime = (double) (finishTime - startTime)/CLOCKS_PER_SEC;
    treeHeight = findHeight(root);

    //Print output

    cout << "=====================================================" << endl;
    cout << "- Built Tree results (2-3 Tree)" << endl;
    cout << "=====================================================" << endl;

    cout << setw(40) << std::left;
    cout << "Total number of words: " << numWords << endl;

    cout << setw(40) << std::left
         << "Total number of distinct words: " << distWords << endl;

    cout << setw(40) << std::left
         <<"Total time spent building index: " << totalTime << endl;

    cout << setw(40) << std::left
    <<"Height of 2-3 Tree is: " << treeHeight << endl;
}

void ttTree::timeTaken() {
    cout << "-----------------------------------------------------" << endl;
    cout << "[MSG] SEARCHING ALL WORDS IN 2-3 TREE..." << endl;
    double totalTime, finishTime, startTime = clock();
    vector<int> lines;

    for(int i = 0; i < words.size(); i++) {
        searchTreeHelper(root, words[i], lines);
    }

    finishTime = clock();
    totalTime = (double) (finishTime - startTime)/CLOCKS_PER_SEC;

    cout << "=====================================================" << endl;
    cout << "- Time Taken Searching all words in index (2-3 Tree)" << endl;
    cout << "=====================================================" << endl;
    cout << setw(40) << std::left;
    cout << "Total time taken by 2-3 Tree: " << totalTime << endl;
}

ttTree::node * ttTree::createNode(const string x, node * left, node * middle, node * right) {
    node * t = new node();
    t->leftKey = x;
    t->left = left;
    t->middle = middle;
    t->right = right;
    return t;
}

bool ttTree::isLeafNode(node * x) {
    if(x->left == NULL && x->middle == NULL && x->right == NULL) {
        return true;
    }
    else {
        return false;
    }
}

ttTree::node * ttTree::add(node * x, node * n) {
    if(x->rightKey.empty()) {
        if(x->leftKey < n->leftKey) {
            x->rightKey = n->leftKey; x->rightLines = n->leftLines;
            x->middle = n->left;
            x->right = n->middle;
        }
        else { //SWAP
            x->rightKey = x->leftKey; x->rightLines = x->leftLines;
            x->leftKey = n->leftKey; x->leftLines = n->leftLines;
            x->right = x->middle;
            x->middle = n->middle;
            x->left = n->left;
        }
        return x;
    }
    // ADD TO LEFT
    else if(x->leftKey >= n->leftKey) {
        node * newNode = createNode(x->leftKey, n, x, NULL);
        newNode->leftLines = x->leftLines;
        x->left = x->middle; x->middle = x->right; x->right = NULL;
        x->leftKey = x->rightKey; x->rightKey.clear();
        x->leftLines = x->rightLines; x->rightLines.clear();

        return newNode;
    }
    // ADD TO CENTER
    else if(x->rightKey >= n->leftKey) {
        node * newNode = createNode(x->rightKey, n->middle, x->right, NULL);
        newNode->leftLines = x->rightLines;
        x->middle = n->left;
        n->middle = newNode; n->left = x;
        x->rightKey.clear(); x->right = NULL; x->rightLines.clear();

        return n;
    }
    // ADD TO RIGHT
    else {
        node * newNode = createNode(x->rightKey, x, n, NULL);
        newNode->leftLines = x->rightLines;
        x->right = NULL; x->rightKey.clear(); x->rightLines.clear();

        return newNode;
    }
}

ttTree::node * ttTree::insert(const string &key, int line, node * root, int &distWord){
    if(root == NULL) {
        node * newNode = createNode(key, NULL, NULL, NULL);
        newNode->leftLines.push_back(line);
        distWord++;
        return newNode;
    }
    if(key == root->leftKey || key == root->rightKey) { // Remove's duplicates
        if(key == root->leftKey)
            root->leftLines.push_back(line);
        else
            root->rightLines.push_back(line);
        return root;
    }
    if(isLeafNode(root)) {
        node * newNode = createNode(key, NULL, NULL, NULL);
        newNode->leftLines.push_back(line);
        node * finalNode = add(root, newNode);
        distWord++;
        return finalNode;
    }
    // LEFT
    if(key < root->leftKey) {
        node * newNode = insert(key, line, root->left, distWord);
        if(newNode == root->left)
            return root;
        else
            return add(root, newNode);
    }
    // MIDDLE
    else if (root->rightKey.empty() || key < root->rightKey) {
        node * newNode = insert(key, line, root->middle, distWord);
        if(newNode == root->middle)
            return root;
        else
            return add(root, newNode);
    }
    // RIGHT
    else {
        node * newNode = insert(key, line, root->right, distWord);
        if(newNode == root->right)
            return root;
        else
            return add(root, newNode);
    }
}

bool ttTree::searchTreeHelper(node * x, string value, vector<int> &lines) {
    if(root == NULL ) {
        return false;
    }
    if(value == x->leftKey) {
        lines = x->leftLines;
        return true;
    }
    if(value == x->rightKey) {
        lines = x->rightLines;
        return true;
    }
    if(isLeafNode(x))
        return false;
    else if(!x->rightKey.empty()) { 
        if (value < x->leftKey) {
            return searchTreeHelper(x->left, value, lines);
        } else if (value > x->leftKey && value < x->rightKey) {
            return searchTreeHelper(x->middle, value, lines);
        } else { 
            return searchTreeHelper(x->right, value, lines);
        }
    }
    else {
        if (value < x->leftKey)
            return searchTreeHelper(x->left, value, lines);
        else
            return searchTreeHelper(x->middle, value, lines);
    }
}

void ttTree::printLines(node * x, bool isLeft, ostream & out) {
    if(isLeft) {
        if(!x->leftLines.empty()) {
            out << " " << x->leftLines[0];
            for (int i = 1; i < x->leftLines.size(); i++)
                out << ", " << x->leftLines[i];
        }
    }
    else {
        if(!x->rightLines.empty()) {
            out << " " << x->rightLines[0];
            for (int i = 1; i < x->rightLines.size(); i++)
                out << ", " << x->rightLines[i];
        }
    }
}

void ttTree::print(node * x, ostream & out) {
    if(x != NULL) {
        if(x->rightKey.empty()) {
            out << setw(30) << std::left;
            out << x->leftKey; printLines(x, true, out);
            out << endl;
        } else {
            out << setw(30) << std::left;
            out << x->leftKey; printLines(x, true, out);
            out << endl;
            out << setw(30) << std::left;
            out << x->rightKey; printLines(x, false, out);
            out << endl;
        }
    }
}

void ttTree::printTreeHelper(node * x, ostream & out) { //Inorder
    if (x != NULL) {
        if (isLeafNode(x)) {
            print(x, out);
        } else {
            printTreeHelper(x->left, out);
            out << setw(30) << std::left;
            out << x->leftKey; printLines(x, true, out);
            out << endl;
            if (x->middle) {
                printTreeHelper(x->middle, out);
                if (!x->rightKey.empty()) {
                    out << setw(30) << std::left;
                    out << x->rightKey; printLines(x, false, out);
                    out << endl;
                }
            }
            printTreeHelper(x->right, out);
        }
    }
}

int ttTree::findHeight(node * x){
    if(x == NULL)
        return 0;
    else {
        int leftHeight = findHeight(x->left), rightHeight = findHeight(x->right);
        int middleHeight = findHeight(x->middle);
        if(leftHeight > rightHeight && leftHeight > middleHeight)
            return(leftHeight+1);
        else if(rightHeight > leftHeight && rightHeight > middleHeight)
            return (rightHeight+1);
        else
            return(middleHeight+1);
    }
}