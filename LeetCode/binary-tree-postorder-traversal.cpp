/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> s;
        TreeNode *p = root, *q;
        if (root == nullptr) return res;
        
        do {
            while (p != nullptr) {
                s.push(p);
                p = p->left;
            }
            q = nullptr;
            while (!s.empty()) {
                p = s.top();
                if (p->right == q) {    // right child visited
                    s.pop();
                    res.push_back(p->val);
                    q = p;              // last visited member
                } else {
                    p = p->right;
                    break;
                }
            }
        } while (!s.empty());
        return res;
    }
};