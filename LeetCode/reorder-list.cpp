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
    ListNode* reverse(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *head2 = head, *cur = head, *pre = nullptr;
        while (cur != nullptr) {
            ListNode *next = cur->next;
            cur->next = pre;
            head2 = cur;
            pre = cur;
            cur = next;
        }
        return head2;
    }
    
    void reorderList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return;
        ListNode *fast=head, *slow=head;
        while (fast != nullptr && fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *head2 = reverse(slow->next);
        slow->next = nullptr;

        // merge two list
        ListNode dumpy(-1);
        ListNode *p = &dumpy;
        while (head != nullptr && head2 != nullptr) {
            p->next = head;
            p = p->next;
            head = head->next;
            p->next = head2;
            p = p->next;
            head2 = head2->next;
        }
        if (head != nullptr) p->next = head;
        head = dumpy.next;
    }
};