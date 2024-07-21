#include <iostream>
#include <string>
#include <cctype> // For isdigit, isupper, islower

std::string decimalToBinary(int decimal) {
    std::string binary;
    while (decimal > 0) {
        int remainder = decimal % 2;
        binary = std::to_string(remainder) + binary;
        decimal /= 2;
    }
    return binary;
}

int main() {
    int decimal;
    std::cout << "Input: ";
    std::cin >> decimal;

    if (decimal < 0) {
        std::cout << "Please enter a positive decimal number." << std::endl;
        return 1;
    }

    std::string binary = decimalToBinary(decimal);
    std::cout << "Output: " << binary << std::endl;

    return 0;
}
