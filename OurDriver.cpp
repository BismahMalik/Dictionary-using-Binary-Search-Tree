
// DRIVER FILE//
/* ~~FINAL TERM PROJECT~~
GROUP MEMBERS: 211342-Anoosha Asif ,211354-Bismah Malik, 211364 -Amnah Saeed 
TOPIC: DICTIONARY APP
SUBMITTED TO : Sir Adnan Aslam*/

#include "OurDictionary.h"
#include "OurDictionary.cpp"

#include<iostream>
#include<string.h>
using namespace std;

int main ()
{   char word[100];
 	char meaning[200];
 	char syno[200];
 	char anty[200];
 	
 	Node* root = NULL;
	char choice ;
	cout << "____________________|| D I C T I O N A R Y ||____________________"<<endl;
	    cout << " ~ENTER 'S' TO START THE DICTIONARY~"<<endl;
	    cin>>choice;
	do{ 
	    
		int opt;
		cout << "----------------------  || M E N U ||  -------------------------\nPress 1 to insert word to the dictionary:\nPress 2 to search word from dictionary:\nPress 3 to delete a word from dictonary\nPress 4 to display entered word list\nPress 5 to exit \n";
		cin>>opt;
		switch(opt){
			case 1:
				 cout <<" Enter word: ";
			 	 cin>> word;
				 cout <<" Enter meaning: ";
				 cin>>meaning;
				 cout <<" Enter Synonym: ";
				 cin>>syno;
				 cout <<" Enter Antynoym: ";
				 cin>>anty;
				 root = insert(root, word,meaning,syno,anty );
				 cout<<"\n_____________________________________________________________"<<endl;
			  break;
			case 2 :
				 cout << "Enter word that you want to search: ";
				 cin>>word;
				 search(root,word);
				 cout<<"\n_____________________________________________________________"<<endl;
			  break;
			case 3 :
				 cout <<"Enter word that you want to delete: ";
				 cin >>word,
				 root=Delete (root,word);
				 cout <<"~~WORD HAS BEEN DELETED ~~"<<endl;
				 cout<<"\n_____________________________________________________________"<<endl;
			  break;
			case 4 :
				 cout << "______________::::DISPLAYING WORD LIST::::______________"<<endl;
				 if(root==NULL)
				 cout<<"=.=.=. WORD LIST IS EMPTY .=.=.=\n";
				 inorder(root);
				 cout<<"\n_____________________________________________________________"<<endl;
			  break;
			case 5 :
				cout <<"----------***** EXITING LOOP ******----------";
				return 0;
		}
	}
	while (choice=='s'||'S');
};
