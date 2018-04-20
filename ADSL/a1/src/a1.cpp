//============================================================================
// Name        : a1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <queue>
using namespace std;

typedef struct node
{
	int data;
	struct node *left,*right;
}node;

class Queue
{
	node *data[30];
	int rear,front;
public:
	Queue()
	{
		rear=front=-1;
	}
	void init()
	{
		rear=front=-1;
	}
	int isempty()
	{
		if(rear==-1)
			return 1;
		return 0;
	}
	void insert(node *ptr)
	{
		if(isempty())
		{
			rear=front=0;
		}
		else
		{
			rear=rear+1;
		}
		data[rear]=ptr;
	}

	node *deleteq()
	{
		node *temp=data[front];
		if(rear==front)
		{
			rear=front=-1;
		}
		else
		{
			front=front+1;
		}
		return temp;
	}
	int size()
	{
		int count=0;
		for(int i=front;i<=rear;i++)
		{
			count++;
		}
		return count;
	}
};

class stack
{
	int top;
	node *data[30];
public:
	stack()
	{
		top=-1;
	}
	int isempty()
	{
		if(top==-1)
			return 1;
		return 0;
	}
	void push(node *p)
	{
		data[++top]=p;
	}
	node* pop()
	{
		if(isempty())
			return NULL;
		return (data[top--]);
	}
};
class BinaryTree
{
public:
	node *root=NULL;
	node* create();
	void printPreorder(node*);
	void printPreorderNR(node*);
	void printPostorder(node*);
	void printPostorderNR(node*);
	node* mirrorimage(node *);
	node* mirrorimageNR(node *);
	int height(node *);
	int heightNR(node *);
	node* operator=(node*);
	int countLeaf(node *);
	int countLeafNR(node *);
	int countInternal(node*);
	int countInternalNR(node*);
	void eraseTree(node *);
	void eraseTreeNR(node *);
};

node* BinaryTree::create()
{
	int data;
	cout<<"\nEnter data (-1 for no data) \n";
	cin>>data;

	if(data==-1)
		return NULL;

	node *newnode=new node;
	newnode->data=data;

	cout<<"\nEnter Left Child of "<<data<<endl;
	newnode->left=create();

	cout<<"\nEnter Right Child of "<<data<<endl;
	newnode->right=create();

	return newnode;
}
void BinaryTree::printPreorder(node *node)
{
	if(node!=NULL)
	{
		cout<<node->data;
		printPreorder(node->left);
		printPreorder(node->right);
	}
}
void BinaryTree::printPostorder(node *node)
{
	if(node!=NULL)
	{
	printPostorder(node->left);
	printPostorder(node->right);
	cout<<node->data;
	}
}

void BinaryTree::printPreorderNR(node *ptr)
{
	stack s;
	while(ptr!=NULL)
	{
		s.push(ptr);
		cout<<" "<<ptr->data<<"->";
		ptr=ptr->left;
	}
	while(!s.isempty())
	{m
		ptr=s.pop();
		ptr=ptr->right;
		while(ptr!=NULL)
		{
			s.push(ptr);
			cout<<" "<<ptr->data<<"->";
			ptr=ptr->left;
		}
	}
}

void BinaryTree::printPostorderNR(node *ptr)
{
	stack s1,s2;
	s1.push(ptr);
	while(!s1.isempty())
	{
		ptr=s1.pop();
		s2.push(ptr);
		if(ptr->left)
			s1.push(ptr->left);
		if(ptr->right)
			s1.push(ptr->right);

	}
	while(!s2.isempty())
	{
		ptr=s2.pop();
		cout<<""<<ptr->data<<"->";
	}
}

node* BinaryTree::mirrorimage(node *ptr)
{
	node *temp;
	if(ptr!=NULL)
	{
		temp=ptr->left;
		ptr->left=mirrorimage(ptr->right);
		ptr->right=mirrorimage(temp);
	}
	return ptr;
}

node* BinaryTree::mirrorimageNR(node *ptr)
{
	node *temp;
	stack s;
	if(ptr==NULL)
		return NULL;
	if(ptr->left==NULL && ptr->right==NULL)
		return NULL;
	s.push(ptr);
	while(!s.isempty())
	{
		ptr=s.pop();
		cout<<ptr->data<<"->";

		temp=ptr->right;
		ptr->right=ptr->left;
		ptr->left=temp;

		if(ptr->right)
			s.push(ptr->right);
		if(ptr->left)
			s.push(ptr->left);
	}
  return ptr;
}
int BinaryTree::height(node *ptr)
{
	if(ptr==NULL)
		return 0;
	return max(height(ptr->left),height(ptr->right))+1;
}

