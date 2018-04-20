//============================================================================
// Name        : a8.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*
#include <iostream>
using namespace std;

float C[20][20];
int R[20][20];
class node
{
	char data;
	node *lchild,*rchild;
public:
	node()
	{
		data='\0';
		lchild=rchild=NULL;
	}
	friend class OBST;
};

class OBST
{
public:
	node *root;
	int n;
	OBST(int n)
	{
		this->n=n;
		root=NULL;
	}
	void optimal(char[],float[],float[]);
	int find(int,int);
	node* construct(char[],int,int);
	void inorder(node*);

};

void OBST::optimal(char D[],float P[],float Q[])
{
	float W[n+1][n+1];
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			W[i][j]=C[i][j]=R[i][j];

	for(int i=1;i<=n;i++)
	{
		W[i][i]=Q[i-1]+P[i]+Q[i];
		C[i][i]=W[i][i];
		R[i][i]=i;
	}

	for(int step=2;step<=n;step++)
	{
		for(int i=1;i<=n-step+1;i++)
		{
			int j=i+step-1;
			W[i][j]=W[i][j-1]+P[j]+Q[j];
			int k=find(i,j);
			C[i][j]=W[i][j]+C[i][k-1]+C[k+1][j];
			R[i][j]=k;
		}
	}
	root=construct(D,1,n);
}

node* OBST::construct(char D[],int i,int j)
{
	node *p;
	if(R[i][j]==0)
		return NULL;
	else
	{
		p=new node;
		p->data=D[R[i][j]];
		p->lchild=construct(D,i,R[i][j]-1);
		p->rchild=construct(D,R[i][j]+1,j);
		return p;
	}
}

int OBST::find(int i,int j)
{
	int l,k;
	float min=999.00;
	for(k=i;k<=j;k++)
	{
		if(C[i][k-1]+C[k+1][j]<min)
		{
			min=C[i][k-1]+C[k+1][j];
			l=k;
		}
	}
	return l;
}

void OBST::inorder(node* temp)
{
	if (temp != NULL)
	{
		inorder(temp->lchild);
		cout << "\t" << temp->data;
		inorder(temp->rchild);
	}
}

int main()
{
	int n;
	cout<<"\nEnter no of keys\n";
	cin>>n;
	OBST obj(n);
	char D[n+1];
	float p[n+1];
	float q[n+1];

	cout<<"\nEnter keys in sorted order\n";
	for(int i=1;i<=n;i++)
	{
		cin>>D[i];
	}
	cout<<"\nEnter Success probability\n";
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
	}

	cout<<"\nEnter failure probability\n";
	for(int i=0;i<=n;i++)
	{
		cin>>q[i];
	}
	obj.optimal(D,p,q);
	obj.inorder(obj.root);
	return 0;
}
*/
#include <iostream>
using namespace std;
float C[20][20];
int R[20][20];
class node
{
	char data;
	node *lchild,*rchild;
public:
	node()
	{
		data='\0';
		lchild=rchild=NULL;
	}
	friend class OBST;
};
class OBST
{
public:
	node *root;
	int n;
	OBST(int n)
	{
		root=NULL;
		this->n=n;
	}
	void optimal(char[],float [],float []);
	int find(int,int);
	node* construct(char[],int,int);
	void inorder(node*);
};

void OBST::optimal(char D[],float P[],float Q[])
{
	float W[n+1][n+1];
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			W[i][j]=C[i][j]=R[i][j];

	for(int i=1;i<=n;i++)
	{
		W[i][i]=Q[i-1]+P[i]+Q[i];
		C[i][i]=W[i][i];
		R[i][i]=i;
	}
	for(int step=2;step<=n;step++)
	{
		for(int i=1;i<=n-step+1;i++)
		{
			int j=i+step-1;
			W[i][j]=W[i][j-1]+Q[j]+P[j];
			int k=find(i,j);
			C[i][j]=W[i][j]+C[i][k-1]+C[k+1][j];
			R[i][j]=k;
		}
	}
	root=construct(D,1,n);
}
node* OBST::construct(char D[],int i,int j)
{
	node *p;
	if(R[i][j]==0)
		return NULL;
	else
	{
		p=new node;
		p->data=D[R[i][j]];
		p->lchild=construct(D,i,R[i][j]-1);
		p->rchild=construct(D,R[i][j]+1,j);
		return p;
	}
}
int OBST::find(int i,int j)
{
	int l,k;
	int min=999.00;
	for(int k=i;k<=j;k++)
	{
		if(C[i][k-1]+C[k+1][j]<min)
		{
			min=C[i][k-1]+C[k+1][j];
			l=k;
		}
	}
	return l;
}
void OBST::inorder(node *ptr)
{
	if(ptr!=NULL)
	{
		inorder(ptr->lchild);
		cout<<""<<ptr->data<<"->";
		inorder(ptr->rchild);
	}
}
int main()
{
	int n;
	cout<<"\nEnter no of keys\n";
	cin>>n;
	OBST o(n);

	char D[n+1];
	float p[n+1];
	float q[n+1];

	cout<<"\nEnter keys\n";
	for(int i=1;i<=n;i++)
		cin>>D[i];

	cout<<"\nEnter success probability\n";
	for(int i=1;i<=n;i++)
		cin>>p[i];

	cout<<"\nEnter failure  probability\n";
	for(int i=0;i<=n;i++)
		cin>>q[i];

	o.optimal(D,p,q);
	o.inorder(o.root);

	return 0;
}

















