#include "calculator.h"

#include <cmath>
#include <iostream>
#include <string>

using namespace std;

bool IsOperationWithOperand(const string& token) {
    return token == "+" || token == "-" || token == "*" || token == "/"
           || token == "**" || token == ":";
}

Number ApplyOperation(const string& operation, Number current_number, Number operand) {
    if (operation == "+") {
        return current_number + operand;
    }
    if (operation == "-") {
        return current_number - operand;
    }
    if (operation == "*") {
        return current_number * operand;
    }
    if (operation == "/") {
        return current_number / operand;
    }
    if (operation == "**") {
        return pow(current_number, operand);
    }
    return operand;
}

bool ReadNumber(Number& result) {
    if (!(cin >> result)) {
        cerr << "Error: Numeric operand expected" << endl;
        return false;
    }
    return true;
}

bool RunCalculatorCycle() {
    Number current_number;
    if (!ReadNumber(current_number)) {
        return false;
    }

    Number memory_number = 0;
    bool is_memory_set = false;
    string token;
    while (cin >> token) {
        if (token == "q") {
            return true;
        } else if (token == "=") {
            cout << current_number << endl;
        } else if (token == "c") {
            current_number = 0;
        } else if (token == "s") {
            memory_number = current_number;
            is_memory_set = true;
        } else if (token == "l") {
            if (!is_memory_set) {
                cerr << "Error: Memory is empty" << endl;
                return false;
            }
            current_number = memory_number;
        } else if (IsOperationWithOperand(token)) {
            Number operand;
            if (!ReadNumber(operand)) {
                return false;
            }
            current_number = ApplyOperation(token, current_number, operand);
        } else {
            cerr << "Error: Unknown token " << token << endl;
            return false;
        }
    }
    return true;
}
