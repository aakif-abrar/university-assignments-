#include<iostream>
using namespace std;
typedef struct
{
    int id;
    string name;
}Person;
void input(Person* p,int* count,int len)
{
    if(*count==len)
    {
        cout<<"Max limit reached!"<<endl<<endl;
    }
    else
    {
    cout<<"Enter Id: ";
    cin>>p[*count].id;
    cout<<"Enter name: ";
    cin.ignore();  
    getline(cin, p[*count].name);
    cout<<endl;
    (*count)++;
    }
}
void sortbyid(Person *p,int count)
{
    for(int i=0;i<count-1;i++)
    {
        for(int j=0;j<count-i-1;j++)
        {
            if(p[j].id>p[j+1].id)
            {
            Person temp=p[j];
            p[j]=p[j+1];
            p[j+1]=temp;
            }
        }
    }
    cout<<"Sorted by id: "<<endl;
    for(int i=0;i<count;i++)
    {
        cout<<"ID: "<<p[i].id<<endl;
        cout<<"Name: "<<p[i].name<<endl<<endl;
    }
}
void sortbyname(Person *p,int count)
{
    for(int i=0;i<count-1;i++)
    {
        for(int j=0;j<count-i-1;j++)
        {
            if(p[j].name[0]>p[j+1].name[0])
            {
            Person temp=p[j];
            p[j]=p[j+1];
            p[j+1]=temp;
            }
        }
    }
    cout<<"Sorted by name: "<<endl;
    for(int i=0;i<count;i++)
    {
        cout<<"ID: "<<p[i].id<<endl;
        cout<<"Name: "<<p[i].name<<endl<<endl;
    }
}
int main()
{
    int size,count=0;
    cout<<"Enter the size of structure: ";
    cin>>size;
    Person per[size];
    int choice;
    while(1)
    {
        cout<<"Choose from the following options: "<<endl<<"1. Add a record"<<endl<<"2. Sort by id"<<endl<<"3. Sort by name"<<endl<<"Press another key to exit"<<endl<<"Choice: ";
        cin>>choice;
        cout<<endl;
        switch(choice)
        {
            case 1:
            input(per,&count,size);
            break;
            case 2:
            if(count<2)
            {
                cout<<"There is only one record and the data is already sorted."<<endl<<endl; 
            }
            else
            sortbyid(per,count);
            break;
            case 3:
            if(count<2)
            {
                cout<<"There is only one record and the data is already sorted."<<endl<<endl; 
            }
            sortbyname(per,count);
            break;
            default:
            cout<<"Exiting program.......";
            exit(0);
        }
    }
}