#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *next, *prev, *random;
};

Node* fixRandom(Node* head) {
    Node* curr = head;
    while(curr) {
        if(curr->random && curr->random->data != curr->data+1) {
            curr->random = curr->next; // expected rule
        }
        curr = curr->next;
    }
    return head;
}

int main() {
    Node* n1 = new Node{1,NULL,NULL,NULL};
    Node* n2 = new Node{2,NULL,NULL,NULL};
    Node* n3 = new Node{3,NULL,NULL,NULL};

    n1->next = n2; n2->prev = n1;
    n2->next = n3; n3->prev = n2;

    n1->random = n3; // wrong
    n2->random = n3;
    n3->random = n2; // wrong

    fixRandom(n1);

    cout<<"Random pointers after correction:\n";
    cout<<n1->random->data<<"\n";
    cout<<n2->random->data<<"\n";
    cout<<n3->random->data<<"\n";

    return 0;
}
