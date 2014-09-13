class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int i = m-1;
        int j = n-1;
        int x = m + n - 1;
        while (x >= 0) {
            if (j < 0 || i < 0) break;
            if (A[i] > B[j]) A[x--] = A[i--];
            else A[x--] = B[j--];
        }
        while (j >= 0) A[x--] = B[j--];
    }
};