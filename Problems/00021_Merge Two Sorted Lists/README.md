以链表为载体的二路归并：

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        auto dummy = new ListNode(-1), p = dummy;
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                p = p->next = list1;
                list1 = list1->next;
            }
            else {
                p = p->next = list2;
                list2 = list2->next;
            }
        }
        if (list1) p->next = list1; // 链表的好处：只需接一下即可，不需要逐个遍历
        if (list2) p->next = list2;
        
        auto res = dummy->next;
        delete dummy;
        return res;
    }
};

```

