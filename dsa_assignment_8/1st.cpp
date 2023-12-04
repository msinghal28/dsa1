#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
Node* buildTree(int arr[], int n, int i = 0) {
    if (i >= n) return nullptr;
    Node* root = new Node(arr[i]);
    root->left = buildTree(arr, n, 2*i + 1);
    root->right = buildTree(arr, n, 2*i + 2);
    return root;
}
void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root -> data <<" ";
}

void inorder(Node* root){
    if (!root) return;
    inorder(root->left);
    cout << root -> data <<" ";
    inorder(root->right);
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    Node* root = buildTree(arr, 5);
    cout << "Pre-order Traversal: ";
    preorder(root);
    cout<<endl;
    cout<<"post-order Traversal";
    postorder(root);
    cout<<endl;
    cout<<"in-order Traversal";
    inorder(root);
    return 0;
}
