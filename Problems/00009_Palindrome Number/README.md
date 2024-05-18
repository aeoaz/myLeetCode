数学（只用判断一半就可以）：

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x && x % 10 == 0) return false; // 注意：下面的代码无法处理这种情况
        int y = 0;
        while (x >= y) {
            y = y * 10 + x % 10;
            if (x == y || x / 10 == y) return true;
            x /= 10;
        }
        return false;
    }
};

```

时间复杂度：$O(1)$（因为 int 型整数在十进制下最多只有 10 位）