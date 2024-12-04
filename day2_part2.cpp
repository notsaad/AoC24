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
        bool valid = false;

        std::vector<int> levels;
        int num;
        std::istringstream iss(line);

        while (iss >> num){
            levels.push_back(num);
        }

        // brute force this part, look at the vector with one element removed
        for (size_t i = 0; i < levels.size(); ++i){
            bool currValid = true;
            bool increasing = true;

            std::vector<int> newLevels;

            for (size_t j = 0; j < levels.size(); ++j){
                if (i != j){
                    newLevels.push_back(levels[j]);
                }
            }

            if (newLevels[0] > newLevels[1]){
                increasing = false;
            }


            for (size_t k = 1; k < newLevels.size(); ++k){

                int curr = newLevels[k];
                int prev = newLevels[k-1];

                if ((increasing && prev >= curr) || (!increasing && prev <= curr) || (std::abs(prev-curr) > 3)){
                    currValid = false;
                    break;
                }

            }

            valid |= currValid;
            if (valid)
                break;

        }

        if (valid)
            answer++;

    }

    inputFile.close();

    std::cout << answer << std::endl;

    return 0;
}


