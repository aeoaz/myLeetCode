快速幂：

```cpp
class Solution {
public:
    double myPow(double x, int n) {
        bool isminus = n < 0;
        long long nll = (long long)abs(n); // 若不转为long long则有可能超出int
        double res = 1;
        while (nll) {
            if (nll & 1) res *= x;
            x *= x;
            nll >>= 1;
        }
        return isminus ? 1 / res : res;
    }
};

```

