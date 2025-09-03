#include <format>
#include <string>
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

// take the info from the user
User login()
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

    User u;
    u.id = "3";
    u.first_name = first_name;
    u.second_name = second_name;
    u.email = email;
    u.password = password;
    return u;
}

// Puts the user information in our simulated db
void user_info_to_database()
{
    User u = login();
    ofstream MyFile("db.txt");
    if (MyFile.is_open())
    {
        string colon = ",";
        string dbJson = "{ _id : " + u.id + colon + " name : " + u.first_name + ' ' + u.second_name + colon + " email : " + u.email + colon + " password : " + to_string(u.password) + " }";
        MyFile << dbJson;
        MyFile.close();
    }
    else
    {
        cerr << "Can not Open File";
    }
}

// read user data from the db
void read_user_data()
{
    string user;
    ifstream MyFile("db.txt");
    if (MyFile.is_open())
    {
        while (getline(MyFile, user))
            cout << user << endl;
        MyFile.close();
    }
    else
    {
        cerr << "Error: Can not open file\n";
    }
}

int main()
{
    user_info_to_database();
    read_user_data();
    return 0;
}