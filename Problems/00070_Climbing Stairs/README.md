斐波那契数列：

```cpp
class Solution {
public:
    int climbStairs(int n) {
        int f = 1, g = 0;
        while (n--) {
            f = f + g;
            g = f - g;
        }
        return f;
    }
};

```

