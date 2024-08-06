#include<iostream>
using namespace std;
int Partition(int arr[],int lb,int ub);
void quicksort(int arr[],int lb,int ub){
	if(lb < ub){
		int loc;
		loc=Partition(arr,lb,ub);
		quicksort(arr,lb,loc-1);
		quicksort(arr,loc+1,ub);
	}
}
int Partition(int arr[],int lb,int ub){
	int pivot=arr[0];
	int start=lb;
	int end=ub;
	while ( start < end){
		while(arr[start]<=pivot){
			start++;
		}
		while(arr[end]>pivot){
			end--;
		}
		if(start < end){
			swap(arr[start],arr[end]);
		}
	}
	if(start > end){
		swap(arr[0],arr[end]);
		return end;
	}
}
int main(){
	int arr[]={3,5,2,1,4};
	int lb=0;
	int ub=4;
	quicksort(arr,lb,ub);
	for(int i=0;i<5;i++){
		cout<<arr[i];
	}
}
