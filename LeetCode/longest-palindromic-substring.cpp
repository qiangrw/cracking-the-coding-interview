class Solution {
    public:
        string longestPalindrome(string s) {
            int maxi = 0, maxlen = 0;
            if (s.empty()) return "";
            int n = s.size();
            bool p[n][n];
            fill_n(&p[0][0], n*n, false);

            int max_start = 0, max_len = 1;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < i; ++j) {
                    p[j][i] = i - j < 2 || (s[j] == s[i] && p[j+1][i-1]);
                    if (p[j][i]) {
                        if (i - j + 1 > max_len) {
                            max_len = i - j + 1;
                            max_start = j;
                        }
                    }
                }
            }
            return s.substr(max_start, max_len);

        }
};
