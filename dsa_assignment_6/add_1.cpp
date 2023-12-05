#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* insertEnd(Node* head, int val) {
    Node* temp = new Node{val, NULL};
    if(!head) {
        temp->next = temp;
        return temp;
    }
    Node* curr = head;
    while(curr->next != head)
        curr = curr->next;
    curr->next = temp;
    temp->next = head;
    return head;
}

void splitCircular(Node* head, Node*& head1, Node*& head2) {
    if(!head) return;

    Node* slow = head;
    Node* fast = head;

    while(fast->next != head && fast->next->next != head) {
        fast = fast->next->next;
        slow = slow->next;
    }

    // slow is mid
    head1 = head;
    head2 = slow->next;
    slow->next = head1;

    // fix end of second list
    if(fast->next == head) fast->next = head2;
    else fast->next->next = head2;
}

void printCircular(Node* head) {
    if(!head) return;
    Node* temp = head;
    do {
        cout<<temp->data<<" ";
        temp = temp->next;
    } while(temp != head);
    cout<<"\n";
}

int main() {
    Node* head = NULL;
    head = insertEnd(head, 10);
    head = insertEnd(head, 2);
    head = insertEnd(head, 4);
    head = insertEnd(head, 9);

    Node *h1=NULL, *h2=NULL;
    splitCircular(head, h1, h2);

    cout << "First half: ";
    printCircular(h1);
    cout << "Second half: ";
    printCircular(h2);

    return 0;
}
