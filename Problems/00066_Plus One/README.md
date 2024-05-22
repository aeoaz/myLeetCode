高精度加法：

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        int t = 1;
        for (int i = digits.size() - 1; i >= 0 || t; i--) {
            if (i >= 0) t += digits[i];
            res.push_back(t % 10);
            t /= 10;
        }
        // 注：本题不会有前导0
        reverse(res.begin(), res.end());
        return res;
    }
};

```

