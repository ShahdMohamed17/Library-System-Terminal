#include <iostream>
#include "user.hpp"

vector<User> User::Users;

// Constructor
User::User() : id_(-1) {}
User::User(int id, const string& name, const string& username, const string& password)
    : id_(id), name_(name), username_(username), password_(password) {}

// Accessors (getters)
int User::getId() const {
    return id_;
}

string User::getName() const {
    return name_;
}

string User::getUsername() const {
    return username_;
}

string User::getPassword() const {
    return password_;
}

ostream& operator<<(ostream& os, const User& user) {
    os << "Name: " << user.name_ << ", UserName: " << user.username_;
    return os;
}

User User::CreatUserFromInput(int id) {
    string name, user, pass;
    cout << "Enter your Name: ";
    cin.ignore();  // Flush the newline
    getline(cin, name);

    cout << "Enter your Username: ";
    cin >> user;

    cout << "Enter your Password: ";
    cin >> pass;

    User userTemp(id, name, user, pass);
    Users.push_back(userTemp);

    return userTemp;
}

User User::Login(string username, string pass) {
    User userTemp;
    for (const User& CurUser : Users) {
        if (CurUser.username_ == username) {
            if (CurUser.password_ == pass) {
                return CurUser;
            }
            else {
                return userTemp;
            }
        }
    }
    return userTemp;
}
