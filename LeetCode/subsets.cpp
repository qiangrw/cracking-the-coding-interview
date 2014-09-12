class Solution {
    public:
        vector<vector<int> > subsets(vector<int> &S) {
            vector<vector<int> > res;
            sort(S.begin(), S.end());
            vector<int> path;
            dfs(res, path, S, 0);
            sort(res.begin(), res.end());
            return res;
        }

        void dfs(vector<vector<int> > &res, vector<int> &path, vector<int> &S, int start) {
            if (start == S.size()) {
                res.push_back(path);
                return;
            }
            dfs(res, path, S, start+1);
            path.push_back(S[start]);
            dfs(res, path, S, start+1);
            path.pop_back();
        }
};
