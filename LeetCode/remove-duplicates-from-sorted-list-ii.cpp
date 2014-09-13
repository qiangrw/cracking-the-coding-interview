class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode dumpy(-1);
        ListNode *newp = &dumpy;
        ListNode *p = head;
        while (p) {
            bool flag = true;
            ListNode *next = p->next;
            while (next && next->val == p->val) {
                flag = false;
                next = next->next;
            }
            // no duplicate
            if (flag) {
                newp->next = p;
                newp = p;
            }
            p = next;
        }
        // DONOT Forget the last element
        newp->next = nullptr;
        return dumpy.next;
    }
};