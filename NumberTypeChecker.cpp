#include <iostream>
#include <fstream>
using namespace std;
bool isInteger(const string& str) {
    for (char c : str) {
        if (!isdigit(c) && c != '-') {
            return false;
        }
    }
    return true;
}

void check(const string& numberStr) {
    if (isInteger(numberStr)) {
        cout << numberStr << " is an Integer number." << endl;
    } else {
        cout << numberStr << " is a Real number." << endl;
    }
}

int main() {
    ifstream inputFile("numberList.txt");

    if (!inputFile.is_open()) {
        cout << "File doesn't exist!" << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line)) {
        if (line.empty()) {
            cout << "Empty line found." << endl;
        } else if (isInteger(line) || (line.front() == '-' && isInteger(line.substr(1)))) {
            check(line);
        } else {
            cout << line << " is not a valid number." << endl;
        }
    }

    inputFile.close();

    return 0;
}
