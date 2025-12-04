#include<iostream>
#include<queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int x){ return new Node{x, NULL, NULL}; }

int maxDepth(Node* root){
    if(!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int main(){
    /* Example Tree
             1
            / \
           2   3
          / \
         4   5
        / \
       7   8
    */
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->left = newNode(7);
    root->left->left->right = newNode(8);

    cout << "Maximum Depth = " << maxDepth(root);
    return 0;
}