int BinaryTree::heightNR(node *ptr)
{
	int h=0;
	queue <node*> q;
	node *temp;
	if(ptr==NULL)
		return 0;

	q.push(ptr);
	while(!q.empty())
	{
		int size=q.size();
		while(size--)
		{
			temp=q.front();
			q.pop();
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
		}
		h++;
	}
	return h;
}

node* BinaryTree::operator =(node *ptr)
{
	node *newnode=new node;
	if(ptr==NULL)
		return NULL;
	else
	{
		newnode->left=ptr->left;
		newnode->right=ptr->right;
		newnode->data=ptr->data;
		return newnode;
	}
}

int BinaryTree::countLeaf(node *ptr)
{
	if(ptr==NULL)
		return 0;
	if(ptr->left==NULL && ptr->right==NULL)
		return 1;
	return (countLeaf(ptr->left)+countLeaf(ptr->right));
}

int BinaryTree::countLeafNR(node *ptr)
{
	node *temp;
	if(ptr==NULL)
		return 0;
	Queue q;
	int count=0;
	q.insert(ptr);
	while(!q.isempty())
	{
		temp=q.deleteq();
		if(temp->left)
			q.insert(ptr->left);
		if(temp->right)
			q.insert(ptr->right);
		if(temp->left==NULL && temp->right==NULL)
			count++;
	}
	return count;
}

int BinaryTree::countInternal(node *ptr)
{
	if(ptr==NULL || (ptr->left==NULL && ptr->right==NULL))
		return 0;
	return 1+countInternal(ptr->left)+countInternal(ptr->right);
}
int BinaryTree::countInternalNR(node *ptr)
{

		node *temp;
		if(ptr==NULL)
			return 0;
		Queue q;
		int count=0;
		q.insert(ptr);
		while(!q.isempty())
		{
			temp=q.deleteq();
			if(temp->left)
				q.insert(ptr->left);
			if(temp->right)
				q.insert(ptr->right);
			if (temp->left && temp->right)
			         count++;
			if (temp->left && !temp->right)
			         count++;
			if (!temp->left && temp->right)
			         count++;
		}
return count;
}
void BinaryTree::eraseTree(node *ptr)
{
	if(ptr->left!=NULL)
		eraseTree(ptr->left);
	if(ptr->right!=NULL)
		eraseTree(ptr->right);
	delete(ptr);
}
void BinaryTree::eraseTreeNR(node *ptr)
{
	if(!ptr)
		return;
	node *temp;
	Queue q;
	q.insert(ptr);
	while(!q.isempty())
	{
		temp=q.deleteq();
		if(temp->left)
			q.insert(ptr->left);
		if(temp->right)
			q.insert(ptr->right);
		delete(temp);
	}
}
int main()
{
	BinaryTree b;
	BinaryTree mt1,mt2,ct;
	int options;
	do
	{
	cout<<"\n1.create Binary Tree\n";
	cout<<"\n2.print preorder \n";
	cout<<"\n3.print preorder NR \n";
	cout<<"\n4.print postorder \n";
	cout<<"\n5.print postorder NR \n";
	cout<<"\n6.mirrorimag \n";
	cout<<"\n7.mirrorimag NR\n";
	cout<<"\n8.Height\n";
	cout<<"\n9.Height NR\n";
	cout<<"\n10.copy\n";
	cout<<"\n11.count Leaf\n";
	cout<<"\n12.count Leaf NR\n";
	cout<<"\n13.count Internal\n";
	cout<<"\n14.count Internal NR\n";
	cout<<"\n15.Erase Tree\n";
	cout<<"\n16.Erase Tree NR\n";
	cout<<"\nEnter choice\n";
	cin>>options;
		switch(options)
		{
		case 1 :
			b.root=b.create();
			break;
		case 2:
			b.printPreorder(b.root);
			break;
		case 3:
			b.printPreorderNR(b.root);
			break;
		case 4:
			b.printPostorder(b.root);
			break;
		case 5:
			b.printPostorderNR(b.root);
			break;
		case 6:
			mt1.root=b.mirrorimage(b.root);
			mt1.printPreorder(mt1.root);
			break;
		case 7:
			mt2.root=b.mirrorimageNR(b.root);
			break;
		case 8:
			cout<<b.height(b.root);
			break;
		case 9:
			cout<<b.heightNR(b.root);
			break;
		case 10:
			ct.root=b.root;
			ct.printPreorder(ct.root);
			break;
		case 11:
			cout<<b.countLeaf(b.root);
			break;
		case 12:
			cout<<b.countLeafNR(b.root);
			break;
		case 13:
			cout<<b.countInternal(b.root);
			break;
		case 14:
			cout<<b.countInternalNR(b.root);
			break;
		case 15:
			b.eraseTree(b.root);
			b.root=NULL;
			break;
		case 16:
			b.eraseTreeNR(b.root);
			b.root=NULL;
			break;
		}
	}while(options!=0);


	return 0;
}
