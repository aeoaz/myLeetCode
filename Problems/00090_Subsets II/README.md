组合类型的 DFS + sort-prev 去重：

```cpp
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int len = 0; len <= nums.size(); len++) {
            dfs(nums, len, 0, 0); // u, start
        }
        return res;
    }

    void dfs(vector<int>& nums, int len, int u, int start) {
        if (u == len) {
            res.push_back(path);
            return;
        }

        int prev = 11;
        for (int i = start; i < nums.size(); i++) {
            if (nums[i] != prev) {
                path.push_back(nums[i]);
                prev = nums[i];
                dfs(nums, len, u + 1, i + 1);
                path.pop_back();
            }
        }
    }
};

```

