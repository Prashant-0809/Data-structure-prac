#include <iostream>
using namespace std;

// Node class represents each node in the linked list
template <typename T>
class Node {
public:
    T data;
    Node* next;

    // Constructor to initialize data and next pointer
    Node(T value) : data(value), next(nullptr) {}
};

// SinglyLinkedList class represents the linked list ADT
template <typename T>
class SinglyLinkedList {
private:
    Node<T>* head; // Pointer to the head of the linked list

public:
    // Constructor to initialize an empty linked list
    SinglyLinkedList() : head(nullptr) {}

    // Destructor to free memory when the object goes out of scope
    ~SinglyLinkedList() {
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Insert an element at the beginning of the linked list
    void insertAtBeginning(T value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = head;
        head = newNode;
    }

    // Insert an element at the i-th position in the linked list
    void insertAtPosition(T value, int position) {
        if (position < 0) {
            cerr << "Invalid position\n";
            return;
        }

        Node<T>* newNode = new Node<T>(value);

        if (position == 0) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node<T>* current = head;
        for (int i = 0; i < position - 1 && current != nullptr; ++i) {
            current = current->next;
        }

        if (current == nullptr) {
            cerr << "Invalid position\n";
            delete newNode;
            return;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    // Remove an element from the beginning of the linked list
    void removeFromBeginning() {
        if (head == nullptr) {
            cerr << "List is empty\n";
            return;
        }

        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }

    // Remove an element from the i-th position in the linked list
    void removeFromPosition(int position) {
        if (position < 0 || head == nullptr) {
            cerr << "Invalid position\n";
            return;
        }

        if (position == 0) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node<T>* current = head;
        Node<T>* previous = nullptr;

        for (int i = 0; i < position && current != nullptr; ++i) {
            previous = current;
            current = current->next;
        }

        if (current == nullptr) {
            cerr << "Invalid position\n";
            return;
        }

        previous->next = current->next;
        delete current;
    }

    // Search for an element and return its pointer
    Node<T>* searchElement(T value) {
        Node<T>* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    // Concatenate two linked lists
    void concatenateLists(SinglyLinkedList<T>& otherList) {
        if (head == nullptr) {
            head = otherList.head;
        } else {
            Node<T>* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = otherList.head;
        }
        otherList.head = nullptr; // Reset the other list to avoid memory leaks
    }

    // Display the linked list
    void display() {
        Node<T>* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    SinglyLinkedList<int> list;
    SinglyLinkedList<int> list2; // Move list2 declaration outside the do-while loop
    int choice, value, position;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at the beginning\n";
        cout << "2. Insert at a specific position\n";
        cout << "3. Remove from the beginning\n";
        cout << "4. Remove from a specific position\n";
        cout << "5. Search for an element\n";
        cout << "6. Concatenate two lists\n";
        cout << "7. Display the list\n";
        cout << "8. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                list.insertAtBeginning(value);
                break;

            case 2:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter position to insert at: ";
                cin >> position;
                list.insertAtPosition(value, position);
                break;

            case 3:
                list.removeFromBeginning();
                break;

            case 4:
                cout << "Enter position to remove from: ";
                cin >> position;
                list.removeFromPosition(position);
                break;

            case 5:
                cout << "Enter value to search: ";
                cin >> value;
                if (list.searchElement(value) != nullptr) {
                    cout << "Element found in the list.\n";
                } else {
                    cout << "Element not found in the list.\n";
                }
                break;

            case 6:
                cout << "Enter elements for the second list (enter -1 to stop):\n";
                while (true) {
                    cin >> value;
                    if (value == -1) {
                        break;
                    }
                    list2.insertAtBeginning(value);
                }
                list.concatenateLists(list2);
                break;

            case 7:
                cout << "Current list: ";
                list.display();
                break;

            case 8:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 8);

    return 0;
}