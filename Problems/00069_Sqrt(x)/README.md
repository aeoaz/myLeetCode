寻找左侧边界的二分（注意本题有两个可能会超出 int 的地方）：

```cpp
class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x;
        while (l < r) {
            long long mid = l + r + 1ll >> 1; // l + r + 1可能超出int范围
            if (mid <= x / mid) l = mid; // 注意mid * mid可能会超出int范围
            else r = mid - 1;
        }
        return l;
    }
};

```

