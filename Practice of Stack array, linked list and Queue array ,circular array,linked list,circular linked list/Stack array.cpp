#include<iostream>
using namespace std;
class stack{
	public:
		int *arr;
		int size;
		int top;
		stack(int size){
			this->size=size;
			arr=new int[size];
			top=-1;
		}
		void push(int element){
			if(top-size>1){
				cout<<"Stack is full"<<endl;
			}
			else{
				top++;
				arr[top]=element;
			}
		}
		void pop(){
			if(top==-1){
				cout<<"Stack is empty"<<endl;
			}
			else{
				arr[top]=-1;
				top--;
			}
		}
		void peek(){
			if(top==-1){
				cout<<"Stack is empty"<<endl;
			}
			else{
				cout<<"The top element is "<<arr[top]<<endl;
			}
		}
		bool empty(){
			if(top==-1){
				return true;
			}
			else{
				return false;
			}
		}
		void print(){
			while(top != -1){
				cout<<arr[top]<<" ";
				top--;
			}
		}
};
int main(){
	stack s(3);
	s.push(22);
	s.push(23);
	s.push(24);
	s.push(25);
	s.print();
}
