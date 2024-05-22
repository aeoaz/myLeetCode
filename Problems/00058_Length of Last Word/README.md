简单的字符串解析：

```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
        int j = s.size() - 1;
        while (j >= 0 && s[j] == ' ') j--;
        int i = j;
        while (i >= 0 && s[i] != ' ') i--;
        return j - i;
    }
};

```

