#include <iostream>
#include "book.hpp"

vector<Book> Book::books;

// Constructor
Book::Book() : borrowed_(false), userID_(-1) {}
Book::Book(int id, const string& name, const string& author, bool borrowed, int userID)
    : id_(id), name_(name), author_(author), borrowed_(borrowed), userID_(userID) {}

// Accessors (getters)
int Book::getId() const {
    return id_;
}

string Book::getName() const {
    return name_;
}

string Book::getAuthor() const {
    return author_;
}

bool Book::getBorrowed() const {
    return borrowed_;
}

int Book::getUserID() const {
    return userID_;
}

ostream& operator<<(ostream& os, const Book& book) {
    os << "Name: " << book.name_ << ", Author: " << book.author_;
    return os;
}

void Book::ViewBooks() {
    for (const Book& book : books) {
        if (!book.borrowed_) {
            cout << "Book Name: " << book.name_ << ". Book Author: " << book.author_ << ". Book ID: " << book.id_ << "\n";
        }
    }
}

void Book::ViewBorrowedBooks() {
    for (const Book& book : books) {
        if (book.borrowed_) {
            cout << "Book Name: " << book.name_ << ". Book Author: " << book.author_ << ". Book ID: " << book.id_ << "\n";
        }
    }
}

void Book::CreatBookFromInput(int id) {
    string name, author;
    cout << "Enter the book's name: ";
    cin.ignore();  // Flush the newline
    getline(cin, name);

    cout << "Enter the book's author: ";
    getline(cin, author);

    Book book(id, name, author, false, -1);
    books.push_back(book);
}

bool Book::Borrow(int id, int userid) {
    for (Book& book : books) {
        if (book.id_ == id && !book.borrowed_) {
            book.borrowed_ = true;
            book.userID_ = userid;
            return true;
        }
    }
    return false;
}

bool Book::Return(int id, int userid) {
    for (Book& book : books) {
        if (book.id_ == id && book.userID_ == userid) {
            book.borrowed_ = false;
            book.userID_ = -1;
            return true;
        }
    }
    return false;
}
