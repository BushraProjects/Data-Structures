#include <bits/stdc++.h>
using namespace std;
struct noD
{
	int insides;
	struct noD* node_address;
};
struct noD* tOP;
void push_Method(int insides)
{
	struct noD* temporary_node;
	temporary_node = new noD();

	if (!temporary_node)
	{
		cout << "------Stack Overflow-----";
		exit(1);
	}
	temporary_node->insides = insides;
	temporary_node->node_address = tOP;
	tOP = temporary_node;
	cout<<"push ("<<temporary_node->insides<<")"<<endl;
}
int pop_method()
{
	struct noD* temporary_node;
	if (tOP == NULL)
	{
		cout << "--------Stack Empty---------" << endl;
		exit(1);
	}
	else
	{
		temporary_node = tOP;
		tOP = tOP->node_address;
		temporary_node->node_address = NULL;
		cout<<"pop ("<<temporary_node->insides<<")"<<endl;
		return tOP->insides;
	}
}
void display_Method()
{
	struct noD* temporary_node;
		temporary_node = tOP;
		while (temporary_node != NULL)
		{
			cout<< temporary_node->insides << " ";
			
			temporary_node = temporary_node->node_address;
		}
		cout<<endl; }
int Empty_Check()
{
    return tOP == NULL;
}
int Value_of_Top()
{
    if (!Empty_Check())
        return tOP->insides;
    else
        exit(1);       
}
int main()
{
	push_Method(12);
	push_Method(-15);
	cout<<"After Second Step: ";
	display_Method();
	cout<<endl;
	
	pop_method();
	push_Method(-2);
	cout<<"After Fourth Step:  ";
	display_Method();
	cout<<endl;
	
	push_Method(-234);
	int t1 = pop_method();
	cout<<"After Sixth Step:  ";
	display_Method();
	cout<<endl;
	
	int t3 = pop_method();
	push_Method(-8);
	cout<<"After Eighth Step:  ";
	display_Method();
	cout<<endl;
	
	push_Method(20);
	int t2 = Value_of_Top();
	pop_method();
	push_Method(4);
	cout<<"Finally:  ";
	display_Method();
	cout<<endl;
	
	cout<<"t1 : "<<t1<<"  t2 : "<<t2<<"  t3 : "<<t3;

	return 0;
}

