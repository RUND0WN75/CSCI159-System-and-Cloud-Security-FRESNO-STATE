/*
HOW TO RUN PROGRAM:
On command line using cygwin, type: ./a.exe , hit enter to execute program, then when asked for input, enter either UserA, UserB, UserC, or UserD. 
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <ctime>
using namespace std;

//User security levels
enum userSecLevel {
    USER_PUBLIC,
    USER_LIMITED,
    USER_SECRET,
    USER_TOPSECRET
};

//File class
class File {
    public:
        string fileName;
        userSecLevel userLevel;

        //Constructor
        File(string a, userSecLevel b) {
            fileName = a;
            userLevel = b;
        }
};

//User class
class User {
    public:
        string userName;
        userSecLevel userLevel;
        vector<File> accessFiles;
};

int main() {
    srand(time(NULL));
    vector<File> file;

    //Getting user input
    string input;
    cout << "Enter username: ";
    cin >> input;

    //Making users
    vector<User> users = {
        {"UserA", USER_PUBLIC},
        {"UserB", USER_LIMITED},
        {"UserC", USER_SECRET},
        {"UserD", USER_TOPSECRET},
    };

    //Making 50 files
    for (int i = 0; i < 50; i++) {
        userSecLevel fileLevel = static_cast<userSecLevel>(rand() % 4);
        file.push_back(File("File " + to_string(i), fileLevel));
    }

    //Find user with given input
    User currUser;
    for (const User &x : users) {
        if (x.userName == input) {
            currUser = x;
            break;
        }
    }

    //Display file accessibility to user
    cout << "Accessible files for: " << currUser.userName << " -> Level: " << currUser.userLevel << endl;

    //Checking to see if user has access to a file
    for (const File &x : file) {
        int a = static_cast<int>(x.userLevel);
        int b = static_cast<int>(currUser.userLevel);
        if (a <= b) {
            currUser.accessFiles.push_back(x);
            cout << x.fileName << " -> Security level: " << x.userLevel << endl;
        }
    }
}