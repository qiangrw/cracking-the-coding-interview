class Solution {
    public:
        int climbStairs(int n) {
            if (n <= 1) return 1;
            int pre1 = 1, pre2 = 1, cur = 1;
            for (int i = 2; i <= n; ++i) {
                cur = pre1 + pre2;
                pre2 = pre1;
                pre1 = cur;
            }
            return cur;
        }
};
