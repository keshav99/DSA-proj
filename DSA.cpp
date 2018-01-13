#include <stdio.h>
#include<iostream>
#include <string>
#include <stdlib.h>
#include <stdbool.h>
#include <fstream>
#include<cstring>
#include <ctime>
#include <shlobj.h>
#include <shlwapi.h>
#include<vector>
#include <objbase.h>
using namespace std;
struct node {
  const char* data;
   const char* key;

   struct node *next;
};

void startUser(string user);
void getUser();
void newUser();

string users[200][2];
int n;

struct list {
   const char* title;
   const char* desc;
   const char* date;

   struct list *next;
};

struct node *head = NULL;
struct node *current = NULL;
struct list *head1 = NULL;
struct list *current1 = NULL;
string user, pwd;
string future[200][3];
string past[200][3];
int countra=-1, countsa=-1;

void insertFirst(const char* key, const char* data) {

   //create a link
   struct node *link = (struct node*) malloc(sizeof(struct node));
   link->key = key;
   link->data = data;

   if (head==NULL) {
      head = link;
      head->next = head;
   } else {
      //point it to old first node
      link->next = head;

      //point first to new first node
      head = link;
   }
}

void insertF(const char* title, const char* desc, const char* date) {

   //create a link
   struct list *link = (struct list*) malloc(sizeof(struct list));
   link->title = title;
   link->desc = desc;
   link->date = date;

   if (head1==NULL) {
      head1 = link;
      head1->next = NULL;
   } /*else {
      //point it to old first node
      link->next = head1;

      //point first to new first node
      head1 = link;
      list *temp=head1;
      list *prev=head1;
      string temp1=head1->date;
      string cure=date;
      if(head1->next==NULL){
      	if(atoi((temp1).substr(0,2).c_str())>atoi(cure.substr(0,2).c_str())){
      		temp=head1;
      		head1=link;
      		head1->next=temp;

		  }
		else{
			head1->next=link;
			link->next=NULL;
		}
	  }
	  else if(atoi(temp1.substr(0,2).c_str())>atoi(cure.substr(0,2).c_str())){
	  	link->next=head1;
	  	head1=link;
	  }
	  else{
	  	while(atoi(temp1.substr(0,2).c_str())<atoi(cure.substr(0,2).c_str())&&temp){
	  		prev=temp;
	  		temp=temp->next;
	  		temp1=temp->date;
		  }
		link->next=temp;
		prev->next=link;
	  }
   }*/

}

void printLines(){

}
void manageConf(){
	
}

struct tree
{
	const char* name;
	const char* task;
	struct tree* left;
	struct tree* right;
};
/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
struct tree* newNode(const char* name, const char* task)
{
	struct tree* nde = (struct tree*)malloc(sizeof(struct tree));
	nde->name = name;
	nde->task= task;
	nde->left = NULL;
	nde->right = NULL;

	return(nde);
}

/* Given a binary tree, print its nodes according to the
"bottom-up" postorder traversal. */
void printPostorder(struct tree* noe)
{
	if (noe == NULL)
		return;

	// first recur on left subtree
	printPostorder(noe->left);

	// then recur on right subtree
	printPostorder(noe->right);

	// now deal with the node
	printf("%s has %s\n", noe->name, noe->task);
}

/* Given a binary tree, print its nodes in inorder*/
void printInorder(struct tree* nde)
{
	if (nde == NULL)
		return;

	/* first recur on left child */
	printInorder(nde->left);

	/* then print the data of node */
	printf("%s has %s\n", nde->name, nde->task); 

	/* now recur on right child */
	printInorder(nde->right);
}

/* Given a binary tree, print its nodes in preorder*/
void printPreorder(struct tree* nde)
{
	if (nde == NULL)
		return;

	/* first print data of node */
	printf("%s has %s\n", nde->name, nde->task); 

	/* then recur on left sutree */
	printPreorder(nde->left); 

	/* now recur on right subtree */
	printPreorder(nde->right);
} 

 

