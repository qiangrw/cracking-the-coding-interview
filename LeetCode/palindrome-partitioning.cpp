class Solution {
    public:
        vector<vector<string>> partition(string s) {
            vector<vector<string> > res;
            if (s.empty()) return res;
            int n = s.size();
            vector<string> path;

            vector<vector<bool> > p(n, vector<bool>(n, false));
            for (int i = n - 1; i >= 0; --i) {
                for (int j = i; j < n; ++j) {
                    p[i][j] = (j-i < 2 || p[i+1][j-1]) && s[i] == s[j];
                }
            }

            dfs(s, 0, p, path, res);        
            return res;
        }

        void dfs(const string &s, int start, vector<vector<bool> > &p, vector<string> &path, 
                    vector<vector<string> > &res) {
            if (start == s.size()) {
                res.push_back(path);
                return;
            }
            for (int i = start; i < s.size(); ++i) {
                if (p[start][i]) {
                    string word = s.substr(start, i - start + 1);
                    path.push_back(word);
                    dfs(s, i + 1, p, path, res);
                    path.pop_back();
                }
            }
        }

        // deprecated, too slow
        bool ispalindrome(const string &word) {
            int start = 0, end = word.size() - 1;
            while (start < end) {
                if (word[start] != word[end]) return false;
                start++;
                end--;
            }
            return true;
        }

};
