#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Given a binary search tree and a range [a,b]
// Delete all nodes whose values are not in this range

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void inorderTraversal(TreeNode *root) {
    TreeNode *cur = root;
    stack<TreeNode *> s;
    while (!s.empty() || cur != nullptr) {
        if (cur != nullptr) {
            s.push(cur);
            cur = cur->left;
        } else {
            cur = s.top();
            s.pop();
            cout << cur->val << " ";
            cur = cur->right;
        }
    }
    cout << endl;
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

TreeNode *deleteNode(TreeNode *root, int a, int b) {
    if (root == nullptr) return root;
    TreeNode *left = deleteNode(root->left, a, b);
    TreeNode *right = deleteNode(root->right, a, b);
    if (root->val < a || root->val > b) {
        if (root->left) {
            root = root->left;
        } else if (root->right) {
            root = root->right;
        } else {
            return nullptr;
        }
    } else {
        root->left = left;
        root->right = right;
    }
    return root;
}

int main() {
    vector<int> num = {15, 20, 30, 35, 40, 45, 50};
    TreeNode *root = sortedArrayToBST(num.begin(), num.end());
    inorderTraversal(root);
    root = deleteNode(root, 25, 35);
    inorderTraversal(root);
    return 0;
}
