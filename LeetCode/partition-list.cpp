/**
 *   Definition for singly-linked list.
 *    struct ListNode {
 *       int val;
 *       ListNode *next;
 *       ListNode(int x) : val(x), next(NULL) {}
 *    };
 */

class Solution {
    public:
        ListNode *partition(ListNode *head, int x) {
            if (head == nullptr || head->next == nullptr) return head;
            ListNode dumpy1(-1), dumpy2(-1);
            ListNode *l1 = &dumpy1, *l2 = &dumpy2;
            for (ListNode *p = head; p != nullptr; p = p->next) {
                if (p->val < x) {
                    l1->next = p;
                    l1 = l1->next;
                } else {
                    l2->next = p;
                    l2 = l2->next;
                }
            }
            l1->next = dumpy2.next;
            l2->next = nullptr;
            return dumpy1.next;
        }
};
