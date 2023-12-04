#include <iostream>
using namespace std;

void improvedSelection(int a[], int n){
    int left=0, right=n-1;
    while(left < right){
        int min=left, max=right;
        for(int i=left;i<=right;i++){
            if(a[i] < a[min]) min=i;
            if(a[i] > a[max]) max=i;
        }
        swap(a[left], a[min]);
        if(max == left) max = min;
        swap(a[right], a[max]);
        left++;
        right--;
    }
}

void printArray(int a[], int n){
    for(int i=0;i<n;i++) cout << a[i] << " ";
    cout << endl;
}

int main(){
    int n;
    cout << "Enter size of arra: ";
    cin >> n;

    int a[n];
    cout << "Enter element to be insertexs: ";
    for(int i=0;i<n;i++) cin >> a[i];

    int choice;
    do{
        cout << "\n1. Improved Selection Sort\n2. Exit\nEnter choice: ";
        cin >> choice;

        int temp[n];
        for(int i=0;i<n;i++) temp[i] = a[i];

        if(choice == 1){
            improvedSelection(temp, n);
            printArray(temp, n);
        }

    } while(choice != 2);

    return 0;
}
