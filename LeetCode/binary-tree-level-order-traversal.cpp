class Solution {
    public:
        vector<vector<int> > levelOrder(TreeNode *root) {
            vector<vector<int> > res;
            if (root == nullptr) return res;
            queue<TreeNode *> current, next;
            current.push(root);
            vector<int> path;
            while (!current.empty()) {
                while (!current.empty()) {
                    TreeNode *p = current.front();
                    current.pop();
                    path.push_back(p->val);
                    if (p->left) next.push(p->left);
                    if (p->right) next.push(p->right);
                }
                res.push_back(path);
                path.clear();
                current.swap(next);
            }
            return res;
        }
};
