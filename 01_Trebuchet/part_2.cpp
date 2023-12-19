#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(){
    std::ifstream InputFile;
    InputFile.open("input.txt");

    if (!InputFile.is_open())
    {
        std::cout << "kan file niet openen." << std::endl;
        return 1;
    }

    int sum = 0;
    std::string line;
    while (std::getline(InputFile, line))
    {
        std::vector<int> digits;

        for (size_t i = 0; i < line.length(); i++)
        {
            if (isdigit(line[i]))
            {
                digits.push_back(line[i] - '0');
                continue;
            }

            if (line.substr(i, 3) == "one") {digits.push_back(1); continue;}
            if (line.substr(i, 3) == "two") {digits.push_back(2); continue;}
            if (line.substr(i, 5) == "three") {digits.push_back(3); continue;}
            if (line.substr(i, 4) == "four") {digits.push_back(4); continue;}
            if (line.substr(i, 4) == "five") {digits.push_back(5); continue;}
            if (line.substr(i, 3) == "six") {digits.push_back(6); continue;}
            if (line.substr(i, 5) == "seven") {digits.push_back(7); continue;}
            if (line.substr(i, 5) == "eight") {digits.push_back(8); continue;}
            if (line.substr(i, 4) == "nine") {digits.push_back(9); continue;}

        }

        int doubleDigit = digits.front() * 10 + digits.back();
        sum += doubleDigit;
    }
    
    std::cout << sum;

    InputFile.close();
    
    return 0;
}
