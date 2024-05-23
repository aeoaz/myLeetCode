双 dummy：

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
    ListNode* partition(ListNode* head, int x) {
        auto dummy = new ListNode(-1), p = dummy;
        auto dummy2 = new ListNode(-1), q = dummy2;

        for (auto t = head; t; t = t->next) 
            if (t->val < x) p = p->next = t;
            else q = q->next = t;

        p->next = dummy2->next;
        q->next = nullptr; // 不可省略
        delete dummy2;
        auto res = dummy->next;
        delete dummy;
        return res;
    }
};

```

