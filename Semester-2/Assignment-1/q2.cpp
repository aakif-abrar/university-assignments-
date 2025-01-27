#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
	int len;
	cout<<"Enter how many numbers you want to add: ";
	cin>>len;
	int* arr,sum=0;
	arr=(int*)malloc(sizeof(int)*len);
	for(int i=0;i<len;i++)
	{
		cin>>*(arr+i);
		sum+=*(arr+i);
	}
	cout<<"sum of "<<len<<" numbers is: "<<sum;
	free(arr);
}
