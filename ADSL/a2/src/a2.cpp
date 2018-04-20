//============================================================================
// Name        : a2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;

struct node
{
	char word[20],meaning[20];
	node *left,*right;
};

class BST
{
public:
	node *temp,*root;
	BST()
	{
		root=NULL;
		temp=NULL;
	}
	node *createnode()
	{
		node *newnode =new node;
		cout<<"\nEnter keyword\n";
		cin>>newnode->word;
		cout<<"\nEnter meaning\n";
		cin>>newnode->meaning;
		newnode->left=newnode->right=NULL;
		return newnode;
	}
	void construct()
	{
		temp=root;
		if(root==NULL)
		{
			temp=createnode();
			root=temp;
			temp=root;
			cout<<"\nNode Inserted\n";
			return;
		}
		else
		{
			int flag=0;
			node *child=createnode();
			while(temp!=NULL  && flag==0 )
			{
				if(strcmp(child->word,temp->word)<0)
				{
					if(temp->left==NULL)
					{
						temp->left=child;
						flag=1;
						cout<<"\nNode Inserted\n";
					}
					else
					{
						temp=temp->left;
					}
				}
				else if(strcmp(child->word,temp->word)>0)
				{
					if(temp->right==NULL)
					{
						temp->right=child;
						flag=1;
						cout<<"\nNode Inserted\n";
					}
					else
					{
						temp=temp->right;
					}
				}
				else
				{
					cout<<"\nKeyword already exists\n";
					return;
				}
			}
		}
	}


	void update()
	{
		temp=root;
		int flag=0;
		char key[20];
		cout<<"\nEnter key to be update\n";
		cin>>key;
		while(temp && flag==0)
		{
			if(strcmp(key,temp->word)==0)
			{
				flag=1;
			}
			else if(strcmp(key,temp->word)<0)
			{
				temp=temp->left;
			}
			else
			{
				temp=temp->right;
			}
		}
		if(flag==1)
		{
			cout<<"\nEnter meaning of "<<key<<endl;
			cin>>temp->meaning;
		}
		else
		{
			cout<<"\nThe keyword doesn't exist!!!";
		}
	}

	void comparisons()
	{
		temp=root;
		int flag=0,count=0;
		char key[20];
		cout<<"\nEnter key to be update\n";
		cin>>key;
		while(temp && flag==0)
		{
			count++;
			if(strcmp(key,temp->word)==0)
			{
				flag=1;
			}
			else if(strcmp(key,temp->word)<0)
			{
				temp=temp->left;
			}
			else
			{
				temp=temp->right;
			}
		}
		if(flag==1)
		{
			cout<<"\nKeyword found\n";
			cout<<endl<<temp->word<<" = "<<temp->meaning;
			cout<<"\nComparisons required="<<count;
		}
		else
		{
			cout<<"\nThe keyword doesn't exist!!!";
		}
	}

	node* search(char key[20])
	{
		node *parent=root;
		temp=root;
		int flag=0,count=0;
		while(temp && flag==0)
		{
			count++;
			if(strcmp(key,temp->word)==0)
			{
				flag=1;
			}
			else if(strcmp(key,temp->word)<0)
			{
				parent=temp;
				temp=temp->left;
			}
			else
			{
				parent=temp;
				temp=temp->right;
			}
		}
		if(flag==1)
		{
			return parent;
		}
		else
		{
			cout<<"\nThe keyword doesn't exist!!!";
			return NULL;
		}

	}
	void inorder_asc(node *n)
	{
		if(n)
		{
			inorder_asc(n->left);
			cout<<n->word<<" : "<<n->meaning<<"\n";
			inorder_asc(n->right);
		}
	}

	void inorder_desc(node *n)
	{
		if(n)
		{
			inorder_desc(n->right);
			cout<<n->word<<" : "<<n->meaning<<"\n";
			inorder_desc(n->left);
		}
	}

	node* operator=(node *n)
	{
		node *newnode=new node;
		if(!n)
			return NULL;
		else
		{
			newnode->left=(n->left);
			newnode->right=(n->right);
			strcpy(newnode->word,n->word);
			strcpy(newnode->meaning,n->meaning);
			return newnode;
		}
	}

