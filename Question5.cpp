#include<iostream>
#include<stack>
#include<string>
using namespace std;
//Checks the for conditions
bool BracketPair(char start,char ending)
{
	if(start == '(' && ending == ')') return true;
	else if(start == '[' && ending == ']') return true;
	else if(start == '{' && ending == '}') return true;
	return false;
}
//Checks the balance of three types of brackets
bool EqualityCheck(string stringExpression)
{
	stack<char>  CharactersInString;
	for(int b =0;b<stringExpression.length();b++)
	{
		if(stringExpression[b] == '(' || stringExpression[b] == '{' || stringExpression[b] == '[')
			CharactersInString.push(stringExpression[b]);
		else if(stringExpression[b] == ')' || stringExpression[b] == '}' || stringExpression[b] == ']'){
			if(CharactersInString.empty() || !BracketPair(CharactersInString.top(),stringExpression[b]))
				return false;
			else
				CharactersInString.pop();
		}
	}
	return CharactersInString.empty() ? true:false;
}

int main()
{
	string yourExpression;
	cout<<"Input your string expression to do the Equality check for brackets: "<<endl;
	cout<<"===================================================================="<<endl;
	cin>>yourExpression;
	if(EqualityCheck(yourExpression))
		cout<<"All The Parenthesis In This String are Organized";
	else
		cout<<"The Parenthesis are Unorganized, You Need to Edit it! ";
		
};	
