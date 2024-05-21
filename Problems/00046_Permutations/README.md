DFS + 回溯（需要用到 `st[]` 数组）：

```cpp
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    bool st[10];
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums, 0); // 该填第u个位置上的数了
        return res;
    }

    void dfs(vector<int>& nums, int u) {
        if (u == nums.size()) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!st[i]) {
                path.push_back(nums[i]);
                st[i] = true;
                dfs(nums, u + 1);
                path.pop_back();
                st[i] =false;
            }
        }
    }
};

```

