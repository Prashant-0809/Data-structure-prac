#include <iostream>

using namespace std;

// CircularQueue class represents the queue ADT using a circular array
class CircularQueue {
private:
    static const int MAX_SIZE = 20; // Maximum size of the circular queue
    int arr[MAX_SIZE];              // Array to store elements of the circular queue
    int front;                      // Index of the front element
    int rear;                       // Index of the rear element

public:
    // Constructor to initialize an empty circular queue
    CircularQueue() : front(-1), rear(-1) {}

    // Check if the circular queue is empty
    bool isEmpty() {
        return front == -1 && rear == -1;
    }

    // Check if the circular queue is full
    bool isFull() {
        return (rear + 1) % MAX_SIZE == front;
    }

    // Enqueue (insert) an element into the circular queue
    void enqueue(int value) {
        if (isFull()) {
            cout << "Error: Circular Queue is full. Cannot enqueue.\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0; // Set front and rear to 0 for the first element
        } else {
            rear = (rear + 1) % MAX_SIZE; // Move rear circularly
        }

        arr[rear] = value;
        cout << "Enqueued " << value << " into the circular queue\n";
    }

    // Dequeue (remove) an element from the circular queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Error: Circular Queue is empty. Cannot dequeue.\n";
            return;
        }

        cout << "Dequeued " << arr[front] << " from the circular queue\n";

        if (front == rear) {
            // Reset front and rear to -1 if the last element is dequeued
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE; // Move front circularly
        }
    }

    // Display the elements of the circular queue
    void display() {
        if (isEmpty()) {
            cout << "Circular Queue is empty\n";
            return;
        }

        cout << "Circular Queue elements: ";
        int i = front;

        do {
            cout << arr[i] << " ";
            i = (i + 1) % MAX_SIZE; // Move i circularly
        } while (i != (rear + 1) % MAX_SIZE); // Loop until i reaches one position after rear

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
