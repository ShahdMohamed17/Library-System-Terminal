#include "user.cpp"
#include "book.cpp"

#include <iostream>
#include <vector>

int idnum = 1, Bidnum = 1;
User curr_user;

int login_menu()
{
    cout << "1)Login \n2)Register\n0)Exit" << endl;
    char c;
    cin >> c;

    // Input validation for menu option
    while (c != '1' && c != '2' && c != '0')
    {
        cout << "Invalid input. Please choose a valid option: ";
        cin >> c;
    }

    if (c == '1')
    {
        string username, pass;
        cout << "Enter your Username: ";
        cin >> username;
        cout << "Enter your Password: ";
        cin >> pass;

        curr_user = User::Login(username, pass);
        if (curr_user.getId() == -1)
        {
            cout << "Wrong Username or Password" << endl;
            return 1; // Failed login, try again
        }
        return 2; // Successful login
    }
    else if (c == '2')
    {
        curr_user = User::CreatUserFromInput(idnum++);
        return 2; // Successful registration and auto-login
    }

    return 0; // Exit program
}

bool books_menu()
{
    cout << "1)View Books\n2)Add a new book\n3)Borrow a book\n4)Return a book\n5)Log out\n";
    int c;
    cin >> c;

    // Input validation for menu option
    while (c < 1 || c > 5)
    {
        cout << "Invalid input. Please choose a valid option: ";
        cin >> c;
    }

    if (c == 1)
    {
        Book::ViewBooks();
        return true;
    }
    else if (c == 2)
    {
        Book::CreatBookFromInput(Bidnum++);
        cout << "Thank you for adding a book!" << endl;
        return true;
    }
    else if (c == 3)
    {
        Book::ViewBooks();
        cout << "Enter the ID of the Book you want to Borrow: ";
        int id;
        cin >> id;
        bool okay = Book::Borrow(id, curr_user.getId());
        if (okay)
            cout << "Congrats! You successfully borrowed the book!\n";
        else
            cout << "Error, could not borrow the book. It may be already borrowed or doesn't exist.\n";
        return true;
    }
    else if (c == 4)
    {
        Book::ViewBorrowedBooks();
        cout << "Enter the ID of the Book you want to Return\n";
        int id;
        cin >> id;
        bool okay = Book::Return(id, curr_user.getId());
        if (okay)
            cout << "Thank you for returning the book. You're always welcome to borrow another book.\n";
        else
            cout << "Error, could not return the book. It may not belong to you or doesn't exist.\n";
        return true;
    }
    else if (c == 5)
    {
        cout << "Logging out...\n";
        return false; // Log out by ending the loop
    }

    return true;
}

bool work()
{
    int flg = 1;
    while (flg == 1) // Keep asking for login or registration until successful
        flg = login_menu();

    if (flg == 2) // User successfully logged in
    {
        cout << "Welcome " << curr_user.getName() << " to our unique Library! What do you want to do now?\n";
        bool loggedIn = true;
        while (loggedIn) // Books menu while user is logged in
        {
            loggedIn = books_menu(); // User can log out from books menu
        }
        return true; // Stay in the main program loop, ask for login again
    }
    
    return false; // Exit the program
}

int main()
{
    bool programActive = true;
    while (programActive) // Loop until user chooses to exit
        programActive = work();

    cout << "Goodbye!\n";
    return 0;
}
