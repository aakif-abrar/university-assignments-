#include<iostream>
using namespace std;
int main()
{
    int len=5,count=0;
    int* a=new int[len];
    while(true)
    {
        if(count==len)
        {
            len*=2;
            int* large=new int[len];
            for(int i=0;i<count;i++)
            {
                large[i]=a[i];
            }
            delete[] a;
            a=large;
        }
        cout<<"Enter element "<<count+1<<" (-1 to exit) : ";
        int val;
        cin>>val;
        if(val==-1)
        break;
        a[count++]=val;
    }
    int* fixed=new int[count];
    for(int i=0;i<count;i++)
    {
        fixed[i]=a[i];
    }
    delete[] a;
    a=fixed;
    cout<<endl<<"Final array: "<<endl;
    for(int i=0;i<count;i++)
    {
        cout<<"Element no. "<<i+1<<": "<<a[i]<<endl;
    }
    delete[] a;
}