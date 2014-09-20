class Solution {
    public:
        vector<vector<int> > combinationSum2(vector<int> &num, int target) {
            vector<vector<int> > res;
            if (num.empty()) return res;
            sort(num.begin(), num.end());
            vector<int> path;
            dfs(num, 0, 0, target, path, res);
            return res;
        }

        void dfs(vector<int> &candidates, int sum, int start, int target, vector<int> &path, vector<vector<int> > &res) {
            if (sum > target) return;
            if (target == sum) {
                res.push_back(path);
                return;
            }
            for (int i = start; i < candidates.size(); i++) {
                if(i > start && candidates[i] == candidates[i-1]) continue;
                path.push_back(candidates[i]);
                dfs(candidates, sum+candidates[i], i+1, target, path, res);
                path.pop_back();
            }
        }
};
