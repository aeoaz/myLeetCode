整数反转：

```cpp
class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x) {
            if (x < 0 && res < (INT_MIN - x % 10) / 10) return 0;
            if (x > 0 && res > (INT_MAX - x % 10) / 10) return 0;
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
};

```

本题需要注意以下问题：

- x 不需要取绝对值，整数反转算法同样适用于负数。