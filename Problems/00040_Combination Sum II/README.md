DFS + prev 去重：

```cpp
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0);
        return res;
    }

    void dfs(vector<int>& candidates, int target, int start) {
        if (!target) {
            res.push_back(path);
            return;
        }

        int prev = -1;
        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] <= target && prev != candidates[i]) {
                prev = candidates[i];
                path.push_back(candidates[i]);
                dfs(candidates, target - candidates[i], i + 1);
                path.pop_back();
            }
        }
    }
};

```

