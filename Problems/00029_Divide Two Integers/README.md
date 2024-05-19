快速乘 && 边界处理：

```cpp
class Solution {
public:
    int divide(int dividend, int divisor) {
        // 特判1：若被除数为INT_MIN
        if (dividend == INT_MIN) {
            if (divisor == 1) return INT_MIN;
            if (divisor == -1) return INT_MAX;
        }

        // 特判2：若除数为INT_MIN
        if (divisor == INT_MIN)
            return dividend == INT_MIN ? 1 : 0;
        
        // 特判3：考虑被除数为0的情况
        if (dividend == 0) return 0; // 注意：下面的代码处理不了这种情况

        bool isminus = (dividend < 0) ^ (divisor < 0);
        
        // 将被除数和除数都转为负数
        if (dividend > 0) dividend = -dividend;
        if (divisor > 0) divisor = -divisor;

        // 先找到base数组
        vector<int> base = {divisor};
        while (dividend - base.back() <= base.back())
            base.push_back(base.back() + base.back());
        
        // 然后逆序查找
        int res = 0;
        for (int i = base.size() - 1; i >= 0; i--) {
            if (base[i] >= dividend) {
                res += (1 << i);
                dividend -= base[i];
            }
        }

        return isminus ? -res : res;
    }
};

```

