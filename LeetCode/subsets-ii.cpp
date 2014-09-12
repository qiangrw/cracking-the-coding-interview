class Solution {
    public:
        vector<vector<int> > subsetsWithDup(vector<int> &S) {
            vector<vector<int> > res;
            sort(S.begin(), S.end());
            vector<int> path;
            dfs(res, path, S, 0);
            sort(res.begin(), res.end());
            return res;
        }

        void dfs(vector<vector<int> > &res, vector<int> &path, vector<int> &S, int start) {
            res.push_back(path);
            for (int i = start; i < S.size(); ++i) {
                if (i != start && S[i] == S[i-1]) continue;
                path.push_back(S[i]);
                dfs(res, path, S, i+1);
                path.pop_back();
            }
        }
};
