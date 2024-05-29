DP：

```cpp
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1; // 边界条件：规定：空树有一种
        for (int i = 1; i <= n; i++) { // i枚举的是树中总的结点个数，最少1个，最多n个
            for (int j = 0; j < i; j++) { // j枚举的是左子树中结点的个数，最少0个，最多i-1个
                dp[i] += dp[j] * dp[i - j - 1]; // 左子树中结点个数为j，右子树中结点个数为i-j-1
            }
        }
        return dp[n];
    }
};
```

