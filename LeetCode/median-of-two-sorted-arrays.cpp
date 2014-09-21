class Solution {
    public:
        double findMedianSortedArrays(int A[], int m, int B[], int n) {
            int len = m+n;
            if (len % 2 == 0) return (findK(A, m, B, n, len/2) + findK(A, m, B, n, len/2+1)) / 2.0;
            else return findK(A, m, B, n, len/2 + 1);
        }

        int findK(int A[], int m, int B[], int n, int k) {
            if (m > n) return findK(B, n, A, m, k);
            if (m == 0) return B[k-1];
            if (k == 1) return min(A[0], B[0]);

            int a = min(k/2, m), b=k-a;
            if (A[a-1] < B[b-1]) return findK(A+a, m-a, B, n, k-a);
            else if (A[a-1] > B[b-1]) return findK(A, m, B+b, n-b, k-b);
            else return A[a-1];
        }


        // solution 1, like merge sort
        double findMedianSortedArraysMerge(int A[], int m, int B[], int n) {
            int mi = 0, ni = 0, counter = 0;
            int first, second, cur;
            while (mi < m || ni < n) {
                int mval = mi < m ? A[mi] : INT_MAX;
                int nval = ni < n ? B[ni] : INT_MAX;
                if (mval < nval) {
                    ++mi;
                    cur = mval;
                } else {
                    ++ni;
                    cur = nval;
                }
                if (counter == (m + n) / 2) first = cur;
                if (counter == (m + n) / 2 - 1) second = cur;
                ++counter;
            }

            if ((m + n) % 2 == 0) return (first + second) / 2.0;
            else return first;
        }
};
