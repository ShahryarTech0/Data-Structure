#include<iostream>
using namespace std;
class stack{
	public:
		int* arr;
		int size;
		int top;
		stack(int size){
			this->size=size;
			arr=new int[size];
			top=-1;
		}
		void push(int val){
			if(size-top>1){
				top++;
				arr[top]=val;
			}
			else{
				cout<<"Stack is full "<<endl;
			}
		}
		void pop(){
			if(top==-1){
				cout<<"Stack is empty "<<endl;
			}
			else{
				arr[top]=-1;
				top--;
			}
		}
		void peek(){
			if(top==-1){
				cout<<"Stack is empty "<<endl;
			}
			else{
				cout<<"The peek element is "<<arr[top]<<endl;
			}
		}
		void print(){
			for(int i=0;i<size;i++){
				cout<<arr[i]<<" ";
			}
			cout<<endl;
		}
};
int main(){
	stack s(3);
	s.push(22);
	s.push(23);
	s.push(25);
	s.pop();
	s.peek();
	s.print();
}
