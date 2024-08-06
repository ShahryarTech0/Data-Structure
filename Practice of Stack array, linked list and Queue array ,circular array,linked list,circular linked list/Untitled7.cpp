#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node* next;
		Node(){
			data=0;
			next=NULL;
		}
};
class stack{
	public:
		Node* top;
		stack(){
			this->top=NULL;
		}
		void push(int element){
			Node* temp=new Node;
			temp->data=element;
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
			Node* temp=top;
			if(top==NULL){
				cout<<"Stack is empty ";
			}
			else{
				top=top->next;
				delete temp;
			}
		}
};
int main(){
	
}
