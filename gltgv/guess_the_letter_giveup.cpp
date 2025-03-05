#include <iostream>
#include <limits> 
#include <vector>
using namespace std;

string alphabet = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";
const char answer = 'F';
char input;
vector<char> inputsequence = {};

bool give_up()
{
    for (size_t i = 0; i < inputsequence.size(); i++)
    {
        if (inputsequence[i] == 'g' && inputsequence[i+1] == 'i' && inputsequence[i+2] == 'v' && inputsequence[i+3] == 'e' && inputsequence[i+4] == 'u' && inputsequence[i+5] == 'p')
            return true;
    }
    return false;
}

bool invalid_characters()
{
    for (char letter : alphabet)
    {
        if (letter == input)
            return false; 
    }
    return true;
}

int main()
{
    cout << "GUESS the letter, case sensitive.\nPress the keyboard and then the ENTER key to TRY.\nNumbers OK. Punctuations OK. Space inserted OK. Chinese characters would cause some matter.\nYou can enter several characters in one time.\nEnter 'giveup' to quit.\n";

    int left = 20;
    for (left; left >= 1; left--)
    {
        cout << "\nYou have " << left << " times left.\n\n";
        cin >> input;
        inputsequence.emplace_back(input);   
            if (invalid_characters())
                cout << "Invalid character '" << input <<"'. Please enter a letter.";
            else if (answer == input)
                goto label1;
            else if (give_up())
                goto lebel2;
            else
                cout << "Not the letter '" << input << "'.";
    }

    if (left == 0)
        cout << "\n\nYou LOSE.\nTimes have been run out.\n";
    else if (left >= 0)
        label1: 
        cout << "\nYou WIN.\nThe letter is " << answer << ".\n";
    else
        lebel2:
        cout <<"\nYou QUIT, which means you LOSE.\n";

    cout << "\nPress any keys followed by enter to exit.\n";
    
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    string exit;
    cin >> exit;

    return 0;
}