class Solution {
    public:
        int removeDuplicates(int A[], int n) {
            if(n <= 1) return n;
            int len = 1;
            int pre = A[0];
            for (int i = 1; i < n; ++i) {
                if (A[i] != pre) {
                    pre = A[i];
                    A[len++] = A[i];
                }
            }
            return len;
        }
};