	void delete_node()
	{
		node *temp1;
		char key[20];
		cout<<"\nEnter key to be delete\n";
		cin>>key;
		if(strcmp(root->word,key)==0)
		{
			temp1=root;
		}
		else
		{
			node *p=search(key);
			if(p->left)
			{
				if(strcmp(p->left->word,key)==0)
				{
					temp1=p->left;
				}
			}
			if(p->right)
			{
				if(strcmp(p->right->word,key)==0)
				{
					temp1=p->right;
				}
			}

			if(temp1)
			{
				if(temp1->left==NULL && temp1->right==NULL)
				{
					if(p->right==temp1)
						p->right=NULL;
					else
						p->left=NULL;
				}
			}

			if(temp1->left==NULL && temp1->right!=NULL)
			{
				if(p->right==temp1)
					p->right=temp1->right;
				else
					p->left=temp1->right;
			}
			if(temp1->left!=NULL && temp1->right==NULL)
			{
				if(p->right==temp1)
					p->right=temp1->left;
				else
					p->left=temp1->left;
			}
		}
		cout<<"\nNode deleted:"<<temp1->word;

		if(temp1->left!=NULL && temp1->right!=NULL)
		{
			node *t =temp1->left;
			while(t->right!=NULL)
			{
				t=t->right;
			}
			node *pa=search(t->word);

			strcpy(temp1->word,t->word);
			strcpy(temp1->meaning,t->meaning);

			if(t)
			{
				if(t->left==NULL && t->right==NULL)
				{
					if(pa->right==t)
						pa->right=NULL;
					else
						pa->left=NULL;
				}
			}

			if(t->left==NULL && t->right!=NULL)
			{
				if(pa->right==t)
					pa->right=t->right;
				else
					pa->left=t->right;
			}
			if(t->left!=NULL && t->right==NULL)
			{
				if(pa->right==t)
					pa->right=t->left;
				else
					pa->left=t->left;
			}

			delete(t);
		}
	}

};

int main()
{
	int no,ch;
	BST b,ct;
	cout<<"\nEnter the number of nodes you want to insert:";
	cin>>no;
	for(int i=0;i<no;i++)
	{
		b.construct();
	}
	do
	{
		cout<<"\n1.Insert new node \n2.Display Ascending Order \n3.Display Descending order \n4.Search Element \n5.Delete Element \n6.Copy the dictionary \n7.Update meaning of key \n8.Exit";
		cout<<"\nEnter your choice:";
		cin>>ch;
		switch(ch)
		{
		case 1:
			b.construct();
			break;

		case 2:
			b.inorder_asc(b.root);
			break;

		case 3:
			b.inorder_desc(b.root);
			break;

		case 4:
			b.comparisons();
			break;

		case 5:
			b.delete_node();
			break;

		case 6:
			ct=b;
			cout<<"\nCopied dictionary:\n";
			ct.inorder_asc(ct.root);
			break;

		case 7:
			b.update();
			break;
		}
	}while(ch!=8);
	return 0;
}


//============================================================================
// Name        : a2a.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*
#include <iostream>
#include <strings.h>
#include <cstring>
using namespace std;

struct node
{
	char key[20],mean[20];
	node *left,*right;
};
class BST
{
public:
	node *root,*temp;
	BST()
	{
		root=NULL;
		temp=NULL;
	}
	node *createnode()
	{
		node *newnode=new node;
		cout<<"\nEnter key\n";
		cin>>newnode->key;
		cout<<"\nEnter mean\n";
		cin>>newnode->mean;
		newnode->left=newnode->right=NULL;
		return newnode;
	}
	void construct()
	{
		temp=root;
		if(root==NULL)
		{
			temp=createnode();
			root=temp;
			temp=root;
			cout<<"\nNode Inserted\n";
			return;
		}
		else
		{
			int flag=0;
			temp=root;
			node *child=createnode();
			while(temp && flag==0)
			{
				if(strcmp(child->key,temp->key)<0)
				{
					if(temp->left==NULL)
					{
						temp->left=child;
						flag=1;
						cout<<"\nNode Inserted\n";
					}
					else
					{
						temp=temp->left;
					}
				}
				else if(strcmp(child->key,temp->key)>0)
				{
					if(temp->right==NULL)
					{
						temp->right=child;
						flag=1;
						cout<<"\nNode Inserted\n";
					}
					else
					{
						temp=temp->right;
					}
				}
				else
				{
					cout<<"\nKeyword already exist\n";
					return;
				}

			}
		}
	}

