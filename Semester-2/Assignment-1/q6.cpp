#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int main()
{
    string name;
    float scores[5],sum=0;
    cout<<"Enter name: ";
    getchar();
    getline(cin,name);
    cout<<"Enter scores: "<<endl;
    for(int i=0;i<5;i++)
    {
        cin>>*(scores+i);
        sum+=*(scores+i);
    }
    printf("Average score: %.2f",sum/(sizeof(scores)/sizeof(scores[0])));
}
