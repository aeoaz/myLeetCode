模板题：删除链表的倒数第 N 哥个结点：

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto dummy = new ListNode(-1, head), p = dummy; // trick: 让p从dummy开始走，
        auto t = head; // t从head开始走，则
        while (n--) t = t->next;
        while (t) {
            t = t->next;
            p = p->next;
        } // p最终停下来的位置就是待删除节点的前驱
        p->next = p->next->next;
        auto res = dummy->next;
        delete dummy; // 防止内存泄漏
        return res;
    }
};

```

