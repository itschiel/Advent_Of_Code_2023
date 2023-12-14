#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

void add_to_map(map<string, vector<int>>* m, int line, int col, int number)
{
    string pos = to_string(line) + '-' + to_string(col);
    (*m)[pos].push_back(number);
}

int main()
{
    ifstream input ("input.txt");
    string line;

    map<string, vector<int>> map; //map of numbers adjecent to an astrisk [[pos *][adjecent numbers]]
    int lineCount = 0;
    int sum = 0;

    string prevLine;
    string currentLine;
    string nextLine;

    while (true)
    {
        // shuffle working lines
        getline(input, line);

        prevLine = currentLine;
        currentLine = nextLine;
        nextLine = line;

        if (currentLine.empty()) continue;
        lineCount++;


        // finding a number
        for (size_t i = 0; i < currentLine.size(); i++)
        {
            
            if (!isdigit(currentLine[i])) continue;

            int number = currentLine[i] - '0';

            while (isdigit(currentLine[++i]))
            {
                number = number * 10 + currentLine[i] - '0';
            }
            
            // check for adjecent *
            int numberLength = to_string(number).length() + 1;
                        
            if (currentLine[i] == '*') add_to_map(&map, lineCount, i, number);
            if (currentLine[i - numberLength] == '*') add_to_map(&map, lineCount, i-numberLength, number);            

            for (size_t j = 0; j <= numberLength; j++)
            {
                if (prevLine[i-j] == '*') add_to_map(&map, lineCount-1, i-j, number);
                if (nextLine[i-j] == '*') add_to_map(&map, lineCount+1, i-j, number);              
            }
            
        }
        
        // Ending the loop
        //getLine() as the while condition did'nt work because the when there are no more lines in the file, the last line is still in nextLine and has not been set as currentLine. There fore it will not be checked for numbers
        if (currentLine == nextLine) break;
        
    }

    //finding the gear ratios
    for (auto const& [k, v] : map)
    {
        if (v.size() != 2) continue;
        
        sum += v[0] * v[1];
    }
    
    cout << sum;
    
    return 0;
}
