#include <iostream>
using namespace std;

void selectionSort(int a[], int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++)
            if(a[j] < a[min]) min=j;
        swap(a[i], a[min]);
    }
}

void insertionSort(int a[], int n){
    for(int i=1;i<n;i++){
        int key=a[i];
        int j=i-1;
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}

void bubbleSort(int a[], int n){
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(a[j] > a[j+1]) swap(a[j], a[j+1]);
}

void merge(int a[], int l, int m, int r){
    int n1 = m-l+1;
    int n2 = r-m;
    int L[n1], R[n2];
    for(int i=0;i<n1;i++) L[i]=a[l+i];
    for(int i=0;i<n2;i++) R[i]=a[m+1+i];
    int i=0, j=0, k=l;
    while(i<n1 && j<n2){
        if(L[i] <= R[j]) a[k++] = L[i++];
        else a[k++] = R[j++];
    }
    while(i<n1) a[k++] = L[i++];
    while(j<n2) a[k++] = R[j++];
}

void mergeSort(int a[], int l, int r){
    if(l<r){
        int m = (l+r)/2;
        mergeSort(a, l, m);
        mergeSort(a, m+1, r);
        merge(a, l, m, r);
    }
}

int partition(int a[], int low, int high){
    int pivot=a[high];
    int i=low-1;
    for(int j=low;j<high;j++){
        if(a[j] < pivot){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[high]);
    return i+1;
}

void quickSort(int a[], int low, int high){
    if(low<high){
        int pi = partition(a, low, high);
        quickSort(a, low, pi-1);
        quickSort(a, pi+1, high);
    }
}

void printArray(int a[], int n){
    for(int i=0;i<n;i++) cout << a[i] << " ";
    cout << endl;
}

int main(){
    int n;
    
    cout << "Enter size of array: ";
    cin >> n;

    int a[n];
    cout << "Enter elements to be sorted: ";
    for(int i=0;i<n;i++) cin >> a[i];

    int choice;
    do{
        cout << "\n1. Selection Sort\n2. Insertion Sort\n3. Bubble Sort\n4. Merge Sort\n5. Quick Sort\n6. Exit\nEnter choice: ";
        cin >> choice;

        int temp[n];
        for(int i=0;i<n;i++) temp[i] = a[i];

        switch(choice){
            case 1: selectionSort(temp,n); printArray(temp,n); break;
            case 2: insertionSort(temp,n); printArray(temp,n); break;
            case 3: bubbleSort(temp,n); printArray(temp,n); break;
            case 4: mergeSort(temp,0,n-1); printArray(temp,n); break;
            case 5: quickSort(temp,0,n-1); printArray(temp,n); break;
        }
    } while(choice != 6);

    return 0;
}
