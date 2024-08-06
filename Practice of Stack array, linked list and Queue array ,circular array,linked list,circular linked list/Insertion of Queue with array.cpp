#include<iostream>
using namespace std;
class queue{
	public:
		int *arr;
		int size;
		int rear;
		int front;
		queue(int size){
			this->size=size;
			arr=new int[size];
			rear=0;
			front=0;
		}
		void push(int element){
			if(rear==size){
				cout<<"Queue is full"<<endl;
			}
			else{
				arr[rear]=element;
				rear++;
			}
		}
		void pop(){
			if(front==rear){
				cout<<"Queue is empty "<<endl;
			}
			else{
				arr[front]=-1;
				front++;
			}
		}
		void print(){
		 while(front != size){
		 	cout<<arr[front]<<" ";
		 	front++;
		 }	
		}
	
};

int main(){
	queue q(3);
	q.push(22);
	q.push(23);
	q.push(24);
	q.print();
	
}
