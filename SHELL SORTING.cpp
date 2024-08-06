#include<iostream>
using namespace std;
int main(){
	//              SHELL SORTING
	
	int size,i,j;
	cout<<"Enter the size "<<endl;
	cin>>size;
	int arr[size];
	cout<<"Enter the elements of an array "<<endl;
	for(int i=0;i<size;i++)
	{
		cin>>arr[i];
	}
	for(int gap=size/2 ; gap>=1 ; gap=gap/2){
		for(j=gap ; j<size ; j++){
			for(i=(j-gap);i>=0;i=i-gap){
				if(arr[i+gap]>arr[i]){
					break;
				}
				else{
					// swaping
					int temp;
					temp=arr[i+gap];
					arr[i+gap]=arr[i];
					arr[i]=temp;
				}
			}
		}
	}
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<" ";
	}
	
}
	
	
