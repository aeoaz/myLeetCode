窗口长度固定的滑动窗问题：

```cpp
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size(), m = words.size(), w = words[0].size();
        unordered_map<string, int> ht;
        for (auto& word : words) ht[word]++;

        vector<int> res;
        for (int i = 0; i < w; i++) {
            unordered_map<string, int> wind;
            int cnt = 0;
            for (int j = i; j + w <= n; j += w) { // i只提供初始值的作用，并不跟随滑动窗一起移动
                if (j >= i + m * w) { // 由于滑动窗长度固定，因此初始左边界可能滑出
                    auto word = s.substr(j - m * w, w); // 此处用的是右边界和滑动窗的长度
                    wind[word]--;
                    if (wind[word] < ht[word]) cnt--;
                }
                auto word = s.substr(j, w);
                wind[word]++;
                if (wind[word] <= ht[word]) cnt++;
                if (cnt == m) res.push_back(j - (m - 1) * w);
            }
        }
        return res;
    }
};

```

