//WAP to find the number of occurences of a  word in file and replace that with another Word

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

void findAndReplaceInFile(const string &filename, const string &oldWord, const string &newWord) {
    ifstream file(filename);
    if (!file) {
        cerr << "Could not open the file!" << endl;
        return;
    }

    stringstream buffer;
    buffer << file.rdbuf();
    string content = buffer.str();

    size_t pos = 0;
    int count = 0;
    while ((pos = content.find(oldWord, pos)) != string::npos) {
        ++count;
        pos += oldWord.length();
    }

    pos = 0;
    while ((pos = content.find(oldWord, pos)) != string::npos) {
        content.replace(pos, oldWord.length(), newWord);
        pos += newWord.length();
    }

    file.close();

    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Could not open the file for writing!" << endl;
        return;
    }
    outFile << content;
    outFile.close();

    cout << "The word '" << oldWord << "' was found " << count << " times and replaced with '" << newWord << "'." << endl;
}

int main (){
  string oldWord, newWord;
  cout<<"Enter old Word";
  cin >> oldWord;
  cout<<"Enter new Word";
  cin >> newWord;
  string file = "file.txt";
  findAndReplaceInFile(file,oldWord,newWord);
  
  return 0;
}