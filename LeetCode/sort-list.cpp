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
    ListNode *getmid(ListNode *head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode *slow=head, *fast=head;
        // Note here must be fast->next->next, when a->b->nullptr, slow should be a.
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    
    ListNode *merge(ListNode *l1, ListNode *l2) {
        ListNode dumpy(-1);
        ListNode *p = &dumpy;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        if (l1) p->next = l1;
        if (l2) p->next = l2;
        return dumpy.next;
    }
    
    ListNode *sortList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *mid = getmid(head);
        ListNode *first = head;
        ListNode *second = mid->next;
        mid->next = nullptr;
        
        first = sortList(first);
        second = sortList(second);
        return merge(first, second);
    }
};