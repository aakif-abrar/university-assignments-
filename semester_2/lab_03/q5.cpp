#include <iostream>
#include <string>
using namespace std;
class Book
{
private:
    string name;
    string isbn;
    string aname;
    string publisher;
    
public:
    void setName(string n)
    {
        name=n;
    }
    void setISBN(string isbn)
    {
        this->isbn=isbn;
    }
    void setAname(string author)
    {
        aname=author;
    }
    void setPublisher(string publisher)
    {
        this->publisher=publisher;
    }
    string getBookInfo()
    {
        return "Book Name: " + name + "\nISBN: " + this->isbn + "\nAuthor: " + aname + "\nPublisher: " + this->publisher +"\n";
    }
};
int main()
{
    Book BookTest[5];
    string name,isbn,author,publisher;
    //setting values:
    for(int i=0;i<5;i++)
    {
        cout<<endl<<"Enter Book "<<i+1<<" Details: "<<endl;
        cout<<"Enter Book Name: ";
        getline(cin,name);
        cout<<"Enter ISBN: ";
        getline(cin,isbn);
        cout<<"Enter Author Name: ";
        getline(cin,author);
        cout<<"Enter Publisher Name: ";
        getline(cin,publisher);
        BookTest[i].setName(name);
        BookTest[i].setISBN(isbn);
        BookTest[i].setAname(author);
        BookTest[i].setPublisher(publisher);
    }
    cout<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<endl<<"Book "<<i+1<<" Details: "<<endl;
        cout<<BookTest[i].getBookInfo();
    }
}
