//============================================================================
// Name        : A6.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Node
{
	string key,mean;
	int value;
	friend class Hash;
};

class Hash
{
	int size;
	Node *table;
public:
	Hash(int size)
	{
		this->size=size;
		table=new Node[size];
		for(int i=0;i<size;i++)
			table[i].key="#";
	}

	bool insertWith();
	bool insertWithout();
	bool deleteWithandWithout();
	int hashValue(string);
	void retrieve();
	void DisplayTable();
};

int  Hash::hashValue(string value)
{
	int no,sum=0,i;
	for( i=0;value[i]!='\0';i++)
	{
		no=value[i];
		sum+=no*(i+1);
	}
	sum/=i;
	sum=sum%size;
	return sum;
}

void Hash::DisplayTable()
{
	cout<<"\n\t*******HASH TABLE********\n";
	cout<<"\t key \t mean \t value\t ";
	for(int i=0;i<size;i++)
	{
		cout<<"\n";
		cout<<"\t "<<table[i].key<<" \t"<<table[i].mean<<" \t"<<table[i].value<<" \t\n";
	}
}

bool Hash::insertWithout()
{
	bool present=false;
	char choice;
	int i,hashvalue;
	string keyword,meaning;
	cout<<"\nEnter keyword\n";
	cin>>keyword;
	hashvalue=hashValue(keyword);
	cout<<hashvalue<<endl;
	if(table[hashvalue].key=="#")
	{
		cout<<"\nEnter meaning\n";
		cin>>meaning;
		table[hashvalue].key=keyword;
		table[hashvalue].mean=meaning;
		table[hashvalue].value=hashvalue;
		cout<<"Insertion Successful"<<endl;
		return  true;
	}
	for( i=(hashvalue)%size;  table[i].key!="#";   i=(i+1)%size )
	{
		if(table[i].key==keyword)
		{
			present=true;
			break;
		}
	}
	if(present)
	{
		cout<<"Keyword already exits"<<endl ;
		cout<<"Do you want to change the meaning?(y/n)"<<endl ;
		cin>>choice ;
		if(choice=='y' || choice =='Y')
		{
			cout<<"\nEnter new Meaning\n";
			cin>>meaning;
			table[i].mean=meaning;
		}
		return false;
	}
	table[i].key=keyword;
	cout<<"\nEnter new Meaning\n";
	cin>>meaning;
	table[i].mean=meaning;
	table[i].value=hashvalue;
	return true;
}

bool Hash::insertWith()
{
	bool present=false;
	char choice;
	int i,hashvalue,val;
	string keyword,meaning,temp;
	cout<<"\nEnter keyword\n";
	cin>>keyword;
	hashvalue=hashValue(keyword);
	cout<<hashvalue<<endl;
	if(table[hashvalue].key=="#")
	{
		cout<<"\nEnter meaning\n";
		cin>>meaning;
		table[hashvalue].key=keyword;
		table[hashvalue].mean=meaning;
		table[hashvalue].value=hashvalue;
		cout<<"Insertion Successful"<<endl;
		return  true;
	}

	if(table[hashvalue].value==hashvalue)
	{
			for( i=(hashvalue+1)%size;  table[i].key!="#";   i=(i+1)%size )
			{
				if(table[i].key==keyword)
				{
					present=true;
					break;
				}
			}
			if(present)
			{
				cout<<"Keyword already exits"<<endl ;
				cout<<"Do you want to change the meaning?(y/n)"<<endl ;
				cin>>choice ;
				if(choice=='y' || choice =='Y')
				{
					cout<<"\nEnter new Meaning\n";
					cin>>meaning;
					table[i].mean=meaning;
				}
				return false;
			}
			table[i].key=keyword;
			cout<<"\nEnter new Meaning\n";
			cin>>meaning;
			table[i].mean=meaning;
			table[i].value=hashvalue;
			return true;
	}

	temp=keyword;
	keyword=table[hashvalue].key;
	table[hashvalue].key=temp;
	meaning=table[hashvalue].mean;
	cout<<"\nEnter Meaning\n";
	cin>>table[hashvalue].mean;
	val=table[hashvalue].value;
	table[hashvalue].value=hashvalue;
	for( i=(hashvalue+1)%size; table[i].key!="#"; i=(i+1)%size);
	table[i].key=keyword;
	table[i].mean=meaning;
	table[i].value=val;
	cout<<"Inserted successfully\n";
	return true;
}
bool Hash::deleteWithandWithout()
{
	string keyword;
	int i,hashvalue;

	cout<<"\nEnter key to be deleted\n";
	cin>>keyword;
	hashvalue=hashValue(keyword);
	if(table[hashvalue].key==keyword)
	{
		table[hashvalue].key="#";
		table[hashvalue].mean="#";
		table[hashvalue].value=size+1;
		cout<<"Deletion Successful\n";
		return false;
	}
	for(i=(hashvalue+1)%size; table[i].key!=keyword; i=(i+1)%size)
	{
		if(i==hashvalue)
		{
			cout<<"No such key found\n";
			return true;
		}
	}
	table[i].key="#";
	table[i].mean="#";
	table[i].value=size+1;
	cout<<"Deletion Successful\n";
	return false;
}

