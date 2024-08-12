#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

void findAndReplaceInFile(const std::string &filename, const std::string &oldWord, const std::string &newWord) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Could not open the file!" << std::endl;
        return;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string content = buffer.str();

    // Counting occurrences
    size_t pos = 0;
    int count = 0;
    while ((pos = content.find(oldWord, pos)) != std::string::npos) {
        ++count;
        pos += oldWord.length();
    }

    // Replacing occurrences
    pos = 0;
    while ((pos = content.find(oldWord, pos)) != std::string::npos) {
        content.replace(pos, oldWord.length(), newWord);
        pos += newWord.length();
    }

    file.close();

    // Writing back to the file
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Could not open the file for writing!" << std::endl;
        return;
    }
    outFile << content;
    outFile.close();

    std::cout << "The word '" << oldWord << "' was found " << count << " times and replaced with '" << newWord << "'." << std::endl;
}

int main() {
    std::string filename, oldWord, newWord;
    std::cout << "Enter the filename: ";
    std::cin >> filename;
    std::cout << "Enter the word to find: ";
    std::cin >> oldWord;
    std::cout << "Enter the word to replace with: ";
    std::cin >> newWord;

    findAndReplaceInFile(filename, oldWord, newWord);

    return 0;
}
