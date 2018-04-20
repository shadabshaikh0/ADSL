//============================================================================
// Name        : A4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include <vector>
using namespace std;

class Node
{
	string city;
	int distance;
	Node *next;
	int indegree,outdegree;
	Node()
	{
		indegree=0;
		outdegree=0;
		city="";
		distance=0;
		next=NULL;
	}
	friend class Graph;
};

class Graph
{
	Node **link;
	int noofvertices;
public:
	Graph(int size)
	{
		noofvertices=size;
		link=new Node*[noofvertices];
		for(int i=0;i<noofvertices;i++)
			link[i]=NULL;
	}
	Node* Allocate(string,int);
	void Create(bool);
	void AddPath();
	void DeletePath();
	void AddLocation();
	void DeleteLocation();
	void Display(int);
	void degreeOfAirport();
	void indegreeOfAirport();
	void outdegreeOfAirport();
};

Node* Graph::Allocate(string location,int distance)
{
	Node *newnode=new Node;
	newnode->city=location;
	newnode->distance=distance;
	newnode->next=NULL;
	return newnode;
}
void Graph::Create(bool first)
{
	int i;
	string location;
	if(first)
	{
		for( i=0;i<noofvertices;i++)
		{
			cout<<"\nEnter location\n";
			cin>>location;
			link[i]= Allocate(location,0);
		}
	  return;
	}

	Graph *obj=new Graph(noofvertices+1);
	for(i=0;i<noofvertices;i++)
	{
		obj->link[i]=link[i];
	}

	Node** temp;
	temp=link;
	link=obj->link;
	cout<<"\nEnter new Location\n";
	cin>>location;
	link[i]=Allocate(location,0);
	noofvertices++;
	delete(temp);
	cout<<"\nNew Location Added Successfully\n";
}
void Graph::AddLocation()
{
	int i;
	bool Available=false;
	string location;
	for( i=0;i<noofvertices;i++)
	{
		if(link[i]->city=="\0")
		{
			Available=true;
			break;
		}
	}
	if(!Available)
	{
		Create(false);
		return;
	}
	cout<<"\nEnter new Location\n";
	cin>>location;
	link[i]->city=location;
	cout<<"\nNew Location Added Successfully\n";
}
void Graph::DeleteLocation()
{
	int i,j;
	bool exists;
	string location;
	cout<<"\nEnter location to be deleted\n";
	cin>>location;
	for(i=0;i<noofvertices;i++)
	{
		if(link[i]->city==location)
		{
			exists=true;
			break;
		}
	}
	if(!exists)
	{
		cout<<"\nNo such location exists\n";
		return;
	}

	Node *back,*temp;
	for(temp=link[i]->next;temp!=NULL;temp=temp->next)//add one for loop before this to make it directed deletion;
	{
		Node *temp1;
		for(j=0;j<noofvertices;j++)
		{
			if(temp->city==link[j]->city)
			{
				for(temp1=link[j];;temp1=temp1->next)
				{
					if(temp1->city==location)
						break;
					back=temp1;
				}
				back->next=temp1->next;
				delete(temp1);
				break;
			}
		}

	}
	while(link[i]->next!=NULL)
	{
		temp=link[i]->next;
		link[i]->next=temp->next;
		delete(temp);
	}
	link[i]->city="\0";
	cout<<"Location Deleted Succesfully"<<endl;
}


