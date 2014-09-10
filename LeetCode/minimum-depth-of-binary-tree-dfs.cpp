class Solution {
    public:
        int minDepth(TreeNode *root) {
            return depth(root, false);
        }

        int depth(TreeNode *root, bool has_bro) {
            if (root == nullptr) return has_bro ? INT_MAX : 0;
            return 1 + min(depth(root->left, root->right != nullptr), depth(root->right, root->left != nullptr));
        }
};
