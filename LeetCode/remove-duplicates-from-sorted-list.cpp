class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == nullptr) return head;
        ListNode *pre = head;
        for (ListNode *p = head->next; p; p = p->next) {
            if (p->val == pre->val) {
                pre->next = p->next;
            } else pre = p;
        }
        return head;
    }
};