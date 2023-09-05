#include<iostream>
using namespace std;
int main(){
    char name[10]="manan";
    for (int i=0;i<10;i++) {
        if(name[i]!='a' && name[i]!='e' && name[i]!='i' && name[i]!='o' && name[i]!='u'){
            if(name[i] != '\0') {
            cout << name[i];
        }
        
    }
}
}