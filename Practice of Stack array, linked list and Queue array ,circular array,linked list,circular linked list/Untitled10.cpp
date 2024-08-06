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
			if(top > size-1){
				cout<<"stack is full "<<endl;
			}
			else{
				top++;
				arr[top]=element;
			}
		}
		void pop(){
			if(top==-1){
				cout<<"Stack is empty ";
			}
			else{
				arr[top]=-1;
				top--;
			}
		}
};
