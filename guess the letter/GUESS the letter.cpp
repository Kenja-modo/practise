#include <iostream>
#include <limits> 
using namespace std;

string alphabet = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";
const char answer = 'Z';
char input;

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
    cout << "GUESS the letter, case sensitive.\nPress the keyboard and then the ENTER key to TRY.\nNumbers OK. Punctuations OK. Space inserted OK. Chinese characters would cause some matter.\nYou can enter several characters in one time.\n";

    int left = 10;
    for (; left >= 1; left--)
    {
        cout << "\nYou have " << left << " times left.\n\n";
        cin >> input;

        if (invalid_characters())
            cout << "Invalid character '" << input <<"'. Please enter a letter.";
        else if (answer == input)
            goto label;
        else
            cout << "Not the letter '" << input << "'.";
    }

    if (left == 0)
        cout << "\n\nYou LOSE.\nTimes have been run out.\n";
    else
        label: 
        cout << "\nYou WIN.\nThe letter is 'Z'\n";

    cout << "\nPress any keys followed by enter to exit.\n";
    
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    string exit;
    cin >> exit;

    return 0;
}