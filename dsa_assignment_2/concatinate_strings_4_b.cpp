#include<iostream>
using namespace std;
int main(){
    char name[10]="manan";
    int i=0;
    while(name[i]!='\0'){
        i++;
    }
    for (int j=i-1; j>=0; j--) {
        cout << name[j];
    }
    
}