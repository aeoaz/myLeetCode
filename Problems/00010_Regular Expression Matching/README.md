DP + 状态优化：

```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        s = ' ' + s, p = ' ' + p;
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));
        for (int i = 0; i <= n; i++) 
            for (int j = 0; j <= m; j++) {
                if (!i && !j) dp[i][j] = true;
                else if (i && !j) dp[i][j] = false;
                else {
                    if (canMatch(s[i], p[j])) dp[i][j] = i && dp[i - 1][j - 1];
                    else if (p[j] == '*') dp[i][j] = dp[i][j - 2] || i && canMatch(s[i], p[j - 1]) && dp[i - 1][j];
                }
            }
                
        return dp[n][m];
    }

    bool canMatch(char s, char p) {
        return s == p || p == '.';
    }
};
```

时间复杂度：$O(n^2)$（若不进行状态优化，则时间复杂度是 $O(n^3)$）

空间复杂度：$O(n^2)$