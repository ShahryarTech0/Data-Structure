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
		void push(int value){
			if(size-top > 1){
				top++;
				arr[top]=value;
			}
			else{
				cout<<"Stack is overflow";
			}
		}
		void pop(){
			if(top>=1){
				top--;
			}
			else{
				cout<<"Stack is underflow ";
			}
		}
		int peek(){
			if(top>=1){
				return arr[top];
			}
			else{
				return -1;
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
		
};
int main(){
	stack s(3);
	s.push(22);
	s.push(23);
	s.push(24);
	s.pop();
	cout<<"Top value is: "<<s.peek()<<endl;
	if(s.empty()){
		cout<<"Stack is empty ";
	}
	else{
		cout<<"Stack is not empty ";
	}
}
