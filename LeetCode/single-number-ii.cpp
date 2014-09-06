class Solution {
    public:
        int singleNumber(int A[], int n) {
            vector<int> count(32, 0);
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < 32; ++j) {
                    count[j] += ((A[i]>>j) & 1);
                    count[j] %= 3;
                }
            }
            int res = 0;
            for (int i = 0; i < 32; ++i) {
                res += (count[i] << i);
            }
            return res;
        }
};
