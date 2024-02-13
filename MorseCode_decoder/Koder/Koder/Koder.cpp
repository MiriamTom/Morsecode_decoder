#include <iostream>
#include <map>
#include <string>
#include <algorithm>

// Morse code lookup table
const std::map<char, std::string> morseTable = {
    {'a', ".-"},
    {'b', "-..."},
    {'c', "-.-."},
    {'d', "-.."},
    {'e', "."},
    {'f', "..-."},
    {'g', "--."},
    {'h', "...."},
    {'i', ".."},
    {'j', ".---"},
    {'k', "-.-"},
    {'l', ".-.."},
    {'m', "--"},
    {'n', "-."},
    {'o', "---"},
    {'p', ".--."},
    {'q', "--.-"},
    {'r', ".-."},
    {'s', "..."},
    {'t', "-"},
    {'u', "..-"},
    {'v', "...-"},
    {'w', ".--"},
    {'x', "-..-"},
    {'y', "-.--"},
    {'z', "--.."},
    {' ', ""},
    {'.', "//"}
};

std::string encodeToMorse(const std::string& input)
{
    std::string result;
    for (char c : input) {
        // Convert the character to lower case
        c = std::tolower(c);

        // Look up the Morse code for the character
        auto it = morseTable.find(c);
        if (it != morseTable.end()) {
            result += it->second + "/";
        }
    }
    return result;
}

int main()
{
    // Read input text from the user
    std::string input;
    std::cout << "Enter text to encode in Morse code: ";
    std::getline(std::cin, input);

    // Encode the text
    std::string encoded = encodeToMorse(input);

    // Print the encoded text
    std::cout << "Encoded text: " << encoded << std::endl;

    return 0;
}
