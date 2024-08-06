#include<iostream>
#include<algorithm>
using namespace std;
void countsort(int arr[],int size,int exp){
	int output[size];
	int count[10]={0};
	for(int i=0;i<size;i++){
		count[(arr[i]/exp)%10]++;
	}
	for(int i=1 ;i<10 ;i++){
	   count[i] += count[i-1];
	}
	for(int i=size-1;i>=0;i--){
		output[count[(arr[i]/exp)%10]-1]=arr[i];
		count[(arr[i]/exp)%10]--;
	}
	for(int i=0;i<size;i++){
		arr[i]=output[i];
	}
}
int getMax(int arr[],int size){
	int max=arr[0];
	for(int i=1;i<size;i++){
		if(arr[i]>max){
			max=arr[i];
		}
	}
	return max;
}
void radixsort(int arr[],int size){
	int m=getMax(arr,size);
	for(int exp=1;m/exp>0;exp *= 10){
		countsort(arr,size,exp);
	}
}
int main(){
	int size;
	cout<<"Enter size: ";
	cin>>size;
	int arr[size];
	cout<<"Enter values: ";
	for(int i=0;i<size;i++){
		cin>>arr[i];
	}
	radixsort(arr,size);
	for(int i=0;i<size;i++){
		cout<<arr[i];
	}
}
