class Solution {
    public:
        bool hasPathSum(TreeNode *root, int sum) {
            if(root == nullptr) return false;
            return hasSum(root, sum);
        } 

        bool hasSum(TreeNode *root, int sum) {
            if(root == nullptr) return sum == 0;
            if(root->left == nullptr  && root->right == nullptr) return sum == root->val;
            if(root->left != nullptr && hasSum(root->left, sum - root->val) ) return true;
            if(root->right != nullptr && hasSum(root->right, sum - root->val) ) return true;
            return false;
        }
};
