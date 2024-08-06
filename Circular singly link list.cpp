#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node* next;
	public:
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
insertToNode(Node* &tail,int element,int value){
	//When tail is empty
	if(tail==NULL){
		Node* temp=new Node(value);
		tail=temp;
		temp->next=temp;
	}
	else{
		Node* curr=tail;
		while(curr->data != element){
			curr=curr->next;
		}
		Node* temp=new Node(value);
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
		tail=tail->next;
	}while(tail != temp);
	cout<<endl;
}
int main(){
	Node* tail=NULL;
	insertToNode(tail,5,3);
	insertToNode(tail,3,6);
	deleteNode(tail,6);
	print(tail);
}
