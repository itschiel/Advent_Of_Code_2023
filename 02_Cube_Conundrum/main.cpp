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

    int maxRed = 12;
    int maxGreen = 13;
    int maxBlue = 14;

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
                if (color[0] == 'r') reds += amount;
                if (color[0] == 'g') greens += amount;
                if (color[0] == 'b') blues += amount;

                if (color[color.length() - 1] == ';') break;
            }

            if (reds > maxRed) break;
            if (greens > maxGreen) break;
            if (blues > maxBlue) break;

            reds = 0;
            greens = 0;
            blues = 0;
        }

        if (reds != 0) continue;;
        if (greens != 0) continue;;
        if (blues != 0) continue;;

        gameSum += gameID;
    }

    std::cout << gameSum;
    return 0;
}
