#include <iostream>
class Books {
protected:
    std::string genre;
public:
    Books(std::string g) : genre(g) {}
    virtual void display() = 0;
};

class Novel : public Books {
    std::string title, author;
public:
    Novel(std::string g, std::string t, std::string a) : Books(g), title(t), author(a) {}
    void display() override {
        std::cout << "Genre: " << genre << ", Title: " << title << ", Author: " << author << std::endl;
    }
};

int main() {
    Novel book("Fiction", "The Alchemist", "Paulo Coelho");
    book.display();
    return 0;
}
