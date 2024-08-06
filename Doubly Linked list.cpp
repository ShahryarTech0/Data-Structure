#include<iostream>
using namespace std;
class Node{
	public:
		int Data;
		Node* next;
		Node* prev;
	public:
		//Create a constructor
		Node(int value){
			this->Data=value;
			this->next=NULL;
			this->prev=NULL;
		}
		
};
void insertionAtTail(Node* &tail,int value){
	Node* temp=new Node(value);
	tail->next=temp;
	temp->prev=tail;
	tail=temp;
}
void insertionAtHead(Node* &head,int value){
	Node* temp=new Node(value);
	temp->next=head;
	head->prev=temp;
	head=temp;
}
void print(Node* &head){
	Node* temp;
	temp=head;
	while(temp != NULL){
		cout<<temp->Data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
void insertionAtPosition(Node* &head,Node* &tail,int position,int value){
	Node* temp=head;
	int count=1;
	if(position==1){
		insertionAtHead(head,value);
	}
	while(count < (position-1)){
	temp=temp->next;
	count++;	
	}
	Node* insertAtPosition=new Node(value);
	if(temp->next==NULL){
		insertionAtTail(tail,value);
	}
	insertAtPosition->next=temp->next;
	temp->next->prev=insertAtPosition;
	temp->next=insertAtPosition;
	insertAtPosition->prev=temp;

}
int main(){
	Node* Node1=new Node(10);
	Node* head=Node1;
	Node* tail=Node1;
	insertionAtHead(head,12);
	insertionAtHead(head,14);
	insertionAtPosition(head,tail,2,22);
//	insertionAtTail(tail,12);
//	insertionAtTail(tail,14);
	print(head);
}
