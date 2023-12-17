#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

// Function to evaluate a prefix expression
int evaluatePrefix(const string& prefixExpression) {
    stack<int> operandStack; // Stack to store operands

    // Iterate through each character in the prefix expression in reverse order
    for (int i = prefixExpression.size() - 1; i >= 0; --i) {
        char ch = prefixExpression[i];

        // If the character is a digit, push it onto the stack
        if (isdigit(ch)) {
            operandStack.push(ch - '0'); // Convert char to int and push onto the stack
        } else {
            // If the character is an operator, pop two operands, perform the operation, and push the result
            int operand1 = operandStack.top();
            operandStack.pop();

            int operand2 = operandStack.top();
            operandStack.pop();

            switch (ch) {
                case '+':
                    operandStack.push(operand1 + operand2);
                    break;
                case '-':
                    operandStack.push(operand1 - operand2);
                    break;
                case '*':
                    operandStack.push(operand1 * operand2);
                    break;
                case '/':
                    operandStack.push(operand1 / operand2);
                    break;
                default:
                    cerr << "Error: Invalid operator\n";
                    return 0; // Indicate an error
            }
        }
    }

    // The final result should be on the top of the stack
    if (!operandStack.empty()) {
        return operandStack.top();
    } else {
        cerr << "Error: Invalid prefix expression\n";
        return 0; // Indicate an error
    }
}

// Function to evaluate a postfix expression
int evaluatePostfix(const string& postfixExpression) {
    stack<int> operandStack; // Stack to store operands

    // Iterate through each character in the postfix expression
    for (char ch : postfixExpression) {
        // If the character is a digit, push it onto the stack
        if (isdigit(ch)) {
            operandStack.push(ch - '0'); // Convert char to int and push onto the stack
        } else {
            // If the character is an operator, pop two operands, perform the operation, and push the result
            int operand2 = operandStack.top();
            operandStack.pop();

            int operand1 = operandStack.top();
            operandStack.pop();

            switch (ch) {
                case '+':
                    operandStack.push(operand1 + operand2);
                    break;
                case '-':
                    operandStack.push(operand1 - operand2);
                    break;
                case '*':
                    operandStack.push(operand1 * operand2);
                    break;
                case '/':
                    operandStack.push(operand1 / operand2);
                    break;
                default:
                    cerr << "Error: Invalid operator\n";
                    return 0; // Indicate an error
            }
        }
    }

    // The final result should be on the top of the stack
    if (!operandStack.empty()) {
        return operandStack.top();
    } else {
        cerr << "Error: Invalid postfix expression\n";
        return 0; // Indicate an error
    }
}

int main() {
    string expression;
    char choice;

    cout << "Choose the expression type (P for Prefix, O for Postfix): ";
    cin >> choice;

    cout << "Enter the expression: ";
    cin.ignore(); // Ignore the newline character left by previous input
    getline(cin, expression);

    int result = 0;

    switch (choice) {
        case 'P':
        case 'p':
            result = evaluatePrefix(expression);
            break;
        case 'O':
        case 'o':
            result = evaluatePostfix(expression);
            break;
        default:
            cerr << "Invalid choice. Please choose P or O.\n";
            return 1; // Indicate an error
    }

    if (result != 0) {
        cout << "Result: " << result << endl;
    }

    return 0;
}
