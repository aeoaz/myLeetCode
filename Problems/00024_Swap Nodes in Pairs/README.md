`swapNodes()` 函数：

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        auto dummy = new ListNode(-1, head), p = dummy;
        while (p->next && p->next->next) {
            swapNodes(p, p->next);
            p = p->next->next;
        }
        auto res = dummy->next;
        delete dummy;
        return res;
    }

    void swapNodes(ListNode* prev, ListNode* x) {
        auto t = x->next;
        prev->next = t;
        x->next = t->next;
        t->next = x;
    }
};

```

