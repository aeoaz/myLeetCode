滑动窗：

```cpp
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> ht;
        for (auto c : t) ht[c]++;

        unordered_map<char, int> wind;
        int cnt = 0; // 局部变量在声明时一定要初始化，否则会产生不可预测的后果
        string res;
        for (int l = 0, r = 0; r < s.size(); r++) {
            wind[s[r]]++;
            if (wind[s[r]] <= ht[s[r]]) cnt++;
            while (wind[s[l]] > ht[s[l]]) wind[s[l++]]--;
            if (cnt == t.size()) {
                if (res.empty() || r - l + 1 < res.size())
                    res = s.substr(l, r - l + 1);
            }
        }
        return res;
    }
};

```

