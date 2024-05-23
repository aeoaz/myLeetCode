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
        auto dummy = new ListNode(-1, head), p = dummy;
        while (p->next && p->next->next) { // 只有当至少有两个结点时，才有可能重复
            if (p->next->val == p->next->next->val) { // 如果重复，
                int x = p->next->val; // 先把重复的数字记录下来，可以方便判断
                while (p->next && p->next->val == x) // 如果遇到重复结点
                    p->next = p->next->next; // 就跳过重复结点
            }
            else p = p->next; // 不重复直接往后走
        }
        auto res = dummy->next;
        delete dummy;
        return res;
    }
};

```

