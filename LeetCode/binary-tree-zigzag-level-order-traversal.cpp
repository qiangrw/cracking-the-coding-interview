class Solution {
    public:
        vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
            vector<vector<int> >  res;
            if(root == nullptr) return res;
            queue<TreeNode *> current, next;
            bool direction = false;
            current.push(root);
            vector<int> path;
            while (!current.empty()) {
                while (!current.empty()) {
                    TreeNode *p = current.front();
                    current.pop();
                    path.push_back(p->val);
                    if (p->left != nullptr) next.push(p->left);
                    if (p->right != nullptr) next.push(p->right);
                }
                if (direction) {
                    reverse(path.begin(), path.end());
                } 
                direction = !direction;
                res.push_back(path);
                current.swap(next);
                path.clear();
            }
            return res;
        }
};
