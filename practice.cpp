#include <iostream>
#include <string>
#include <vector>

int square(int value) {
    return value * value;
}

void printNumbers(const std::vector<int>& numbers) {
    for (int number : numbers) {
        std::cout << number << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::cout << "C++ practice starter" << std::endl;

    std::string name;
    int favoriteNumber = 0;

    std::cout << "Enter your name: ";
    std::getline(std::cin, name);

    std::cout << "Enter your favorite number: ";
    std::cin >> favoriteNumber;

    std::cout << "Hello, " << name << "!" << std::endl;
    std::cout << "Favorite number: " << favoriteNumber << std::endl;
    std::cout << "Square of favorite number: " << square(favoriteNumber) << std::endl;

    if (favoriteNumber % 2 == 0) {
        std::cout << "That is an even number." << std::endl;
    } else {
        std::cout << "That is an odd number." << std::endl;
    }

    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::cout << "Numbers: ";
    printNumbers(numbers);

    std::cout << "Count from 1 to 5:" << std::endl;
    for (int index = 1; index <= 5; ++index) {
        std::cout << index << std::endl;
    }

    // Practice ideas:
    // 1. Add a cube() function and print the result.
    // 2. Ask for three numbers and store them in a vector.
    // 3. Find the largest value in the vector.
    // 4. Add a loop that lets the user run the program again.

    return 0;
}
