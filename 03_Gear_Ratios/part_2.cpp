#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

bool isSymbol(char c) {
    if (c <= '\000') return false;
    if (c == '.') return false;
    if (c >=  '0' && c <= '9') return false;

    return true;

}

int main()
{
    ifstream input ("input.txt");
    string line;

    map<string, vector<int>> map;
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
                        
            if (currentLine[i] == '*') map[to_string(lineCount) + '-' + to_string(i)].push_back(number);
            if (currentLine[i - numberLength] == '*') map[to_string(lineCount) + '-' + to_string(i-numberLength)].push_back(number);            

            for (size_t j = 0; j <= numberLength; j++)
            {
                if (prevLine[i-j] == '*') map[to_string(lineCount - 1) + '-' + to_string(i-j)].push_back(number);
                if (nextLine[i-j] == '*') map[to_string(lineCount + 1) + '-' + to_string(i-j)].push_back(number);              
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
