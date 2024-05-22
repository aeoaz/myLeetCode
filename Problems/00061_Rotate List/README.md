注意两个特判：

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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head; // 此特判不可省略
        auto tail = head;
        int n = 1;
        while (tail->next) {
            n++;
            tail = tail->next;
        }
        k %= n;
        if (k == 0) return head; // 此特判不可省略

        auto dummy = new ListNode(-1, head), p = dummy;
        for (int i = 0; i < n - k; i++) p = p->next; // 此时p是新的tail
        
        dummy->next = p->next;
        tail->next = head;
        p->next = nullptr;

        auto res = dummy->next;
        delete dummy;
        return res;
    }
};

```

