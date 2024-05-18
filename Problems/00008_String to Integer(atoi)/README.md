模拟题：

```cpp
class Solution {
public:
    int myAtoi(string s) {
        // 跳过前导空格
        int k = 0;
        while (k < s.size() && s[k] == ' ') k++;

        // 判断符号
        bool isminus = false;
        if (k < s.size() && (s[k] == '+' || s[k] == '-')) {
            // if (k + 1 < s.size() && !isdigit(s[k + 1])) return 0; // 注意：此特判并无必要
            if (s[k] == '-') isminus = true;
            k++;
        }

        // 求数值
        int res = 0;
        for (int i = k; i < s.size() && isdigit(s[i]); i++) {
            // 判断有无溢出
            if (res > (INT_MAX - s[i] + '0') / 10) { // trick: 先减后加避免溢出
                return isminus ? INT_MIN : INT_MAX;
            }
            res = res * 10 - '0' + s[i]; // trick: 先减后加防止溢出
        }
        return isminus ? -res : res;
    }
};

```

