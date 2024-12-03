#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>

int main() {

    std::ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    // store the respective inputs in two vectors of integers and sort them, then calculate their distances
    std::vector<int> left_numbers;
    std::vector<int> right_numbers;

    std::string line;
    while (std::getline(inputFile, line)) { 
        int num1;
        int num2;

        std::istringstream iss(line);

        iss >> num1 >> num2;
        // fill the vectors with the numbers
        left_numbers.push_back(num1);
        right_numbers.push_back(num2);
    }

    inputFile.close();

    // sort the two vectors
    std::sort(left_numbers.begin(), left_numbers.end());
    std::sort(right_numbers.begin(), right_numbers.end());

    int answer = 0;

    for (int i=0; i < left_numbers.size(); ++i){
        answer += std::abs(left_numbers[i] - right_numbers[i]);
    }

    std::cout << answer << std::endl;

    return 0;
}