void Conf(){
	std::ifstream ifs ("confs.txt");
ifs.close ();

std::ofstream myile ("confs.txt", std::ios::out | std::ios::trunc); // clear contents


			cout<<"\nEnter number of users for this conference(max 7)\n";
			
			cin>>n;
			cout<<"\n Enter the name of each user to create the conference followed by task. \nTIP: Add the users who have higher priority first. The next two users will be under the first one. \n";
			
			string temp2, temp3, line;
			string temp, temp1;
			for(int i=0; i<n; i++){
				cin>>temp;
				cin>>temp1;
				
				ifstream myfie ("names.txt");
				bool check=false;
				while(getline(myfie, line)){
					if(line.substr(0, line.length()-1)==temp.substr(0, temp.length())||line.substr(0, line.length())==temp.substr(0, temp.length()))
					check=true;
					
				}
				if(!check)
				cout<<"\nUnable to find user\n";
				else{

					users[i][0]=temp.c_str();
					users[i][1]=temp1.c_str();
					myile<<"\n"<<temp<<" "<<temp1;
				}
			}
			string title, desc, date;
			cout<<"\nEnter title: ";
			cin>>title;
			myile<<"\n"<<title;
			cout<<"\nEnter description: ";
			cin>>desc;
			myile<<"\n"<<desc;
			cout<<"\nEnter last date: ";
			cin>>date;
			myile<<"\n"<<date<<"\n";
			cout<<"\nConference "<<title<<" successfully created.";
			
	
	struct tree *root = newNode(users[0][0].c_str(), users[0][1].c_str());
	root->left	= newNode(users[1][0].c_str(), users[1][1].c_str());
	root->right	 = newNode(users[2][0].c_str(), users[2][1].c_str());
	root->left->left	 = newNode(users[3][0].c_str(), users[3][1].c_str());
	root->left->right = newNode(users[4][0].c_str(), users[4][1].c_str()); 
	root->right->left= newNode(users[5][0].c_str(), users[5][1].c_str());
	root->right->right=newNode(users[6][0].c_str(), users[6][1].c_str());
	
	cout<<"\n Type 0 if you want to see the coordinators first(post order traversal) 1 to see organizers first(inorder traversal)";
	int np;
	
	if(np==0){
	printf("\nPostorder traversal of binary tree is \n");
	printPostorder(root);
	}
	else if(np==1){
	printf("\nInorder traversal of binary tree is \n");
	printInorder(root); 
	}
	startUser(user);
//	printf("\nPostorder traversal of binary tree is \n");
//	printPostorder(root);
	/*	nod->left->left->name=users[3][0];
		nod->left->left->task=users[3][1];
		nod->left->right->name=users[4][0];
		nod->left->right->task=users[4][1];
		nod->right->left->name=users[5][0];
		nod->right->left->task=users[5][1];
		nod->right->right->name=users[6][0];
		nod->right->right->task=users[6][1];*/
		//printLevelOrder(nod);
			
}

void startUser(string user){
    int kind;
		cout<<"\nEnter 0 to add item to your list, 1 to display archived events, \n2 to add a conference event, 3 to manage conferences\n 4 to logout";
		cin>>kind;
		if(kind==0){
			string title, desc, date;
			cout<<"\nEnter title of list: \n";
			cin>>title;
			cout<<"\nEnter description: \n";
			cin>>desc;
			cout<<"\nEnter last date due\n";
			cin>>date;
			insertF(title.c_str(), desc.c_str(), date.c_str());
			std::ofstream outfile;
			string fname="";
			fname= user+".txt";
			outfile.open(fname.c_str(), std::ios::app);
			std::ifstream myfile(fname.c_str());
			std::fstream file(fname.c_str()) ;
			int i=0;
			string line;
			while(getline(myfile, line)){
				i++;
				
						outfile << "\n"<<title<<"\n"<<desc<<"\n"<<date;

						break;
					
			}

  			outfile.close();
			cout<<"\nTitle: "<<title<<"\nDescription: "<<desc<<"\ndate: "<<date;
			printLines();

			startUser(user);
		}
		else if(kind==1){
			for(int i=0; i<=countsa; i++){
        		cout<<"\nTitle: "<<past[i][0]<<"\nDescription: "<<past[i][1]<<"\nDate: "<<past[i][2]<<"\n";
	  		}
	  		cout<<"\nTo add an archived note to any of the archived list items type first name of note/conference\nelse type 1 to return to main menu\n";
	  		string naam;
	  		cin>>naam;
	  		if(naam=="1"){
	  			startUser(user);
			  }
			else{
				ofstream myile;
				naam.append(".txt");
				myile.open (naam.c_str());
	  			ShellExecute(0, 0, naam.c_str(), 0, 0 , SW_SHOW);
	  			myile.close();
	  			startUser(user);
			}
		}
		else if(kind==2){
			Conf();
		}
		else if(kind==4){
			cout<<"\nEnter 0 to login, 1 to sign up, 2 to exit\n";
			cin>>kind;
			if(kind==0){
				getUser();
			}
			else if(kind==1){
			newUser();
			}
		}
		else{
			cout<<"\nPlease type 0, 1 , 2 or 3\n";
			startUser(user);
		}
}

