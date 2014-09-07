class Solution {
    public:
        ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
            ListNode dumpy(-1);
            ListNode *p = &dumpy;
            int c = 0, a, b, res;
            while (l1 || l2 || c) {
                a = l1 == nullptr ? 0 : l1->val;
                b = l2 == nullptr ? 0 : l2->val;
                res = (a + b + c);
                c = res / 10;
                p->next = new ListNode(res % 10);

                p = p->next;
                if (l1) l1 = l1->next;
                if (l2) l2 = l2->next;
            }
            return dumpy.next;
        }
};
