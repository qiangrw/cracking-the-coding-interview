class Solution {
    public:
        TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
            return buildTree(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
        }

        template <typename BidIt>
        TreeNode *buildTree(BidIt inbegin, BidIt inend, BidIt postbegin, BidIt postend) {
            if (postbegin == postend || inbegin == inend) return nullptr;
            auto rit = prev(postend);
            TreeNode *root = new TreeNode(*rit);

            auto rit_in = find(inbegin, inend, *rit);
            int len = distance(inbegin, rit_in);
            root->left = buildTree(inbegin, rit_in, postbegin, next(postbegin, len));
            root->right = buildTree(rit_in + 1, inend, next(postbegin, len), postend-1);
            return root;
        }
};
