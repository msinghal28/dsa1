#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int x){ return new Node{x, NULL, NULL}; }

int findIndex(int arr[], int start, int end, int val){
    for(int i=start;i<=end;i++)
        if(arr[i] == val) return i;
    return -1;
}

Node* buildTree(int inorder[], int preorder[], int inStart, int inEnd, int &preIndex){
    if(inStart > inEnd) return NULL;

    Node* root = newNode(preorder[preIndex++]);

    if(inStart == inEnd) return root;

    int mid = findIndex(inorder, inStart, inEnd, root->data);

    root->left  = buildTree(inorder, preorder, inStart, mid-1, preIndex);
    root->right = buildTree(inorder, preorder, mid+1, inEnd, preIndex);

    return root;
}

void postorder(Node* root){
    if(!root) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main(){
    int inorder[]   = {4,2,5,1,6,3};
    int preorder[]  = {1,2,4,5,3,6};
    int n = 6;

    int preIndex = 0;
    Node* root = buildTree(inorder, preorder, 0, n-1, preIndex);

    cout<<"Postorder: ";
    postorder(root);

    return 0;
}
