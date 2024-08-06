#include<iostream>
using namespace std;
// Insertion of stack with linked list
class Node{
	public:
		int data;
		Node* next;
		Node(){
			data=0;
		    this->next=NULL;
		}
		~Node(){
			int value=this->data;
			if(this->next != NULL){
				delete next;
		      this->next=NULL;
			}
		}
};
class stack{
	public:
		Node* top;
		stack(){
			this->top=NULL;
		}
	void push(int element){
	if(top==NULL){
		Node* temp=new Node;
		temp->data=element;
		temp->next=top;
		top=temp;
	}
		else{
		Node* temp=new Node;
		temp->data=element;
		temp->next=top;
		top=temp;
	}
    }
    void pop(){
	if(top==NULL){
		cout<<"Stack is Empty ";
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
		cout<<"Stack is empty "<<endl;
	}
	else{
		cout<<"Top value is "<<top->data<<endl;
	}
}
   void empty(){
	if(top==NULL){
		cout<<"Stack is empty ";
	}
	else{
		cout<<"Stack is not empty"<<endl;
	}
}
void size(){
	Node* temp=top;
	int count=0;
	while(temp != NULL){
		temp=temp->next;
		count++;
	}
	cout<<"The size of stack is "<<count<<endl;
}
   void print(){
	Node* temp=top;
	do{
		cout<<temp->data<<" ";
		temp=temp->next;
	}while(temp != NULL);
}
};
int main(){
	stack st;
	st.push(22);
	st.push(23);
	st.push(24);
	st.pop();
	st.peek();
	st.size();
	st.empty();
	st.print();
}
