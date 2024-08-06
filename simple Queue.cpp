#include<iostream>
#include<queue>
using namespace std;
int main(){
	//Simple stack 
	queue<int> q;
	q.push(22);
	q.push(23);
	q.push(24);
	q.pop();
	cout<<"The size of Queue: "<<q.size()<<endl;
	cout<<"top element is: "<<q.front()<<endl;
	if(q.empty()){
		cout<<"Queue is empty: ";
	}
	else{
		cout<<"Queue is not empty: ";
	}
}
