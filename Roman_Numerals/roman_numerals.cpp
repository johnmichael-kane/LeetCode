#include <vector>
#include <string>
#include <iostream>

class Solution {

public:

    std::string intToRoman(int num) {
        static const std::vector<std::pair<int, std::string>> roman{
        {1000, "M"}, {900, "CM"}, {500, "D"},
        {400, "CD"}, {100, "C"}, {90, "XC"},
        {50, "L"}, {40, "XL"}, {10, "X"},
        {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    }; //Reference to every number, since these are the only cases to the left
        std::string result;
        for(const auto& value : roman){
            while (num >=value.first){
                result+=value.second;
                num -=value.first;
            }
        }
        return result;
    }


};

int main(){

    std::vector<int> numbers;
    std::string input;
    std::cout << "Add number to list ('0' to exit): " << std::endl;
    // Loop to get user input
    while (true) {
        std::cout << "\t";
        std::getline(std::cin, input); // Get the entire line to handle input
        
        if (input == "0") {
            break; // Exit the loop if the user enters '0'
        }

        try {
            // Convert the input to an integer and add to the list
            int number = std::stoi(input);
            numbers.push_back(number);
        } catch (std::invalid_argument& e) {
            // Handle the case where the input cannot be converted to an integer
            std::cout << "Invalid input, please enter a number or '0' to quit." << std::endl;
        }
    }

    Solution solution;

    for(int i: numbers){
        std::cout << i << " converted to Roman Numerals: " << std::endl;
        std::string roman = solution.intToRoman(i);
        std::cout << roman << std::endl;
    }

     //reference to the solution
    return 0;
};