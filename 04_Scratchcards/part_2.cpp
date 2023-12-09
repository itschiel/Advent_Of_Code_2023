#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main(){

    ifstream input("input.txt");
    string line;
    string ignore;

    vector<int> cardNumbers;

    int totalNumberOfScratchCards =0;


    //fetching list of cards
    cardNumbers.push_back(0);
    while (getline(input, line)) cardNumbers.push_back(1);
    
    input.clear();
    input.seekg(0, ios::beg);
    int cardNumber = 0;
    while (getline(input, line))
    {
        istringstream card(line);
        cardNumber++;
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
        int count = 0;
        for (size_t i = 0; i < 25; i++)
        {
            for (size_t j = 0; j < 10; j++)
            {
                if (drawnNumbers[i] == winningNumbers[j]) 
                {
                    count++;
                }     
            }  
        }

        // updating card multiplier
        for (size_t i = 1; i <= count; i++)
        {            
            cardNumbers[cardNumber + i] += (1 * cardNumbers[cardNumber]);
        }       
              
        
    }    

    for (size_t i = 0; i < cardNumbers.size(); i++)
    {
        totalNumberOfScratchCards += cardNumbers[i];
    }
    
    cout << totalNumberOfScratchCards;


}