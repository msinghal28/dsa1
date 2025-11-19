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

void insertEnd(int val) {
    Node* newNode = new Node(val);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

int sizeDLL(Node* head) {
    int count = 0;
    Node* temp = head;

    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    
    cout << "Size of Doubly Linked List = " 
         << sizeDLL(head) << endl;

    return 0;
}
