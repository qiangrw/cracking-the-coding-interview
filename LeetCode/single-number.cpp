class Solution {
    public:
        int singleNumber(int A[], int n) {
            int res;
            for (int i = 0; i < n; ++i) {
                res ^= A[i];
            }
            return res;
        }
};
