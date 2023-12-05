#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *next, *prev, *up, *down;
};

Node* create2D(int a[3][3], int r, int c) {
    Node* grid[10][10];

    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            grid[i][j] = new Node{a[i][j], NULL, NULL, NULL, NULL};
        }
    }

    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            if(j+1<c) grid[i][j]->next = grid[i][j+1];
            if(j-1>=0) grid[i][j]->prev = grid[i][j-1];
            if(i-1>=0) grid[i][j]->up = grid[i-1][j];
            if(i+1<r) grid[i][j]->down = grid[i+1][j];
        }
    }

    return grid[0][0]; // head of structure
}

int main() {
    int mat[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    Node* head = create2D(mat, 3, 3);

    cout<<"Top row: ";
    Node* t = head;
    while(t) {
        cout<<t->data<<" ";
        t = t->next;
    }
    cout<<"\n";

    return 0;
}
