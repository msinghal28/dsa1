#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* getIntersection(Node* h1, Node* h2) {
    if(!h1 || !h2) return NULL;

    Node* a = h1;
    Node* b = h2;

    // When a pointer finishes, jump to other list head
    while(a != b) {
        a = (a == NULL ? h2 : a->next);
        b = (b == NULL ? h1 : b->next);
    }
    return a; // will be NULL or intersection node
}
