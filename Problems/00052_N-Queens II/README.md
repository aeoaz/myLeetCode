思路同 51 题，只是不需要再填充棋盘，只需记录方案即可，仍是二维表格型 DFS + 回溯：

```cpp
class Solution {
public:
    bool col[10], dg[20], udg[20];
    int res;
    int totalNQueens(int n) {
        dfs(n, 0);
        return res;
    }

    void dfs(int n, int u) {
        if (u == n) {
            res++;
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!col[i] && !dg[u - i + n] && !udg[u + i]) {
                col[i] = dg[u - i + n] = udg[u + i] = true;
                dfs(n, u + 1);
                col[i] = dg[u - i + n] = udg[u + i] = false;
            }
        }
    }
};

```

