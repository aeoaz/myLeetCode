DFS：

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
    vector<TreeNode*> generateTrees(int n) {
        return dfs(1, n);
    }

    vector<TreeNode*> dfs(int st, int ed) {
        if (st > ed) return {nullptr};

        vector<TreeNode*> res;
        for (int i = st; i <= ed; i++) {
            auto lchids = dfs(st, i - 1), rchilds = dfs(i + 1, ed);
            for (auto& lc : lchids) {
                for (auto& rc : rchilds) {
                    auto root = new TreeNode(i);
                    root->left = lc;
                    root->right = rc;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};

```

