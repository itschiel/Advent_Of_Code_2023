/*
Determine which games would have been possible
if the bag had been loaded with only 12 red cubes, 13 green cubes, and 14 blue cubes. 
What is the sum of the IDs of those games?
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main(){

    std::ifstream input ("input.txt");
    std::string line;

    if (!input.is_open())
    {
        std::cout << "Failed to open input file";
        return 0;
    }

    int gameSum = 0;

    while (std::getline(input, line))
    {
        std::istringstream iss (line);
        std::string ignore;

        int gameID;
        int amount;
        std::string color;

        int reds = 0;
        int greens = 0;
        int blues = 0;

        
        iss >> ignore >> gameID >> ignore;

        while (!iss.eof())
        {      

            while (iss >> amount >> color)
            {
                if (color[0] == 'r' && amount > reds) reds = amount;
                if (color[0] == 'g' && amount > greens) greens = amount;
                if (color[0] == 'b' && amount > blues) blues = amount;

                if (color[color.length() - 1] == ';') break;
            }
        }

        int power = reds * greens * blues;

        gameSum += power;
    }

    std::cout << gameSum;
    return 0;
}
