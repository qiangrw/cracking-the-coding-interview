class Solution {
    public:
        /*int depth(TreeNode *root) {
          if (root == nullptr) return 0;
          return max(depth(root->left), depth(root->right)) + 1;
          }*/

        int depth(TreeNode *root) {
            if (root == nullptr) return 0;
            int left_len = depth(root->left);
            int right_len = depth(root->right);
            if (left_len < 0 || right_len < 0 || abs(left_len - right_len) > 1) return -1;
            return max(left_len, right_len) + 1;
        }

        bool isBalanced(TreeNode *root) {
            if (root == nullptr) return true;
            //return (isBalanced(root->left) && isBalanced(root->right) && abs(depth(root->left) - depth(root->right)) <= 1);
            return depth(root) != -1;
        }
};
