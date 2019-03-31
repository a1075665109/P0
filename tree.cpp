//Yanchen Guo
//CS4280 P0
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>

#include "node.h"
#include "tree.h"

using namespace std;

//Different traversal functions and a build tree function
//seperated by space.

void inorder(Node *ptr, int depth,ofstream &fp){
	if(ptr){
		inorder(ptr->left,depth+1,fp);
		string s;
		for(int i=0; i<depth; i++){
			s+="  ";
		}
		fp<< s;
		for(int i=0; i < ptr->data.size(); ++i){
			fp << ptr->data.at(i) << " ";
		}
		fp<< "\n";
		inorder(ptr->right, depth+1,fp);
	}
}

/*printfunction that opens up file streams and pass file pointers
  to the traversal function so its not called recursively*/
void printInorder(struct Node* ptr,string fn){
	fn+=".inorder";
        ofstream fp;
        fp.open(fn.c_str(),ios::out);
        inorder(ptr,0,fp);
        fp.close();
}


void preorder(Node* ptr, int depth, ofstream &fp){
	if(ptr){
		string s;
		for(int i=0;i<depth;i++){
			s+="  ";
		}
		fp<< s;
		for(int i=0; i < ptr->data.size();i++){
			fp << ptr->data.at(i) <<" ";
		}		
		fp<< "\n";
		preorder(ptr->left, depth+1,fp);
		preorder(ptr->right, depth+1,fp);
	}
}

void printPreorder(struct Node* ptr,string fn){
        fn+=".preorder";
	ofstream fp;
        fp.open(fn.c_str(),ios::out);
        preorder(ptr,0,fp);
        fp.close();
}


void postorder(Node* ptr, int depth,ofstream &fp){
	if(ptr){
		postorder(ptr->left,depth+1,fp);
		postorder(ptr->right,depth+1,fp);
		string s;
		for(int i=0; i<depth; i++){
			s += "  ";
		}
		fp<< s;
		for(int i=0; i<ptr->data.size();i++){
			fp << ptr->data.at(i) <<" ";
		}
		fp<< "\n";
	}
}
void printPostorder(struct Node* ptr,string fn){
	fn+=".postorder";
        ofstream fp;
        fp.open(fn.c_str(),ios::out);
        postorder(ptr,0,fp);
        fp.close();
}


struct Node *newNode(string data,char key){
	struct Node* temp = new Node;
	temp->key = key;
	temp->left = temp->right=NULL;
	temp->data.push_back(data);
	return temp;
}

struct Node* buildTree(struct Node*root,string data, char key){
	if(root==NULL){
		struct Node*temp =NULL;
		temp = new Node;
		temp->key = key;
		temp->left = temp->right=NULL;
		temp->data.push_back(data);
		return temp ;
	}
	if(key < root->key){
		root->left = buildTree(root->left,data,key);
	}else if(key > root->key){
		root->right = buildTree(root->right,data,key);
	}else if(key == root->key){
		for(int i = 0; i < root->data.size();i++){
			if (data == root->data.at(i)){
				return root;
			}
		}
		root->data.push_back(data);
	}
	return root;
}	 
