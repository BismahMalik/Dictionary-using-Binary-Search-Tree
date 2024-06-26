
//IMPLEMENTATION FILE//
/* ~~FINAL TERM PROJECT~~
GROUP MEMBERS: 211342-Anoosha Asif ,211354-Bismah Malik, 211364 -Amnah Saeed 
TOPIC: DICTIONARY APP
SUBMITTED TO : Sir Adnan Aslam*/

#include<iostream>
#include<string.h>

#include "OurDictionary.h"

using namespace std;

//defining class node 
Node::Node()   
       {
         
	         left = NULL;
		     right = NULL;
	     }
    
    //Global Variable
    Node* root = NULL;
    
       //creating node to enter words in dictionary in the form of binary search tree 
	Node* Create(char* word, char* meaning, char* syno, char* anty)
    	{
   		 Node* newnode = new Node();
		 strcpy(newnode->word,word);
		 strcpy(newnode->meaning,meaning);
		 strcpy(newnode->syno,syno);
		 strcpy(newnode->anty,anty);
		 newnode->left = NULL;
		 newnode->right = NULL;
		 return newnode;
	    }
	    //function to insert words in the dictionary 
	Node* insert(Node* root, char* word, char* meaning, char* syno, char* anty)
    	{
	     if (!root)
		    {
			  root = Create(word, meaning,syno,anty);
		 	  return root;
		    }

		 Node* current = NULL;
		 Node* temp = NULL;
		 Node* n = NULL;
		 int i = 0;
		 for (current = root; current != NULL; current = (i > 0) ? current->right : current->left)
		      {
			     i = strcasecmp(word, current->word);
			     if (i == 0) 
				     {
				     cout << "  Word already exists. Enter new word... ";
			 	    return NULL;
		  	         }
			 temp = current;
              }
         n = Create(word, meaning,syno,anty);
         i > 0 ? (temp->right = n) : (temp->left = n);
         return root;
        }
        
        //function to search word from list entered in BST
	Node* search(Node* root,char* word)
		{
			//Data Not Found(DNF)
			int DNF=0;
			int i=0;
			if(root==NULL)
			{
				cout<<"=.=.=. WORD LIST IS EMPTY .=.=.=";
				return NULL;
			}
			
        while (root) {
                if ((i = strcasecmp(root->word, word)) == 0) 
				{
                     cout<<"Word: "<<root->word<<endl;
                     cout<<"Meaning: "<<root->meaning<<endl;
                     cout<<"Synonym: "<<root->syno<<endl;
                     cout<<"Antynoym: "<<root->anty<<endl;
                     DNF = 1;
                     break;
                }
                 root = (i > 0) ? root->left : root->right;
            }
        if (DNF==0)
             //displaying message when element doesnot exist in binary search tree 
             cout<<"\nSearched word not found in dictionary \n";
             return root;
             
		}

        //finding minimum value in order to add and arrange in binary search tree 
	Node* FindMin(Node* current)  
         {  
           while(current->left != NULL) 
		   {  
           current = current->left;  
           }  
           return current;  
         } 
	//Funtion to delete entered word 

	Node* Delete( Node* root, char* word)
	{
		Node *current=root;
		 
		int i=strcasecmp(root->word,word);
       if (root ==NULL)
       return root;
       //Move to left of tree
       else if( i < 0)
       root->left = Delete (root->left, word);
       //Move to right of tree
       else if( i > 0)
       root->right = Delete (root->right, word);
       
       else
       {
       	 //node has No childs
       	 if (root->left == NULL && root->right == NULL)
       	 {
       	    delete root;
       	    root = NULL;
       	    return root;
				
		 }
		 
		 //Node has One child
		 else if( root->left == NULL)
		 {
		 	Node *temp= root;
		 	root= root->right;
		 	delete temp;
		 }
		 
		 else if(root->right == NULL)
		 {
		 	Node *temp= root;
		 	root= root->left;
		 	delete temp;
		 }
		 //Node has two childs
		 else 
		 {
		 	Node *temp = FindMin(root->right);
		 	strcpy(root->word,temp->word);
		 	strcpy(root->meaning,temp->meaning);
		 	strcpy(root->syno,temp->syno);
		 	strcpy(root->anty,temp->anty);
		 	root->right= Delete(root->right, temp->word);
		 	
		 }
       	
	   }
	   return root;
	  
	}
	
    void inorder(Node* root)
	{
        
         if (root != NULL) 
		    {
             inorder(root->left);
             cout<<endl << "\n Word: "<<root->word <<"\n Meaning: "<< root->meaning<<"\n Synonym "<<root->syno<<"\n Antonoym "<< root->anty<<endl;
             inorder(root->right);
             
           }
          
        }
	