void Graph::AddPath()
{
	string source,destination;
	bool exists;
	int i,j,length;
	cout<<"\nEnter Distance in KM\n";
	cin>>length;

	cout<<"\nEnter Source Location\n";
	cin>>source;
	exists=false;
	for(i=0;i<noofvertices;i++)
	{
		if(source==link[i]->city)
		{
			exists=true;
			break;
		}
	}
	if(!exists)
	{
		cout<<"\nNo such location exists\n";
		return;
	}

	cout<<"\nEnter Destination Location\n";
	cin>>destination;
	if(source==destination)
	{
		cout<<"\nBoth are same\n";
		return;
	}
	exists=false;
	for(j=0;j<noofvertices;j++)
	{
		if(destination==link[j]->city)
		{
			exists=true;
			break;
		}
	}
	if(!exists)
	{
		cout<<"\nNo such location exists\n";
		return;
	}

	Node *temp,*back;
	char choice;
	bool change=false;
	for(temp=link[i];temp!=NULL;temp=temp->next)
	{
		back=temp;
		if(temp->city==destination)
		{
			cout<<"This Path Already exists"<<endl;
			cout<<"Do you want to change the distance ?(y/n)"<<endl;
			cin>>choice ;
			if('y' == choice || 'Y' == choice)
			{
				change = true ;
				break ;
			}
			return;
		}
	}

	if(change)
	{
		temp->distance=length;
		for(temp=link[j];temp!=NULL;temp=temp->next)
			if(temp->city==source)
				break;

		temp->distance=length;
		cout<<"Distance modified"<<endl;
		return ;
	}

	back->next=Allocate(destination,length);
	for(temp=link[j];temp!=NULL;temp=temp->next)
		back=temp;
	back->next=Allocate(source,length);
	cout<<"Path Added";
	link[j]->indegree++;
	link[i]->outdegree++;
}
void Graph::DeletePath()
{
	string source,destination;
	bool exists;
	int i,j;

	cout<<"\nEnter 1st Location\n";
	cin>>source;
	for(i=0;i<noofvertices;i++)
	{
		if(source==link[i]->city)
		{
			exists=true;
			break;
		}
	}
	if(!exists)
	{
		cout<<"\nNo such location exists\n";
		return;
	}

	cout<<"\nEnter 2nd Location\n";
	cin>>destination;
	if(source==destination)
	{
		cout<<"\nBoth are same\n";
		return;
	}
	for(j=0;j<noofvertices;j++)
	{
		if(destination==link[j]->city)
		{
			exists=true;
			break;
		}
	}
	if(!exists)
	{
		cout<<"\nNo such location exists\n";
		return;
	}

	Node *temp,*back;
	exists=false;
	for(temp=link[i];temp!=NULL;temp=temp->next)
	{
		if(temp->city==destination)
		{
			exists=true;
			break;
		}
		back=temp;
	}
	if(!exists)
	{
		cout<<"No Path present between these two locations"<<endl;
		return ;
	}
	back->next=temp->next;
	delete(temp);
	for(temp=link[j];;temp=temp->next)
	{
		if(temp->city==source)
			break;
		back=temp;
	}
	back->next = temp->next ;
	delete(temp);
	cout<<"Path Deleted"<<endl ;
	link[j]->indegree--;
	link[i]->outdegree--;
}
void Graph::Display(int choice)
{
	int i;
	Node *temp;
	if(choice==6)
	{
		for(i=0;i<noofvertices;i++)
		{
			for(temp=link[i]->next;temp!=NULL;temp=temp->next)
			{
				if(temp->distance!=0)
				{
					cout<<link[i]->city<<" -> "<<temp->city<<","<<temp->distance<<"km."<<endl ;
				}
			}
		}
	 return;
	}
	vector<string> v ;
	bool present ;
	vector<string>::iterator it ;
	for(i = 0 ; i<noofvertices ; i++)
	{
		for(temp = link[i] ; NULL != temp ; temp = temp->next )
		{
			present = false;
			for(it = v.begin();it != v.end() ;it++)
			{
				if(*it == temp->city)
				{
					present = true ;
					break ;
				}
			}
			if(!present)
				v.push_back(temp->city) ;

		}
	}
	for(it = v.begin() ; it != v.end() ; it++)
		cout<<*it<<"	";

}

void Graph::degreeOfAirport()
{
	int count,i;
	Node *temp;
	for(i=0;i<noofvertices;i++)
	{
		count=0;
		for(temp=link[i]->next;temp!=NULL;temp=temp->next)
		{
			if(temp->distance!=0)
			{
				count++;
			}
		}
		cout<<"Degree of "<<link[i]->city<<":"<<count<<endl ;
	}
 return ;
}