	void update()
	{
		char word[20];
		int flag=0;
		temp=root;
		cout<<"\nEnter keyword to upadate\n";
		cin>>word;

		while(temp && flag==0)
		{
			if(strcmp(word,temp->key)==0)
			{
				flag=1;
				break;
			}
			else if(strcmp(word,temp->key)<0)
			{
				temp=temp->left;
			}
			else
			{
				temp=temp->right;
			}
		}
		if(flag==1)
		{
			cout<<"\nEnter meaning\n";
			cin>>temp->mean;
			cout<<"\nNode updated\n";
			return;
		}
		else
		{
			cout<<"\nNot exists\n";
		}
	}

	node* search(char word[])
	{
		node *parent;
		int flag=0;
		temp=root;
		parent=root;

		while(temp && flag==0)
		{
			if(strcmp(word,temp->key)==0)
			{
				flag=1;
				break;
			}
			else if(strcmp(word,temp->key)<0)
			{
				parent=temp;
				temp=temp->left;
			}
			else
			{
				parent=temp;
				temp=temp->right;
			}
		}
		if(flag==1)
		{
			return parent;
		}
		else
		{
			cout<<"\nThe keyword doesn't exist!!!";
			return NULL;
		}
	}

	void inorder_asc(node *n)
	{
		if(n)
		{
			inorder_asc(n->left);
			cout<<n->key<<" : "<<n->mean<<"\n";
			inorder_asc(n->right);
		}
	}

	void delete_node()
	{
		node *temp1;
		char word[20];
		cout<<"\nEnter keyword to upadate\n";
		cin>>word;
		if(strcmp(root->key,word)==0)
		{
			temp1=root;
		}
		else
		{
			node *pa=search(word);
			if(pa->left)
			{
				if(strcmp(pa->left->key,word)==0)
				{
					temp1=pa->left;
				}
			}
			if(pa->right)
			{
				if(strcmp(pa->right->key,word)==0)
				{
					temp1=pa->right;
				}
			}
			if(temp1)
			{
				if(temp1->left==NULL && temp1->right ==NULL)
				{
					if(pa->right==temp1)
						pa->right=NULL;
					if(pa->left==temp1)
						pa->left=NULL;
				}
			}
				if(temp1->left==NULL && temp1->right !=NULL)
				{
					if(pa->right==temp1)
						pa->right=temp1->right;
					if(pa->left==temp1)
						pa->left=temp1->right;
				}

				if(temp1->left!=NULL && temp1->right ==NULL)
				{
					if(pa->right==temp1)
						pa->right=temp1->left;
					if(pa->left==temp1)
						pa->left=temp1->left;
				}
		}

		cout<<"\nNode deleted"<<temp1->key<<endl;
		if(temp1->left!=NULL && temp1->right!=NULL)
		{
			node *t =temp1->left;
			while(t->right!=NULL)
			{
				t=t->right;
			}
			node *pa=search(t->key);

			strcpy(temp1->key,t->key);
			strcpy(temp1->mean,t->mean);

			if(t)
			{
				if(t->left==NULL && t->right ==NULL)
				{
					if(pa->right==t)
						pa->right=NULL;
					if(pa->left==t)
						pa->left=NULL;
				}
			}
				if(t->left==NULL && t->right !=NULL)
				{
					if(pa->right==t)
						pa->right=t->right;
					if(pa->left==t)
						pa->left=t->right;
				}

				if(t->left!=NULL && t->right ==NULL)
				{
					if(pa->right==t)
						pa->right=t->left;
					if(pa->left==t)
						pa->left=t->left;
				}

				delete(t);
		}

	}

};
int main()
{
	int no,ch;
	BST b,ct;
	cout<<"\nEnter the number of nodes you want to insert:";
	cin>>no;
	for(int i=0;i<no;i++)
	{
		b.construct();
	}
	do
	{
		cout<<"\n1.Insert new node \n2.Display Ascending Order \n3.Display Descending order \n4.Search Element \n5.Delete Element \n6.Copy the dictionary \n7.Update meaning of key \n8.Exit";
		cout<<"\nEnter your choice:";
		cin>>ch;
		switch(ch)
		{
		case 1:
			b.construct();
			break;

		case 2:
			b.inorder_asc(b.root);
			break;

		case 3:
			break;

		case 4:
			break;

		case 5:
			b.delete_node();
			break;

		case 6:
			break;

		case 7:
			b.update();
			break;
		}
	}while(ch!=8);
	return 0;
}
*/
