DP：

```cpp
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size(), k = s3.size();
        if (n + m != k) return false;
        s1 = ' ' + s1, s2 = ' ' + s2, s3 = ' ' + s3;
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++) {
                if (!i && !j) dp[i][j] = true;
                else if (!i && j) dp[i][j] = dp[i][j - 1] && (s2[j] == s3[i + j]);
                else if (i && !j) dp[i][j] = dp[i - 1][j] && (s1[i] == s3[i + j]);
                else dp[i][j] = dp[i - 1][j] && (s3[i + j] == s1[i]) || dp[i][j - 1] && (s3[i + j] == s2[j]);
            }
        
        return dp[n][m];
    }
};
// dp[i][j]表示s1[i]和s2[j]能否交错成s3[i+j]

```