void Graph::indegreeOfAirport()
{
	int i;
	for(i=0;i<noofvertices;i++)
	{
		cout<<"City:"<<link[i]->city<<"  "<<"Indegree:"<<link[i]->indegree<<endl;
	}
}
void Graph::outdegreeOfAirport()
{
	int i;
	for(i=0;i<noofvertices;i++)
	{
		cout<<"City:"<<link[i]->city<<"  "<<"Outdegree:"<<link[i]->outdegree<<endl;
	}
}

int main() {
	int choice,size;
	cout<<"\nEnter number of Airports\n";
	cin>>size;

	Graph *obj=new Graph(size);
    obj->Create(true);

	do
	{
	cout<<endl<<"SELECT"<<endl;
	cout<<"1 : Add Path"<<endl<<"2 : Delete Path"<<endl<<"3 : Add Location"<<endl;
	cout<<"4 : Delete Location"<<endl<<"5 : Display(Breadth first)"<<endl<<"6 : Display routes"<<endl;
	cout<<"7.degree of Aiports"<<endl<<"8.indegree"<<endl<<"9.outdegree"<<endl;
    cout<<"0 : EXIT"<<endl;
	cin>>choice;
		switch(choice)
		{
		case 1 :
			obj->AddPath();
			break;
		case 2 :
			obj->DeletePath();
			break;
		case 3 :
			obj->AddLocation() ;
			break;
		case 4 :
			obj->DeleteLocation() ;
			break;
		case 5 :
			obj->Display(choice) ;
			break;
		case 6 :
			obj->Display(choice) ;
			break ;
		case 7:
			obj->degreeOfAirport();
			break;
		case 8:
			obj->indegreeOfAirport();
			break;
		case 9:
			obj->outdegreeOfAirport();
			break;
		default :
			if(0 != choice)
				cout<<"Wrong Choice"<<endl;
		}
	}while(0 != choice);


	return 0;
}


