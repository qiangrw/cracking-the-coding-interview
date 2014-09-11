class Solution {
    public:
        TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
            return buildTree(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
        }

        template <typename BidiIt>
        TreeNode *buildTree(BidiIt prefirst, BidiIt prelast, BidiIt infirst, BidiIt inlast) {
            if (prefirst == prelast || infirst == inlast) return nullptr;
            TreeNode *root = new TreeNode(*prefirst);       
            auto rit = find(infirst, inlast, *prefirst);    
            int len = distance(infirst, rit);
            root->left = buildTree(prefirst+1, next(prefirst, len+1), infirst, next(infirst, len));
            root->right = buildTree(next(prefirst, len+1), prelast, next(infirst, len+1), inlast);
            return root;
        }

};
