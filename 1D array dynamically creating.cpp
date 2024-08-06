#include<iostream>
using namespace std;
int main(){
	//Creating 1D- Array Dynamically
	int size,sum=0;
	cout<<"Enter the size "<<endl;
	cin>>size;
	int *array=new int[size]; //Dynamic creating
	//Input taking
	for(int i=0;i<(size+4);i++){
		cin>>array[i]; //array[i]=*(array+i)
		sum=sum+array[i];
	}
	cout<<"The sum of an array is "<<sum<<endl;
	delete[] array;   //Delete dynamic memory allocation mutually
}
