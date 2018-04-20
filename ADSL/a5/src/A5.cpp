//============================================================================
// Name        : A5.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*
#include <iostream>
using namespace std;

class Graph
{
	int **matrix;
	string *office;
	int size;
public:
	Graph(int size)
	{
		this->size=size;
		matrix=new int*[size];
		for (int i = 0; i < size; ++i)
			matrix[i]=new int[size];

		for(int i=0;i<size;i++)
			for(int j=0;j<size;j++)
				matrix[i][j]=-1;

		office=new string[size];
		for(int i=0;i<size;i++)
			office[i]="#";
	}
	void Addline();
	void Deleteline();
	void Addoffices();
	void prims();
	void kruskal();
};

void Graph::Addoffices()
{
	for (int i = 0; i <size; ++i) {
		cout<<"\nEnter Office Name\n";
		cin>>office[i];
	}
}

void Graph::Addline()
{
	bool present;
	int cost,i,j;
	string source,destination;
	char choice;

	cout<<"\nEnter 1st office \n";
	cin>>source;

	present=false;
	for(i=0;i<size;i++)
	{
		if(source==office[i])
		{
			present=true;
			break;
		}
	}
	if(!present)
	{
		cout<<"\nNo such office  with name "<<source<<"present"<<endl;
	}

	cout<<"\nEnter 2nd office \n";
	cin>>destination;
	present=false;
	for(j=0;j<size;j++)
	{
		if(destination==office[j])
		{
			present=true;
			break;
		}
	}
	if(!present)
	{
		cout<<"\nNo such office  with name "<<destination<<"present"<<endl;
	}

	if(matrix[i][j]!=-1)
	{
		cout << "Phone Line Already Present" << endl;
		cout << "Do you want to change the cost?(y/n)" << endl;
		cin >> choice;
		if ('y' == choice || 'Y' == choice)
			goto l1;
		else
			return;
	}

	cout << "Enter Cost of the phone line" << endl;
	cin >> cost;
	matrix[i][j] = cost;
	matrix[j][i] = cost;
	cout << "Phone Line Added" << endl;
	return;

	l1:
		cout << "Enter Cost of the phone line" << endl;
		cin >> cost;
		matrix[i][j] = cost;
		matrix[j][i] = cost;
		cout << "Phone Line updated" << endl;
		return;

}

void Graph::Deleteline()
{
	bool present;
	int cost,i,j;
	string source,destination;
	char choice;

	cout<<"\nEnter 1st office \n";
	cin>>source;

	present=false;
	for(i=0;i<size;i++)
	{
		if(source==office[i])
		{
			present=true;
			break;
		}
	}
	if(!present)
	{
		cout<<"\nNo such office  with name "<<source<<"present"<<endl;
	}

	cout<<"\nEnter 2nd office \n";
	cin>>destination;
	present=false;
	for(j=0;j<size;j++)
	{
		if(destination==office[j])
		{
			present=true;
			break;
		}
	}
	if(!present)
	{
		cout<<"\nNo such office  with name "<<destination<<"present"<<endl;
	}

	matrix[i][j]=-1;
	matrix[j][i]=-1;
	cout<<"phone line Removed";
}

void Graph::prims()
{
	int result[size][size],G[size][size],visited[size];
	int i,j,u,v,min,count,sum;

	for (i = 0; i < size; ++i) {
		visited[i]=0;
		for (j = 0; j < size; ++j) {
			if(matrix[i][j]==-1)
				G[i][j]=999;
			else
				G[i][j]=matrix[i][j];
			result[i][j]=0;
		}
	}

	visited[0]=1;
	for(count=0;count<size-1;count++){
		min=999;
		for (i = 0; i < size; ++i) {
			if(visited[i]==1){
				for (j = 0; j < size; ++j) {
					if(visited[j]!=1){
						if(min>G[i][j]){
							min=G[i][j];
							u=i;
							v=j;
						}
					}
				}
			}
		}
		visited[v]=1;
		result[u][v]=min;
		result[v][u]=min;
	}
	cout << "Minimum cost giving telephone line is" << endl;
	sum = 0;
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			cout << result[i][j] << "	";
			sum += result[i][j];
		}
		cout<<endl;
	}
	cout << endl;
	cout << "Cost : " << sum/2 <<endl;
}


