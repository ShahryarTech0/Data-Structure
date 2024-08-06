#include<iostream>
using namespace std;
class Node{
	public:
	int data;
	Node* next;
	Node* prev;
	Node(int value){
		data=value;
		next=NULL;
		prev=NULL;
	}
	~Node(){
		int value=this->data;
		if(this->next!=NULL){
			delete next;
			this->next=NULL;
		}
	}

};
void insertionAtHead(Node* &head,int value){
	Node* temp=new Node(value);
	temp->next=head;
	temp->next->prev=temp;
	head=temp;
}
void insertionAtTail(Node* &tail,int value){
	Node* temp=new Node(value);
	tail->next=temp;
	temp->prev=tail;
	tail=temp;
}
void print(Node* &head){
	Node* temp;
	temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
	
}
void insertionAtPosition(Node* &head,Node* &tail,int value,int position){
         Node* temp=head;
         if(position==1){
         	insertionAtHead(head,value);
         	return;
		 }
		 int count=1;
		 while(count < (position-1)){
		 	temp=temp->next;
		 	count++;
		 }
		 if(temp->next==NULL){
		 	insertionAtTail(tail,value);
		 	return;
		 }
		 Node* newinsertion=new Node(value);
		 newinsertion->next=temp->next;
		 temp->next->prev=newinsertion;
		 temp->next=newinsertion;
		 newinsertion->prev=temp;
}
void DeleteNode(Node* &head,int position){
	if(position==1){
		Node* temp=head;
		head=head->next;
		head->prev=NULL;
		temp->next=NULL;
		delete temp;
	}
	else{
		Node* curr=head;
		Node* prev=NULL;
		int count=1;
		while(count<(position)){
			prev=curr;
			curr=curr->next;
			count++;
		}
		prev->next=curr->next;
		curr->next->prev=prev;
		curr->prev=NULL;
		curr->next=NULL;
		delete curr;
	}
}
void swap(Node* &head,int position1,int position2){
	int count=1;
	Node* prev=head;
	Node* curr=prev->next;
	while(count < (position2-1)){
		prev=curr;
		curr=curr->next;
	}
	prev->prev->data=curr->data;
	curr->data=prev->prev->data;
	prev->prev=curr->next;
	curr->next=prev->prev;
	curr->next=prev;
	prev->next=curr;

}
int main(){
	Node* Node1=new Node(5);
	Node* head=Node1;
	Node* tail=Node1;
	insertionAtHead(head,4);
	insertionAtHead(head,3);
	insertionAtHead(head,2);
	insertionAtHead(head,1);
//	insertionAtTail(tail,2);
//	insertionAtPosition(head,tail,3,3);
//	DeleteNode(head,3);
//	swap(head,2,4);
	print(head);
}
