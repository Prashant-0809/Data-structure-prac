#include <iostream>
#include <queue>

using namespace std;

// Node class represents each item in our tree
class TreeNode {
public:
    int data;          // Value of the node
    TreeNode* left;     // Pointer to the left child
    TreeNode* right;    // Pointer to the right child

    // Constructor to create a new node with a given value
    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// BinarySearchTree class represents our tree
class BinarySearchTree {
private:
    TreeNode* root;    // Pointer to the root of the tree

public:
    // Constructor to create an empty tree
    BinarySearchTree() : root(nullptr) {}

    // Function to insert a new value into the tree
    void insert(int value) {
        root = insertNode(root, value);
    }

    // Function to delete a value from the tree
    void remove(int value) {
        root = removeNode(root, value);
    }

    // Function to search for a value and change it to a new value
    void searchAndChange(int oldValue, int newValue) {
        root = searchAndChangeValue(root, oldValue, newValue);
    }

    // Function to display the tree elements in different orders
    void display() {
        cout << "Preorder: ";
        displayPreorder(root);
        cout << "\n";

        cout << "Inorder: ";
        displayInorder(root);
        cout << "\n";

        cout << "Postorder: ";
        displayPostorder(root);
        cout << "\n";

        cout << "Level Order: ";
        displayLevelOrder(root);
        cout << "\n";
    }

    // Function to display the height of the tree
    void displayHeight() {
        int height = calculateHeight(root);
        cout << "Tree Height: " << height << "\n";
    }

private:
    // Helper function to insert a new value into the tree
    TreeNode* insertNode(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }

        if (value < node->data) {
            node->left = insertNode(node->left, value);
        } else if (value > node->data) {
            node->right = insertNode(node->right, value);
        }

        return node;
    }

    // Helper function to remove a value from the tree
    TreeNode* removeNode(TreeNode* node, int value) {
        // Implementation of removing a node is a bit more complex
        // but it involves finding the node, removing it, and rearranging the tree.
        // For simplicity, we won't cover it in detail here.
        // For a complete implementation, you might want to refer to more detailed resources.

        // This function will return the modified tree after removing the node.
        return node;
    }

    // Helper function to search for a value and change it to a new value
    TreeNode* searchAndChangeValue(TreeNode* node, int oldValue, int newValue) {
        if (node == nullptr) {
            return nullptr;
        }

        if (oldValue < node->data) {
            node->left = searchAndChangeValue(node->left, oldValue, newValue);
        } else if (oldValue > node->data) {
            node->right = searchAndChangeValue(node->right, oldValue, newValue);
        } else {
            // Node to be changed found
            node->data = newValue;
        }

        return node;
    }

    // Helper function to display the tree in preorder
    void displayPreorder(TreeNode* node) {
        if (node != nullptr) {
            cout << node->data << " ";
            displayPreorder(node->left);
            displayPreorder(node->right);
        }
    }

    // Helper function to display the tree in inorder
    void displayInorder(TreeNode* node) {
        if (node != nullptr) {
            displayInorder(node->left);
            cout << node->data << " ";
            displayInorder(node->right);
        }
    }

    // Helper function to display the tree in postorder
    void displayPostorder(TreeNode* node) {
        if (node != nullptr) {
            displayPostorder(node->left);
            displayPostorder(node->right);
            cout << node->data << " ";
        }
    }

    // Helper function to display the tree in level order
    void displayLevelOrder(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            cout << current->data << " ";

            if (current->left != nullptr) {
                q.push(current->left);
            }

            if (current->right != nullptr) {
                q.push(current->right);
            }
        }
    }

    // Helper function to calculate the height of the tree
    int calculateHeight(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        int leftHeight = calculateHeight(node->left);
        int rightHeight = calculateHeight(node->right);

        return max(leftHeight, rightHeight) + 1;
    }
};

// Main function where the user interacts with the BST
int main() {
    BinarySearchTree bst;
    int choice, oldValue, newValue;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert an element\n";
        cout << "2. Delete an element (Not implemented)\n";
        cout << "3. Search for an element and change its value\n";
        cout << "4. Display elements in different orders\n";
        cout << "5. Display Tree Height\n";
        cout << "6. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to insert: ";
                cin >> newValue;
                bst.insert(newValue);
                break;

            case 2:
                // For simplicity, removing a node is not implemented in this example
                cout << "Removing an element is not implemented in this example.\n";
                break;

            case 3:
                cout << "Enter element to search: ";
                cin >> oldValue;
                cout << "Enter new value: ";
                cin >> newValue;
                bst.searchAndChange(oldValue, newValue);
                break;

            case 4:
                bst.display();
                break;

            case 5:
                bst.displayHeight();
                break;

            case 6:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 6);

    return 0;
}