void printL(const char* user){
    std::string fname(user);
		fname.append(".txt");
		std::ifstream myfile(fname.c_str());
		int i=0;
		cout<<"\n"<<"-----------------------"<<"\n"<<"YOUR LIST FOR TODAY"<<"\n"<<"-----------------------"<<"\n";
	string line, title, desc, date;
	
	
    while ( getline (myfile,line) )
    {

      i++;
      if(i%3==1||i==1){
		title=line;
	  }
      else if(i%3==2){
      	desc=line;
	  }
      else if(i%3==0){
      	date=line;
      	insertF(title.c_str(), desc.c_str(), date.c_str());
      	time_t t = time(0);   // get time now
        struct tm * now = localtime( & t );
        if(atoi(date.substr(0,2).c_str())==now->tm_mday){
            cout<<"\nTitle: "<<title<<"\nDescription: "<<desc<<"\nLast date: Today"<<"\n";
        }
        else  if(atoi(date.substr(0,2).c_str())>now->tm_mday){
            countra++;
            future[countra][0]=title;
            future[countra][1]=desc;
            future[countra][2]=date;

        }
        else{
            countsa++;
            past[countsa][0]=title;
            past[countsa][1]=desc;
            past[countsa][2]=date;

        }
      	title="";
      	desc="";
      	date="";
	  }


	  }
	  string temp[3];
	  for(i=1;i<=countra;++i)
    	{
        for(int j=0;j<(countra);++j)
            if(atoi(future[j][2].substr(0,2).c_str())>atoi(future[j+1][2].substr(0,2).c_str()))
            {
                temp[0]=future[j][0];
                temp[1]=future[j][1];
                temp[2]=future[j][2];
                future[j][0]=future[j+1][0];
                future[j][1]=future[j+1][1];
                future[j][2]=future[j+1][2];
                future[j+1][0]=temp[0];
                future[j+1][1]=temp[1];
                future[j+1][2]=temp[2];
            }
    	}
    	for(i=1;i<=countsa;++i)
    	{
        for(int j=0;j<(countsa);++j)
            if(atoi(past[j][2].substr(0,2).c_str())>atoi(past[j+1][2].substr(0,2).c_str()))
            {
                temp[0]=past[j][0];
                temp[1]=past[j][1];
                temp[2]=past[j][2];
                past[j][0]=past[j+1][0];
                past[j][1]=past[j+1][1];
                past[j][2]=past[j+1][2];
                past[j+1][0]=temp[0];
                past[j+1][1]=temp[1];
                past[j+1][2]=temp[2];
            }
    	}
	  cout<<"\n"<<"-----------------------"<<"\n"<<"UPCOMING LISTS"<<"\n"<<"-----------------------"<<"\n";
	  for(int i=0; i<=countra; i++){
        cout<<"\nTitle: "<<future[i][0]<<"\nDescription: "<<future[i][1]<<"\nDate: "<<future[i][2]<<"\n";
	  }
	  cout<<"\n";
	  
	  
	  startUser(user);
}

void newUser(){
    string newusr, newpwd;
	cout<<"\nEnter new username: ";
	cin>>newusr;
	cout<<"\nEnter new pwd: ";
	cin>>newpwd;
	insertFirst(newusr.c_str(), newpwd.c_str());
	std::ofstream outfile;

  			outfile.open("names.txt", std::ios::app);
  			outfile << "\n"<<newusr<<"\n"<<newpwd;
  			outfile.close();
  	user=newusr;
  	pwd=newpwd;
  	startUser(user);
}

void getUser(){
	string user, pwd, inpuser, inppwd;
    cout<<"\nEnter username: ";
	cin>>inpuser;
	cout<<"\nEnter pwd: ";
	cin>>inppwd;
	ifstream myfile ("names.txt");
string title, desc, date;
string line;
bool found=false;
  if (myfile.is_open())
  {
  	int i=0;
    while ( getline (myfile,line) )
    {

      i++;
      if(i%2!=0){
      	user=line;
      	user=user.substr(0, user.length()-1);
	  }
      else{
      	pwd=line;
      	insertFirst(user.c_str(), pwd.c_str());
      	if(user==inpuser&&inppwd==pwd){
      		found=true;
      		break;
		  }
	  }

	  }
	myfile.close();
	if(found){
		printL(user.c_str());
		startUser(user);
	}
	else{
		cout<<"User not found"<<endl;
	}
}



  else cout << "Unable to open file";
}

main(){
    string inpuser, inppwd, user, pwd;
int kind;
cout<<"----------------------------\n";
cout<<"Welcome to your to-do list\n";
cout<<"----------------------------\n";
cout<<"\nEnter 0 to login, 1 to sign up, 2 to exit\n";
cin>>kind;
if(kind==0){
	getUser();
}
else if(kind==1){
	newUser();
}
}

