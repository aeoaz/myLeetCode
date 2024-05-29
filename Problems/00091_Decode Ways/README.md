本质还是爬楼梯问题：

```cpp
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        s = "  " + s;
        vector<int> dp(n + 2);
        dp[0] = dp[1] = 1;
        for (int i = 2; i < n + 2; i++) {
            if (s[i] != '0') dp[i] += dp[i - 1];
            if (isValid(s.substr(i - 1, 2))) dp[i] += dp[i - 2];
        }
        return dp[n + 1];
    }

    bool isValid(const string& s) {
        return "10" <= s && s <= "26";
    }
};

```

