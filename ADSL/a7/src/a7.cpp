//============================================================================
// Name        : a7.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Node
{
	string name,attribute;
	int value,chain;
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
		{
			table[i].name="#";
			table[i].attribute="#";
			table[i].chain=-1;
		}
	}
	bool insertWith();
	bool insertWithout();
	bool deletewithandwithout();
	void retrieve();
	int hashValue(string);
	void displayTable();
};

int Hash::hashValue(string value)
{
	int no,sum,i;
	for ( i = 0;value[i]!='\0'; ++i)
	{
		no=value[i];
		sum+=no*(i+1);
	}
	sum/=i;
	sum=sum%size;
	return sum;
}

void Hash::displayTable()
{

	cout<<"\n\t*******HASH TABLE********\n";
	cout<<"\tname attribute value chain \t ";
	for(int i=0;i<size;i++)
	{
		cout<<"\n";
		cout<<"\t "<<table[i].name<<" \t"<<table[i].attribute<<" \t"<<table[i].value<<" \t"<<table[i].chain<<" \t\n";
	}
}


bool Hash::insertWithout()
{
	bool present=false;
	char choice;
	int i,j,hashvalue;
	string keyword,meaning;
	cout<<"\nEnter name\n";
	cin>>keyword;
	hashvalue=hashValue(keyword);
	cout<<hashvalue<<endl;
	if(table[hashvalue].name == "#")
	{
		cout<<"\nEnter Attribute\n";
		cin>>meaning;
		table[hashvalue].name=keyword;
		table[hashvalue].attribute=meaning;
		table[hashvalue].value=hashvalue;
		cout<<"\nInsert Successfully\n";
		return true;
	}

	j=hashvalue;
	for(i=(hashvalue+1)%size; table[i].name!="#"; i=(i+1)%size)
	{
		if(table[i].value==hashvalue)
			j=i;
		if(table[i].name==keyword)
		{
			present=true;
			break;
		}
	}
	if(present)
	{
		cout<<"Name already exits"<<endl ;
		cout<<"Do you want to change the Attribute?(y/n)"<<endl ;
		cin>>choice ;
		if(choice == 'y' || choice == 'Y')
		{
			cout<<"\nEnter Attribute\n";
			cin>>meaning;
			table[hashvalue].attribute=meaning;
		}
		return false;
	}

	table[i].name=keyword;
	cout<<"\nEnter Attribute\n";
	cin>>meaning;
	table[i].attribute=meaning;
	table[i].value=hashvalue;
	table[j].chain=i;

	cout<<"\nInsert Successfully\n";
	return true;
}

bool Hash::insertWith()
{
	bool present=false;
	char choice;
	int i,j,hashvalue,val;
	string keyword,meaning,temp;
	cout<<"\nEnter name\n";
	cin>>keyword;
	hashvalue=hashValue(keyword);
	cout<<hashvalue<<endl;
	if(table[hashvalue].name == "#")
	{
		cout<<"\nEnter Attribute\n";
		cin>>meaning;
		table[hashvalue].name=keyword;
		table[hashvalue].attribute=meaning;
		table[hashvalue].value=hashvalue;
		cout<<"\nInsert Successfully\n";
		return true;
	}

	j=hashvalue;

	if(table[hashvalue].value==hashvalue)
	{
			for(i=(hashvalue+1)%size; table[i].name!="#"; i=(i+1)%size)
			{
				if(table[i].value==hashvalue)
					j=i;
				if(table[i].name==keyword)
				{
					present=true;
					break;
				}
			}
			if(present)
			{
				cout<<"Name already exits"<<endl ;
				cout<<"Do you want to change the Attribute?(y/n)"<<endl ;
				cin>>choice ;
				if(choice == 'y' || choice == 'Y')
				{
					cout<<"\nEnter Attribute\n";
					cin>>meaning;
					table[hashvalue].attribute=meaning;
				}
				return false;
			}

			table[i].name=keyword;
			cout<<"\nEnter Attribute\n";
			cin>>meaning;
			table[i].attribute=meaning;
			table[i].value=hashvalue;
			table[j].chain=i;

			cout<<"\nInsert Successfully\n";
			return true;
	}

	temp=keyword;
	keyword=table[hashvalue].name;
	table[hashvalue].name=temp;
	meaning=table[hashvalue].attribute;
	cout<<"\nEnter Attribute\n";
	cin>>table[hashvalue].attribute;
	val=table[hashvalue].value;
	table[hashvalue].value=hashvalue;
	table[hashvalue].chain=-1;

	j=val;
	for(j=val; table[j].chain!=hashvalue; j=table[j].chain);

	for(i=(hashvalue+1)%size; table[i].name!="#"; i=(i+1)%size)
	{
		if(table[i].value==hashvalue)
			j=i;
	}
	table[i].name = keyword ;
	table[i].attribute = meaning ;
	table[i].value = val ;
	table[j].chain = i ;
	cout<<"Insert Successfully"<<endl ;
	return true ;
}

bool Hash::deletewithandwithout()
{
	string keyword;
	int hashvalue,i;
	bool present;
	cout<<"\nEnter name to be deleted\n";
	cin>>keyword;
	hashvalue=hashValue(keyword);
	present=false;

	for(i=hashvalue; i!=-1 ;i=table[i].chain)
	{
		if(table[i].name==keyword)
		{
			present=true;
			break;
		}
	}
	if(present)
	{
		table[i].name="#";
		table[i].attribute="#";
		table[i].value=size+1;
		cout<<"Deletion Successful"<<endl ;
		return false ;
	}
	cout<<"\nNo such name found\n";
	return true;
}

void Hash::retrieve()
{
	string keyword;
	int hashvalue,i;
	bool present;

	cout<<"\nEnter name\n";
	cin>>keyword;

	hashvalue=hashValue(keyword);

	present=false;
	for(i=hashvalue; i!=-1 ;i=table[i].chain)
	{
		if(table[i].name == keyword)
		{
			cout<<table[i].name<<" : "<<table[i].attribute<<endl ;
			return ;
		}
	}
	cout<<"No such Name Found"<<endl ;

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
									inc=obj.deletewithandwithout();
									if(!inc)
										i--;
								}
								break;
							case 4:
								obj.displayTable();
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
								inc=obj.deletewithandwithout();
								if(!inc)
									i--;
							}
							break;
						case 4:
							obj.displayTable();
							break;
					}
				}while(choice1!=0);
				break;

		}
	}while(choice!=0);

	return 0;

	return 0;
}
