#include <iostream>

using namespace std;

// Node class represents each node in the circular linked list
class Node {
public:
    int data;
    Node* next;

    // Constructor to initialize data and next pointer
    Node(int value) : data(value), next(nullptr) {}
};

// CircularQueue class represents the queue ADT using a circular linked list
class CircularQueue {
private:
    Node* front; // Pointer to the front of the circular queue
    Node* rear;  // Pointer to the rear of the circular queue

public:
    // Constructor to initialize an empty circular queue
    CircularQueue() : front(nullptr), rear(nullptr) {}

    // Destructor to free memory when the object goes out of scope
    ~CircularQueue() {
        // Iterate through the circular queue and delete nodes
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    // Check if the circular queue is empty
    bool isEmpty() {
        return front == nullptr && rear == nullptr;
    }

    // Enqueue (insert) an element into the circular queue
    void enqueue(int value) {
        Node* newNode = new Node(value);

        if (isEmpty()) {
            // If the queue is empty, set front and rear to the new node
            front = rear = newNode;
        } else {
            // Otherwise, add the new node after the rear and update rear
            rear->next = newNode;
            rear = newNode;
        }

        // Make the circular connection
        rear->next = front;

        cout << "Enqueued " << value << " into the circular queue\n";
    }

    // Dequeue (remove) an element from the circular queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Error: Circular Queue is empty. Cannot dequeue.\n";
            return;
        }

        // Store the data of the front node to be dequeued
        int dequeuedValue = front->data;

        // If there is only one node, set front and rear to nullptr
        if (front == rear) {
            delete front;
            front = rear = nullptr;
        } else {
            // Otherwise, move front to the next node and delete the old front
            Node* temp = front;
            front = front->next;
            delete temp;

            // Update the circular connection
            rear->next = front;
        }

        cout << "Dequeued " << dequeuedValue << " from the circular queue\n";
    }

    // Display the elements of the circular queue
    void display() {
        if (isEmpty()) {
            cout << "Circular Queue is empty\n";
            return;
        }

        cout << "Circular Queue elements: ";
        Node* current = front;

        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != front);

        cout << "\n";
    }
};

int main() {
    CircularQueue circularQueue;
    int choice, value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                circularQueue.enqueue(value);
                break;

            case 2:
                circularQueue.dequeue();
                break;

            case 3:
                circularQueue.display();
                break;

            case 4:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 4);

    return 0;
}
