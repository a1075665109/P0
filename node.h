//Yanchen Guo
//CS4280 P0
#ifndef NODE_H
#define NODE_H

#include <vector>
#include <string>
using namespace std;

// Basic structure of the node.
struct Node{
	char key;
	struct Node *left, *right;
	vector<string>data;
	int depth;
};

#endif
