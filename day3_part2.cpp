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

    std::regex pattern(R"((mul\(\d+\,\d+\))|(don't\(\))|(do\(\)))");
    std::regex num_pattern(R"((\d+\,\d+)|(don't\(\))|(do\(\)))");
    int answer = 0;

    std::string line;
    while (std::getline(inputFile, line)) { 
        std::sregex_iterator begin(line.begin(), line.end(), pattern);
        std::sregex_iterator end;
        bool allowed = true;

        for (std::sregex_iterator it = begin; it != end; ++it) {
            std::smatch match = *it;
            std::string m = match.str();

            if (m == "do()"){
                allowed = true;
            }
            else if (m == "don't()"){
                allowed = false;
            }
            else {
                if (allowed){
                    int idx = m.find(",");
                    int i2 = m.find(")");
                    std::string n1 = m.substr(4, idx - 4);
                    std::string n2 = m.substr(idx+1, i2 - idx - 1);
                    answer += (std::stoi(n1) * std::stoi(n2));
                }
            }


        }

    }

    std::cout << answer << std::endl;

    inputFile.close();
    return 0;
}

