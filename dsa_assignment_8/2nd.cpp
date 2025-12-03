#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

Node* insertNode(Node* root, int x){
    if(!root) return new Node(x);
    if(x < root->data) root->left = insertNode(root->left, x);
    else root->right = insertNode(root->right, x);
    return root;
}

Node* searchRec(Node* root, int x){
    if(!root || root->data == x) return root;
    if(x < root->data) return searchRec(root->left, x);
    return searchRec(root->right, x);
}

Node* searchIter(Node* root, int x){
    while(root){
        if(root->data == x) return root;
        if(x < root->data) root = root->left;
        else root = root->right;
    }
    return NULL;
}

int maxBST(Node* root){
    while(root->right) root = root->right;
    return root->data;
}

int minBST(Node* root){
    while(root->left) root = root->left;
    return root->data;
}

Node* inorderSuccessor(Node* root, int x){
    Node* curr = searchRec(root, x);
    if(!curr) return NULL;
    if(curr->right){
        curr = curr->right;
        while(curr->left) curr = curr->left;
        return curr;
    }
    Node* succ = NULL;
    while(root){
        if(x < root->data){
            succ = root;
            root = root->left;
        } else if(x > root->data){
            root = root->right;
        } else break;
    }
    return succ;
}

Node* inorderPredecessor(Node* root, int x){
    Node* curr = searchRec(root, x);
    if(!curr) return NULL;
    if(curr->left){
        curr = curr->left;
        while(curr->right) curr = curr->right;
        return curr;
    }
    Node* pred = NULL;
    while(root){
        if(x > root->data){
            pred = root;
            root = root->right;
        } else if(x < root->data){
            root = root->left;
        } else break;
    }
    return pred;
}

int main(){
    Node* root = NULL;
    int arr[] = {20, 10, 30, 5, 15, 25, 40};
    for(int x: arr) root = insertNode(root, x);

    cout << maxBST(root) << endl;
    cout << minBST(root) << endl;
    cout << searchIter(root, 15)->data << endl;

    Node* s = inorderSuccessor(root, 15);
    if(s) cout << s->data << endl;

    Node* p = inorderPredecessor(root, 15);
    if(p) cout << p->data << endl;
}
