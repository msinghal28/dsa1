#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int x){ return new Node{x,NULL,NULL}; }

void convertToDLL(Node* root, Node*& head){
    static Node* prev = NULL;
    if(!root) return;

    convertToDLL(root->left, head);

    if(prev == NULL)
        head = root;
    else{
        prev->right = root;
        root->left = prev;
    }
    prev = root;

    convertToDLL(root->right, head);
}

Node* mergeDLL(Node* a, Node* b){
    if(!a) return b;
    if(!b) return a;

    Node* head = NULL;
    Node* tail = NULL;

    while(a && b){
        Node* temp;
        if(a->data < b->data){
            temp = a;
            a = a->right;
        } else {
            temp = b;
            b = b->right;
        }

        temp->left = tail;
        if(tail) tail->right = temp;
        else head = temp;
        tail = temp;
    }

    Node* rem = (a ? a : b);
    while(rem){
        rem->left = tail;
        if(tail) tail->right = rem;
        else head = rem;
        tail = rem;
        rem = rem->right;
    }

    return head;
}

void printDLL(Node* head){
    while(head){
        cout<<head->data<<" <--> ";
        head = head->right;
    }
    cout<<"null\n";
}

int main(){
    // First BST
    Node* T1 = newNode(20);
    T1->left = newNode(10);
    T1->right = newNode(30);
    T1->left->right = newNode(15);
    T1->right->left = newNode(25);
    T1->right->right = newNode(50);
    T1->right->left->right = newNode(100);

    // Second BST
    Node* T2 = newNode(5);
    T2->right = newNode(70);

    Node *dll1=NULL, *dll2=NULL;

    convertToDLL(T1, dll1);
    convertToDLL(T2, dll2);

    Node* merged = mergeDLL(dll1, dll2);

    printDLL(merged);

    return 0;
}
