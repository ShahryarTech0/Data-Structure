#include <iostream>
using namespace std;
// INDIRECT Recursion
int fun2(int );
int fun()
{
	static int num=0;
	num++;
	fun2(num);
}
int fun2(int num)
{
	if(num>5)
	{
		exit(1);
	}
	else 
	{
		cout<<num<<" ";
		fun();	
	}
}
int main()
{
	fun();
}
