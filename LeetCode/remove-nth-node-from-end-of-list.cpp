class Solution {
    public:
        ListNode *removeNthFromEnd(ListNode *head, int n) {
            if (head == nullptr || n == 0) return head;
            ListNode dumpy(-1);
            dumpy.next = head;
            ListNode *slow = &dumpy, *fast = &dumpy;
            for (int i = 0; i < n; ++i) {
                fast = fast->next;
            }
            while(fast->next != nullptr) {
                fast = fast->next;
                slow = slow->next;
            }

            ListNode *tmp = slow->next;
            slow->next = slow->next->next;
            delete tmp;
            return dumpy.next;
        }
};
