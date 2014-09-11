class Solution {
    public:
        TreeNode *sortedListToBST(ListNode *head) {
            if (head == nullptr) return nullptr;
            ListNode *pre_mid = nullptr;
            ListNode *slow = head, *fast = head;
            while (fast->next && fast->next->next) {
                pre_mid = slow;
                slow = slow->next;
                fast = fast->next->next;
            }

            TreeNode *root = new TreeNode(slow->val);
            if (pre_mid) {
                pre_mid->next = nullptr;
                root->left = sortedListToBST(head);
            }
            root->right = sortedListToBST(slow->next);
            return root;
        }
};
