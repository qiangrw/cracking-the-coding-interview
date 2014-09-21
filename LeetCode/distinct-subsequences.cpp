class Solution {
public:
    int numDistinct(string S, string T) {
        int m = S.size();
        int n = T.size();
        vector<int> f(n+1, 0);
        f[0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = min(n - 1, i); j >= 0; --j) {
                f[j+1] += (S[i] == T[j]) ? f[j] : 0;
            }
        }
        return f[n];
    }
};
