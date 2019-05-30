// Assignment: 		Project 3
// Created By: 		Jevan Smith, Isaac Davidson
// Course: 			CS 415
// Date: 			April 16, 2019
// Descriptions:	A simple Binary Search Tree, and 2-3 Tree
//					implementation supporting features like
//					search, insert and inorder traversal.

#include "bst.h"
#include "time.h"
#include <iomanip>
#include <sstream>

//Constructor
BST::BST(){
    root = NULL;
}

//Returns true if there are no nodes in the tree
bool BST::isEmpty(){
    return root == NULL;
}

//Used to implement the search function in the main
//program.
void BST::contains() const{
   string input;
   node *foundNode = NULL;
   cout << "Search word: ";
   cin >> input;
    	if(containsHelper(input, root, foundNode)){
	    cout << "Line Numbers: " << foundNode->lines[0];
	    for(int i = 1; i < foundNode->lines.size(); i++)
		cout << ", " <<foundNode->lines[i]; 
	    cout << '\n';
	    }
	else
	    cout << '\"' << input <<"\" is not in the document\n";
}

//Prints the index to the supplied receiver, either
//cout or the output file
void BST::printTree(ostream & out) const {
	out << "Binary Search Tree Index:\n-------------------------\n";
	printTreeHelper(root, out);
}

//Receives the specified input file and constructs 
//the actual tree. Prints a message when finished.
void BST::buildTree(ifstream & input) {
	cout << "-----------------------------------------------------" << endl;
	cout << "[MSG] BUILDING BST TREE..." << endl;
	int line = 1, numWords = 0, distWords = 0, treeHeight = 0;
	stringstream tempWord;
	double totalTime, finishTime, startTime = clock();
	while (!input.eof()) {
		string tempLine, tempWord;

		//Read a whole line of text from the file
		getline(input, tempLine);
		for (int i = 0; i < tempLine.length(); i++) {
		    //Insert valid chars into tempWord until a delimiter( newline or space) is found
		    while (tempLine[i] != ' '&& tempLine[i] != '\n' && i < tempLine.length() ) {
				tempWord.insert(tempWord.end(), tempLine[i]);
				i++;
		    }
		   
            //Trim any punctuation off end of word. Will leave things like apostrophes
            //and decimal points
            while(tempWord.length() > 0 && !isalnum(tempWord[tempWord.length() - 1]))
			    tempWord.resize(tempWord.size() -1);   
			
            if (tempWord.length() > 0)
            {
				words.push_back(tempWord);
                //Once word is formatted, call insert with the word, the line of the input
                //file it came from, the root of our tree, and the distinct word counter
                insertHelper(tempWord, line, root, distWords);
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
    cout << "- Built Tree results (BST Search Tree)" << endl;
    cout << "=====================================================" << endl;

	cout << setw(40) << std::left;
	cout << "Total number of words: " << numWords<< endl;

	cout << setw(40) << std::left 
	<< "Total number of distinct words: " << distWords << endl;

	cout << setw(40) << std::left 
	<<"Total time spent building index: " << totalTime << endl;

	cout << setw(40) << std::left
	<<"Height of BST is: " << treeHeight << endl;
 
}

void BST::timeTaken() {
	cout << "-----------------------------------------------------" << endl;
	cout << "[MSG] SEARCHING ALL WORDS IN BST TREE..." << endl;
	double totalTime, finishTime, startTime = clock();
	vector<int> lines;
	node *foundNode = NULL; // NEVER USED IN THIS FUNCTION

    for(int i = 0; i < words.size(); i++) {
        containsHelper(words[i], root, foundNode);
    }

    finishTime = clock();
    totalTime = (double) (finishTime - startTime)/CLOCKS_PER_SEC;

    cout << "=====================================================" << endl;
    cout << "- Time Taken Searching all words in index (BST Tree)" << endl;
    cout << "=====================================================" << endl;
    cout << setw(40) << std::left;
    cout << "Total time taken by BST: " << totalTime << endl;
}

//x is the word to insert, line is the line in the text file
//the word was found at, node is the node of the tree being
//examined, and distWord is incremented if a new word is created
//and used by buildTree
void BST::insertHelper(const string &x, int line, node *& t, int &distWord){
    if(t == NULL){
	    t = new node(x, NULL, NULL);
	    t->lines.push_back(line);
	    distWord++;
    }
    else {
		if (x.compare(t->key) > 0)
			insertHelper(x, line, t->right, distWord);
			//If word is already in tree, then add the line the inserted word
			//came from the the nodes lines vector
		else if (x.compare(t->key) == 0)
			t->lines.push_back(line);
		else
			insertHelper(x, line, t->left, distWord);
			
    }
}

//Used by contains() to see if a words is present or not. Will
//give contains() a pointer to the found node so that contains()
//can prints the lines the word was found on.
bool BST::containsHelper(const string & x, node * t, node *& result) const{
	if (t == NULL)
		return false;
	if (t->key.compare(x) == 0){
	    result = t;
 	    return true;
	}
	else if (x > t->key)
		return containsHelper(x, t->right, result);
	else
		return containsHelper(x, t->left, result);
}

//Called by printTree(), does the actual formatted printing
void BST::printTreeHelper(node *t, ostream & out) const{
    if(t == NULL)
		return;
	else {
		printTreeHelper(t->left, out);
		out << setw(30) << std::left;
		out << t->key << " " << t->lines[0];
		for (int i = 1; i < t->lines.size(); i++)
			out << ", " << t->lines[i];
		out << endl;
		printTreeHelper(t->right, out);
	}
}

//Returns height of tree. If tree has only one node, height is 1    
int BST::findHeight(node *t){
    if(t == NULL)
	return 0;
    else{
	int leftHeight = findHeight(t->left), rightHeight = findHeight(t->right);
	if(leftHeight > rightHeight)
	    return(leftHeight+1);
	else 
	    return(rightHeight+1);
    }
}
