class Solution {
    public:
        RandomListNode *copyRandomList(RandomListNode *head) {
            if (head == nullptr) return nullptr;
            RandomListNode *p = head, *next;
            RandomListNode *newp;
            while (p) {
                next = p->next;
                newp = new RandomListNode(p->label);

                p->next = newp;
                newp->next = next;
                p = next;
            }
            // Now deal with the random field
            for (p = head; p; p = p->next->next) {
                if (p->random != nullptr) p->next->random = p->random->next;
            }
            // Now recover the next filed
            p = head;
            newp = p->next;
            RandomListNode *res = newp;
            while (p != nullptr) {
                p->next = newp->next;
                if (newp->next == nullptr) break;
                newp->next = newp->next->next;
                p = p->next;
                newp = newp->next;
            }
            return res;
        }
};
