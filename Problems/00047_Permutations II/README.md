DFS + 回溯 + prev 去重 + `st[]` 数组：

```cpp
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    bool st[10];
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return res;
    }

    void dfs(vector<int>& nums, int u) {
        if (u == nums.size()) {
            res.push_back(path);
            return;
        }

        int prev = -11;
        for (int i = 0; i < nums.size(); i++) {
            if (!st[i] && prev != nums[i]) {
                prev = nums[i];
                path.push_back(nums[i]);
                st[i] = true;
                dfs(nums, u + 1);
                path.pop_back();
                st[i] = false;
            }
        }
    }
};

```

