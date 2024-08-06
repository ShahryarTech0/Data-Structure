#include<iostream>
using namespace std;
class Node{
	public :
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
		queue(){
			this->rear=NULL;
			this->front=NULL;
		}
		void enqueue(int element){
			Node* temp=new Node;
			temp->data=element;
			if(front==NULL && rear==NULL){
				rear=temp;
				front=temp;
			}
			else{
				rear->next=temp;
				rear=temp;
			}
		}
		void dequeue(){
			Node* temp=front;
			if(front==NUll && rear==NULL){
				cout<<"Queue is empty "<<endl;
			}
			else{
				front=front->next;
				temp->next=NULL;
				delete temp;
			}
		}
};
