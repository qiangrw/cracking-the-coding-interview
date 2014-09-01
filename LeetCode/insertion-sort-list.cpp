/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode dumpy(-1);
        ListNode *next = head, *p = nullptr;
        while (next) {
            p = next;
            next = p->next;
            p->next = nullptr;
            
            // insert node p to the new list
            ListNode *pre = &dumpy;
            ListNode *q = dumpy.next;
            while (q != nullptr) {
                if (q->val > p->val) break;
                pre = q;
                q = q->next;
            }
            pre->next = p;
            p->next = q;
        }
        return dumpy.next;
    }
};