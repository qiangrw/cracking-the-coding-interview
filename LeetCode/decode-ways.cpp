class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) return 0;
        int n = s.size();
        vector<int> f(n + 1, 0);
        f[0] = 1;
        f[1] = s[0] == '0' ? 0 : 1;
        for (int l = 2; l <= n; ++l) {
            f[l] = s[l-1] == '0' ? 0 : f[l-1];
            if (s[l-2] == '1' || s[l-2] == '2' && s[l-1] <= '6') f[l] += f[l-2];
        }
        return f[n];
    }
};