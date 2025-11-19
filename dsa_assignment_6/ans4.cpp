#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

Node* head = nullptr;

void insertAtbeginning(int num) {
    Node* newNode = new Node(num);
    if (!head) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insertAfterValue(int value, int num) {
    Node* newNode = new Node(num);
    if (!head) {
        head = newNode;
        return;
    }
    Node* current = head;
    while (current) {
        if (current->data == value) {
            newNode->next = current->next;
            newNode->prev = current;
            if (current->next) current->next->prev = newNode;
            current->next = newNode;
            return;
        }
        current = current->next;
    }
    cout << "Value " << value << " not found in the list." << endl;
}

void deleteNode(int num) {
    Node* current = head;
    while (current) {
        if (current->data == num) {
            if (current->prev) current->prev->next = current->next;
            if (current->next) current->next->prev = current->prev;
            if (current == head) head = current->next;
            delete current;
            return;
        }
        current = current->next;
    }
    cout << "Node with value " << num << " not found." << endl;
}

void display() {
    Node* current = head;
    if (!current) {
        cout << "List is empty." << endl;
        return;
    }
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void search(int num) {
    Node* current = head;
    int position = 1;
    while (current) {
        if (current->data == num) {
            cout << "Value " << num << " found at position " << position << "." << endl;
            return;
        }
        current = current->next;
        position++;
    }
    cout << "Value " << num << " not found in the list." << endl;
}

int findSize(Node* curr) {
    int size = 0;
    while (curr != NULL) {
        size++;
        curr = curr->next;
    }
    return size;
}

int checkPalindrome(Node* head) {
    if (!head || !head->next) return 1;

    Node* left = head;
    Node* right = head;

    // Move right pointer to end
    while (right->next != NULL) right = right->next;

    // Compare from both ends
    while (left != right && right->next != left) {
        if (left->data != right->data) return 0;
        left = left->next;
        right = right->prev;
    }
    return 1;
}

int main() {
    char choice;
    while (true) {
        cout << "\nMenu:\n";
        cout << "a. Insert at beginning\n";
        cout << "b. Insert after a value\n";
        cout << "c. Delete a node\n";
        cout << "d. Display list\n";
        cout << "e. Search for a value\n";
        cout << "f. Find size\n";
        cout << "g. Check palindrome\n";
        cout << "h. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 'a') {
            int num;
            cout << "number to insert at beginning: ";
            cin >> num;
            insertAtbeginning(num);

        } else if (choice == 'b') {
            int value, num;
            cout << "value after which to insert: ";
            cin >> value;
            cout << "number to insert: ";
            cin >> num;
            insertAfterValue(value, num);

        } else if (choice == 'c') {
            int del;
            cout << "Enter node to be deleted: ";
            cin >> del;
            deleteNode(del);

        } else if (choice == 'd') {
            display();

        } else if (choice == 'e') {
            int num;
            cout << "Enter the value to search for: ";
            cin >> num;
            search(num);

        } else if (choice == 'f') {
            cout << "Size: " << findSize(head) << endl;

        } else if (choice == 'g') {
            if (checkPalindrome(head))
                cout << "The list IS a palindrome." << endl;
            else
                cout << "The list is NOT a palindrome." << endl;

        } else if (choice == 'h') {
            cout << "Exiting program." << endl;
            break;

        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
