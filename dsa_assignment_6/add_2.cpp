#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

int parity(int x) {
    int c=0;
    while(x) { c += (x&1); x >>= 1; }
    return c;
}

Node* insertEnd(Node* head, int val) {
    Node* temp = new Node{val, NULL, NULL};
    if(!head) return temp;
    Node* curr = head;
    while(curr->next) curr = curr->next;
    curr->next = temp;
    temp->prev = curr;
    return head;
}

Node* removeEvenParity(Node* head) {
    Node* curr = head;
    while(curr) {
        if(parity(curr->data) % 2 == 0) {
            Node* del = curr;
            if(curr->prev) curr->prev->next = curr->next;
            else head = curr->next;

            if(curr->next) curr->next->prev = curr->prev;
        }
        curr = curr->next;
    }
    return head;
}

void printList(Node* head) {
    while(head) { cout<<head->data<<" "; head = head->next; }
    cout<<"\n";
}

int main() {
    Node* head = NULL;

    head = insertEnd(head, 9);
    head = insertEnd(head, 11);
    head = insertEnd(head, 34);
    head = insertEnd(head, 6);
    head = insertEnd(head, 13);
    head = insertEnd(head, 21);

    head = removeEvenParity(head);

    printList(head);
    return 0;
}
