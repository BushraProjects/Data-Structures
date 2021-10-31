#include <bits/stdc++.h>
using namespace std;

class noD
{
	public:
	int nodeData;
	noD* nextOne;
	noD* previousOne;
};
noD* head = NULL;

//We First Need to Insert Some Values To Do The Operations
void node_insertion_at_end(int newOne)
{
	noD** headR = &head;
	noD* newNode = new noD();
	newNode->nodeData = newOne;
	
	noD* lastOne = *headR;
	newNode->nextOne = NULL;
	
	if (*headR == NULL)
	{
		newNode->previousOne = NULL;
		*headR = newNode;
		return;
	}

	while (lastOne->nextOne != NULL)
		lastOne = lastOne->nextOne;

	lastOne->nextOne = newNode;
	newNode->previousOne = lastOne;
}
//Method For Viewing or Printing All the List:
void nodes_traversing()
{
	noD* nodd = head;
	noD* lastOne;
	cout<<endl<<"Nodes Traversal in the Forward Direction Preview:"<<endl;
	
	while (nodd != NULL)
	{
		cout<<" "<<nodd->nodeData<<" ";
		lastOne = nodd;
		nodd = nodd->nextOne;
	}
	
	cout<<endl<<"Nodes Traversal in the Reversed Direction Preview:"<<endl;
	while (lastOne != NULL)
	{
		cout<<" "<<lastOne->nodeData<<" ";
		lastOne = lastOne->previousOne;
	}
}
//Method For Searching Nodes
void node_Searching(int inside_value)
{
	noD* nodd = head;
	int node_location=1;
	bool not_there = false;
	while (nodd != NULL)
	{
		if(nodd->nodeData == inside_value){
		
			cout<<endl<<"Your inserted value is in element location: "<<node_location<<endl;
			not_there = true;
			break;
		}
		else if(nodd->nodeData != inside_value){
			nodd = nodd->nextOne;
			node_location++;
		}
		
	}
	if(not_there == false){
		
		cout<<endl<<"Intended values not Found."<<endl;
	}
	
}
//Method For Sorting
void nodes_bubble_sort_method()
{
    int node_swap, x;
    noD* node_pointerToNext;
    noD* lastOne = NULL;
  
    if (head == NULL)
        return;
    do
    {
        node_swap = 0;
        node_pointerToNext = head;
        while (node_pointerToNext->nextOne != lastOne)
        {
            if (node_pointerToNext->nodeData > node_pointerToNext->nextOne->nodeData)
            {
                swap(node_pointerToNext->nodeData, node_pointerToNext->nextOne->nodeData);
                node_swap = 1;
            }
            node_pointerToNext = node_pointerToNext->nextOne;
        }
        lastOne = node_pointerToNext;
    }
    while (node_swap);
}


//main method to input values and text all the methods:

int main()
{
	//Value Insertion:
	node_insertion_at_end(1023);
	node_insertion_at_end(1050);
	node_insertion_at_end(1070);
	node_insertion_at_end(1011);
	node_insertion_at_end(1001);

	nodes_traversing();
	cout<<endl<<endl<<"---------------After Sorting: -----------------"<<endl<<endl;
	//Sorts the values then print:
	nodes_bubble_sort_method();
	nodes_traversing();
	//Searching For both existing and non existing values:
	cout<<endl<<endl<<"---------------Searching Values: -----------------"<<endl<<endl;
	node_Searching(1001);
	node_Searching(1000);
}