void Graph::kruskal()
{
	int min,u,v,noofedges=1;
	int result[size][size],parent[size],G[size][size];
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			G[i][j] = matrix[i][j];

	for (int i = 0; i < size; i++)
	{
		parent[i] = -1;
		for (int j = 0; j < size; j++)
		{
			if (G[i][j] == -1)
				G[i][j] = 999;
			result[i][j] = 0;
		}
	}

	while(noofedges<size)
	{
		min=999;
		for (int i = 0; i < size; ++i) {
			for (int j = 0;  j < size; ++ j) {
				if(min>G[i][j])
				{
					min=G[i][j];
					u=i;
					v=j;
				}
			}
		}

		int x=u;
		int y=v;
		G[u][v]=G[v][u]=999;
		int rt1,rt2;
		while(u>=0)
		{
			rt1=u;
			u=parent[u];
		}
		while(v>=0)
		{
			rt2=v;
			v=parent[v];
		}
		if(rt1!=rt2)
		{
			noofedges++;
			result[x][y]=min;
			result[y][x]=min;
			parent[rt2]=rt1;
		}
	}
	cout << "Minimum cost giving telephone line is"<<endl;

	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << result[i][j] << "	";
			sum += result[i][j];
		}
		cout<<endl ;
	}
	cout<<"Cost : "<<sum/2<<endl ;

}

int main() {
	int size, choice, i, choice1;
	cout << "Enter Number of offices" << endl;
	cin >> size;
	Graph obj(size);
	obj.Addoffices();

	do {
		cout << "SELECT" << endl;
		cout << "1 : Add Phone Line\n2 : Remove Phone Line" << endl;
		cout << "3 : Calculate Minimum Cost\n0 : EXIT" << endl;
		cin >> choice;
		switch (choice) {
		case 1:
			obj.Addline();
			break;
		case 2:
			obj.Deleteline();
			break;
		case 3:
			cout << "1 : Prims Algorithm" << endl << "2 : Kruskals Algorihm"
					<< endl;
			cin >> choice1;
			if (1 == choice1)
				obj.prims();
			else if (2 == choice1)
				obj.kruskal();
			else
				cout << "****  Wrong Choice  ****" << endl;
			break;
		default:
			if (0 != choice)
				cout << "****  Wrong Choice  ****" << endl;
		}
	} while (0 != choice);

	return 0;
}
*/
#include <iostream>
using namespace std;

class Graph
{
	int **matrix;
	string *office;
	int size;
public:
	Graph(int size)
	{
		this->size=size;
		matrix=new int*[size];
		for(int i=0;i<size;i++)
			matrix[i]=new int[size];

		for(int i=0;i<size;i++)
			for(int j=0;j<size;j++)
				matrix[i][j]=-1;

		office=new string[size];
		for(int i=0;i<size;i++)
			office[i]="#";

	}
	void Addline();
	void Deleteline();
	void Addoffices();
	void prims();
	void kruskal();
};
void Graph::Addoffices()
{
	for (int i = 0; i <size; ++i) {
		cout<<"\nEnter Office Name\n";
		cin>>office[i];
	}
}

void Graph::Addline()
{
	bool present;
	int cost,i,j;
	string source,destination;
	char choice;

	cout<<"\nEnter 1st office \n";
	cin>>source;

	present=false;
	for(i=0;i<size;i++)
	{
		if(source==office[i])
		{
			present=true;
			break;
		}
	}
	if(!present)
	{
		cout<<"\nNo such office  with name "<<source<<"present"<<endl;
	}

	cout<<"\nEnter 2nd office \n";
	cin>>destination;
	present=false;
	for(j=0;j<size;j++)
	{
		if(destination==office[j])
		{
			present=true;
			break;
		}
	}
	if(!present)
	{
		cout<<"\nNo such office  with name "<<destination<<"present"<<endl;
	}

	if(matrix[i][j]!=-1)
	{
		cout << "Phone Line Already Present" << endl;
		cout << "Do you want to change the cost?(y/n)" << endl;
		cin >> choice;
		if ('y' == choice || 'Y' == choice)
			goto l1;
		else
			return;
	}

	cout << "Enter Cost of the phone line" << endl;
	cin >> cost;
	matrix[i][j] = cost;
	matrix[j][i] = cost;
	cout << "Phone Line Added" << endl;
	return;

	l1:
		cout << "Enter Cost of the phone line" << endl;
		cin >> cost;
		matrix[i][j] = cost;
		matrix[j][i] = cost;
		cout << "Phone Line updated" << endl;
		return;

}

