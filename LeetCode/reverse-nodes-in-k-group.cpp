/**
 *  * Definition for singly-linked list.
 *   * struct ListNode {
 *    *     int val;
 *     *     ListNode *next;
 *      *     ListNode(int x) : val(x), next(NULL) {}
 *       * };
 *        */
class Solution {
    public:
        ListNode *reverseKGroup(ListNode *head, int k) {
            if (head == nullptr || head->next == nullptr) return head;
            int n = 0;
            for (ListNode *p=head; p; p = p->next) n++;
            if (k > n || k == 1) return head;

            ListNode dumpy(-1);
            ListNode *pre = nullptr, *cur = nullptr, *next = head;
            ListNode *pre_last = &dumpy, *cur_last = nullptr;

            for (int g = 0; g < n/k; g++) {
                cur_last = next;
                for (int i = 0; i < k; i++) {
                    cur = next;
                    next = cur->next;
                    cur->next = pre;
                    pre = cur;
                }
                pre_last->next = cur;
                pre_last = cur_last;
            }
            if(pre_last != nullptr) pre_last->next = next;
            return dumpy.next;
        }
};
