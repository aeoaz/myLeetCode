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
        using PIL = pair<int, ListNode*>;
        priority_queue<PIL, vector<PIL>, greater<PIL>> heap;
        for (auto l : lists) {
            if (l) heap.push({l->val, l});
        }

        auto dummy = new ListNode(-1), p = dummy;
        while (!heap.empty()) {
            auto [val, node] = heap.top(); heap.pop();
            p = p->next = node; // 注意：尾插法中p指针要跟着往后移
            if (node->next) heap.push({node->next->val, node->next});
        }
        auto res = dummy->next;
        delete dummy;
        return res;
    }
};

```

