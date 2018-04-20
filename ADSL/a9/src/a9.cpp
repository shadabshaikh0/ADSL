//============================================================================
// Name        : a9.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
using namespace std;
class Student
{
public:
	int heap[30],n;
	void getdata()
	{
		cout<<"\nEnter no of students\n";
		cin>>n;
		heap[0]=n;
		cout<<"\nEnter marks\n";
		for(int i=1;i<=n;i++)
		{
			cin>>heap[i];
		}
	}
	void display()
	{
		cout<<"\nMin Marks="<<heap[1]<<endl;
		cout<<"\nMax Marks="<<heap[n]<<endl;
	}

	void create(int []);
	void down_adjust(int [],int);
};

void Student::create(int heap[])
{
	int n=heap[0];
	for(int i=n/2;i>=1;i--)
	{
		down_adjust(heap,i);
	}
}

void Student::down_adjust(int heap[],int i)
{
	int temp,flag=1,j;
	int n=heap[0];
	while(2*i<=n && flag==1)
	{
		j=2*i;
		if(j+1<=n && heap[j+1]>heap[j])
			j++;
		if(heap[i]>heap[j])
			flag=0;
		else
		{
			temp=heap[i];
			heap[i]=heap[j];
			heap[j]=temp;
			i=j;
		}
	}
}


int main()
{
	Student s;
	s.getdata();
	s.create(s.heap);
	while(s.heap[0]>1)
	{
		int last=s.heap[0];
		int temp=s.heap[1];
		s.heap[1]=s.heap[last];
		s.heap[last]=temp;
		s.heap[0]--;
		s.down_adjust(s.heap,1);
	}
	s.display();
	return 0;
}
*/
#include <iostream>
using namespace std;
class student
{
public:
	int n;
	int heap[30];
	void getdata()
	{
		cout<<"\nEnter no of students\n";
		cin>>n;
		heap[0]=n;
		for(int i=1;i<=n;i++)
		{
			cin>>heap[i];
		}
	}
	void show()
	{
		cout<<"\nMin Marks="<<heap[1]<<endl;
		cout<<"\nMax Marks="<<heap[n]<<endl;
	}
	void create(int []);
	void down_adjust(int[],int);
};
void student::create(int heap[])
{
	int n=heap[0];
	for(int i=n/2;i>=1;i--)
	{
		down_adjust(heap,i);
	}
}

void student::down_adjust(int heap[],int i)
{
	int temp,flag=1,j;
	int n=heap[0];
	while(2*i<=n && flag==1)
	{
		j=2*i;
		if(j+1<=n && heap[j+1]>heap[j])
			j++;
		if(heap[i]>heap[j])
			flag=0;
		else
		{
			temp=heap[i];
			heap[i]=heap[j];
			heap[j]=temp;
			i=j;
		}
	}
}
int main()
{
	student s;
	s.getdata();
	s.create(s.heap);
	while(s.heap[0]>1)
	{
		int last=s.heap[0];
		int temp=s.heap[1];
		s.heap[1]=s.heap[last];
		s.heap[last]=temp;
		s.heap[0]--;
		s.down_adjust(s.heap,1);
	}
	s.show();
}

