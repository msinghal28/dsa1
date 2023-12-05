#include<iostream>
using namespace std;
#define MAX 100

typedef struct {
    int arr[MAX];
    int front, rear;
} Queue;

Queue init() {
    Queue q;
    q.front = q.rear = -1;
    return q;
}

int isEmpty(Queue q) { return q.front == -1; }

int isFull(Queue q) { return q.rear == MAX - 1; }

Queue enqueue(Queue q, int x) {
    if(isFull(q)) { cout<<"Overflow\n"; return q; }
    if(isEmpty(q)) q.front = 0;
    q.arr[++q.rear] = x;
    return q;
}

Queue dequeue(Queue q, int &x) {
    if(isEmpty(q)) { cout<<"Underflow\n"; return q; }
    x = q.arr[q.front];
    if(q.front == q.rear) q.front = q.rear = -1;
    else q.front++;
    return q;
}

int getFront(Queue q) { return q.arr[q.front]; }

// Find index of minimum element in queue (unsorted part)
int findMinIndex(Queue &q, int sortedIndex) {
    int minVal = 999999, minIdx = -1;
    int n = q.rear - q.front + 1;

    for(int i = 0; i < n; i++) {
        int cur;
        q = dequeue(q, cur);

        if(i <= sortedIndex && cur < minVal) {
            minVal = cur;
            minIdx = i;
        }

        q = enqueue(q, cur);
    }
    return minIdx;
}

// Move the minimum element to rear
Queue moveMinToRear(Queue q, int minIdx) {
    int n = q.rear - q.front + 1;
    int minVal;

    for(int i = 0; i < n; i++){
        int cur;
        q = dequeue(q, cur);

        if(i == minIdx) {
            minVal = cur;
        } else {
            q = enqueue(q, cur);
        }
    }
    return enqueue(q, minVal);
}

int main() {
    Queue q = init();

    int n;
    cout<<"Enter number of elements: ";
    cin>>n;

    cout<<"Enter elements:\n";
    for(int i=0;i<n;i++){
        int x; cin>>x;
        q = enqueue(q, x);
    }

    for(int i = n-1; i >= 0; i--) {
        int minIdx = findMinIndex(q, i);
        q = moveMinToRear(q, minIdx);
    }

    cout<<"Sorted queue: ";
    while(!isEmpty(q)) {
        int x;
        q = dequeue(q, x);
        cout<<x<<" ";
    }
}
