class Solution {
    public:
        bool isSameTree(TreeNode *p, TreeNode *q) {
            if (p == nullptr) return q == nullptr;
            if (q == nullptr) return p == nullptr;
            if (p->val != q->val) return false;
            if (!isSameTree(p->left, q->left)) return false;
            if (!isSameTree(p->right, q->right)) return false;
            return true;
        }
};
