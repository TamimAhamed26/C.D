#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

bool isDuplicateFunction(const string& functionName, const string functions[], int functionCount) {
    for (int i = 0; i < functionCount; ++i) {
        if (functions[i] == functionName) {
            return true;
        }
    }
    return false;
}

bool isDuplicateOperator(const string& op, const string operators[], int operatorCount) {
    for (int i = 0; i < operatorCount; ++i) {
        if (operators[i] == op) {
            return true;
        }
    }
    return false;
}

int main() {
    ifstream inputFile("program.cpp");

    if (!inputFile.is_open()) {
        cerr << "Error opening file 'program.cpp'" << endl;
        return 1;
    }

    const int maxFunctions = 100;
    const int maxOperators = 100;

    string functions[maxFunctions];
    string operators[maxOperators];

    int functionCount = 0;
    int operatorCount = 0;

    string line;

    while (getline(inputFile, line)) {
        istringstream iss(line);

        string word;
        while (iss >> word) {
            if (word == "int" || word == "void" || word == "double" || word == "float" || word == "char"|| word == "bool") {
                iss >> word;
                if (word.find('(') != string::npos) {
                    string functionName = word.substr(0, word.find('('));

                    // Exclude "main" from being considered as a user-defined function
                    if (functionName != "main" && !isDuplicateFunction(functionName, functions, functionCount)) {
                        functions[functionCount++] = functionName;
                    }
                }
            }

            if (word == "+" || word == "-" || word == "*" || word == "/" || word == "=") {
                if (!isDuplicateOperator(word, operators, operatorCount)) {
                    operators[operatorCount++] = word;
                }
            }
        }
    }

    inputFile.close();

    cout << "User Defined Functions:" << endl;
    for (int i = 0; i < functionCount; ++i) {
        cout << "Function-" << i + 1 << ": " << functions[i] << endl;
    }
    cout << "Total number of user-defined functions: " << functionCount << endl;

    cout << "\nOperators:" << endl;
    for (int i = 0; i < operatorCount; ++i) {
        cout << "Operator-" << i + 1 << ": " << operators[i] << endl;
    }
    cout << "Total number of operators: " << operatorCount << endl;

    return 0;
}
