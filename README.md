## Authors
Made by: Jevan Smith, and Isaac Davidson

## Project Goals
1. Implement 2-3 Tree to build an index from a text document. 
2. Compare the complexity of searching for a string using a 2-3 tree with that of a BST tree.

## Requirements
- Built using C++17
- type "make" to build file (on linux)
- after compiling type "./main.out <inputtext.txt>" to run file (on linux)

## Expected Outputs Below
<pre>
=====================================================
- Program Main Menu
=====================================================
Options:
(a) BST
(b) 2-3 Tree
(c) Compare BST and 2-3 Tree
Choice: c
-----------------------------------------------------
[MSG] BUILDING BST TREE...
=====================================================
- Built Tree results (BST Search Tree)
=====================================================
Total number of words:                  1002
Total number of distinct words:         489
Total time spent building index:        0.004876
Height of BST is:                       19
-----------------------------------------------------
[MSG] SEARCHING ALL WORDS IN BST TREE...
=====================================================
- Time Taken Searching all words in index (BST Tree)
=====================================================
Total time taken by BST:                0.001565
-----------------------------------------------------
[MSG] BUILDING 2-3 TREE...
=====================================================
- Built Tree results (2-3 Tree)
=====================================================
Total number of words:                  1002
Total number of distinct words:         489
Total time spent building index:        0.00619
Height of 2-3 Tree is:                  7
-----------------------------------------------------
[MSG] SEARCHING ALL WORDS IN 2-3 TREE...
=====================================================
- Time Taken Searching all words in index (2-3 Tree)
=====================================================
Total time taken by 2-3 Tree:           0.001091




=====================================================
- Program Main Menu
=====================================================
Options:
(a) BST
(b) 2-3 Tree
(c) Compare BST and 2-3 Tree
Choice: a
-----------------------------------------------------
[MSG] BUILDING BST TREE...
=====================================================
- Built Tree results (BST Search Tree)
=====================================================
Total number of words:                  40
Total number of distinct words:         26
Total time spent building index:        0.000214
Height of BST is:                       8
Options: (a) display index, (b) search, (c) save index, (d) quit
a
Binary Search Tree Index:
-------------------------
a                              15
b                              16
c                              1, 17
d                              18
e                              19
f                              20
g                              9, 21
h                              22
i                              7, 23
j                              24
k                              25
l                              26
m                              3, 27
n                              8, 28
o                              2, 29
p                              4, 30
q                              31
r                              32
s                              33
t                              6, 34
u                              5, 10, 11, 35
v                              36
w                              12, 37
x                              13, 38
y                              14, 39
z                              40
Options: (a) display index, (b) search, (c) save index, (d) quit
q





=====================================================
- Program Main Menu
=====================================================
Options:
(a) BST
(b) 2-3 Tree
(c) Compare BST and 2-3 Tree
Choice: b
-----------------------------------------------------
[MSG] BUILDING 2-3 TREE...
=====================================================
- Built Tree results (2-3 Tree)
=====================================================
Total number of words:                  40
Total number of distinct words:         26
Total time spent building index:        0.000263
Height of 2-3 Tree is:                  4
Options: (a) display index, (b) search, (c) save index, (d) quit
a
2-3 Tree Index:
-------------------------
a                              15
b                              16
c                              1, 17
d                              18
e                              19
f                              20
g                              9, 21
h                              22
i                              7, 23
j                              24
k                              25
l                              26
m                              3, 27
n                              8, 28
o                              2, 29
p                              4, 30
q                              31
r                              32
s                              33
t                              6, 34
u                              5, 10, 11, 35
v                              36
w                              12, 37
x                              13, 38
y                              14, 39
z                              40
Options: (a) display index, (b) search, (c) save index, (d) quit
c
Enter a filename to save your index to (Suggested: <filename>.txt) : test.txt
Saved
Options: (a) display index, (b) search, (c) save index, (d) quit
d

