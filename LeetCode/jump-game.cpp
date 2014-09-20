class Solution {
    public:
        bool canJump(int A[], int n) {
            int maxlen = 1;
            for (int i = 0; i < n; ++i) {
                if (maxlen == 0) return false;
                --maxlen;
                maxlen = max(maxlen, A[i]);
            }
            return true;
        }
};
