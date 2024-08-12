#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void removeComments(const string& inputFilename, const string& outputFilename, int& commentCount) {
    ifstream inputFile(inputFilename);
    ofstream outputFile(outputFilename);

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Error: Could not open file(s)." << endl;
        return;
    }

        string line;
        bool inBlockComment = false;

    while (getline(inputFile, line)) {
        string processedLine;
        bool isCommentLine = false;
        size_t i = 0;

        while (i < line.length()) {
            if (!inBlockComment && i + 1 < line.length() && line[i] == '/' && line[i + 1] == '/') {

                isCommentLine = true;
                break;
            } else if (!inBlockComment && i + 1 < line.length() && line[i] == '/' && line[i + 1] == '*') {
                
                inBlockComment = true;
                isCommentLine = true;
                i += 2;
            } else if (inBlockComment && i + 1 < line.length() && line[i] == '*' && line[i + 1] == '/') {
               
                inBlockComment = false;
                i += 2;
            } else if (!inBlockComment) {
                processedLine += line[i];
                i++;
            } else {
                i++;
            }
        }

        if (isCommentLine) {
            commentCount++;
        } else if (!processedLine.empty()) {
            outputFile << processedLine << endl;
        }
    }

    inputFile.close();
    outputFile.close();
}

int main() {
    string inputFilename, outputFilename;
    int commentCount = 0;

    cout << "Enter the input filename: ";
    cin >> inputFilename;

    cout << "Enter the output filename: ";
    cin >> outputFilename;

    removeComments(inputFilename, outputFilename, commentCount);

    cout << "Number of comment lines removed: " << commentCount << endl;
    cout << "Processed file saved as: " << outputFilename << endl;

    return 0;
}