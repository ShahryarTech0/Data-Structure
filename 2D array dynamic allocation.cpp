#include<iostream>
using namespace std;
int main(){
	//2D-Array
	int row,col;
	cout<<"Enter the number of rows "<<endl;
	cin>>row;
	cout<<"Enter the number of columns "<<endl;
	cin>>col;
	//Creating 2D-Array Dynamically
	int **array=new int*[row]; 
	for(int i=0;i<row;i++){
		array[i]=new int[col];
	}
	//How to Input and Output
	cout<<"Enter the Elements "<<endl;
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			cin>>array[i][j];
		}
	}
	
		for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			cout<<array[i][j]<<" ";
		}
		cout<<endl;
	}
	//How to delete 2D-Array from heap or dynamically
	for(int i=0;i<row;i++){
	delete[] array[i];
	}
	delete[] array;
	
	
}
