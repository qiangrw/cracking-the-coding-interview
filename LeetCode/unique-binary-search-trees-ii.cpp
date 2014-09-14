class Solution {
    public:
        vector<TreeNode *> generate(int start, int end) {
            // CORNER CASE! MUST RETURN NULL SUBTREE
            if (start > end) return {nullptr};
            vector<TreeNode *> res;
            for (int k = start; k <= end; ++k) {
                vector<TreeNode *> left = generate(start, k-1);
                vector<TreeNode *> right = generate(k+1, end);
                for (auto l: left) {
                    for (auto r: right) {
                        TreeNode *root = new TreeNode(k);
                        root->left = l;
                        root->right = r;
                        res.push_back(root);
                    }
                }
            }
            return res;
        }

        vector<TreeNode *> generateTrees(int n) {
            return generate(1, n);
        }
};
