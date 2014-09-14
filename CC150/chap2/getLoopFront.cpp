#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) { val = x; next = nullptr; }
};

ListNode *getLoopFront(ListNode *head) {
    if(head == nullptr || head->next == nullptr) return head;
    ListNode *slow = head, *fast = head;
    // run until they meet in LoopSize-k%LoopSize
    while(slow != nullptr && fast != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) break;
    }

    // run another k steps to get to the collide point
    slow = head;
    while(slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return fast;
}

int main() {
    ListNode a(1), b(2), c(3), d(4), e(5), f(6), g(7), h(8), i(9), j(10), k(11);
    a.next = &b; b.next = &c; c.next = &d; d.next = &e; e.next = &f; f.next = &g;
    g.next = &h; h.next = &i; i.next = &j; j.next = &k; k.next = &d;
    ListNode *start = getLoopFront(&a);
    cout << start->val << endl;
    return 0;
}
