#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class nodemaking {
public:
    Node* head;
    nodemaking() {
        head = nullptr;
    }
    void insertvalue(int data) {
        Node* Newnode = new Node(data);
        Newnode->next = head;
        head = Newnode;
    }
    void printlist() {
        Node* system = head;
        int count=0;
        while (system != nullptr) {
            cout << system->data << " ";
            system =system->next;
            count++;
        }
        cout <<"maje:"<<count<< endl;
    }

    void reverse(){
        Node* previous = nullptr;
        Node* current = head;
        Node* forward = nullptr;

        
        while(current!=nullptr){
            forward = current ->next;
            current->next = previous;
            previous = current;
            current = forward;
        }
        head = previous;
        
    }
};
int main(){
 nodemaking list;
    list.insertvalue(1);
    list.insertvalue(2);
    list.insertvalue(3);
    list.insertvalue(4);
    list.insertvalue(5);
    cout << "Linked List: ";
    list.printlist();
    list.reverse();
    list.printlist();
}