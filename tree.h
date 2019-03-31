//Yanchen Guo
//CS4280 P0
#ifndef TREE_H
#define TREE_H
#include "node.h"
#include <fstream>
#include <string>

// Prototype of the print traversal function and build tree function
void printInorder(Node*,string);
void printPreorder(Node*, string);
void printPostorder(Node*, string);
struct Node* buildTree(Node*, string,char);
#endif
