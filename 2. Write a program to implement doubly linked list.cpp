#include <iostream>
using namespace std;

// Node class represents each node in the doubly linked list
template <typename T>
class Node {
public:
    T data;
    Node* prev;
    Node* next;

    // Constructor to initialize data and pointers
    Node(T value) : data(value), prev(nullptr), next(nullptr) {}
};

// DoublyLinkedList class represents the doubly linked list ADT
template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head; // Pointer to the head of the doubly linked list

public:
    // Constructor to initialize an empty doubly linked list
    DoublyLinkedList() : head(nullptr) {}

    // Destructor to free memory when the object goes out of scope
    ~DoublyLinkedList() {
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Insert an element at the beginning of the doubly linked list
    void insertAtBeginning(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (head != nullptr) {
            newNode->next = head;
            head->prev = newNode;
        }
        head = newNode;
    }

    // Insert an element at the i-th position in the doubly linked list
    void insertAtPosition(T value, int position) {
        if (position < 0) {
            cerr << "Invalid position\n";
            return;
        }

        Node<T>* newNode = new Node<T>(value);

        if (position == 0) {
            if (head != nullptr) {
                newNode->next = head;
                head->prev = newNode;
            }
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

        newNode->prev = current;
        newNode->next = current->next;

        if (current->next != nullptr) {
            current->next->prev = newNode;
        }

        current->next = newNode;
    }

    // Insert an element at the end of the doubly linked list
    void insertAtEnd(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node<T>* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = newNode;
        newNode->prev = current;
    }

    // Remove an element from the beginning of the doubly linked list
    void removeFromBeginning() {
        if (head == nullptr) {
            cerr << "List is empty\n";
            return;
        }

        Node<T>* temp = head;
        head = head->next;

        if (head != nullptr) {
            head->prev = nullptr;
        }

        delete temp;
    }

    // Remove an element from the i-th position in the doubly linked list
    void removeFromPosition(int position) {
        if (position < 0 || head == nullptr) {
            cerr << "Invalid position\n";
            return;
        }

        if (position == 0) {
            Node<T>* temp = head;
            head = head->next;

            if (head != nullptr) {
                head->prev = nullptr;
            }

            delete temp;
            return;
        }

        Node<T>* current = head;
        for (int i = 0; i < position && current != nullptr; ++i) {
            current = current->next;
        }

        if (current == nullptr) {
            cerr << "Invalid position\n";
            return;
        }

        if (current->prev != nullptr) {
            current->prev->next = current->next;
        }

        if (current->next != nullptr) {
            current->next->prev = current->prev;
        }

        delete current;
    }

    // Remove an element from the end of the doubly linked list
    void removeFromEnd() {
        if (head == nullptr) {
            std::cerr << "List is empty\n";
            return;
        }

        Node<T>* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }

        if (current->prev != nullptr) {
            current->prev->next = nullptr;
        } else {
            head = nullptr;
        }

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

    // Concatenate two doubly linked lists
    void concatenateLists(DoublyLinkedList<T>& otherList) {
        if (head == nullptr) {
            head = otherList.head;
        } else {
            Node<T>* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = otherList.head;
            if (otherList.head != nullptr) {
                otherList.head->prev = current;
            }
        }
        otherList.head = nullptr; // Reset the other list to avoid memory leaks
    }

    // Display the doubly linked list
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
    DoublyLinkedList<int> list;
    DoublyLinkedList<int> list2; // Move list2 declaration outside the do-while loop
    int choice, value, position;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at the beginning\n";
        cout << "2. Insert at a specific position\n";
        cout << "3. Insert at the end\n";
        cout << "4. Remove from the beginning\n";
        cout << "5. Remove from a specific position\n";
        cout << "6. Remove from the end\n";
        cout << "7. Search for an element\n";
        cout << "8. Concatenate two lists\n";
        cout << "9. Display the list\n";
        cout << "10. Exit\n";

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
                cout << "Enter value to insert: ";
                cin >> value;
                list.insertAtEnd(value);
                break;

            case 4:
                list.removeFromBeginning();
                break;

            case 5:
                cout << "Enter position to remove from: ";
                cin >> position;
                list.removeFromPosition(position);
                break;

            case 6:
                list.removeFromEnd();
                break;

            case 7:
                cout << "Enter value to search: ";
                cin >> value;
                if (list.searchElement(value) != nullptr) {
                    cout << "Element found in the list.\n";
                } else {
                    cout << "Element not found in the list.\n";
                }
                break;

            case 8:
                cout << "Enter elements for the second list (enter -1 to stop):\n";
                while (true) {
                    cin >> value;
                    if (value == -1) {
                        break;
                    }
                    list2.insertAtEnd(value);
                }
                list.concatenateLists(list2);
                break;

            case 9:
                cout << "Current list: ";
                list.display();
                break;

            case 10:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 10);

    return 0;
}
