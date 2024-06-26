
// HEADER FILE//
/* ~~FINAL TERM PROJECT~~
GROUP MEMBERS: 211342-Anoosha Asif ,211354-Bismah Malik, 211364 -Amnah Saeed 
TOPIC: DICTIONARY APP
SUBMITTED TO : Sir Adnan Aslam*/

#ifndef OURDICTIONARY_H_
#define OURDICTIONARY_H_

#include<iostream>
#include<string.h>

class Node
{
	public:

  	    char word[100];
 	    char meaning[200];
 	    char syno[200];
 	    char anty[200];
 	    Node* left;
 	    Node* right;
 	    
 	    //constructor
 	    Node();
 	    	    
};
#endif

//prototype of creating node function
Node* Create(char* , char* , char* , char* );

//protype of inserting node function
Node* insert(Node* , char* , char* , char* , char* );

//protype of searching the node function
Node* search(Node* ,char* );

//prototype for finding the minimum value
Node* FindMin(Node* );

//prototype for deleting the node function
Node* Delete( Node* , char* );

//prototype for inorder function
void inorder(Node* );


