class Solution {
    public:
        void flatten(TreeNode *root) {
            if(root == nullptr) return;
            if(root->left == nullptr && root->right == nullptr) return;

            flatten(root->left);
            flatten(root->right);

            TreeNode *tmp = root->right;
            root->right = root->left;
            root->left = nullptr;
            // find the last right 
            TreeNode *p = root;
            while (p->right) p = p->right;
            p->right = tmp;
        }
};
