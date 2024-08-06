#include<iostream>
using namespace std;
class Node{
	public:
	int data;
	Node* next;
	Node(int value){
		data=value;
		next=NULL;
	}
	~Node(){
		int value=this->data;
		if(this->next!=NULL){
			delete next;
			this->next=NULL;
		}	
	}

};
void insertionNode(Node* &tail,int value,int element){
	Node* temp=new Node(value);
	if(tail==NULL){
		tail=temp;
		temp->next=tail;
	}
	else{
		Node* curr=tail;
		while(curr->data != element){
			curr=curr->next;
		}
		temp->next=curr->next;
		curr->next=temp;
	}
}
void deleteNode(Node* &tail,int element){
	if(tail==NULL){
		cout<<"List is empty ";
		return;
	}
	else{
		Node* prev=tail;
		Node* curr=prev->next;
		while(curr->data!=element){
			prev=curr;
			curr=curr->next;
		}
		if(tail==curr){
			tail=curr->next;
		}
	    prev->next=curr->next;
	    curr->next=NULL;
	    delete curr;
		
	}
	
}
void print(Node* &tail){
	Node* temp=tail;
	do{
		cout<<temp->data<<" ";
		temp=temp->next;
	}while(tail!=temp);
	cout<<endl;
	
}
int main(){
	Node* tail=NULL;
	insertionNode(tail,1,5);
	insertionNode(tail,2,1);
	deleteNode(tail,1);
	print(tail);
}
