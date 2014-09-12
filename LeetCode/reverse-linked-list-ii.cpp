class Solution {
    public:
        ListNode *reverseBetween(ListNode *head, int m, int n) {
            if (m == n || head == nullptr) return head;
            ListNode dumpy(-1);
            dumpy.next = head;
            ListNode *pre_head = &dumpy;
            for (int i = 0; i < m - 1; ++i) pre_head = pre_head->next;
            ListNode *p = pre_head->next;

            ListNode *next = p->next;
            for (int i = m; i < n; ++i) {
                p->next = next->next;
                next->next = pre_head->next;
                pre_head->next = next;
                next = p->next;
            }
            return dumpy.next;
        }
};
