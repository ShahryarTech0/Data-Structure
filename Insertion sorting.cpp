#include<iostream>
using namespace std;
int main(){
	//              INSERTION SORTING
	
	int size,minIndex;
	cout<<"Enter the size "<<endl;
	cin>>size;
	int arr[size];
	cout<<"Enter the elements of an array "<<endl;
	for(int i=0;i<size;i++){
		cin>>arr[i];
	}
	for(int i=1;i<size;i++){
	     int max;
	      max=arr[i];
	      int j=(i-1);
		for(;j>=0;j--){
			if(arr[j]>max){
			arr[j+1]=arr[j];
			}
			else{
				break;
			}
		}
		arr[j+1]=max;
	}
	for(int i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}
}
