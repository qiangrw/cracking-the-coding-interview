class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            if (s.empty()) return 0;

            unordered_set<char> used;
            int maxlen = 0;
            int start = 0, end = 0;
            while (end < s.size()) {
                if (used.find(s[end]) == used.end()) {
                    used.insert(s[end]);
                } else {
                    maxlen = max(maxlen, end - start);
                    while (s[start] != s[end]) {
                        used.erase(s[start]);
                        ++start;
                    }
                    ++start;
                }
                ++ end;
            }
            return max(maxlen, end - start);
        }
};
