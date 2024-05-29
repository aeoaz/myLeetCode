区间 DP：

```cpp
class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(n, vector<bool>(n + 1)));

        for (int k = 1; k <= n; k++) {
            for (int i = 0; i + k <= n; i++) {
                for (int j = 0; j + k <= n; j++) {
                    if (k == 1) dp[i][j][k] = s1[i] == s2[j];
                    else {
                        for (int u = 1; u < k; u++) {
                            dp[i][j][k] = dp[i][j][u] && dp[i + u][j + u][k - u] || 
                                          dp[i][j + k - u][u] && dp[i + u][j][k - u];
                            if (dp[i][j][k]) break;
                        }
                    }
                }
            }
        }
        return dp[0][0][n];
    }
};
// 区间DP:
// 状态表示：dp[i][j][k]:
// 集合：当长度为k时，由s1(i, k)扰乱得到s2(j, k)的所有方案
// 属性：集合是否非空
// 状态计算：
// 枚举所有的长度u:[1, k-1]，只要存在一种可行的扰乱方案, dp[i][j][k]即为true
// for (int u = 1; u < k; u++)
// dp[i][j][k] = dp[i][j][u] && dp[i + u][j + u][k - u] || dp[i][j + k - u][u] && dp[i + u][k][k - u];
// 如果发现了可行方案，就及时退出
```

