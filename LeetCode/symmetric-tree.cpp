class Solution {
    public:
        bool isSymmetric(TreeNode *root) {
            if (root == nullptr) return true;
            return isSymmetric(root->left, root->right);
        }

        bool isSymmetric(TreeNode *left, TreeNode *right) {
            if (left == nullptr) return right == nullptr;
            if (right == nullptr) return left == nullptr;
            return left->val == right->val && 
                isSymmetric(left->right, right->left) && isSymmetric(left->left, right->right);
        }
};
