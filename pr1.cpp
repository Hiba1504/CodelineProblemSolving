#include <iostream>
#include <string>
#include <cctype> // For isdigit, isupper, islower

bool isValidUsername(const std::string& username) {
    // Check if the username is not empty and does not exceed 50 characters
    return !username.empty() && username.length() <= 50;
}

bool isValidPassword(const std::string& password) {
    // Check if the password is at least 8 characters long
    if (password.length() < 8) {
        return false;
    }

    // Check if the password contains at least one special symbol
    std::string specialSymbols = "!@#$%^&*()_+[]{}|;:,.<>?~";
    bool hasSpecialSymbol = false;
    for (char c : password) {
        if (specialSymbols.find(c) != std::string::npos) {
            hasSpecialSymbol = true;
            break;
        }
    }
    if (!hasSpecialSymbol) {
        return false;
    }

    // Check if the password has one or more numbers
    bool hasNumber = false;
    for (char c : password) {
        if (std::isdigit(c)) {
            hasNumber = true;
            break;
        }
    }
    if (!hasNumber) {
        return false;
    }

    // Check if the password has one or more uppercase and lowercase characters
    bool hasUppercase = false;
    bool hasLowercase = false;
    for (char c : password) {
        if (std::isupper(c)) {
            hasUppercase = true;
        } else if (std::islower(c)) {
            hasLowercase = true;
        }
    }
    if (!hasUppercase || !hasLowercase) {
        return false;
    }

    return true;
}

bool isValidEmail(const std::string& email) {
    // Check if the email has "@" symbol
    size_t atPos = email.find('@');
    if (atPos == std::string::npos) {
        return false;
    }

    // Check if there are alphanumeric characters before and after the "@" symbol
    std::string usernamePart = email.substr(0, atPos);
    std::string domainPart = email.substr(atPos + 1);
    if (usernamePart.empty() || domainPart.empty()) {
        return false;
    }

    // Check if the domain part has letters and a "." character in between
    size_t dotPos = domainPart.find('.');
    if (dotPos == std::string::npos || dotPos == 0 || dotPos == domainPart.length() - 1) {
        return false;
    }

    return true;
}

int main() {
    std::string username, password, email;

    std::cout << "Enter username: ";
    std::cin >> username;

    std::cout << "Enter password: ";
    std::cin >> password;

    std::cout << "Enter email: ";
    std::cin >> email;

    if (isValidUsername(username)) {
        std::cout << "Username is valid." << std::endl;
    } else {
        std::cout << "Username is invalid." << std::endl;
    }

    if (isValidPassword(password)) {
        std::cout << "Password is valid." << std::endl;
    } else {
        std::cout << "Password is invalid." << std::endl;
    }

    if (isValidEmail(email)) {
        std::cout << "Email is valid." << std::endl;
    } else {
        std::cout << "Email is invalid." << std::endl;
    }

    return 0;
}
