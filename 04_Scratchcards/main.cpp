#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;


int main()
{
    ifstream input ("input.txt");
    string line;
    string ignore;

    int sum;

    while (getline(input, line))
    {
        istringstream card(line);
        getline(card, ignore, ':');

        int winningNumbers[10];
        int drawnNumbers[25];

        // fetch the winningNumbers
        for (size_t i = 0; i < 10; i++) card >> winningNumbers[i];

        // ignore the | seperator
        card >> ignore;

        // fetch the drawnNumbers
        for (size_t i = 0; i < 25; i++) card >> drawnNumbers[i];        

        // count the score by comparing the winning and the drawn numbers
        int cardScore = 0;
        for (size_t i = 0; i < 25; i++)
        {
            for (size_t j = 0; j < 10; j++)
            {
                if (drawnNumbers[i] == winningNumbers[j]) 
                {
                    if (cardScore > 0) cardScore = cardScore * 2;       
                    if (cardScore == 0) cardScore++;
                }
                
            }
            
        }
        
        sum += cardScore;        
        
    }

    cout << sum;
    
    return 0;
}
