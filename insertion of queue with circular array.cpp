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
		void enqueue(int value){
			if((front==0 && rear==(size-1)) || (rear==(front-1)%(size-1))){
				cout<<"Queue is Full "<<endl;
			}
			else if(front==-1 && rear==-1){
				rear=0;
				front=0;
				arr[rear]=value;
			}
			else if(front != 0 && rear==size-1 ){
				rear=0;
				arr[rear]=value;
				cout<<arr[rear];
			}
			else{
				rear++;
				arr[rear]=value;
			}
		}
		void dequeue(){
			if(front==-	1){
				cout<<"Queue is empty ";
			}
			else if(front==rear){
				arr[front]=-1;
				front=-1;
				rear=-1;
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
	queue q(5);
	q.enqueue(22);
	q.enqueue(23);
	q.enqueue(24);
	q.enqueue(25);
	q.enqueue(26);
	q.dequeue();
	q.enqueue(27);
	
	
}
