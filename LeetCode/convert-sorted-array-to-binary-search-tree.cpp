class Solution {
    public:
        TreeNode *sortedArrayToBST(vector<int> &num) {
            return sortedArrayToBST(num.begin(), num.end());
        }

        template <typename BidIt>
        TreeNode *sortedArrayToBST(BidIt start, BidIt end) {
            if (start == end) return nullptr;
            auto mid = start + distance(start, end) / 2;
            TreeNode *root = new TreeNode(*mid);
            root->left = sortedArrayToBST(start, mid);
            root->right = sortedArrayToBST(mid+1, end);
            return root;
        }
};
