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
class queue{
	public:
		Node* rear;
		Node* front;
		Node* prev;
		Node* curr;
		queue(){
			this->rear=NULL;
			this->front=NULL;
			this->prev=NULL;
			this->curr=NULL;
		}
		void push(int element){
			Node* temp=new Node;
			temp->data=element;
			if(rear==NULL && front==NULL){
				rear=temp;
				front=temp;
				temp->next=front;
			}
			else{
				rear->next=temp;
				temp->next=front;
				rear=temp;
			}
		}
		void pop(){
			Node* temp=front;
			if(rear==NULL && front==NULL){
				cout<<"Queue is empty ";
			}
			else{
				front=temp->next;
				temp->next=NULL;
				delete temp;
			}
		}
		void print(){
			Node* temp=front;
			do{
				cout<<temp->data;
				temp=temp->next;
			}
		    while(temp!=front);
		}
};
int main(){
	queue q;
	q.push(22);
	q.push(23);
	q.push(24);
	q.pop();
	q.print();
           }
	

