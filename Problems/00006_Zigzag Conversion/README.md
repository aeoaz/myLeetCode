模拟：

```cpp
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s; // 注意：下面的代码无法处理这种边界情况
        vector<string> rows(numRows);
        int dir = -1, r = 0;
        for (auto c : s) {
            rows[r] += c;
            if (r == 0 || r == numRows - 1) dir = -dir;
            r += dir;
        }
        string res;
        for (auto& row : rows) res += row;
        return res;
    }
};

```

时间复杂度：$O(n)$；

空间复杂度：$O(n)$。