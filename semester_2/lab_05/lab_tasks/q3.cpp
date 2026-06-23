#include <iostream>
#include <vector>
#include <memory>
#include <unordered_map>
using namespace std;

class Book {
public:
    string title, isbn;
    Book(string t, string i) : title(t), isbn(i) {}
};

class Catalog {
    unordered_map<string, string> index;
public:
    void addBook(Book* book) { index[book->isbn] = book->title; }
    string findBook(string isbn) { return index.count(isbn) ? index[isbn] : "Not found"; }
};

class Library {
    Catalog catalog;
    vector<shared_ptr<Book>> books;
public:
    void addBook(shared_ptr<Book> book) { books.push_back(book); catalog.addBook(book.get()); }
    void findBook(string isbn) { cout << catalog.findBook(isbn) << endl; }
};

int main() {
    Library library;
    shared_ptr<Book> book1 = make_shared<Book>("C++ Primer", "1234");
    shared_ptr<Book> book2 = make_shared<Book>("Data Structures", "5678");
    library.addBook(book1);
    library.addBook(book2);
    library.findBook("1234");
    return 0;
}