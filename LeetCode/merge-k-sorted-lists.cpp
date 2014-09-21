class Solution {
    public:
        ListNode *mergeKLists(vector<ListNode *> &lists) {
            if (lists.size() == 0) return nullptr;
            ListNode *p = lists[0];
            for (int i = 1; i < lists.size(); i++) p = mergeTwoList(p, lists[i]);
            return p;
        }

        ListNode *mergeTwoList(ListNode *l1, ListNode *l2) {
            ListNode dumpy(-1);
            ListNode *p = &dumpy;
            while (l1 != nullptr || l2 != nullptr) {
                int val1 = l1 == nullptr ? INT_MAX : l1->val;
                int val2 = l2 == nullptr ? INT_MAX : l2->val;
                if (val1 < val2) {
                    p->next = l1;
                    l1 = l1->next;
                } else {
                    p->next = l2;
                    l2 = l2->next;
                }
                p = p->next;
            }
            return dumpy.next;
        }
};
