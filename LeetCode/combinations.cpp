class Solution {
    public:
        vector<vector<int> > combine(int n, int k) {
            vector<vector<int> > res;
            vector<int> path;
            vector<bool> used(n+1, false);
            dfs(res, path, used, n, 0, k, 0);
            return res;
        }

        void dfs(vector<vector<int> > &res, vector<int> &path, vector<bool> &used, int n, int level, int k, int pre)
        {
            if (level == k) {
                res.push_back(path);
                return;
            }
            for (int i = pre + 1; i <= n; ++i) {
                if(used[i]) continue;
                used[i] = true;
                path.push_back(i);
                dfs(res, path, used, n, level+1, k, i);
                path.pop_back();
                used[i] = false;
            }
        }
};
