#include<iostream>
#include<cstdlib>
using namespace std;
void* arrOp(void* arr,int size)
{
    int* c=new int[size];
    for(int i=0;i<size;i++)
    {
    c[i]=((int*)arr)[i]+i;
    }
    void* newArr=c;
    return newArr;
}
int main(int argc,char* argv[])
{
    if (argc < 2) 
    {
        cout << "Usage: " << *argv << " num1 num2 num3 ..." << endl;
        return 1;
    }
    int* arr=new int[argc-1];
    for(int i=0;i<argc-1;i++)
    {
        arr[i]=atoi(argv[i+1]);
    }
   void* newArr=arrOp((void*) arr,argc-1);
   for(int i=0;i<argc-1;i++)
   {
    cout<<"Element "<<i+1<<": "<<((int*)newArr)[i]<<endl;
   }
    delete[] arr;
    delete[] (int*)newArr;
}