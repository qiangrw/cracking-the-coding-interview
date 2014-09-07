class Solution {
    public:
        int dfs(TreeNode *root, int sum)
        {
            if(root == nullptr) return 0;
            if(root->left == nullptr && root->right == nullptr) {
                sum = sum * 10 + root->val;
                return sum;
            }
            return dfs(root->left, sum * 10 + root->val) + 
                dfs(root->right, sum * 10 + root->val);
        }

        int sumNumbers(TreeNode *root) {
            return dfs(root, 0);
        }
};
