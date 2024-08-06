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
class queue{
	public:
		Node* rear;
		Node* front;
		queue(){
			this->rear=NULL;
			this->front=NULL;
		}
		void enqueue(int val){
			if(rear==NULL && front==NULL){
				Node* temp=new Node;
				temp->data=val;
				rear=temp;
				front=temp;
			}
			else{
				Node* temp=new Node;
				temp->data=val;
				rear->next=temp;
				rear=temp;
			}
		}
		void pop(){
			if(rear==NULL && front==NULL){
				cout<<"Queue is empty "<<endl;
			}
			else{
				Node* temp;
				temp=front;
				front=temp->next;
				temp->next=NULL;
				delete temp;
			}
		}
		void print(){
			Node* temp;
			temp=front;
			while(temp!=NULL){
				cout<<temp->data<<" ";
				temp=temp->next;
			}
		}
};
int main(){
	queue q;
	q.enqueue(22);
	q.enqueue(23);
	q.enqueue(24);
	q.enqueue(25);
	q.pop();
	q.print();
}
