class Solution {
    public:
        /*ListNode *mergeKLists(vector<ListNode *> &lists) {
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
        }*/

        struct cmp {
            bool operator()(const ListNode* a, const ListNode* b) {
                return a->val > b->val;
            }
        };

        ListNode *mergeKLists(vector<ListNode *> &lists) {
            priority_queue<ListNode*, vector<ListNode*>, cmp> minheap;
            for (int i = 0; i < lists.size(); i++) {
                if (lists[i] != nullptr) minheap.push(lists[i]);
            }
            ListNode dummy(-1);
            ListNode *p = &dummy;
            while (!minheap.empty()) {
                ListNode* cur = minheap.top();
                p->next = cur;
                p = p->next;
                minheap.pop();
                if (cur->next) minheap.push(cur->next);
            }
            return dummy.next;
        }
};
