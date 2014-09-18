class Solution {
    public:
        ListNode *rotateRight(ListNode *head, int k) {
            if (head == nullptr || k == 0) return head;

            int n = 1;
            ListNode *p = head;
            while (p->next)  {
                n += 1;
                p = p->next;
            }
            k = n - k % n;
            // form a circle
            p->next = head;

            for (int i = 0; i < k; ++i) {
                p = p->next;
            }
            head = p->next;
            // cut the circle
            p->next = nullptr;
            return head;
        }
};
