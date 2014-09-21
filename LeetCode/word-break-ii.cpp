class Solution {
    public:
        void genpath(vector<vector<bool> > &p, vector<string> &path, vector<string> &res, string s, int cur) {
            if (cur == 0) {
                string output;
                for (auto rit = path.rbegin(); rit != path.rend(); ++rit) {
                    output += *rit + " ";
                }
                output.erase(output.end() - 1);
                res.push_back(output);
                return;
            } 

            for (int i = 0; i < s.size(); ++i) {
                if (p[cur][i]) {
                    path.push_back(s.substr(i, cur-i));
                    genpath(p, path, res, s, i);
                    path.pop_back();
                }
            }
        }

        vector<string> wordBreak(string s, unordered_set<string> &dict) {
            int n = s.size();
            vector<bool> f(n+1, false);
            vector<string> res;
            f[0] = true;
            vector<vector<bool> > p(n+1, vector<bool>(n, false));
            for (int k = 1; k <= n; k++) {
                for (int i = 0; i < k; i++) {
                    string subword = s.substr(i, k-i);
                    if (f[i] && dict.count(subword) != 0) {
                        f[k] = true;
                        p[k][i] = true;
                    }
                }
            }

            vector<string> path;
            if (f[n]) genpath(p, path, res, s, s.size());
            return res;
        }
};
