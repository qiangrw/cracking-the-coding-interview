class Solution {
    public:
        vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
            vector<vector<int> > res;
            if(candidates.empty()) return res;
            sort(candidates.begin(), candidates.end());
            vector<int> path;
            dfs(candidates, 0, 0, target, path, res);
            return res;
        }

        void dfs(vector<int> &candidates, int sum, int start, int target, vector<int> &path, vector<vector<int> > &res) {
            if (sum > target) return;
            if (target == sum) {
                res.push_back(path);
                return;
            }
            for (int i = start; i < candidates.size(); ++i) {
                path.push_back(candidates[i]);
                dfs(candidates, sum+candidates[i], i, target, path, res);
                path.pop_back();
            }
        }
};
