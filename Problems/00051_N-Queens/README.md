二维表格型 DFS + 回溯：

```cpp
class Solution {
public:
    vector<vector<string>> res;
    bool col[10], dg[20], udg[20];
    vector<vector<string>> solveNQueens(int n) {
        vector<string> g;
        for (int i = 0; i < n; i++) g.push_back(string(n, '.'));
        dfs(g, n, 0);
        return res;
    }

    void dfs(vector<string>& g, int n, int u) {
        if (u == n) {
            res.push_back(g);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!col[i] && !dg[u - i + n] && !udg[u + i]) {
                g[u][i] = 'Q';
                col[i] = dg[u - i + n] = udg[u + i] = true;
                dfs(g, n, u + 1);
                g[u][i] = '.';
                col[i] = dg[u - i + n] = udg[u + i] = false;
            }
        }
    }
};

```

