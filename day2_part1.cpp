#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

int main() {

    std::ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    // all numbers on each line must follow the following critera:
    // 1. strictly increasing or strictly decreasing
    // 2. a number can only differ from its adjacent numbers by 1-3 values inclusive

    int answer = 0;
    std::string line;
    while (std::getline(inputFile, line)) { 
        bool valid = true;
        bool increasing = true;

        std::vector<int> levels;
        int num;
        std::istringstream iss(line);

        while (iss >> num){
            levels.push_back(num);
        }

        if (levels[0] > levels[1]){
            increasing = false;
        }

        for (int i = 1; i < levels.size(); ++i){
            if (!valid)
                break;

            int curr = levels[i];
            int prev = levels[i-1];

            if ((increasing && prev >= curr) || (!increasing && prev <= curr) || (std::abs(prev-curr) > 3)){
                valid = false;
            }
        }

        if (valid)
            answer++;

    }

    inputFile.close();

    std::cout << answer << std::endl;

    return 0;
}

