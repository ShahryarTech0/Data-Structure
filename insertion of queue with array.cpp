#include<iostream>
using namespace std;

//         Insertion of Queue with array
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
		void push(int value){
			if(rear==size){
				cout<<"Queue is Full "<<endl;
			}
			else{
				arr[rear]=value;
				rear++;
			}
		}
		void pop(){
			if(front==rear){
				cout<<"Queue is empty ";
			}
			else{
				arr[front]=-1;
				front++;
				if(front==rear){
					rear=0;
					front=0;
				}
			}
		}
		void top(){
			if(front==rear){
				cout<<"Queue is empty";
			}
			else{
				cout<<"Front element is "<<arr[front]<<endl;
			}
		}
		void empty(){
			if(rear==front){
				cout<<"Queue is empty"<<endl;
			}
			else{
				cout<<"Queue is not empty"<<endl;
			}
		}
};
int main(){
	queue q(3);
	q.push(22);
	q.push(23);
	q.push(24);
	q.top();
	q.empty();
}
