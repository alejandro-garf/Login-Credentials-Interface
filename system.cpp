#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void registerUser() {
    string name, password, age;
    cout << "Please Enter username: ";
    cin >> name;
    cout << "Please Enter password: ";
    cin >> password;
    cout << "Please Enter age: ";
    cin >> age;

    ofstream of1("file.txt");
    if (of1.is_open()) {
        of1 << name << "|" << password << "|" << age << "\n";
        cout << "Registration successful" << endl;
    }
    of1.close();
}

bool loginUser() {
    string user, pass, line, uname, upass, uage;
    cout << "Please Enter username: ";
    cin >> user;
    cout << "Please Enter password: ";
    cin >> pass;

    ifstream of2("file.txt");
    if (of2.is_open()) {
        while (getline(of2, line)) {
            istringstream iss(line);
            getline(iss, uname, '|');
            getline(iss, upass, '|');
            getline(iss, uage);

            if (user == uname && pass == upass) {
                cout << "Login successful" << endl;
                cout << "Details: " << endl;
                cout << "Username: " << uname << endl;
                cout << "Password: " << upass << endl;
                cout << "Age: " << uage << endl;
                of2.close();
                return true;
            }
        }
        of2.close();
    }
    cout << "Incorrect Credentials" << endl;
    return false;
}

void changePassword() {
    string oldPass, newPass1, newPass2, line, uname, upass, uage;
    cout << "Enter the old password: ";
    cin >> oldPass;

    fstream file("file.txt", ios::in | ios::out);
    if (file.is_open()) {
        while (getline(file, line)) {
            long pos = file.tellg();
            istringstream iss(line);
            getline(iss, uname, '|');
            getline(iss, upass, '|');
            getline(iss, uage);

            if (oldPass == upass) {
                cout << "Enter the new password: ";
                cin >> newPass1;
                cout << "Confirm the new password: ";
                cin >> newPass2;

                if (newPass1 == newPass2) {
                    file.seekp(pos - line.length() - 1);
                    file << uname << "|" << newPass1 << "|" << uage << endl;
                    cout << "Password changed successfully" << endl;
                    file.close();
                    return;
                } else {
                    cout << "Passwords do not match" << endl;
                    file.close();
                    return;
                }
            }
        }
        file.close();
    }
    cout << "Old password is incorrect" << endl;
}

int main() {
    int choice;

    do {
        cout << "Security System" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Change Password" << endl;
        cout << "4. End Program" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                changePassword();
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
