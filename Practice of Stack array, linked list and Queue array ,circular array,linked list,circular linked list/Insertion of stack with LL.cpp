#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node* next;
		Node(){
			next=NULL;
			data=0;
		}
};
class stack{
	public:
		Node* top;
		stack(){
			top=NULL;
		}
		void push(int element){
			if(top==NULL){
				Node* temp=new Node;
				temp->data=element;
				temp->next=top;
				top=temp;
			}
			else{
				Node* temp=new Node;
				temp->data=element;
				temp->next=top;
				top=temp;
			}
		}
		void pop(){
			if(top==NULL){
				cout<<"Stack is empty";
			}
			else{
			Node* temp=top;
			top=top->next;
			temp->next=NULL;
			delete temp;
		}
	}
	void print(){
		Node* temp=top;
		while(temp != NULL){
			cout<<temp->data<<" ";
			temp=temp->next;
		}
	}
	void peek(){
		if(top==NULL){
			cout<<"Stack is empty ";
		}
		else{
			cout<<"Peek element is "<<top->data<<endl;
		}
	}
};
int main(){
	stack s;
	s.push(22);
	s.push(23);
	s.push(24);
	s.pop();
	s.peek();
	s.print();
}