void Graph::Deleteline()
{
	bool present;
	int cost,i,j;
	string source,destination;
	char choice;

	cout<<"\nEnter 1st office \n";
	cin>>source;

	present=false;
	for(i=0;i<size;i++)
	{
		if(source==office[i])
		{
			present=true;
			break;
		}
	}
	if(!present)
	{
		cout<<"\nNo such office  with name "<<source<<"present"<<endl;
	}

	cout<<"\nEnter 2nd office \n";
	cin>>destination;
	present=false;
	for(j=0;j<size;j++)
	{
		if(destination==office[j])
		{
			present=true;
			break;
		}
	}
	if(!present)
	{
		cout<<"\nNo such office  with name "<<destination<<"present"<<endl;
	}

	matrix[i][j]=-1;
	matrix[j][i]=-1;
	cout<<"phone line Removed";
}
void Graph::prims()
{
	int result[size][size],visited[size],G[size][size];
	int min,u,v,i,j;
	for(int i=0;i<size;i++)
	{
		visited[i]=0;
		for(int j=0;j<size;j++)
		{
			if(matrix[i][j]==-1)
				G[i][j]=999;
			else
				G[i][j]=matrix[i][j];
			result[i][j]=0;
		}
	}

	visited[0]=1;
	for(int count=0;count<size-1;count++)
	{
		min=999;
		for( i=0;i<size;i++)
		{
			if(visited[i]==1)
			{
				for( j=0;j<size;j++)
				{
					if(visited[j]!=1)
					{
						if(min>G[i][j])
						{
							min=G[i][j];
							u=i;
							v=j;
						}
					}
				}

			}
		}
		visited[v]=1;
		result[u][v]=min;
		result[v][u]=min;
	}

	int sum=0;
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			cout<<" "<<result[i][j]<<"\t";
			sum+=result[i][j];
		}
		cout<<"\n";
	}

	cout<<"\nCost="<<sum<<endl;
}

void Graph::kruskal()
{
	int u,v,noofedges=1,min;
	int result[size][size],parent[size],G[size][size];
	for(int i=0;i<size;i++)
	{
		parent[i]=-1;
		for(int j=0;j<size;j++)
		{
			if(matrix[i][j]==-1)
				G[i][j]=999;
			else
				G[i][j]=matrix[i][j];
			result[i][j]=0;
		}
	}

	while(noofedges<size)
	{
		min=999;
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				if(min>G[i][j])
				{
					min=G[i][j];
					u=i;
					v=j;
				}
			}
		}

		int x=u;
		int y=v;
		G[u][v]=G[v][u]=999;
		int rt1,rt2;
		while(u>=0)
		{
			rt1=u;
			u=parent[u];
		}
		while(v>=0)
		{
			rt2=v;
			v=parent[v];
		}

		if(rt1!=rt2)
		{
			noofedges++;
			result[x][y]=min;
			result[y][x]=min;
			parent[rt2]=rt1;
		}
	}

	int sum=0;
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			cout<<" "<<result[i][j]<<"\t";
			sum+=result[i][j];
		}
		cout<<"\n";
	}

	cout<<"\nCost="<<sum<<endl;

}

int main()
{
	int size, choice, i, choice1;
	cout << "Enter Number of offices" << endl;
	cin >> size;
	Graph obj(size);
	obj.Addoffices();

	do {
		cout << "SELECT" << endl;
		cout << "1 : Add Phone Line\n2 : Remove Phone Line" << endl;
		cout << "3 : Calculate Minimum Cost\n0 : EXIT" << endl;
		cin >> choice;
		switch (choice) {
		case 1:
			obj.Addline();
			break;
		case 2:
			obj.Deleteline();
			break;
		case 3:
			cout << "1 : Prims Algorithm" << endl << "2 : Kruskals Algorihm"
					<< endl;
			cin >> choice1;
			if (1 == choice1)
				obj.prims();
			else if (2 == choice1)
				obj.kruskal();
			else
				cout << "****  Wrong Choice  ****" << endl;
			break;
		default:
			if (0 != choice)
				cout << "****  Wrong Choice  ****" << endl;
		}
	} while (0 != choice);

	return 0;
}

