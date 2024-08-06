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
			rear=-1;
			front=-1;
		}
		void push(int element){
			if((front==0 && rear==size-1) || (rear==(front-1)%(size-1))){
				cout<<"queue is full "<<endl;
			}
			else if(front==-1 && rear==-1){
				front=0;
				rear=0;
				arr[rear]=element;
			}
			else if(front != 0 && rear==size-1){
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
				cout<<"Queue is empty "<<endl;
			}
			else if(front==0){
				arr[front]=-1;
				rear=-1;
				front=-1;
			}
			else if(front==size-1){
				arr[front]=-1;
				front=0;
			}
			else{
				arr[front]=-1;
				front++;
			}
		}
};
int main(){
	queue q(4);
	q.push(22);
	q.push(23);
	q.push(24);
	q.pop();
	q.push(25);
	q.push(26);
	
}
