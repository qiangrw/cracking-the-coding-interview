#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *quicksort(ListNode *head, ListNode **tail) {
    if (head == nullptr || head->next == nullptr) {
        *tail = head;
        return head;
    }
    ListNode d1(-1), d2(-1);
    ListNode *pivot = head, *p = head->next;
    while (p != nullptr) {
        ListNode *next = p->next;
        ListNode *tmp = nullptr;
        if (p->val < pivot->val) {
            tmp = d1.next;
            d1.next = p;
        } else {
            tmp = d2.next;
            d2.next = p;
        }
        p->next = tmp;
        p = next;
    }
    ListNode *t1 = nullptr, *t2 = nullptr;
    ListNode *h1 = quicksort(d1.next, &t1);
    ListNode *h2 = quicksort(d2.next, &t2);
    if (t1 != nullptr) t1->next = pivot;
    *tail = pivot;
    pivot->next = h2;
    if (t2 != nullptr) *tail = t2;
    return h1 == nullptr ? pivot : h1;
}

void print(ListNode *head) {
    for (ListNode *p = head; p; p = p->next) {
        cout << p->val << " ->  ";
    }
    cout << "nullptr" << endl;
}

int main() {
    ListNode* head = new ListNode(4);
    ListNode* p = head;
    vector<int> v { 3,4,5,2,3,6,7,9,4,5,2,5,6,3,1 };
    for (auto a : v) {
        p->next = new ListNode(a);
        p = p->next;
    }
    print(head);
    ListNode *tail;
    head = quicksort(head, &tail);
    print(head);
    return 0;
}
