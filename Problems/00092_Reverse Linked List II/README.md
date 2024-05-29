代码如下：

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        auto dummy = new ListNode(-1, head), prev = dummy;
        for (int i = 0; i < left - 1; i++) prev = prev->next; // prev永远指向翻转区前一个位置
        auto cur = prev->next; // cur永远指向待翻转区域的第一个位置
        for (int i = 0; i < right - left; i++) { // 只需翻转right - left次
            auto next = cur->next;
            cur->next = next->next; // step 1
            next->next = prev->next; // step 2
            prev->next = next; // step 3
        }
        auto res = dummy->next;
        delete dummy;
        return res;
    }
};

```

