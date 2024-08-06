#include<iostream>
using namespace std;
int getmax(int arr[],int size){
	int max=arr[0];
	for(int i=1; i<size;i++){
		if(arr[i]>max){
			max=arr[i];
		}
	}
	return max;
}
void countingsort(int arr[],int size,int exp){
	int newarr[size];
	int count[10]={0};
	
	for(int i=0;i<size;i++){
		count[(arr[i]/exp)%10]++;
	}
	for(int i=1;i<10;i++){
		count[i] += count[i-1];
	}
	for(int i=size-1;i>=0;i--){
		newarr[count[(arr[i]/exp)%10]-1]=arr[i];
		count[(arr[i]/exp)%10]--;
	}
	for(int i=0;i<size;i++){
		arr[i]=newarr[i];
	}
	
}
void radixsort(int arr[],int size){
	int m=getmax(arr,size);
	for(int exp=1;m/exp>0; exp *= 10){
		countingsort(arr,size,exp);
	}
}
int main(){
	int arr[6]={5,3,1,0,4,2};
	int size=6;
	radixsort(arr,size);
	for(int i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
