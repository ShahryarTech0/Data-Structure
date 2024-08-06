#include<iostream>
using namespace std;
class queue{
	public:
		int* arr;
		int size;
		int rear;
		int front;
		queue(int size){
			this->size=size;
			arr=new int[size];
			rear=-1;
			front=-1;
		}
		void enqueue(int val){
			if(front==0 && rear==size-1 || rear==(front-1)%(size-1)){
				cout<<"Queue is full "<<endl;
			}
			else if(front==-1 && rear==-1){
				front=0;
				rear=0;
				arr[rear]=val;
			}
			else if(front!=0 && rear==size-1){
				rear=0;
				arr[rear]=val;
			}
			else{
				rear++;
				arr[rear]=val;
			}
		}
		void dequeue(){
			if(front==-1 && rear==-1){
				cout<<"Queue is empty "<<endl;
			}
			else if(front==0&&rear==0){
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
		void print(){
			for(int i=0;i<size;i++){
				cout<<arr[i]<<" ";
			}
			cout<<endl;
		}
};
int main(){
	queue q(3);
	q.enqueue(22);
	q.enqueue(23);
	q.enqueue(24);
	q.dequeue();
	q.print();
}
