#include <iostream>
#include <string>
using namespace std;

class Media {
protected:
    string title, publicationDate, uniqueID, publisher;
public:
    Media(string t, string pd, string id, string pub) : title(t), publicationDate(pd), uniqueID(id), publisher(pub) {}

    virtual void displayInfo() {
        cout << title << " " << publicationDate << " " << uniqueID << " " << publisher << endl;
    }

    virtual void checkOut() {}

    virtual void returnItem() {}
};

class Book : public Media {
    string author, ISBN;
    int numberOfPages;
public:
    Book(string t, string pd, string id, string pub, string a, string isbn, int pages)
        : Media(t, pd, id, pub), author(a), ISBN(isbn), numberOfPages(pages) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << author << " " << ISBN << " " << numberOfPages << endl;
    }
};

class DVD : public Media {
    string director, rating;
    int duration;
public:
    DVD(string t, string pd, string id, string pub, string d, int dur, string r)
        : Media(t, pd, id, pub), director(d), duration(dur), rating(r) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << director << " " << duration << " " << rating << endl;
    }
};

class CD : public Media {
    string artist, genre;
    int numberOfTracks;
public:
    CD(string t, string pd, string id, string pub, string a, int tracks, string g)
        : Media(t, pd, id, pub), artist(a), numberOfTracks(tracks), genre(g) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << artist << " " << numberOfTracks << " " << genre << endl;
    }
};