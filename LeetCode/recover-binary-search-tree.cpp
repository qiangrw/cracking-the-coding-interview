class Solution {
    public:
        TreeNode *first_node, *second_node, *pre_node;
        void recoverTree(TreeNode *root) {
            first_node = nullptr;
            second_node = nullptr;
            pre_node = nullptr;
            inorder(root);
            swap(first_node->val, second_node->val);
        }

        void inorder(TreeNode *root) {
            if(root == nullptr) return;
            inorder(root->left);
            if (pre_node != nullptr && root->val < pre_node->val) {
                if(first_node == nullptr) first_node = pre_node;
                second_node = root;
            }
            pre_node = root;
            inorder(root->right);
        }
};
