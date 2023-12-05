#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int x){ return new Node{x,NULL,NULL}; }

int findIndex(int arr[], int start, int end, int val){
    for(int i=start;i<=end;i++)
        if(arr[i] == val) return i;
    return -1;
}

Node* build(int inorder[], int postorder[], int inStart, int inEnd, int &postIndex){
    if(inStart > inEnd) return NULL;

    Node* root = newNode(postorder[postIndex--]);

    if(inStart == inEnd) return root;

    int mid = findIndex(inorder, inStart, inEnd, root->data);

    root->right = build(inorder, postorder, mid+1, inEnd, postIndex);
    root->left  = build(inorder, postorder, inStart, mid-1, postIndex);

    return root;
}

void preorder(Node* root){
    if(!root) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    int inorder[]   = {4,2,5,1,6,3};
    int postorder[] = {4,5,2,6,3,1};
    int n = 6;

    int postIndex = n-1;
    Node* root = build(inorder, postorder, 0, n-1, postIndex);

    cout<<"Preorder: ";
    preorder(root);

    return 0;
}