/*
#include<iostream>
#include <string>
using namespace std;
class Node
{
	string city;
	int distance,indegree,outdegree;
	Node *next;
public:
	Node()
	{
		city="";
		distance=0;
		indegree=0;
		outdegree=0;
		next=NULL;
	}
	friend class Graph;
};
class Graph
{
	Node **link;
	int noofvertices;
public:
	Graph(int n)
	{
		noofvertices=n;
		link=new Node*[n];
		for(int i=0;i<noofvertices;i++)
			link[i]=NULL;
	}
	Node* Allocate(string,int);
	void Create(bool);
	void AddLocation();
	void DeleteLocation();
	void AddPath();
	void DeletePath();
	void display(int);
};
Node* Graph::Allocate(string location,int distance)
{
	Node *newnode=new Node;
	newnode->city=location;
	newnode->distance=distance;
	newnode->next=NULL;
	return newnode;
}

void Graph::Create(bool first)
{
	int i;
	string location;
	if(first)
	{
		for( i=0;i<noofvertices;i++)
		{
			cout<<"\nEnter locaation\n";
			cin>>location;
			link[i]=Allocate(location,0);
		}
		return;
	}

	Graph *obj=new Graph(noofvertices+1);
	for( i=0;i<noofvertices;i++)
	{
		obj->link[i]=link[i];
	}

	Node **temp;
	temp=link;
	link=obj->link;
	cout<<"\nEnter location\n";
	cin>>location;
	link[i]=Allocate(location,0);
	noofvertices++;
	delete(temp);
	cout<<"\nAdd City succesfully\n";

}
void Graph::AddLocation()
{
	int i;
	bool Available=false;
	string location;
	for( i=0;i<noofvertices;i++)
	{
		if(link[i]->city=="\0")
		{
			Available=true;
			break;
		}
	}
	if(!Available)
	{
		Create(false);
		return;
	}
	cout<<"\nEnter new Location\n";
	cin>>location;
	link[i]->city=location;
	cout<<"\nNew Location Added Successfully\n";
}

void Graph::DeleteLocation()
{
	int i,j;
	bool exists=false;
	string location;
	cout<<"\nEnter location to be deleted\n";
	cin>>location;
	for(i=0;i<noofvertices;i++)
	{
		if(location==link[i]->city)
		{
			exists=true;
			break;
		}
	}
	if(!exists)
	{
		cout<<"\nNo such Location found\n";
		return;
	}

	Node *back,*temp;
	for(temp=link[i]->next;temp!=NULL;temp=temp->next)
	{
		Node *temp1;
		for(j=0;j<noofvertices;j++)
		{
			if(link[j]->city==temp->city)
			{
				for(temp1=link[j];;temp1=temp1->next)
				{
					if(temp1->city==location)
						break;
					back=temp1;
				}
				back->next=temp1->next;
				delete(temp1);
				break;
			}
		}
	}
	while(link[i]->next!=NULL)
	{
		temp=link[i]->next;
		link[i]->next=temp->next;
		delete(temp);
	}
	link[i]->city='\0';
	cout<<"\nLocation Deleted succesfully\n";
}

void Graph::AddPath()
{
	string source,destination;
	bool exists=false,change;
	int i,j,length;
	cout<<"\nEnter length in KM\n";
	cin>>length;

	cout<<"\nEnter source\n";
	cin>>source;
	for(i=0;i<noofvertices;i++)
	{
		if(source==link[i]->city)
		{
			exists=true;
			break;
		}
	}
	if(!exists)
	{
		cout<<"\nNo such location found\n";
		return;
	}

	cout<<"\nEnter Destination\n";
	cin>>destination;
	if(source==destination)
	{
		cout<<"\nBoth are same\n";
	}
	for(j=0;j<noofvertices;j++)
	{
		if(destination==link[j]->city)
		{
			exists=true;
			break;
		}
	}
	if(!exists)
	{
		cout<<"\nNo such location found\n";
		return;
	}

	Node *temp,*back;
	change=false;
	char choice;
	for(temp=link[i];temp!=NULL;temp=temp->next)
	{
		back=temp;
		if(destination==temp->city)
		{
			cout<<"\nPath Already Exists\n";
			cout<<"\nDo you want to change(y/n)\n";
			cin>>choice;
			if(choice=='y' || choice=='Y')
			{
				change=true;
				break;
			}
			return;
		}
	}
	if(change)
	{
		temp->distance=length;
		for(temp=link[j];temp!=NULL;temp=temp->next)
			if(source==temp->city)
				break;
		temp->distance=length;
		cout<<"\nDistance Modified\n";
		return;
	}

	back->next=Allocate(destination,length);
	for(temp=link[j];temp!=NULL;temp=temp->next)
		back=temp;
	back->next=Allocate(source,length);
	cout<<"\nPath Added\n";
	link[i]->outdegree++;
	link[j]->indegree--;

}

void Graph::DeletePath()
{
	string source,destination;
	bool exists=false,change;
	int i,j;

	cout<<"\nEnter source\n";
	cin>>source;
	for(i=0;i<noofvertices;i++)
	{
		if(source==link[i]->city)
		{
			exists=true;
			break;
		}
	}
	if(!exists)
	{
		cout<<"\nNo such location found\n";
		return;
	}

	cout<<"\nEnter Destination\n";
	cin>>destination;
	if(source==destination)
	{
		cout<<"\nBoth are same\n";
	}
	for(j=0;j<noofvertices;j++)
	{
		if(destination==link[j]->city)
		{
			exists=true;
			break;
		}
	}
	if(!exists)
	{
		cout<<"\nNo such location found\n";
		return;
	}

	Node *temp,*back;
	exists=false;
	for(temp=link[i];temp!=NULL;temp=temp->next)
	{
		if(destination==link[i]->city)
		{
			exists=true;
			break;
		}
		back=temp;
	}
	if(!exists)
	{
		cout<<"\nNo such path present\n";
		return;
	}
	back->next=temp->next;
	delete(temp);
	for(temp=link[j]->next;;temp=temp->next)
	{
		if(source==link[j]->city)
			break;
		back=temp;
	}
	back->next=temp->next;
	delete(temp);

	cout<<"\nPath Removed\n";
	link[i]->outdegree--;
	link[j]->indegree++;
}


int main()
{

	return 0;
}

*/
