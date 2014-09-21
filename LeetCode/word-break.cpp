class Solution {
    public:
        bool wordBreak(string s, unordered_set<string> &dict) {
            int n = s.size();
            vector<bool> f(n+1, false);
            f[0] = true;
            // f[i] means prefix s with len=i can be segmented by dict
            for (int i = 1; i <= n; ++i) {
                for (int j = 0; j < i; ++j) {
                    if (f[j] && dict.find(s.substr(j, i-j)) != dict.end()) {
                        f[i] = true;
                        break;
                    }
                }
            }
            return f[n];
        }
};
