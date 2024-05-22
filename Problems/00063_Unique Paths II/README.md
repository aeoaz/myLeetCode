动态规划（思路同 62 题，依然是动态规划，只是需要加一些对障碍物的额外处理）：

```cpp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (obstacleGrid[i][j] == 1) dp[i][j] = 0;
                else {
                    if (!i && !j) dp[i][j] = 1;
                    else if (!i && j) dp[i][j] = dp[i][j - 1];
                    else if (i && !j) dp[i][j] = dp[i - 1][j];
                    else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        
        return dp[n - 1][m - 1];
    }
};

```

