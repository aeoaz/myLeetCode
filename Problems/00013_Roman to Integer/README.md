模拟题：

```cpp
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> ht = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i + 1 < s.size() && ht[s[i]] < ht[s[i + 1]])
                res -= ht[s[i]];
            else 
                res += ht[s[i]];
        }
        return res;
    }
};

```

