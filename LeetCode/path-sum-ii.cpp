class Solution {
    public:
        vector<vector<int> > pathSum(TreeNode *root, int sum) {
            vector<vector<int> > res;
            if (root == nullptr) return res;
            vector<int> path;
            dfs(root, sum, res, path);
            return res;
        }

        void dfs(TreeNode *root, int sum, vector<vector<int> > &res, vector<int> &path) {
            if (root == nullptr) {
                if (sum == 0) res.push_back(path);
            } else {
                path.push_back(root->val);
                if (root->left == nullptr && root->right == nullptr) {
                    if (sum == root->val) res.push_back(path);
                } else {
                    if (root->left)  dfs(root->left, sum - root->val, res, path);
                    if (root->right) dfs(root->right, sum - root->val, res, path);
                }
                path.pop_back();
            }
        }
};
