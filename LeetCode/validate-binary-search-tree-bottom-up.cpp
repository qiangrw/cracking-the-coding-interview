class Solution {
    public:
        bool isValidBST(TreeNode *root) {
            if (root == nullptr) return true;
            auto p = getRange(root);
            return p.first <= p.second;
        }

        pair<int,int> getRange(TreeNode *root) {
            auto res = make_pair(root->val, root->val);
            if (root->left) {
                auto l = getRange(root->left);
                if (l.first > l.second) return make_pair(0, -1);
                if (root->val <= l.second) return make_pair(0, -1);
                res.first = l.first;
            }
            if (root->right) {
                auto r = getRange(root->right);
                if (r.first > r.second) return make_pair(0, -1);
                if (root->val >= r.first) return make_pair(0, -1);
                res.second = r.second;
            }
            return res;
        }
};
