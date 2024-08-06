#include<iostream>
using namespace std;
void merge(int arr[],int lb,int mid,int ub);
void mergesort(int arr[],int lb,int ub){
	int mid;
	if( lb < ub){
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
	int newarr[6];
	while(i <= mid && j <= ub){
		if(arr[i] <= arr[j]){
			newarr[k]=arr[i];
			i++;
			k++;
		}
		else{
			newarr[k]=arr[j];
			k++;
			j++;
		}
	}
	if( i > mid ){
		while(j <= ub){
			newarr[k]=arr[j];
			k++;
			j++;
		}
	}
	else{
		while( i <= mid){
			newarr[k]=arr[i];
			k++;
			i++;
		}
	}
	for(k=lb;k<=ub;k++){
		arr[k]=newarr[k];
	}
}
int main(){
	int arr[]={3,1,2,4,6,5};
	int lb=0;
	int ub=5;
	mergesort(arr,lb,ub);
	for(int i=0;i<6;i++){
		cout<<arr[i];
	}
}
