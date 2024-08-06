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
			front=0;
			rear=0;
		}
		void push(int element){
			if(rear==size){
				cout<<"Queue is full";
			}
			else{
				arr[rear]=element;
				rear++;
			}
		}
		void pop(){
			if(front==rear==0){
				cout<<"Queue is empty "<<endl;
			}
			else{
				arr[front]=-1;
				front++;
				if(rear==front){
					rear=0;
					font=0;
				}
			}
		}
};
