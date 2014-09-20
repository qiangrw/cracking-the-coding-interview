class Solution {
    public:
        int divide(int dividend, int divisor) {
            bool neg = false;
            long long a = dividend, b = divisor;
            if (dividend < 0) {
                neg = !neg;
                a = -a;
            }
            if (divisor < 0) {
                neg = !neg;
                b = -b;
            }
            int res = 0;
            while (a >= b) {
                long long m = b;
                for (int i = 0; a >= m; i++) {
                    a -= m;
                    res += (1 << i);
                    m = m << 1;
                }
            }
            return neg ? -res : res;
        }
};
