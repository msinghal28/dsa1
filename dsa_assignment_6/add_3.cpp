#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* insertEnd(Node* head, int val) {
    Node* t = new Node{val, NULL, NULL};
    if(!head) return t;
    Node* c = head;
    while(c->next) c = c->next;
    c->next = t;
    t->prev = c;
    return head;
}

Node* reverseK(Node* head, int k) {
    if(!head) return NULL;

    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    int count = 0;

    while(curr && count < k) {
        next = curr->next;
        curr->next = prev;
        curr->prev = next;
        prev = curr;
        curr = next;
        count++;
    }

    if(next)
        head->next = reverseK(next, k);

    return prev;
}

void print(Node* head) {
    while(head) {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<"\n";
}

int main() {
    Node* head = NULL;

    head = insertEnd(head, 1);
    head = insertEnd(head, 2);
    head = insertEnd(head, 3);
    head = insertEnd(head, 4);
    head = insertEnd(head, 5);
    head = insertEnd(head, 6);

    int k = 2;

    head = reverseK(head, k);

    print(head);
    return 0;
}
