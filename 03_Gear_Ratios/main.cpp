#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

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


        // finding a number
        for (size_t i = 0; i < currentLine.size(); i++)
        {
            
            if (!isdigit(currentLine[i])) continue;

            int number = currentLine[i] - '0';

            while (isdigit(currentLine[++i]))
            {
                number = number * 10 + currentLine[i] - '0';
            }
            

            // check for adjecent symbols
            bool hasAdjecentSymbol = false;
            int numberLength = to_string(number).length() + 1;
            
            if (isSymbol(currentLine[i])) hasAdjecentSymbol = true;
            if (isSymbol(currentLine[i - numberLength])) hasAdjecentSymbol = true;                

            for (size_t j = 0; j <= numberLength; j++)
            {
                if (isSymbol(prevLine[i-j])) hasAdjecentSymbol = true; 
                if (isSymbol(nextLine[i-j])) hasAdjecentSymbol = true;                
            }
             
            if (hasAdjecentSymbol) sum = number;
            
        }
        
        // Ending the loop
        //getLine() as the while condition did'nt work because the when there are no more lines in the file, the last line is still in nextLine and has not been set as currentLine. There fore it will not be checked for numbers
        if (currentLine == nextLine) break;
        
    }
    
    cout << sum;  
    
    return 0;
}
