class Solution {
    public:
        int maxPathSum(TreeNode *root) {
            max_sum = INT_MIN;
            dfs(root);
            return max_sum;
        }

    private:
        int max_sum;
        int dfs(TreeNode *root){
            if (root == NULL) return 0;
            int l = dfs(root->left);
            int r = dfs(root->right);
            int sum=root->val;
            if (l > 0) sum+=l;
            if (r > 0) sum+=r;
            if (sum > max_sum) max_sum = sum;
            return max(l,r)>0 ? max(l,r) + root->val : root->val;
        }
};
