#include <iostream>

using namespace std;

// Node class represents each node in the linked list
template <typename T>
class Node {
public:
    T data;
    Node* next;

    // Constructor to initialize data and pointers
    Node(T value) : data(value), next(nullptr) {}
};

// Stack class represents the stack ADT using a linked list
template <typename T>
class Stack {
private:
    Node<T>* top; // Pointer to the top of the stack

public:
    // Constructor to initialize an empty stack
    Stack() : top(nullptr) {}

    // Destructor to free memory when the object goes out of scope
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Push an element onto the stack
    void push(T value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = top;
        top = newNode;
        cout << "Pushed " << value << " onto the stack\n";
    }

    // Pop the top element from the stack
    void pop() {
        if (isEmpty()) {
            cerr << "Error: Stack underflow\n";
            return;
        }

        Node<T>* temp = top;
        top = top->next;
        cout << "Popped " << temp->data << " from the stack\n";
        delete temp;
    }

    // Peek at the top element without removing it
    T peek() {
        if (isEmpty()) {
            cerr << "Error: Stack is empty\n";
            return T(); // Return a default-constructed value to indicate an error
        }
        return top->data;
    }

    // Display the elements of the stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }

        cout << "Stack elements: ";
        Node<T>* current = top;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << "\n";
    }
};

int main() {
    Stack<int> stack;
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
                if (value != stack.peek()) {
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
