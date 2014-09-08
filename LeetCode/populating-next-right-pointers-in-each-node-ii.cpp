/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
    public:
        void connect(TreeLinkNode *root) {
            while(root != nullptr) {
                TreeLinkNode *next = nullptr, *pre=nullptr;
                while(root != nullptr) {
                    if(next == nullptr) next = root->left == nullptr ? root->right : root->left;
                    if(root->left != nullptr) {
                        if(pre != nullptr) pre->next = root->left;
                        pre = root->left;
                    }
                    if(root->right != nullptr) {
                        if(pre != nullptr) pre->next = root->right;
                        pre = root->right;;
                    }
                    root = root->next;
                }
                root = next;
            }
        }
};
