class Solution {
    public:
        int fac(int n) {
            int res = 1;
            for (int i = 2; i <= n; ++i) res *= i;
            return res;
        }

        string kpermutation(string s, int k) {
            string res;
            int n = s.size();
            int base = fac(n-1);
            k -= 1;  // start from 0

            for (int i = n - 1; i > 0; --i) {
                auto a = next(s.begin(), k/base);
                res.push_back(*a);
                s.erase(a);
                k %= base;
                base /= i;
            }
            res.push_back(s[0]);
            return res;
        }

        string getPermutation(int n, int k) {
            string s(n, '0');
            for (int i = 0; i < n; ++i) s[i] += (i+1);
            return kpermutation(s, k);
        }
};
