#include <iostream>
using namespace std;

class Stack {
private:
    static const int MAX_SIZE = 100; // Maximum size of the stack
    int arr[MAX_SIZE];               // Array to store elements of the stack
    int top;                         // Index of the top element

public:
    // Constructor to initialize an empty stack
    Stack() : top(-1) {}

    // Check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Check if the stack is full
    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    // Push an element onto the stack
    void push(int value) {
        if (isFull()) {
            cerr << "Error: Stack overflow\n";
            return;
        }
        arr[++top] = value;
        cout << "Pushed " << value << " onto the stack\n";
    }

    // Pop the top element from the stack
    void pop() {
        if (isEmpty()) {
            cerr << "Error: Stack underflow\n";
            return;
        }
        cout << "Popped " << arr[top--] << " from the stack\n";
    }

    // Peek at the top element without removing it
    int peek() {
        if (isEmpty()) {
            cerr << "Error: Stack is empty\n";
            return -1; // Return a special value to indicate an error
        }
        return arr[top];
    }

    // Display the elements of the stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <= top; ++i) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    Stack stack;
    int choice, value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                stack.push(value);
                break;

            case 2:
                stack.pop();
                break;

            case 3:
                value = stack.peek();
                if (value != -1) {
                    cout << "Top element: " << value << "\n";
                }
                break;

            case 4:
                stack.display();
                break;

            case 5:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 5);

    return 0;
}
