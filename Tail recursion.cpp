#include<iostream>
using namespace std;
// NON Tail Recursion
void get_recursion(int n){
	if(n>=1)
	{
		cout<<n<<" ";
	}
	else
	{
		return;
    }
    get_recursion(n/2);
    cout<<n<<" ";
}
int main(){
	get_recursion(10);
}
