#include <iostream>
#include <regex>
#include <fstream>
#include <string>
#include <vector>

int main() {

    std::ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    std::regex pattern(R"(mul\(\d+\,\d+\))");
    std::regex num_pattern(R"(\d+)");
    int answer = 0;

    std::string line;
    while (std::getline(inputFile, line)) { 
        std::sregex_iterator begin(line.begin(), line.end(), pattern);
        std::sregex_iterator end;

        for (std::sregex_iterator it = begin; it != end; ++it) {
            std::smatch match = *it;
            std::string match_string = match.str();

            std::sregex_iterator num_begin(match_string.begin(), match_string.end(), num_pattern);
            std::sregex_iterator num_end;
            int num = 1;

            for (std::sregex_iterator num_it = num_begin; num_it != num_end; ++num_it) {
                std::smatch num_match = *num_it;
                num *= std::stoi(num_match.str());
            }

            answer += num;
        }

    }

    std::cout << answer << std::endl;

    inputFile.close();
    return 0;
}

