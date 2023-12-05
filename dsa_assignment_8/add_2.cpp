#include<iostream>
#include<vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x){ data=x; left=right=NULL; }
};

vector<Node*> generate(int start, int end){
    vector<Node*> trees;
    if(start > end){
        trees.push_back(NULL);
        return trees;
    }

    for(int i=start;i<=end;i++){
        vector<Node*> left = generate(start, i-1);
        vector<Node*> right = generate(i+1, end);

        for(Node* l: left){
            for(Node* r: right){
                Node* root = new Node(i);
                root->left = l;
                root->right = r;
                trees.push_back(root);
            }
        }
    }
    return trees;
}

void preorder(Node* root){
    if(!root) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    int n = 3;
    vector<Node*> trees = generate(1, n);

    cout << "All unique BSTs (preorder form):\n";
    for(auto t: trees){
        preorder(t);
        cout << endl;
    }
    return 0;
}
