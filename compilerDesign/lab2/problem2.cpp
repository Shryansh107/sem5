#include <iostream>
#include <fstream>
#include <string>

void countFileStats(const std::string &filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Could not open the file!" << std::endl;
        return;
    }

    int characterCount = 0;
    int wordCount = 0;
    int spaceCount = 0;
    int lineCount = 0;

    std::string line;
    while (std::getline(file, line)) {
        ++lineCount; 
        characterCount += line.length();

        bool inWord = false;
        for (char c : line) {
            if (std::isspace(c)) {
                ++spaceCount;
                if (inWord) {
                    ++wordCount;
                    inWord = false;
                }
            } else {
                inWord = true;
            }
        }
        if (inWord) {
            ++wordCount; 
        }
    }

    file.close();

    std::cout << "Number of characters: " << characterCount << std::endl;
    std::cout << "Number of words: " << wordCount << std::endl;
    std::cout << "Number of spaces: " << spaceCount << std::endl;
    std::cout << "Number of lines: " << lineCount << std::endl;
}

int main() {
    std::string filename;
    std::cout << "Enter the filename: ";
    std::cin >> filename;

    countFileStats(filename);

    return 0;
}
