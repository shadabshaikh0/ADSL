//============================================================================
// Name        : ass10.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*
#include <iostream>
#include <fstream>
using namespace std;

class Student
{
	int rollno;
	char name[20];
public:
	void input();
	void show();
	int getRollno()
	{
		return rollno;
	}
	char* getname()
	{
		return name;
	}
};
void Student::input()
{
	cout<<"\nEnter roll no\n";
	cin>>rollno;
	cout<<"\nEnter name\n";
	cin>>name;
}
void Student::show()
{
	cout<<endl;
	cout<<"Roll NO:" <<rollno<<"\t"<<"Name: "<<name<<"\n";
}


int main()
{
	ofstream o;
	fstream file;
	file.open("abc.txt",ios::out);
	file.clear();
	file.close();
	Student s;

	int roll;
	int options;
	do
	{
		cout<<"\n1.Add Student\n";
		cout<<"\n2.Delete Student\n";
		cout<<"\n3.Search Student\n";
		cout<<"\n4.Display \n";
		cout<<"\n0.exit\n";
		cout<<"\nEnter your choice\n";
		cin>>options;
		switch(options)
		{
		case 1:
			s.input();
			file.open("abc.txt",ios::out|ios::app);
			file.write((char*)&s,sizeof(s));
			file.close();
			break;
		case 3:
			cout<<"\nEnter Roll No\n";
			cin>>roll;
			file.open("abc.txt",ios::in);
			file.seekg(0,ios::beg);
			while(file.read((char*)&s,sizeof(s)))
			{
				if(roll==s.getRollno())
				{
					cout<<"Roll NO:" <<s.getRollno()<<"\t"<<"Name: "<<s.getname()<<"\n";
				}
			}
			file.close();
			break;
		case 2:
			cout<<"\nEnter roll no to be deleted\n";
			cin>>roll;
			o.open("new.txt",ios::out);
			file.open("abc.txt",ios::in);
			file.seekg(0,ios::beg);
			while(file.read((char*)&s,sizeof(s)))
			{
				if(roll==s.getRollno())
				{

				}
				else
				{
					o.write((char*)&s,sizeof(s));
				}
			}
			o.close();
			file.close();
			remove("abc.txt");
			rename("new.txt","abc.txt");
			break;
		case 4:
			file.open("abc.txt",ios::in);
			file.seekg(0,ios::beg);
			while(file)
			{
				file.read((char*)&s,sizeof(s));
				if(!file.eof())
				{
					s.show();
				}
			}
			file.close();
			break;
		case 0:
			exit(0);
			break;
		}

	}while(options!=0);

	return 0;
}

*/

#include<iostream>
#include <fstream>
using namespace std;
class student
{
	int rollno;
	char name[20];
public:
	void input()
	{
		cout<<"\nEnter Roll No\n";
		cin>>rollno;
		cout<<"\nEnter name\n";
		cin>>name;
	}
	void show()
	{
		cout<<endl;
		cout<<"Roll NO:" <<rollno<<"\t"<<"Name: "<<name<<"\n";
	}
	int getRollNo()
	{
		return rollno;
	}
	char* getName()
	{
		return name;
	}
};
int main()
{
	int roll;
	ofstream o;
	fstream file;
	file.open("abc.txt",ios::out);
	file.clear();
	file.close();
	student s;
	int choice;
	do
	{
		cout<<"\n1.Add Student\n";
		cout<<"\n2.Delete Student\n";
		cout<<"\n3.Search Student\n";
		cout<<"\n4.Display \n";
		cout<<"\n0.exit\n";
		cout<<"\nEnter your choice\n";
		cin>>choice;
		switch(choice)
		{
			case 1:
					s.input();
					file.open("abc.txt",ios::out|ios::app);
					file.write((char*)&s,sizeof(s));
					file.close();
					break;
			case 2:
				cout<<"\nEnter roll no to be searched\n";
				cin>>roll;
				o.open("new.txt",ios::out);
				file.open("abc.txt",ios::in);
				file.seekg(0,ios::beg);
				while(file.read((char*)&s,sizeof(s)))
				{
					if(roll==s.getRollNo())
					{
					}
					else
					{
						o.write((char*)&s,sizeof(s));
					}
				}
				file.close();
				o.close();
				remove("abc.txt");
				rename("new.txt","abc.txt");
				break;
			case 3:
				cout<<"\nEnter roll no to be searched\n";
				cin>>roll;
				file.open("abc.txt",ios::in);
				file.seekg(0,ios::beg);
				while(file.read((char*)&s,sizeof(s)))
				{
					if(roll==s.getRollNo())
					{
						s.show();
					}
				}
				file.close();
				break;
			case 4:
				file.open("abc.txt",ios::in);
				file.seekg(0,ios::beg);
				while(file)
				{
					file.read((char*)&s,sizeof(s));
					if(!file.eof())
					{
						s.show();
					}
				}
				file.close();
				break;
			case 0:
				exit(0);
		}

	}while(choice!=0);

}






