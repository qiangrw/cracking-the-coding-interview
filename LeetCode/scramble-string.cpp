class Solution {
public:
    bool isScramble(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        if (m != n) return false;
        if (n == 0) return true;
        // given the len, start from i in s1, start from j in s2
        bool f[n+1][n][n];
        fill_n(&f[0][0][0], (n+1)*n*n, false);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) 
                f[1][i][j] = s1[i] == s2[j];
                
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i + len <= n; ++i) {
                for (int j = 0; j + len <= n; ++j) {
                    for (int k = 1; k < len; ++k) {
                        if (f[k][i][j] && f[len-k][i+k][j+k] 
                            || f[k][i][j+len-k] && f[len-k][i+k][j]) {
                            f[len][i][j] = true;
                            break;
                        }
                    }
                }
            }
        }
        return f[n][0][0];
    }
};