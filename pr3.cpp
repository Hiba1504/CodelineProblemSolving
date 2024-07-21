#include <iostream>
using namespace std;

// Function prototypes
void displayOnesTriangle(int numLines);
void displayPalindromicTriangle(int numLines);
void displayHelp();

int main() {
    int choice;
    int numLines;

    do {
        // Display menu
        cout << "Menu:" << endl;
        cout << "1. Display a right-angle triangle of ones" << endl;
        cout << "2. Display a Palindromic Triangle" << endl;
        cout << "3. Help" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter the number of lines: ";
                cin >> numLines;
                displayOnesTriangle(numLines);
                break;
            case 2:
                cout << "Enter the number of lines: ";
                cin >> numLines;
                displayPalindromicTriangle(numLines);
                break;
            case 3:
                displayHelp();
                break;
            case 4:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice! Please enter a number from 1 to 4." << endl;
        }

        cout << endl;

    } while(choice != 4);

    return 0;
}

// Function to display a right-angle triangle of ones
void displayOnesTriangle(int numLines) {
    for (int i = 1; i <= numLines; ++i) {
        for (int j = 1; j <= i; ++j) {
            cout << "1";
        }
        cout << endl;
    }
}

// Function to display a palindromic triangle
void displayPalindromicTriangle(int numLines) {
    for (int i = 1; i <= numLines; ++i) {
        // Left part of the triangle
        for (int j = 1; j <= i; ++j) {
            cout << j;
        }
        // Right part of the triangle
        for (int j = i - 1; j >= 1; --j) {
            cout << j;
        }
        cout << endl;
    }
}

// Function to display help information
void displayHelp() {
    cout << "Help:" << endl;
    cout << "A Palindromic Triangle is a triangular array of numbers where each row forms a palindrome." << endl;
    cout << "The first few lines of a Palindromic Triangle are:" << endl;
    cout << "1" << endl;
    cout << "11" << endl;
    cout << "121" << endl;
    cout << "12321" << endl;
    cout << "1234321" << endl;
    cout << "You can use this pattern to draw a Palindromic Triangle for any number of lines." << endl;
}
