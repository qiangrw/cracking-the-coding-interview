class Solution {
    public:
        string longestCommonPrefix(vector<string> &strs) {
            if (strs.empty()) return "";
            int maxlen = 0;
            while (true) {
                if (strs[0].size() < maxlen + 1) break;
                int i;
                for (i = 1; i < strs.size(); ++i) {
                    if (strs[i].size() < maxlen + 1 || strs[i][maxlen] != strs[0][maxlen]) break;
                }
                if (i == strs.size()) maxlen += 1;
                else break;
            }
            return strs[0].substr(0, maxlen);
        }
};
