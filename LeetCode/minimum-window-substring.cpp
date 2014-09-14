class Solution {
    public:
        string minWindow(string S, string T) {
            if (T.empty() || S.size() < T.size()) return "";
            unordered_map<char, int> appeared, expected;
            for (auto c: T) {
                expected[c] += 1;
                appeared[c] = 0;
            }
            int start = 0, minstart = 0, minlen = INT_MAX, total = 0;
            for (int i = 0; i < S.size(); ++i) {
                if (expected.find(S[i]) != expected.end()) {
                    if (appeared[S[i]] < expected[S[i]]) total += 1;
                    appeared[S[i]] += 1;
                }
                if (total == T.size()) {
                    // shorten, not found, more than expected
                    while (expected.find(S[start]) == expected.end() || appeared[S[start]] > expected[S[start]]) {
                        appeared[S[start]] -= 1;
                        start += 1;
                    }
                    if (i - start + 1 < minlen) {
                        minlen = i - start + 1;
                        minstart = start;
                    }
                }
            }
            return minlen == INT_MAX ? "" : S.substr(minstart, minlen);
        }
};
