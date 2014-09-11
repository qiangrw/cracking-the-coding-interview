class Solution {
    public:
        bool isValidBST(TreeNode *root) {
            return valid(root, INT_MAX, INT_MIN);
        }

        bool valid(TreeNode *root,  int maxval, int minval) {
            if(root == nullptr) return true;
            if(root->val <= minval || root->val >= maxval) return false;
            return valid(root->left, root->val, minval) &&
                valid(root->right, maxval, root->val);
        }
};
