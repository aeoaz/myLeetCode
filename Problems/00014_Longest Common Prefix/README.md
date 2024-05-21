暴力做法即可：

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = strs[0];
        for (auto& s : strs) {
            int len = min(res.size(), s.size());
            int i = 0;
            for (; i < len; i++) {
                if (res[i] != s[i]) break;
            }
            res = res.substr(0, i);
        }
        return res;
    }
};

```

