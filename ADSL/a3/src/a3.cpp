//============================================================================
// Name        : a3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct node
{
	int data;
	node *left,*right;
	int lflag,rflag;
};
class tbt
{
public:
	node *root,*temp;
	tbt()
	{
		root=NULL;
		temp=NULL;
	}
	node *createnode()
	{
		node *newnode=new node;
		cout<<"\nEnter the data:";
		cin>>newnode->data;
		newnode->left=NULL;
		newnode->right=NULL;
		return newnode;
	}
	void insert()
	{
		node *nn=createnode();
		int f=0;
		temp=root;
		if(root==NULL)
		{
			root=nn;
			nn->left=nn->right=NULL;
			nn->lflag=nn->rflag=1;
		}
		else
		{
			while(f==0)
			{
				if(nn->data<temp->data)
				{
					if(temp->lflag==0)
					{
						temp=temp->left;
					}
					else
					{
						nn->left=temp->left;
						nn->lflag=1;
						nn->right=temp;
						nn->rflag=1;
						temp->left=nn;
						temp->lflag=0;
						f=1;
					}
				}
				else if(nn->data>temp->data)
				{
					if(temp->rflag==0)
					{
						temp=temp->right;
					}
					else
					{
						nn->right=temp->right;
						nn->rflag=1;
						nn->left=temp;
						nn->lflag=1;
						temp->right=nn;
						temp->rflag=0;
						f=1;
					}
				}
				else
				{
					cout<<"\nData already exists!!!";
				}
			}
		}
	}

	node* inorderprede(node *n)
	{
		node *t;
		if(n->lflag==1)
			return n->left;
		else
		{
			t=n->left;
			while(t->rflag==0)
			{
				t=t->right;
			}
			return t;
		}
	}
	node* inordersucc(node  *n)
	{
		node *t;
		if(n->rflag==1)
			return n->right;
		else
		{
			t=n->right;
			while(t->lflag==0)
			{
				t=t->left;
			}
			return t;
		}
	}

	void inorder(node *ptr)
	{
		node *temp=ptr;
		cout<<"\n";
		while(temp->lflag==0)
		{
			temp=temp->left;
		}
		while(temp!=NULL)
		{
			cout<<""<<temp->data<<"->";
			temp=inordersucc(temp);
		}
	}

	node* preordersucc(node  *n)
	{
		if(n->lflag==0)
			return n->left;
		if(n->rflag==0)
			return n->right;
		while(n->rflag==1)
			n=n->right;
		return n->right;
	}

	void preorder(node *ptr)
	{
		node *temp=ptr;
		cout<<"\n";
		while(temp!=NULL)
		{
			cout<<""<<temp->data<<"->";
			temp=preordersucc(temp);
		}
	}

	node *search(int key)
	{
		node *parent;
		int flag=0;
		temp=root;
		parent=root;
		while(temp && flag==0)
		{
			if(temp->data==key)
			{
				flag=1;
			}
			else if(temp->data>key)
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
			return parent;
		else
			return parent;
	}


	void delete_node()
	{
		node *temp1,*child,*pre,*suc;
		int key;
		cout<<"\nEnter the keyword you want to delete:";
		cin>>key;
		node *p;
		if(root->data==key)
		{
			temp1=root;
		}
		else
		{
			p=search(key);
			if(p->left)
			{
				if(p->left->data==key)
					temp1=p->left;
			}
			if(p->right)
			{
				if(p->right->data==key)
					temp1=p->right;
			}

			if(temp1)
			{
				if(temp1->lflag==1 && temp1->rflag==1)
				{
					if(p->right==temp1)
					{
						p->rflag=1;
						p->right=temp1->right;
					}
					if(p->left==temp1)
					{
						p->lflag=1;
						p->left=temp1->left;
					}
				}
			}

			pre=inorderprede(temp1);
			suc=inordersucc(temp1);
			if(temp1->lflag==1 && temp1->rflag==0)
			{
				child=temp1->right;
				if(p->right==temp1)
					p->right=child;
				else
					p->left=child;
				suc->left=pre;
			}
			if(temp1->lflag==0 && temp1->rflag==1)
			{
				child=temp1->left;
				if(p->right==temp1)
					p->right=child;
				else
					p->left=child;
				pre->right=suc;
			}

			cout<<"\nNode deleted:"<<temp1->data;

			if(temp1->lflag==0 && temp1->rflag==0)
			{
				suc=inordersucc(temp1);
				node *parentsucc=search(suc->data);

				temp1->data=suc->data;
				if(suc)
				{
					if(suc->lflag==1 && suc->rflag==1)
					{
						if(parentsucc->right==suc)
						{
							parentsucc->rflag=1;
							parentsucc->right=suc->right;
						}
						else
						{
							parentsucc->lflag=1;
							parentsucc->left=suc->left;
						}
					}
				}

				node *preee=inorderprede(suc);
				node *succc=inordersucc(suc);
				if(suc->lflag==1 && suc->rflag==0)
				{
					child=suc->right;
					if(parentsucc->right==suc)
						parentsucc->right=child;
					else
						parentsucc->left=child;
					succc->left=preee;
				}
				if(suc->lflag==1 && suc->rflag==0)
				{
					child=suc->left;
					if(parentsucc->right==suc)
						parentsucc->right=child;
					else
						parentsucc->left=child;
					preee->left=succc;
				}

			}

		}
	}

	void preordernew()
	{
	    int flag=0;
		node *s=root;
		cout<<"\n"<<s->data;

		while(s!=NULL)
		{
			while(s->lflag==0 && flag==0)
			{
				s=s->left;
				cout<<"\n"<<s->data;
			}
			if(s->rflag)
			{
				s=s->right;
				flag=1;
			}
			else
			{
				s=s->right;
				cout<<"\n"<<s->data;
				flag=0;
			}
		}

	}
};

int main()
{
	tbt t;
	int no;
	cout<<"\nEnter the number of nodes you want to insert:";
	cin>>no;
	for(int i=0;i<no;i++)
	{
		t.insert();
	}
	cout<<"\nInorder=";
	t.inorder(t.root);
	cout<<"\nPreorder=";
	t.preordernew();
/*	cout<<"\nPreorder=";
	t.preorder(t.root);

	t.delete_node();
	cout<<"\nInorder=";
	t.inorder(t.root);
	t.delete_node();
	cout<<"\nInorder=";
	t.inorder(t.root);
	t.delete_node();
	cout<<"\nInorder=";
	t.inorder(t.root);
*/
	return 0;
}
