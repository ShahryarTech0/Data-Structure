#include<iostream>
#include<stack>
using namespace std;
int main(){
	//Simple stack 
	stack<int> s;
	s.push(22);
	s.push(23);
	s.push(24);
	s.pop();
	cout<<"The size of stack: "<<s.size()<<endl;
	cout<<"top element is: "<<s.top()<<endl;
	if(s.empty()){
		cout<<"stack is empty: ";
	}
	else{
		cout<<"Stack is not empty: ";
	}
}
