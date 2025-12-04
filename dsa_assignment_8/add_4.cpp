#include<iostream>
#include<queue>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int x){ return new Node{x,NULL,NULL}; }

void rightView(Node* root){
    if(!root) return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        Node* node = NULL;

        while(size--){
            node = q.front(); q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }

        cout << node->data << " "; // last element of level
    }
}

int main(){
    /*
            1
           / \
          2   3
         / \   \
        4   5   6
           /
          7
    */
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
    root->left->right->left = newNode(7);

    cout << "Right View: ";
    rightView(root);

    return 0;
}
