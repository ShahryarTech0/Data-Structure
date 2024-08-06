#include<iostream>
using namespace std;
class queue{
	public:
		int *arr;
		int size;
		int front;
		int rear;
		queue(int size){
			this->size=size;
			arr=new int[size];
			front=-1;
			rear=-1;
		}
		void push(int element){
			if(front==0 && rear=size-1){
				cout<<"queue is full ";
			}
			else if(front==rear==-1){
				rear=0;front=0;
				arr[rear]=element;
			}
			else if(front !=0 && rear=size-1){
				rear=0;
				arr[rear]=element;
			}
			else{
				rear++;
				arr[rear]=element;
			}
		}
		void pop(){
			if(front==rear==-1){
				
			}
			else if(front==0){
				arr[front]=-1;
				front=-1;
				rear=-1;
			}
			else if(front=size-1){
				arr[front]=-1;
				front=0;
			}
			else{
				arr[front]=-1;
				front++;
			}
		}
};

