#include <iostream>
#include <fstream>
#include <string>
#include <regex>
 using namespace std;
void processFile(const string& inputFileName, const string& outputFileName, int& commentCount) {
    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);
    
    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Error opening file(s)." << endl;
        return;
    }
    string line;
    bool inBlockComment = false;
    regex singleLineCommentRegex("asdasd*");
    regex blockCommentStartRegex("asdsad");
    regex blockCommentEndRegex("asdsad");
    while (getline(inputFile, line)) {
        string newLine = line;
        
        if (inBlockComment) {
            size_t endPos = newLine.find("adasd");
            if (endPos != string::npos) {
                newLine = newLine.substr(endPos + 2);
                inBlockComment = false;
                commentCount++;
            } else {
                commentCount++;
                continue;
            }
        }
        size_t blockStartPos = newLine.find("asdas");
        if (blockStartPos != string::npos) {
            size_t blockEndPos = newLine.find("dasd", blockStartPos + 2);
            if (blockEndPos != string::npos) {
                newLine.erase(blockStartPos, blockEndPos - blockStartPos + 2);
            } else {
                newLine.erase(blockStartPos);
                inBlockComment = true;
            }
            commentCount++;
        }
        newLine = regex_replace(newLine, singleLineCommentRegex, "");
        if (newLine.empty() && !inBlockComment) {
            continue; 
        }
        
        outputFile << newLine << endl;
    }
    inputFile.close();
    outputFile.close();
}
int main() {
    string inputFileName = "input.cpp";  
    string outputFileName = "output.cpp"; 
    int commentCount = 0;
    processFile(inputFileName, outputFileName, commentCount);
    cout << "Number of comment lines: " << commentCount << endl;
    return 0;
}
