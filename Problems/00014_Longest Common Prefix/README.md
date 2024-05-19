暴力做法即可：

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            int len = min(res.size(), strs[i].size());
            int j = 0;
            for (; j < len; j++) {
                if (res[j] != strs[i][j]) break;
            }
            res = res.substr(0, j);
        }
        return res;
    }
};

```

