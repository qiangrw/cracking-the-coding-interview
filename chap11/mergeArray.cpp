#include <iostream>
using namespace std;

void merge(int A[], int B[], int lenA, int lenB) {
    int i=lenA-1, j=lenB-1;
    int k=lenA+lenB-1;
    while(i >=0 && j >=0) {
        if(A[i] > B[j]) {
            A[k--] = A[i--];
        } else {
            A[k--] = B[j--];
        }
    }
    while(j>=0) A[k--] = B[j--];
}

int main() {
    int A[30], B[10];
    for(int i=0; i<10; i++) {
        A[i] = i*i*2 - 2*i + 8;
        B[i] = 8*i + 4;
    }
    merge(A, B, 10, 10);
    for(int i=0; i<20; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}
