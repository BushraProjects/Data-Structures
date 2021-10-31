#include <bits/stdc++.h>
#include <iostream>
using namespace std;
//Question 4:
class Modification_queue 
{
	public:
	int A[10];
	int rEaR=1;
	int froNT=0;
	void enque_value_method(int value)
	{
		froNT++;
		A[froNT]=value;
		cout<<"ENQUE ("<<value<<")"<<endl;
	}
	int deque_value_method()
	{	
		int a = A[rEaR];
		if (froNT == 0) {
			cout<<endl<<"The Que is NULL"<<endl;
			return 0;
		}
		else {
			int value = A[rEaR];
			cout<<"DEQUE ("<<value<<")"<<endl;
			rEaR++;
		}
		return a; }
	void display_values_method()
	{
		int x;
		if (froNT == 0) {
			cout<<endl<<"The Que is NULL"<<endl;
			return;
		}

		for (x = rEaR; x <= froNT; x++) {
			cout<<A[x]<<"\t";
		}
		cout<<endl;
	}

	int froNTValue()
	{
		if (froNT == 0) {
			cout<<endl<<"The Que is NULL"<<endl;
			return 0;
		}

		return A[froNT];
	}
};
int main(void)
{
	
		Modification_queue Queue;
		Queue.enque_value_method(9);
		Queue.enque_value_method(2);
		cout<<"Step Two: "<<endl;
		Queue.display_values_method();
		cout<<endl;
		Queue.enque_value_method(-2);
		Queue.enque_value_method(-82);
		cout<<"Step Four: "<<endl;
		Queue.display_values_method();
		cout<<endl;
		int t1 = Queue.froNTValue();
		Queue.enque_value_method(-6);
		cout<<"Step Six: "<<endl;
		Queue.display_values_method();
		cout<<endl;
		int t3 = Queue.deque_value_method();
		Queue.enque_value_method(14);
		cout<<"Step Eight: "<<endl;
		Queue.display_values_method();
		cout<<endl;
		int t2 = Queue.deque_value_method();
		Queue.enque_value_method(3);
		Queue.display_values_method();
		
		Queue.deque_value_method();
		Queue.deque_value_method();
		Queue.display_values_method();
		
		cout<<"t1 : "<<t1<<"  t2 : "<<t2<<"  t3 : "<<t3;
	return 0;
}

