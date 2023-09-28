#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data ;
    Node* next;
    Node(int num){
        data = num;
        next = nullptr;
    }
};
Node* transverse(Node* head){
    Node* current = head;
    while (current != nullptr){
        cout<<current->data<<" ";
        current = current->next;
    }
}
class Nodemaking{
    public:
    Node* head;
    Nodemaking(){
        head = nullptr;
    }
    void insertvalue(int data){
        Node* Newnode = new Node(data);
        Newnode->next = head;
        head = Newnode;
    }
    void insertend(int data){
       Node* end = head;
       Node* Newnode = new Node(data);
       while(end->next!=nullptr){
        end = end->next;
       }
       end->next = Newnode;
    }
    void insertafter(int atr , int m) {
    Node* temp = head;
    while (temp != nullptr && temp->data != atr) {
        temp = temp->next;
    }
    Node* newNode = new Node(m);
    newNode->next = temp->next; 
    temp->next = newNode;       
    }
    void deletehead(){
        Node* temp = head;
        head = head -> next;
        free(temp);
    }
    void deletetail() {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    }
    void deletespecific(int val){
        if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }
        if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
        }
        Node* temp = head;
        while(temp->next->data == val && temp->next!=nullptr){
        temp = temp ->next;
        }
        delete temp->next;
        if(temp->next->next!=nullptr){
        temp = temp->next->next;
        }
        else
        temp = nullptr;
    }

    void searchnode(int x){
        Node* search = head;
        int count=1;
        while(search!= nullptr && search->data!=x){
            search = search->next;
            count++;
        }
        cout<<"data:"<<x<<"is on node:"<<count<<endl;
    }


    void printlist(){
    Node* current = head;
    while(current!=nullptr){
        cout<<current->data<<" ";
        current = current->next;
    }
    }
    
};



int main(){
    cout << "\nMenu:\n";
     cout << "1. Insert at Beginning\n";
     cout<<"2.Insert a value at end\n";
    cout << "3. Insert After a Value\n";
    cout<<"4.deletion from begining\n";
    cout<<"5.deletion from end\n";
    cout<<"6.deletion of a specific node \n";
    cout<<"7.serch for a node and dipaly its position from head\n";
    cout << "8. Print List\n";
    cout << "0. Exit\n";
    int key , val ,choice;
    Nodemaking list;
    while(choice!=0){
        cout << "Enter choice: ";
        cin >> choice;
    switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                list.insertvalue(val);
                break;
            case 2:
                cout<<"enter value";
                cin>>val;
                list.insertend(val);
                break;    
            case 3:
                cout << "Enter key (after which to insert): ";
                cin >> key;
                cout << "Enter value to insert: ";
                cin >> val;
                list.insertafter(key, val);
                break;
            case 4:
                cout<<"deleting\n";
                list.deletehead();
                list.printlist();    
                break;
            case 5:
                cout<<"deleting\n";
                list.deletetail();
                list.printlist();
                break;    
            case 6:
                cout<<"enter a node to be deleted:\n";
                cin>>val;
                list.deletespecific(val)    ;
                break;
            case 7:
                cout<<"enter the node to be serch:";
                cin>>val;
                list.searchnode(val);\
                break;
            case 8:
                list.printlist();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    }
}