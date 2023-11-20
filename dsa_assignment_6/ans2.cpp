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

void insertAtEnd(int num) {
    Node* newNode = new Node(num);

    if (!head) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

void makeCircular() {
    if (!head) return;

    Node* tail = head;
    while (tail->next != NULL)
        tail = tail->next;

    tail->next = head;
    head->prev = tail;
}

void displayCircular(Node* head) {
    if (!head) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << head->data;  // print head again
    cout << endl;
}

int main() {
    insertAtEnd(20);
    insertAtEnd(100);
    insertAtEnd(40);
    insertAtEnd(80);
    insertAtEnd(60);

    makeCircular();
    displayCircular(head);

    return 0;
}
