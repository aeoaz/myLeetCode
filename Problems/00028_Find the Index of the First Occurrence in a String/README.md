模板题：KMP 算法

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        vector<int> ne(m + 1); // 因为needle前面要加一个空格，所以ne数组的长度设为m+1
        haystack = ' ' + haystack, needle = ' ' + needle;

        for (int i = 2, j = 0; i <= m; i++) { // 注意是i <= m
            while (j && needle[i] != needle[j + 1]) j = ne[j];
            if (needle[i] == needle[j + 1]) j++;
            ne[i] = j;
        }

        for (int i = 1, j = 0; i <= n; i++) {
            while (j && haystack[i] != needle[j + 1]) j = ne[j];
            if (haystack[i] == needle[j + 1]) j++;
            if (j == m) return i - m;
        }

        return -1;
    }
};

```

