class Solution {
    public:
        int removeDuplicates(int A[], int n) {
            if (n <= 2) return n;
            int len = 1;
            int pre = A[0];
            int pre_cnt = 1;
            for (int i = 1; i < n; ++i) {
                if (A[i] != pre || pre_cnt < 2) {
                    if (pre == A[i]) pre_cnt += 1;
                    else pre_cnt = 1;

                    pre = A[i];
                    A[len++] = A[i];
                }
            }
            return len;
        }
};
