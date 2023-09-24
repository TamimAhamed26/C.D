#include <iostream>
#include <string>

using namespace std;

int main() {
    string expression;
    string operators;

    cout << "Enter an expression: ";
    cin >> expression;

    for (char ch : expression) {
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            operators += ch;
        }
    }

    if (!operators.empty()) {
        cout << "Operators in the expression are: " << operators << endl;
    } else {
        cout << "No operators found in the expression." << endl;
    }

    return 0;
}
