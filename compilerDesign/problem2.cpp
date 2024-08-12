#include <iostream>
#include <cctype>
#include <string>
#include <unordered_set>

bool isValidArithmeticExpression(const std::string& expr) {
    for (char ch : expr) {
        if (!std::isdigit(ch) && !std::isalpha(ch) && ch != '+' && ch != '-' && ch != '*' && ch != '/' && ch != ' ' && ch != '(' && ch != ')') {
            return false; 
        }
    }
    return true;
}

void countIdentifiersAndOperators(const std::string& expr, int& identifierCount, int& operatorCount) {
    std::unordered_set<std::string> identifiers;
    std::string currentIdentifier;
    operatorCount = 0;
    identifierCount = 0;

    for (char ch : expr) {
        if (std::isalpha(ch)) {
            currentIdentifier += ch;
        } else {
            if (!currentIdentifier.empty()) {
                identifiers.insert(currentIdentifier);
                currentIdentifier.clear();
            }
            if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
                operatorCount++;
            }
        }
    }
    // Handle the last identifier if there is one
    if (!currentIdentifier.empty()) {
        identifiers.insert(currentIdentifier);
    }

    identifierCount = identifiers.size();
}

int main() {
    std::string expression;
    int identifierCount, operatorCount;

    std::cout << "Enter an arithmetic expression: ";
    std::getline(std::cin, expression);

    if (!isValidArithmeticExpression(expression)) {
        std::cout << "Invalid arithmetic expression.\n";
        return 1;
    }

    countIdentifiersAndOperators(expression, identifierCount, operatorCount);

    std::cout << "Number of unique identifiers: " << identifierCount << "\n";
    std::cout << "Number of operators: " << operatorCount << "\n";

    return 0;
}
