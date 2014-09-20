class Solution {
    public:
        vector<string> anagrams(vector<string> &strs) {
            unordered_map<string, vector<string> > dict;
            for (int i = 0; i <strs.size(); ++i) {
                string word = strs[i];
                sort(word.begin(), word.end());
                dict[word].push_back(strs[i]);
            }

            vector<string> res;
            for (auto it = dict.begin(); it != dict.end(); ++it) {
                for (auto s : it->second) {
                    if (it->second.size() <= 1) continue;
                    res.push_back(s);
                }
            }
            return res;
        }
};
