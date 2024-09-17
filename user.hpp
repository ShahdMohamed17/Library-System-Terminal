#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
using namespace std;

class User {
public:
    // Constructor
    User();
    User(int id, const string& name, const string& username, const string& password);

    friend std::ostream& operator<<(std::ostream& os, const User& user);

    // Accessors (getters)
    int getId() const;
    string getName() const;
    string getUsername() const;
    string getPassword() const;

    static User CreatUserFromInput(int id);
    static User Login(string username, string password);

private:
    static vector<User> Users;
    int id_;
    string name_;
    string username_;
    string password_;
};

#endif // USER_H
