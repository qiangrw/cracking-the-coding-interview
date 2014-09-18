class Solution {
    public:
        ListNode *rotateRight(ListNode *head, int k) {
            if (head == nullptr || head->next == nullptr || k == 0) return head;
            ListNode dumpy(-1);
            dumpy.next = head;

            int n = 0;
            ListNode *p = &dumpy;
            while (p->next)  {
                n += 1;
                p = p->next;
            }
            k = k % n;
            if (k == 0) return head;

            ListNode *newtail = &dumpy, *newhead = nullptr;
            for (int i = 0; i < n - k; ++i) newtail = newtail->next;
            newhead = newtail->next;
            newtail->next = nullptr;
            p->next = dumpy.next;
            return newhead;
        }
};
