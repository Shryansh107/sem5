#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void removeComments(const string& inputFile, const string& outputFile, int& commentCount) {
    ifstream inputObj(inputFile);
    ofstream outputObj(outputFile);

    if (!inputObj.is_open() || !outputObj.is_open()) {
        cerr << "Error: Could not open file(s)." << endl;
        return;
    }

        string line;
        bool inBlockComment = false;

    while (getline(inputObj, line)) {
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
        if (!outputObj.is_open()) {
                cerr << "Error: Could not open file(s)." << endl;
                return;
            }
            
        if (isCommentLine) {
            commentCount++;
            cout<<"comment line found"<< commentCount <<endl;
        } else if (!processedLine.empty()) {
            outputObj << processedLine << endl;
        }
    }

    inputObj.close();
    outputObj.close();
}

int main() {
    string inputFile, outputFile;
    int commentCount = 0;
    inputFile = "input.cpp";
    outputFile = "output.cpp";

    removeComments(inputFile, outputFile, commentCount);

    cout << "file generated successfully";
    cout << "Number of comment lines removed: " << commentCount << endl;

    return 0;
}