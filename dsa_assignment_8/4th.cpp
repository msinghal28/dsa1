#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int x){ data = x; left = right = NULL; }
};

bool isBSTUtil(Node* root, int minv, int maxv){
    if(!root) return true;
    if(root->data <= minv || root->data >= maxv) return false;
    return isBSTUtil(root->left, minv, root->data) &&
           isBSTUtil(root->right, root->data, maxv);
}

bool isBST(Node* root){
    return isBSTUtil(root, -1000000, 1000000);
}

int main(){
    Node* a = new Node(10);
    a->left = new Node(5);
    a->right = new Node(20);

    cout << isBST(a) << endl;
}
