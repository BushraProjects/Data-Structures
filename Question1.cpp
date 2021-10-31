#include<iostream>
using namespace std;
struct noD
{
    int insides;
    struct noD* next;
};

struct noD* head=NULL;
//Main Class of making Circular Linked List

class circular_linkedList
{
public:
	//Inserstion method for section a) of Q1
    void node_insertion(int value)
    {
        struct noD* temporary_node = new noD();
        temporary_node->insides = value;
        temporary_node->next = NULL;
        if(head == NULL)
        {
            head = temporary_node;
        }
        else
        {
            struct noD* second_temporary_node = head;
            while(second_temporary_node->next != NULL)
            {
                second_temporary_node = second_temporary_node->next;
            }
            second_temporary_node->next = temporary_node;
        }
    }
	//Making Circular Linked list method:
    void make_circular_linkedList()
    {
        struct noD* temporary_node = head;
        while(temporary_node->next != NULL)
        {
            temporary_node = temporary_node->next;
        }
        temporary_node->next = head;
    }
	//Delete method for section b) of Q1
	void node_deletion(int input)
    {
        struct noD* temporary_node = head;
        struct noD* last_one = temporary_node;
        bool warning = false;
        while(temporary_node->next != head)
        {
        	if(temporary_node->insides == input){
        		warning = true;
        		break;
			}
        	last_one = temporary_node;
            temporary_node = temporary_node->next;
        
        }   
        struct noD* next=temporary_node->next;
        delete temporary_node;
        last_one->next = next;
        if(warning == false){
		cout<<endl<<"The value you are searching for does not exist. Sorry!!!"<<endl;
	}
    }
	//Method for Making the Node Null:
	void making_node_null()
    {
        struct noD* temporary_node = head;
        while(temporary_node->next != head)
        {
            temporary_node = temporary_node->next;
        }
        temporary_node->next = NULL;
    }
	//Method For Traversing the list for c) of Q1:
    void traversing_nodes()
    {
        noD* temporary_node = head;
        cout << temporary_node->insides << " ";
        temporary_node = temporary_node->next;
        while(temporary_node != head)
        {
            cout << temporary_node->insides << " ";
            temporary_node = temporary_node->next;
        }
        cout<<endl;
    }
};
//Main method to run the codes and test the results:
int main()
{
    circular_linkedList question_one;
    question_one.node_insertion(999);
    question_one.node_insertion(888);
    question_one.node_insertion(777);
    question_one.node_insertion(666);
    question_one.node_insertion(555);
    question_one.node_insertion(444);
    question_one.node_insertion(333);
    question_one.make_circular_linkedList();
    
    //Preview of inserted values in linked list:
    cout<<endl<<"Linked List Preview:"<<endl;
    question_one.traversing_nodes();
    
    //Insertion of 2 additional values at the end:
    cout<<endl<<"When I Insert The Values of 222 and 111"<<endl;
    question_one.making_node_null();
    question_one.node_insertion(222);
    question_one.node_insertion(111);
    question_one.make_circular_linkedList();
    question_one.traversing_nodes();
    
    //Deleting the value 777 from the list:
    cout<<endl<<"When I try to Delete 777:"<<endl;
    question_one.node_deletion(777);
    question_one.traversing_nodes();
    
    //Checking the method of deletion:
    cout<<endl<<"When I try to Delete Something that Doesn't exit in list: 1001"<<endl;
    question_one.node_deletion(1001);
    return 0;
}
