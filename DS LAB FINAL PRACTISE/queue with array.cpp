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
			front=0;
			rear=0;
		}
		void push(int val){
			if(rear==size){
				cout<<"Queue is full"<<endl;
			}
			else{
				arr[rear]=val;
				rear++;
			}
		}
		void pop(){
			if(front==0 && rear==0){
				cout<<"Queue is empty "<<endl;
			}
			else{
				arr[front]=-1;
				front++;
				if(rear==front){
					rear=0;
					front=0;
				}
			}
			
		}
		void peek(){
			if(front==0 && rear==0){
				cout<<"Queue is empty "<<endl;
			}
			else{
				cout<<"Peek element is "<<arr[front]<<endl;
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
	queue q(4);
	q.push(22);
	q.push(23);
	q.push(24);
	q.push(25);
	q.pop();
	q.peek();
	q.print();
}
