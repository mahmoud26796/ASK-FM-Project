#include <iostream>
#include <fstream>
using namespace std;

// make a new user struct
struct User
{
    string id;
    string first_name;
    string second_name;
    string email;
    int password;

    void set_user_info(string first_name, string second_name, string email, int password)
    {
        this->first_name = first_name;
        this->second_name = second_name;
        this->email = email;
        this->password = password;
    }
};

// Puts the user information in our simulated db
void user_info_to_database()
{
}

// read user data from the db
void read_user_data()
{
    string user;
    ifstream Mystream("db.txt");
    string userName;
    while (getline(Mystream, user))
        userName;
    Mystream.close();
}

// take the info from the user
void login()
{
    string first_name;
    string second_name;
    string email;
    int password;
    int password_confirm;
    while (true)
    {
        cout << "Please Enter Your First Name: " << endl;
        cin >> first_name;
        cout << "Please Enter Your Second Name: " << endl;
        cin >> second_name;
        cout << "Please Enter Your Email Address: " << endl;
        cin >> email;
        cout << "Please Create A New Password: " << endl;
        cin >> password;
        cout << "Please Confirm Your Password: " << endl;
        cin >> password_confirm;
        break;
    }

    cout << "user: " + first_name + " " + second_name + " Logged In Successfuly" << endl;
}
int main()
{
    // login();
    read_user_data();
    return 0;
}