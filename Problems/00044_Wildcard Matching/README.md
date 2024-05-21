动态规划 + 状态优化：

```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        s = ' ' + s, p = ' ' + p;
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));
        dp[0][0] = true;
        for (int i = 0; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                if (i && p[j] != '*')
                    dp[i][j] = dp[i - 1][j - 1] && (s[i] == p[j] || p[j] == '?');
                else if (p[j] == '*')
                    dp[i][j] = dp[i][j - 1] || i && dp[i - 1][j];
            }
        
        return dp[n][m];
    }
};

// i && p[j] != '*': dp[i][j] = dp[i - 1][j - 1] &&(s[i] == p[j] || p[j] == '?');
// p[j] == '*': dp[i][j] = dp[i][j - 1] || dp[i - 1][j - 1] || dp[i - 2][j - 1] ||
// dp[i - 1][j] = dp[i - 1][j - 1] || dp[i - 2][j - 1] || dp[i - 3][j - 1] ||
// dp[i][j] = dp[i][j - 1] || dp[i - 1][j];

```

