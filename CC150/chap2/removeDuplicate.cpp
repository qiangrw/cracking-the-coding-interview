#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) { val = x; next = nullptr; }
};

bool isDup(ListNode *cur, ListNode *p) {
    while(p != nullptr && p != cur) {
        if(p->val == cur->val) return true;
        p = p->next;
    }
    return false;
}

ListNode *removeDuplicate(ListNode *head) {
    if(head == nullptr || head->next == nullptr) return head;
    ListNode *p, *cur=head->next, *pre=head;
    while(cur != nullptr) {
        // skip dup node
        if(isDup(cur, head)) {
            pre->next = cur->next;
            // pre should not change in this case
            cur = cur->next;
        } else {
            pre = cur;
            cur = cur->next;
        }
    }
    return head;
}

int main() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(2);
    ListNode *p=removeDuplicate(head);
    for(; p!=nullptr; p=p->next) cout << p->val << "->";
    cout << "NULL" << endl;
    return 0;
}
