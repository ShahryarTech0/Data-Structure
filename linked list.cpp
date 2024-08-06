#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node* next;
	public:
		//constructor
		Node(int value){
			data=value;
			next=NULL;
		}
		~Node(){
			int value=this->data;
			if(this->next != NULL){
				delete next;
				this->next=NULL;
			}
		}
};

void insertionAtTail(Node* &tail,int value){
	Node* temp=new Node(value);
	tail->next=temp;
	tail=temp;
}
void insertionAtHead(Node* &head,int value){
	Node* temp=new Node(value);
	temp->next=head;
	head=temp;
}
void print(Node* &head){
	Node* temp;
	temp=head;
	while(temp != NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
void insertionAtPosition(Node* &head,Node* &tail,int position,int value){
	Node* temp=head;
	int count=1;
	while(count < (position-1)){
		temp=temp->next;
		count++;
	}
	Node* insertAtPosition=new Node(value);
	insertAtPosition->next=temp->next;
	temp->next=insertAtPosition;
	if(position==1){
		insertionAtHead(head,value);
	}
	if(temp->next==NULL){
		temp->next=insertAtPosition;
		tail=insertAtPosition;
	}
}
void DeleteNode(Node* &head,int position){
	if(position==1){
		Node* temp=head;
		head=head->next;
		temp->next=NULL;
		delete temp;
	}
	else{
	int count=1;
	Node* curr=head;
	Node* prev=NULL;
	while(count < position){
		prev=curr;
		curr=curr->next;
		count++;
	}
	prev->next=curr->next;
	curr->next=NULL;
	delete curr;
}
	
}
int main(){
	Node* Node1=new Node(10);
	Node* head=Node1;
	Node* tail=Node1;
	insertionAtTail(tail,11);
	insertionAtTail(tail,11);
	insertionAtTail(tail,14);
//	insertionAtPosition(head,tail,1,22);
//	insertionAtHead(head,12);
//	insertionAtHead(head,14);
	print(head);
//	DeleteNode(head,11);
	print(head);
}
