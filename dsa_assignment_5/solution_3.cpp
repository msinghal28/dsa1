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
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    void occurance(int x) {
        Node* tail = head;
        int count = 0;
        while (tail != nullptr) {
            if (tail->data == x) {
                count++;
            }
            tail = tail->next;
        }
        if (count == 0)
            cout<<"Key "<<x<< " not found ." << endl;
        else
            cout<<"Key "<<x<< " appeared " << count << " times." << endl;
    }
};
int main() {
    nodemaking list;
    list.insertvalue(1);
    list.insertvalue(2);
    list.insertvalue(3);
    list.insertvalue(2);
    list.insertvalue(2);
    list.insertvalue(1);
    cout << "Linked List: ";
    list.printlist();
    list.occurance(2);
}
