// Given an array of integer, range from 1..n-1, find the first (min) duplicate number
// Example, A = {2, 1, 1, 3, 4}  result = 1

#include <iostream>
using namespace std;

int firstDuplicateNum(int A[], int n) {
    int res = n;
    for (int i = 0; i < n; ++i) {
        while (A[i] != i + 1 && A[i] >= 1 && A[i] < n) {
            if (A[i] == A[A[i] - 1]) {
                res = min(res, A[i]);
                break;
            } else swap(A[i], A[A[i]-1]);
        }
    }
    return res; 
}

int main() {
    int A[] = {4, 1, 2, 4, 2};
    cout << firstDuplicateNum(A, 5) << endl;
    return 0;
}
