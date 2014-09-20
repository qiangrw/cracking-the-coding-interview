class Solution {
    public:
        int maxSubArray(int A[], int n) {
            int maxsum = INT_MIN, cursum = 0;
            for (int i = 0; i < n; ++i) {
                cursum += A[i];
                maxsum = max(maxsum, cursum);
                if (cursum < 0) cursum = 0;
            }
            return maxsum;
        }
};
