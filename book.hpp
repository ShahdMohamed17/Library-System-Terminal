#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <vector>
using namespace std;

class Book {
public:
    // Constructor
    Book();
    Book(int id, const string& name, const string& author, bool borrowed, int userID);

    friend std::ostream& operator<<(std::ostream& os, const Book& book);

    // Accessors (getters)
    int getId() const;
    string getName() const;
    string getAuthor() const;
    bool getBorrowed() const;
    int getUserID() const;

    static void CreatBookFromInput(int id);
    static bool Borrow(int id, int userid);
    static bool Return(int id, int userid);
    static void ViewBooks();
    static void ViewBorrowedBooks();

private:
    static vector<Book> books;
    int id_;
    string name_;
    string author_;
    bool borrowed_;
    int userID_;
};

#endif 
