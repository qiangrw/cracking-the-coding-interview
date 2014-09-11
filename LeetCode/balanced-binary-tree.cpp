class Solution {
    public:
        int depth(TreeNode *root) {
            if (root == nullptr) return 0;
            return max(depth(root->left), depth(root->right)) + 1;
        }

        bool isBalanced(TreeNode *root) {
            if (root == nullptr) return true;
            return (isBalanced(root->left) && isBalanced(root->right) && abs(depth(root->left) - depth(root->right)) <= 1);
        }
};
