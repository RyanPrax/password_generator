#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;

char lowercase[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
char upper[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
char numbers[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
char symbols[25] = { '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '=', '+', '[', '{', ']', '}', '|', ';', ':', '<', '>', '/', '?' };

int main() {
    srand(time(0));
    int length;
    int characters = 0;
    vector<char> passwordChars;

    cout << "How many characters will your password be?" << endl;
    cin >> length;

    // Add one lowercase, one uppercase, one number, and one symbol to the passwordChars vector, ensuring the password contains at least one of each type
    //push_back() adds the value to the end of the specified vector
    passwordChars.push_back(lowercase[rand() % 26]);
    passwordChars.push_back(upper[rand() % 26]);
    passwordChars.push_back(numbers[rand() % 10]);
    passwordChars.push_back(symbols[rand() % 25]);
    characters += 4;

    // Fill the remaining characters randomly
    while (characters < length) {
        int selection = rand() % 4;
        if (selection == 0) {
            passwordChars.push_back(lowercase[rand() % 26]);
        }
        else if (selection == 1) {
            passwordChars.push_back(upper[rand() % 26]);
        }
        else if (selection == 2) {
            passwordChars.push_back(numbers[rand() % 10]);
        }
        else {
            passwordChars.push_back(symbols[rand() % 25]);
        }
        characters++;
    }

    // Shuffle the passwordChars vector to randomize the order of required characters
    random_shuffle(passwordChars.begin(), passwordChars.end());

    // Output the password
    for (char c : passwordChars) {
        cout << c;
    }

    cout << endl;

    return 0;
}
