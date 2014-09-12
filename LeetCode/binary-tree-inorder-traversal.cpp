class Solution {
    public:
        vector<int> inorderTraversal(TreeNode *root) {
            vector<int> res;
            TreeNode *cur = root;
            stack<TreeNode *> s;

            while (!s.empty() || cur != nullptr) {
                if (cur != nullptr) {
                    s.push(cur);
                    cur = cur->left;
                } else {
                    cur = s.top();
                    s.pop();
                    res.push_back(cur->val);
                    cur = cur->right;
                }
            }
            return res;
        }
};
