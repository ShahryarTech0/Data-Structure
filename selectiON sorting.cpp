#include<iostream>
using namespace std;
int main(){
	//              SELECTION SORTING
	
	int size,minIndex;
	cout<<"Enter the size "<<endl;
	cin>>size;
	int arr[size];
	cout<<"Enter the elements of an array "<<endl;
	for(int i=0;i<size;i++){
		cin>>arr[i];
	}
	for(int i=0;i<(size-1);i++){
		minIndex=i;
		for(int j=(i+1);j<size;j++){
			if(arr[j]<arr[minIndex]){
				int temp;
				temp=arr[minIndex];
				arr[minIndex]=arr[j];
				arr[j]=temp;
			}
		}
	}
	for(int i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}
	
	
}
