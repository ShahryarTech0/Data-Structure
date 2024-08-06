#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node* next;
		Node(){
			data=0;
			this->next=NULL;
		}
};
class stack{
	public:
		Node* top;
		stack(){
			this->top=NULL;
		}
		void push(int val){
			Node* temp=new Node;
			temp->data=val;
			if(top==NULL){
			temp->next=top;
			top=temp;	
			}
			else{
				temp->next=top;
				top=temp;
			}
		}
		void pop(){
			if(top==NULL){
				cout<<"Stack is full "<<endl;
			}
			else{
				Node* temp;
				temp=top;
				top=temp->next;
				temp->next=NULL;
				delete temp;
			}
		}
		void peek(){
			if(top==NULL){
				cout<<"Stack is full "<<endl;
			}
			else{
				cout<<"The peek element is "<<top->data<<endl;
			}
		}
		void print(){
			Node* temp;
			temp=top;
			while(temp!=NULL){
				cout<<temp->data<<" ";
				temp=temp->next;
			}
		}
};
int main(){
	stack s;
	s.push(22);
	s.push(23);
	s.push(24);
	s.push(25);
	s.pop();
	s.peek();
	s.print();
}
