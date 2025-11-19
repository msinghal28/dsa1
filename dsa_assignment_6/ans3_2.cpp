#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

Node* head = nullptr;

void insertEnd(int val) {
    Node* newNode = new Node(val);

    if (head == nullptr) {
        head = newNode;
        head->next = head; // circular
        return;
    }

    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}

int sizeCLL(Node* head) {
    if (head == nullptr) return 0;

    int count = 0;
    Node* temp = head;

    do {
        count++;
        temp = temp->next;
    } while (temp != head);

    return count;
}

int main() {
    insertEnd(20);
    insertEnd(40);
    insertEnd(60);

    cout << "Size of Circular Linked List = "
         << sizeCLL(head) << endl;

    return 0;
}
