#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    ifstream input ("input.txt");
    string line;

    int scoreSum;

    while (getline(input, line))
    {
        istringstream lineStream(line);
        lineStream.ignore(10, ':');

        // fetch the winningNumbers and drawnNumbers
        vector<int> winningNumbers;
        vector<int> drawnNumbers;

        int number;
        while (lineStream >> number)winningNumbers.push_back(number);

        lineStream.clear();
        lineStream.ignore(2, '|');

        while (lineStream >> number) {drawnNumbers.push_back(number);}


        // count the score by comparing the winning and the drawn numbers
        int cardScore = 0;
        for (int drawnNumber : drawnNumbers)
        {
            if (find(winningNumbers.begin(), winningNumbers.end(), drawnNumber) != winningNumbers.end())
            {
                if (cardScore > 0) cardScore = cardScore * 2;       
                if (cardScore == 0) cardScore++;
            }
            
        }
        
        scoreSum += cardScore;        
        
    }

    cout << scoreSum;
    
    return 0;
}
