#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ifstream input("input.txt");
    string line;

    // Create a vector to store the amount of copies we have of each card
    // Index = card number, Value = amount of copies
    vector<int> cardCopies;
    cardCopies.push_back(0); // because there is'nt a card 0
    while (getline(input, line)) cardCopies.push_back(1);
    

    // Resetting the input filestream
    input.clear();
    input.seekg(0, ios::beg);


    for (size_t cardNumber = 1; getline(input, line); cardNumber++)
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


        // count the matches between the winning and drawn numbers
        int matchesCount = 0;
        for (int drawnNumber : drawnNumbers)
        {
            if (find(winningNumbers.begin(), winningNumbers.end(), drawnNumber) != winningNumbers.end()) matchesCount++;
        }

        // count the copies we won
        for (size_t i = 1; i <= matchesCount; i++)
        {            
            cardCopies[cardNumber + i] += cardCopies[cardNumber];
        }       
    }    

    int totalNumberOfScratchCards = 0;
    for (int copies : cardCopies)
    {
        totalNumberOfScratchCards += copies;
    }
    
    cout << totalNumberOfScratchCards;


}