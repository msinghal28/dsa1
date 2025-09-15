#include <iostream>
using namespace std;
#define SIZE 6

class Queue {
    int arr[SIZE], front, rear;
public:
    Queue() { front = -1; rear = -1; }
    void enqueue(int x) {
    if (isFull()) {
       return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }
    arr[rear] = x;
    }
    void dequeue() {
        if (isEmpty()) {
            cout<<"Queue is empty"<<endl;
            return;
        }
        if (front == rear) {    
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }
    bool isEmpty() { if(front == -1){
        cout<<"Queue is empty"<<endl;
        return true;
    }
    return false;
    }
    bool isFull() { if((rear + 1) % SIZE == front) {
        cout<<"Queue is full"<<endl;
        return true;
    }
    return false;
    }
    int peek(){ 
        return isEmpty() ? -1 : arr[front]; 
        }
    void display() {
        if (isEmpty()) {
            cout<<"Queue is empty"<<endl;
            return;
        }
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, val;
    int n;
    while(true){
        cout<<"enter choice\n1. Enqueue\n2. Dequeue\n3. Is Empty?\n4. Is Full?\n5. Display\n6. Peek\n7. Exit"<<endl;
        cin>>n;
        switch(n){
            case 1: cout<<"1. Enqueue"<<endl;
                    cout<<"enter value to be inserted"<<endl;
                    cin>>val;
                    q.enqueue(val);
                    break;

            case 2: cout<<"2. Dequeue"<<endl;
                    q.dequeue();
                    break;

            case 3: cout<<"3. Is Empty?"<<endl;
                cout << q.isEmpty() << endl;                
                break;
            case 4: cout<<"4. Is Full?"<<endl;
                cout << q.isFull() << endl;
                break; 
            case 5: q.display();
                break;
            case 6: cout << q.peek() << endl;
                break;
            case 7: cout << "Exiting switch case ..." << endl;
                exit(0);
                break;
        default: break;
    }
}
}