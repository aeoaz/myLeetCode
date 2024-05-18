方法一：动态规划

- 更长的回文串是由更短的回文串不断地向两边扩展出来的；
- 因此动态规划必须按长度从小到大的顺序去进行状态转移：
  - 第一层循环：从小到大枚举不同长度；
  - 第二层循环：从左到右枚举不同的起点。

```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2) return s; // 边界条件特判
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; i++) dp[i][i] = true;
        int start = 0, maxLen = 1; // 回文子串长度至少为1
        for (int L = 2; L <= n; L++) { // L最长为n
            for (int i = 0; i < n; i++) {
                // j - i + 1 = L
                int j = i + L - 1;
                if (j >= n) break;
                if (s[i] != s[j]) dp[i][j] = false;
                else {
                    if (j - i < 3) dp[i][j] = true;
                    else dp[i][j] = dp[i + 1][j - 1];
                }

                if (dp[i][j] && L > maxLen) {
                    start = i;
                    maxLen = L;
                }
            }
        }

        return s.substr(start, maxLen);
    }
};

```

时间复杂度：$O(n^2)$；

空间复杂度：$O(n^2)$。



方法二：枚举每个中心

- 从左到右枚举不同的中心，从每个中心处分别进行“奇扩展”和“偶扩展”，看能扩展得到的最大长度。

```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); i++) {
            auto [l1, r1] = expand(s, i, i);
            auto [l2, r2] = expand(s, i, i + 1);

            if (r1 - l1 > end - start) start = l1, end = r1;
            if (r2 - l2 > end - start) start = l2, end = r2;
        }
        return s.substr(start, end - start + 1);
    }

    pair<int, int> expand(string& s, int l, int r) {
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            l--, r++;
        }
        return {l + 1, r - 1};
    }
};

```

时间复杂度：$O(n^2)$；

空间复杂度：$O(1)$。