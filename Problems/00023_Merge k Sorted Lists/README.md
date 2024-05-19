堆 + 合并链表：

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto dummy = new ListNode(-1), p = dummy;
        using PIL = pair<int, ListNode*>;
        priority_queue<PIL, vector<PIL>, greater<PIL>> heap; // val, index
        for (auto lis : lists) {
            if (lis) heap.push({lis->val, lis});
        }
        while (!heap.empty()) {
            auto [val, t] = heap.top();
            heap.pop();
            p = p->next = t; // 注意：尾插法中p指针要跟着往后移
            t = t->next;
            if(t) heap.push({t->val, t});
        }
        auto res = dummy->next;
        delete dummy;
        return res;
    }
};

```

