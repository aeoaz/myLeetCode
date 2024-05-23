DFS（本题是 77 题的延伸）：

```cpp
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> subsets(vector<int>& nums) {
        for (int len = 0; len <= nums.size(); len++)
            dfs(nums, len, 0, 0);
        return res;
    }

    void dfs(vector<int>& nums, int len, int u, int start) {
        if (u == len) {
            res.push_back(path);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            path.push_back(nums[i]);
            dfs(nums, len, u + 1, i + 1);
            path.pop_back();
        }
    }
};

```

