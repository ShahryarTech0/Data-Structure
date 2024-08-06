#include<iostream>
using namespace std;
int Partition(int arr[],int lb,int ub);
void Quicksort(int arr[],int lb,int ub){
	if(lb < ub){
		int loc;
		loc= Partition(arr,lb,ub);
		Quicksort(arr,lb,loc-1);
		Quicksort(arr,loc+1,ub);
	}
}
int Partition(int arr[],int lb,int ub){
	int pivot=arr[lb];
	int start=lb;
	int end=ub;
	while(start < end){
		while(arr[start] <= pivot){
			start++;
		}
		while(arr[end] > pivot){
			end--;
		}
		if(start < end){
			swap(arr[start],arr[end]);
		}
	}
		swap(arr[lb],arr[end]);
		return end;
	
}
int main(){
	int arr[]={3,1,2,4,6,5};
	int lb=0;
	int ub=5;
	Quicksort(arr,lb,ub);
	for(int i=0;i<6;i++){
		cout<<arr[i];
	}
}
