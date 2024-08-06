#include<iostream>
using namespace std;
class heap{
	public:
		int arr[100];
		int size;
		heap(){
			arr[0]=-1;
			size=0;
		}
		void insert(int val){
			size=size+1;
			int index=size;
			arr[index]=size;
			while(index>1){
				int parent=index/2;
				if(arr[parent]<arr[index]){
					swap(arr[parent],arr[index]);
					index=parent;
				}
				else{
					return;
				}
			}
		}
			void deletefromheap(){
				if(size==0){
					cout<<"Nothing is present "<<endl;
				}
				swap(arr[1],arr[size]);
				size--;
				int i=1;
				while(i<size){
					int leftchild=2*i;
					int rightchild=2*i+1;
					if(leftchild<=size && arr[i]<arr[leftchild]){
						swap(arr[i],arr[leftchild]);
						i=leftchild;
					}
					if(rightchild<=size && arr[i]<arr[rightchild]){
						swap(arr[i],arr[rightchild]);
						i=rightchild;
					}
					else{
						return;
					}
				}
			}
			void print(){
				for(int i=1;i<=size;i++){
					cout<<arr[i]<<" ";
				}
				cout<<endl;
			}
};
void heapify(int arr[],int size,int i){
	int largest=i;
	int left=2*i;
	int right=2*i+1;
	if(left<=size && arr[largest]<arr[left]){
		largest=left;
	}
	if(right<=size && arr[largest]<arr[right]){
		largest=right;
	}
	if(largest!=i){
		swap(arr[largest],arr[i]);
		heapify(arr,size,largest);
	}
}
void heapsort(int arr[],int size){
	int t=size;
	while(t>1){
		swap(arr[t],arr[1]);
		t--;
		heapify(arr,t,1);
	}
}
int main(){
	heap h;
	h.insert(50);
	h.insert(55);
	h.insert(53);
	h.insert(52);
	h.insert(54);
	cout<<"After insertion: ";
	h.print();
	cout<<"After Deletion: ";
	h.deletefromheap();
	h.print();
	int arr[6]={-1,2,3,4,6};
	int size=4;
	for(int i=size/2;i>0;i--){
		heapify(arr,size,i);
	}
	cout<<"After the heapify the array is converted into heap "<<endl;
	for(int i=1;i<=size;i++){
		cout<<arr[i]<<" ";
	}cout<<endl;
	heapsort(arr,size);
	cout<<"After the Sorting: ";
	for(int i=1;i<=size;i++){
		cout<<arr[i]<<" ";
	}cout<<endl;
}
