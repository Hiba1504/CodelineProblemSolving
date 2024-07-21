#include <iostream>
#include <vector>
using namespace std;

// Function to generate squares of even numbers from a list
vector<int> squaresOfEvenNumbers(const vector<int>& inputList) {
    vector<int> squares;
    for (int num : inputList) {
        if (num % 2 == 0) {
            squares.push_back(num * num);
        }
    }
    return squares;
}

// Function to slice a sublist from a list based on start and end indices
vector<int> sliceSublist(const vector<int>& inputList, int startIndex, int endIndex) {
    vector<int> sublist;
    if (startIndex < 0 || endIndex >= inputList.size() || startIndex > endIndex) {
        return sublist;  // Invalid indices, return empty sublist
    }
    for (int i = startIndex; i <= endIndex; ++i) {
        sublist.push_back(inputList[i]);
    }
    return sublist;
}

int main() {
    vector<int> inputList;
    int num, startIdx, endIdx;

    // Taking input from user
    cout << "Enter the list of integers (separated by spaces, end with -1): ";
    while (cin >> num && num != -1) {
        inputList.push_back(num);
    }

    // Generate squares of even numbers
    vector<int> evenSquares = squaresOfEvenNumbers(inputList);
    cout << "List of squares of even numbers: [";
    for (size_t i = 0; i < evenSquares.size(); ++i) {
        if (i > 0) cout << ", ";
        cout << evenSquares[i];
    }
    cout << "]" << endl;

    // Slice a sublist from the list
    cout << "Enter start index: ";
    cin >> startIdx;
    cout << "Enter end index: ";
    cin >> endIdx;
    vector<int> sublist = sliceSublist(inputList, startIdx, endIdx);
    cout << "Sublist: [";
    for (size_t i = 0; i < sublist.size(); ++i) {
        if (i > 0) cout << ", ";
        cout << sublist[i];
    }
    cout << "]" << endl;

    return 0;
}
