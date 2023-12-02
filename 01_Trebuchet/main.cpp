#include <iostream>
#include <fstream>
#include <string>

int getFirsttDigitInString(std::string string){
    for (size_t i = 0; i < string.length(); i++){

        if (isdigit(string[i])){

            return string[i] - '0';
        }
    }

    return 0;
}

int getLastttDigitInString(std::string string){
    for (size_t i = string.length(); i >= 0; i--){

        if (isdigit(string[i])){
            
            return string[i] - '0';
        }
    }

    return 0;
}


int main(){
    std::ifstream InputFile;
    InputFile.open("input.txt");

    if (!InputFile.is_open())
    {
        std::cout << "kan file niet openen." << std::endl;
        return 1;
    }

    std::string line;
    int sum = 0;
    while (std::getline(InputFile, line))
    {
        int doubleDigit = getFirsttDigitInString(line) * 10 + getLastttDigitInString(line);
        sum += doubleDigit;
    }
    
    std::cout << sum;

    InputFile.close();
    
    return 0;
}
