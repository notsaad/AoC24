#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <unordered_map>

int main() {

    std::ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    // store the respective inputs in two vectors of integers and sort them, then calculate their distances
    std::vector<int> left_numbers;
    std::unordered_map<int, int> right_numbers;

    std::string line;
    while (std::getline(inputFile, line)) { 
        int num1;
        int num2;

        std::istringstream iss(line);

        iss >> num1 >> num2;
        // fill the vectors with the numbers
        left_numbers.push_back(num1);
        right_numbers[num2]++;
    }

    inputFile.close();

    // sort the two vectors
    std::sort(left_numbers.begin(), left_numbers.end());

    int answer = 0;

    for (int i=0; i < left_numbers.size(); ++i){
        answer += (left_numbers[i] * right_numbers[left_numbers[i]]);
    }

    std::cout << answer << std::endl;

    return 0;
}

