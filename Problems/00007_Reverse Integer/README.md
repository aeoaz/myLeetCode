整数反转：

```cpp
class Solution {
public:
    string convert(string s, int numRows) { // 模拟：O(n)
        if (numRows == 1) return s; // 下面的代码无法处理这种边界情况
        vector<string> rows(numRows);
        int direction = -1, i = 0; // direction: 方向, i: 行索引
        for (auto c : s) {
            rows[i] += c;
            if (i == 0 || i == numRows - 1) direction = -direction;
            i += direction;
        }
      
        string res;
        for (auto& t : rows) res += t;
        return res;
    }
};

```

本题需要注意以下问题：

- x 不需要取绝对值，整数反转算法同样适用于负数。