class Solution {
    public:
        ListNode *swapPairs(ListNode *head) {
            if (head == nullptr || head->next == nullptr) return head;
            ListNode *last = head->next->next;
            ListNode *newhead = head->next;
            newhead->next = head;
            head->next = swapPairs(head->next->next);
            return newhead;
        }
};
