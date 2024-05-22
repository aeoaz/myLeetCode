动态规划：

```cpp
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        word1 = ' ' + word1, word2 = ' ' + word2;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++) {
                if (!i && !j) dp[i][j] = 0;
                else if (!i && j) dp[i][j] = j;
                else if (i && !j) dp[i][j] = i;
                else {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (word1[i] != word2[j]));
                }
            }
        
        return dp[n][m];
    }
};

```

