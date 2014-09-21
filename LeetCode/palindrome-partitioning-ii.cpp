class Solution {
    public:
        int minCut(string s) {
            int n =s.size();
            if(s.size() == 0 || s.size() == 1) return 0;
            vector<vector<bool> > p(n, vector<bool>(n, false));
            for (int i = n - 1; i >= 0; --i) {
                for (int j = i; j < n; ++j) {
                    p[i][j] = (j-i < 2 || p[i+1][j-1]) && s[i] == s[j];
                }
            }

            vector<int> cuts = vector<int>(n, n);
            cuts[0] = 0;
            for (int i = 1; i < n; i++) {
                for (int j = 0; j <= i; j++) {
                    if (p[j][i]) {
                        if (j == 0) cuts[i] = 0;    // self parlindrome
                        else if (cuts[j-1] + 1 < cuts[i]) {
                            cuts[i] = cuts[j-1] + 1;
                        }
                    }
                }

            }
            return cuts[n-1];
        }
};
