#include <iostream>

using namespace std;

// Node class represents each node in the circular linked list
template <typename T>
class Node {
public:
    T data;
    Node* next;

    // Constructor to initialize data and pointers
    Node(T value) : data(value), next(nullptr) {}
};

// CircularLinkedList class represents the circular linked list ADT
template <typename T>
class CircularLinkedList {
private:
    Node<T>* head; // Pointer to the head of the circular linked list

public:
    // Constructor to initialize an empty circular linked list
    CircularLinkedList() : head(nullptr) {}

    // Destructor to free memory when the object goes out of scope
    ~CircularLinkedList() {
        if (head == nullptr) {
            return;
        }

        Node<T>* current = head->next;
        while (current != nullptr && current != head) {
            Node<T>* temp = current;
            current = current->next;
            delete temp;
        }

        // Delete the head node
        delete head;
    }

    // Insert an element at the front of the circular linked list
    void insertAtFront(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (head == nullptr) {
            head = newNode;
            head->next = head; // Point to itself to form a circular structure
        } else {
            newNode->next = head->next;
            head->next = newNode;
        }
    }

    // Insert an element after an element y in the circular linked list
    void insertAfterElement(T x, T y) {
        if (head == nullptr) {
            cerr << "List is empty\n";
            return;
        }

        Node<T>* current = head->next;
        while (current != nullptr && current != head && current->data != y) {
            current = current->next;
        }

        if (current == nullptr || current == head) {
            cerr << "Element " << y << " not found in the list\n";
            return;
        }

        Node<T>* newNode = new Node<T>(x);
        newNode->next = current->next;
        current->next = newNode;
    }

    // Insert an element at the back of the circular linked list
    void insertAtBack(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (head == nullptr) {
            head = newNode;
            head->next = head; // Point to itself to form a circular structure
        } else {
            newNode->next = head->next;
            head->next = newNode;
            head = newNode;
        }
    }

    // Remove an element from the back of the circular linked list
    void removeFromBack() {
        if (head == nullptr) {
            cerr << "List is empty\n";
            return;
        }

        Node<T>* current = head->next;
        Node<T>* prev = nullptr;

        // Traverse to the last node
        while (current != nullptr && current != head) {
            prev = current;
            current = current->next;
        }

        if (current == nullptr) {
            cerr << "Error: Head node not found\n";
            return;
        }

        // Remove the last node
        prev->next = current->next;

        // If the head is the last node, update the head
        if (current == head) {
            head = prev;
        }

        delete current;
    }

    // Remove an element from the front of the circular linked list
    void removeFromFront() {
        if (head == nullptr) {
            cerr << "List is empty\n";
            return;
        }

        Node<T>* temp = head->next;
        if (temp == head) {
            // If there's only one node, reset the head to null
            head = nullptr;
        } else {
            head->next = temp->next;
        }

        delete temp;
    }

    // Remove the element x from the circular linked list
    void removeElement(T x) {
        if (head == nullptr) {
            cerr << "List is empty\n";
            return;
        }

        Node<T>* current = head->next;
        Node<T>* prev = nullptr;

        // Traverse to find the node with data x
        while (current != nullptr && current != head && current->data != x) {
            prev = current;
            current = current->next;
        }

        if (current == nullptr || current == head) {
            cerr << "Element " << x << " not found in the list\n";
            return;
        }

        // Remove the node
        prev->next = current->next;

        // If the head is the node to be removed, update the head
        if (current == head) {
            head = prev;
        }

        delete current;
    }

    // Search for an element and return its pointer
    Node<T>* searchElement(T value) {
        if (head == nullptr) {
            return nullptr;
        }

        Node<T>* current = head->next;
        while (current != nullptr && current != head) {
            if (current->data == value) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    // Concatenate two circular linked lists
    void concatenateLists(CircularLinkedList<T>& otherList) {
        if (head == nullptr) {
            head = otherList.head;
        } else if (otherList.head != nullptr) {
            Node<T>* current = head->next;
            while (current->next != head) {
                current = current->next;
            }
            current->next = otherList.head->next;
            otherList.head->next = head;
            head = otherList.head;
            otherList.head = nullptr; // Reset the other list to avoid memory leaks
        }
    }

    // Display the circular linked list
    void display() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }

        Node<T>* current = head->next;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);

        cout << endl;
    }
};

int main() {
    CircularLinkedList<int> list;
    CircularLinkedList<int> list2; // Move list2 declaration outside the do-while loop
    int choice, value, y;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at the front\n";
        cout << "2. Insert after an element\n";
        cout << "3. Insert at the back\n";
        cout << "4. Remove from the back\n";
        cout << "5. Remove from the front\n";
        cout << "6. Remove an element\n";
        cout << "7. Search for an element\n";
        cout << "8. Concatenate two lists\n";
        cout << "9. Display the list\n";
        cout << "10. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at the front: ";
                cin >> value;
                list.insertAtFront(value);
                break;

            case 2:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter element after which to insert: ";
                cin >> y;
                list.insertAfterElement(value, y);
                break;

            case 3:
                cout << "Enter value to insert at the back: ";
                cin >> value;
                list.insertAtBack(value);
                break;

            case 4:
                list.removeFromBack();
                break;

            case 5:
                list.removeFromFront();
                break;

            case 6:
                cout << "Enter element to remove: ";
                cin >> value;
                list.removeElement(value);
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
                    list2.insertAtBack(value);
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
