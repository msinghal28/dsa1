#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int x){
    return new Node{x, NULL, NULL};
}

int sumLeftLeaves(Node* root, bool isLeft){
    if(!root) return 0;

    if(!root->left && !root->right && isLeft)
        return root->data;

    return sumLeftLeaves(root->left, true) +
           sumLeftLeaves(root->right, false);
}

int main(){
    /*
            3
           / \
          9  20
             / \
            15  7
    */

    Node* root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);

    cout << "Sum of left leaves = " << sumLeftLeaves(root, false);
    return 0;
}
