//Yanchen Guo
//cs4280 p0
//Yanchen Guo
//CS 4280
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdio>
#include <unistd.h>

#include "tree.h"
#include "node.h"
using namespace std;
int main(int argc, char*argv[]){
	//creating a node pointer and point it to a new node
	//resize the string vector to avoid seg fault	
	struct Node* root;
	root = new Node;
	root->data.resize(0);
	
    //if it there is no redirect	
    if(isatty(STDIN_FILENO)){	
	
	//if there is no argument then record from keyboard
	//write the input into a input.txt file for later use
	if(argc ==1){
		
		string filename = "input.txt";        
		string tempInput;
		ofstream wfile;
		wfile.open (filename.c_str());
		while (getline(cin,tempInput)){
			wfile <<tempInput<< " ";
		}
		string tempOutput;
		wfile.close();
		
		//read words from the input.txt file and build the tree	
		ifstream rfile;
		rfile.open(filename.c_str());
		while(rfile >> tempOutput){
		  root=buildTree(root,tempOutput,tempOutput[0]);
		}
		rfile.close();
		
		//out up the file with the correct name then removing the temp input file
		//output file using the different traversal functions
		filename="out";
		printInorder(root,filename);
		printPreorder(root,filename);	
		printPostorder(root,filename);	
		remove("input.txt");
		return 0;
	 
	 // if there is a argument passed when executing
	}else if(argc == 2){
		string ogfn = argv[1];
		string filename =ogfn + ".input1";
		ifstream rfile;
		rfile.open(filename.c_str());
		
		// checking to see if the file is not empty and does exist
		if(rfile && !(rfile.peek() == std::ifstream::traits_type::eof())){
			string tempOutput;
			while(rfile>>tempOutput){
				root=buildTree(root,tempOutput,tempOutput[0]);
			}
			printInorder(root,ogfn);
			printPreorder(root,ogfn);
			printPostorder(root,ogfn);
			rfile.close();
		}else if(!rfile){
                        cout<< "The file does not exist, please try again.\n";
                }
		else{
			cout<< "The file is empty, please try again.\n";
		}
		return 0;
	}else{
		cout <<"\nERROR! Too many arguments.\n";
		return 0;
	}
    }else{
	//if it has been redirected, copy the date from redirected file to a temp file 
        string input;
	ofstream write;
	write.open("input.txt");
	while(getline(cin,input)){
		write << input<<"\n";
	}
	write.close();
	ifstream read;
        read.open("input.txt");
	string tempOutput;

	//build the tree using the data within the temp file.
	//Then traverse it using the traversal functions.
        while(read>>tempOutput){
		root=buildTree(root,tempOutput,tempOutput[0]);
        }
	read.close();
	remove("input.txt");
                string filename="out";
                printInorder(root,filename);
                printPreorder(root,filename);
                printPostorder(root,filename);
                return 0;	

    }     

} 
