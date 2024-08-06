#include<iostream>
using namespace std;
int Partition(int arr[],int lb,int ub);
void quicksort(int arr[],int lb,int ub){
	int loc;
	if(lb <ub){
		loc=Partition(arr,lb,ub);
		quicksort(arr,lb,loc);
		quicksort(arr,loc+1,ub);
	}
}
int Partition(int arr[],int lb,int ub){
	int pivot=arr[lb];
	int start=lb;
	int end=ub;
	while(start < end){
		if(arr[start] <= pivot){
			start++;
		}
		if(arr[end] > pivot){
			end--;
		}
		if(start < end){
			swap(arr[start],arr[end]);
		}
	}
		swap(arr[end],arr[lb]);
		return end;
}
int main(){
	int arr[6]={5,3,1,0,4,2};
	int lb=0;
	int ub=5;
	quicksort(arr,lb,ub);
	for(int i=lb;i<=ub;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
