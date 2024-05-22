动态规划（二维表格型 DFS 如果只是求方案数或者如果只是让判断是否可行，则需要考虑是否需要用动态规划来优化）：

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (!i && !j) dp[i][j] = 1;
                else if (!i && j) dp[i][j] = dp[i][j - 1];
                else if (i && !j) dp[i][j] = dp[i - 1][j];
                else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        
        return dp[m - 1][n - 1];
    }
};

```

