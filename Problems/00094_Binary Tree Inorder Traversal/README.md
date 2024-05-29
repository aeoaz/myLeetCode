goAlongVine：

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        stack<TreeNode*> S;
        auto x = root;
        while (true) {
            goAlongVine(x, S);
            if (S.empty()) break;
            x = S.top(); S.pop();
            res.push_back(x->val);
            x = x->right;
        }
        return res;
    }

    void goAlongVine(TreeNode* x, stack<TreeNode*>& S) {
        while (x) {
            S.push(x);
            x = x->left;
        }
    }
};

```

