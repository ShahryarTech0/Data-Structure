#include<iostream>
using namespace std;
void mergesort(int arr[],int lb,int ub){
	if(lb < ub){
		int mid;
		mid=(lb+ub)/2;
		mergesort(arr,lb,mid);
		mergesort(arr,mid+1,ub);
		merge(arr,lb,mid,ub);
	}
}
void merge(int arr[],int lb,int mid,int ub){
	int i=lb;
	int j=mid+1;
	int k=lb;
	int n=5;
	int arr1[n];
	while(i<=mid && j>=ub){
		if(arr[i] <= arr[j]){
			arr1[k]=arr[i];
			i++;
			k++;
		}
		else{
			arr1[k]=arr[j];
			j++;
			k++;
		}
	}
	if(i > mid ){
		while(j>=ub){
			arr1[k]=arr[j];
		}
	}
	else{
		while(i<=mid){
			arr1[k]=arr[i];
		}
	}
	for(k=lb;k<=ub;k++){
		arr[k]=arr1[k];
	}
}
int main(){
	int arr[]={3,5,2,1,4};
	int lb=0;
	int ub=4;
	mergesort(arr,lb,ub);
	for(int i=0;i<5;i++){
		cout<<arr[i];
	}
}