void Hash::retrieve()
{
	string keyword;
	int i,hashvalue;

	cout<<"\nEnter key to be Retrieved\n";
	cin>>keyword;
	hashvalue=hashValue(keyword);
	if(table[hashvalue].key==keyword)
	{
		cout<<table[hashvalue].key<<":"<<table[hashvalue].mean<<endl;
		return;
	}
	for(i=(hashvalue+1)%size; table[i].key!=keyword; i=(i+1)%size)
		if(i==hashvalue)
			break;
	if(i==hashvalue)
	{
		cout<<"No such key found";
		return;
	}
	cout<<table[hashvalue].key<<":"<<table[hashvalue].mean<<endl;
}


int main()
{
	bool inc;
	int size,choice,choice1;
	cout<<"\nEnter size of hashtable\n";
	cin>>size;
	Hash obj(size);
	do
	{
		cout<<"SELECT"<<endl ;
		cout<<"1 : Linear Probing Without Replacement"<<endl<<"2 : Linear Probing With Replacement"<<endl ;
		cout<<"0 : EXIT"<<endl ;
		cin>>choice ;
		int i = 0 ;
		switch(choice)
		{
			case 1:
					do
					{
						cout<<"1 : Insert"<<endl<<"2 : Retrieve"<<endl ;
						cout<<"3 : Delete"<<endl<<"4 : Display Table\n"<<"0 : EXIT"<<endl ;
						cin>>choice1 ;
						switch(choice1)
						{
							case 1:
								if(i==size)
									cout<<"Hashtable full"<<endl;
								else
								{
									inc=obj.insertWithout();
									if(inc)
										i++;
								}
								break;
							case 2:
								obj.retrieve();
								break;
							case 3:
								if(i==0)
									cout<<"Empty Hash Table"<<endl;
								else
								{
									inc=obj.deleteWithandWithout();
									if(!inc)
										i--;
								}
								break;
							case 4:
								obj.DisplayTable();
								break;
						}
					}while(choice1!=0);
					break;
			case 2:
				do
				{
					cout<<"1 : Insert"<<endl<<"2 : Retrieve"<<endl ;
					cout<<"3 : Delete"<<endl<<"4 : Display Table\n"<<"0 : EXIT"<<endl ;
					cin>>choice1 ;
					switch(choice1)
					{
						case 1:
							if(i==size)
								cout<<"Hashtable full"<<endl;
							else
							{
								inc=obj.insertWith();
								if(inc)
									i++;
							}
							break;
						case 2:
							obj.retrieve();
							break;
						case 3:
							if(i==0)
								cout<<"Empty Hash Table"<<endl;
							else
							{
								inc=obj.deleteWithandWithout();
								if(!inc)
									i--;
							}
							break;
						case 4:
							obj.DisplayTable();
							break;
					}
				}while(choice1!=0);
				break;

		}
	}while(choice!=0);

	return 0;
}
