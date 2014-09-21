class Solution {
    public:
        int reverse(int x) {
            if (x < 0) return -reverse(-x);

            int res = 0;
            // may have overflow problem, e.g. x = 1000000003
            while (x != 0) {
                res = res * 10 + x % 10;
                x = x / 10;
            }
            return res;
        }
};
