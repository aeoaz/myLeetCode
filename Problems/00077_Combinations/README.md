组合类型的 DFS：

（组合问题中是 start，排列问题中是 st[]）

```cpp
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> combine(int n, int k) {
        dfs(n, k, 0, 1);
        return res;
    }

    void dfs(int n, int k, int u, int start) { // u表示当前已经填了几个数了
        if (u == k) {
            res.push_back(path);
            return;
        }

        for (int i = start; i <= n; i++) { // 注意组合问题中要有start
            path.push_back(i);
            dfs(n, k, u + 1, i + 1);
            path.pop_back();
        }
    }
};

```

