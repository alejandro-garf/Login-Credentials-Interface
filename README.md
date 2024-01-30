# User Authentication System

This project is a simple User Authentication System implemented in C++. The program allows users to register, login, and change their password. The user's data such as username, password, and age are stored in a text file named `file.txt`.

## Features

- **User Registration**: Users can register by providing a username, password, and age. This data is stored in a file.
- **User Login**: Users can log in using their registered username and password.
- **Change Password**: Users can change their password after providing the old password for verification.

## How to Run

1. Ensure you have a C++ compiler installed on your system.
2. Compile the source code. For example, if you are using g++, you can compile with `g++ -o authSystem main.cpp`.
3. Run the compiled program. For example, `./authSystem`.

## Code Structure

- `registerUser()`: Function to handle the user registration process.
- `loginUser()`: Function to handle the user login process.
- `changePassword()`: Function to allow a user to change their password.
- `main()`: The main function presents a menu to the user to choose from the available options.




