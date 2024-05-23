代码：

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
    ListNode* deleteDuplicates(ListNode* head) {
        auto p = head;
        while (p && p->next) {
            if (p->val == p->next->val) { // 如果发现重复，
                int x = p->val; // 记录重复结点的值
                while (p->next && p->next->val == x) // 处理重复
                    p->next = p->next->next;
            }
            else p = p->next;
        }
        return head;
    }
};

```

