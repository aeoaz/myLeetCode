动态规划：

状态转移方程：

```cpp
dp[i] = max(dp[i - 1] + nums[i], nums[i]);
```

代码实现：

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        for (int i = 1; i < n; i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
        }
        int res = dp[0];
        for (int i = 0; i < n; i++) res = max(res, dp[i]);
        return res;
    }
};

```

