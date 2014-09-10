// Time O(n), Space O(n)
class Solution {
    public:
        int minDepth(TreeNode *root) {
            if (root == nullptr) return 0;
            queue<TreeNode *> current, next;
            int len = 0;
            current.push(root);
            while (!current.empty()) {
                len += 1;
                while (!current.empty()) {
                    TreeNode *p = current.front();
                    current.pop();
                    if (p->left == nullptr && p->right == nullptr) return len;
                    if (p->left) next.push(p->left);
                    if (p->right) next.push(p->right);
                }
                current.swap(next);
            }
            return len;
        }
};
