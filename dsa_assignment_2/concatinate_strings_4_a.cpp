
#include<iostream>
using namespace std;
int main(){
    char bigggerarray[40];
    char name[20] = "manan";
    char name2[20] = "singhal";
    int i = 0;
    while (name[i] != '\0') {
        bigggerarray[i] = name[i];
        i++;
    }
    int j = 0;
    while (name2[j] != '\0') {
        bigggerarray[i] = name2[j];
        i++;
        j++;
    }
    bigggerarray[i] = '\0';
    cout << "Combined string: " << bigggerarray << endl;
    return 0;
}