DFS：按照选和不选当前数字来进行分支

```cpp
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, target, 0);
        return res;
    }

    void dfs(vector<int>& candidates, int target, int u) {
        if (!target) {
            res.push_back(path);
            return;
        }

        if (u == candidates.size()) return;

        // case 1: do not choose the current number
        dfs(candidates, target, u + 1);

        // case 2: choose the current number
        if (candidates[u] <= target) {
            path.push_back(candidates[u]);
            dfs(candidates, target - candidates[u], u);
            path.pop_back();
        }
    }
}; // 按照选当前数字和不选当前数字来进行分支

```

