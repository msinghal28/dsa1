#include<iostream>
using namespace std;

int main(){
    int st[100], minst[100];
    int top=-1, mintop=-1;

    int choice, x;
    while(true){
        cout<<"\n1 Push\n2 Pop\n3 getMin\n4 Exit\n";
        cin>>choice;

        if(choice==1){
            cin>>x;
            st[++top] = x;
            if(mintop==-1 || x <= minst[mintop])
                minst[++mintop] = x;
        }
        else if(choice==2){
            if(top==-1) cout<<"Underflow\n";
            else{
                if(st[top] == minst[mintop]) mintop--;
                top--;
            }
        }
        else if(choice==3){
            if(mintop==-1) cout<<"Empty\n";
            else cout<<"Min = "<<minst[mintop]<<endl;
        }
        else break;
    }
}
