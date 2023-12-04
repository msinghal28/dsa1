#include <iostream>
using namespace std;

class PQueue{
public:
    int a[100];
    int n=0;

    void push(int x){
        a[n] = x;
        int i = n;
        n++;
        while(i>0 && a[(i-1)/2] < a[i]){
            swap(a[i], a[(i-1)/2]);
            i = (i-1)/2;
        }
    }

    int top(){
        return a[0];
    }

    void pop(){
        if(n==0) return;
        a[0] = a[n-1];
        n--;
        int i = 0;
        while(true){
            int l = 2*i+1, r = 2*i+2;
            int mx = i;
            if(l<n && a[l]>a[mx]) mx=l;
            if(r<n && a[r]>a[mx]) mx=r;
            if(mx==i) break;
            swap(a[i], a[mx]);
            i = mx;
        }
    }
};

int main(){
    PQueue q;
    q.push(5);
    q.push(20);
    q.push(3);
    cout << q.top() << endl;
    q.pop();
    cout << q.top() << endl;
}
