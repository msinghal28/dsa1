#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int x){ data = x; left = right = NULL; }
};

Node* insertNode(Node* root, int x){
    if(!root) return new Node(x);
    if(x < root->data) root->left = insertNode(root->left, x);
    else if(x > root->data) root->right = insertNode(root->right, x);
    return root;
}

Node* findMin(Node* root){
    while(root->left) root = root->left;
    return root;
}

Node* deleteNode(Node* root, int x){
    if(!root) return NULL;
    if(x < root->data) root->left = deleteNode(root->left, x);
    else if(x > root->data) root->right = deleteNode(root->right, x);
    else{
        if(!root->left) return root->right;
        else if(!root->right) return root->left;
        Node* t = findMin(root->right);
        root->data = t->data;
        root->right = deleteNode(root->right, t->data);
    }
    return root;
}

int maxDepth(Node* root){
    if(!root) return 0;
    int L = maxDepth(root->left);
    int R = maxDepth(root->right);
    return 1 + max(L, R);
}

int minDepth(Node* root){
    if(!root) return 0;
    int L = minDepth(root->left);
    int R = minDepth(root->right);
    if(!root->left) return 1 + R;
    if(!root->right) return 1 + L;
    return 1 + min(L, R);
}

int main(){
    Node* root = NULL;
    root = insertNode(root, 10);
    root = insertNode(root, 5);
    root = insertNode(root, 20);
    root = insertNode(root, 15);

    cout << maxDepth(root) << endl;
    cout << minDepth(root) << endl;

    root = deleteNode(root, 20);
    cout << maxDepth(root) << endl;
}
