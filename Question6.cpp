#include<iostream>
#include <list>
using namespace std;
//-------------------class---------------
class graphDirected
{
	int value_element;
	list<int> *adjaCent; 
public:
	graphDirected(int value_element); 
	void add_value_element(int a, int b); 
	bool con_check(int c, int d);
};
//----------------method-------------------
graphDirected::graphDirected(int value_element)
{
	this->value_element = value_element;
	adjaCent = new list<int>[value_element];
}
//------------------For Adding Value----------
void graphDirected::add_value_element(int a, int b)
{
	adjaCent[a].push_back(b); 
}
//------------------For Checking connection---------
bool graphDirected::con_check(int c, int d)
{
	if (c == d)
	return true;
	bool *nodeVisited = new bool[value_element];
	for (int i = 0; i < value_element; i++){
		nodeVisited[i] = false;
	}	

	list<int> Quoo;
	nodeVisited[c] = true;
	Quoo.push_back(c);

	list<int>::iterator i;

	while (!Quoo.empty())
	{
		c = Quoo.front();
		Quoo.pop_front();
		for (i = adjaCent[c].begin(); i != adjaCent[c].end(); ++i)
		{
			if (*i == d)
				return true;
			if (!nodeVisited[*i])
			{
				nodeVisited[*i] = true;
				Quoo.push_back(*i);
			}
		}
	}
	return false;
}
//---------------Main method to test and run the codes----------
int main()
{
	graphDirected graph_DirecteD(10);
	graph_DirecteD.add_value_element(9, 6);
	graph_DirecteD.add_value_element(6, 3);
	graph_DirecteD.add_value_element(3, 1);
	graph_DirecteD.add_value_element(1, 6);
	graph_DirecteD.add_value_element(1, 4);

	int first = 9, second = 4;
	if(graph_DirecteD.con_check(first, second))
		cout<<endl<< "Path Exists from " << first << " --> " << second;
	else
		cout<<endl<< "Path doesn't Exist from " << first << " --> " << second;
	
	return 0;
}

