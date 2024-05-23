单调栈：

本题可转化为第 84 题，做法还是单调栈（把每层当作第一层向上统计每层的高度，然后取最大矩形最值，本题即可转化为 84 题）。

```cpp
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> h(m);
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) // 处理得到height数组
                if (matrix[i][j] == '1') h[j]++;
                else h[j] = 0; // 注意：如果当前这一行某个位置不为1，则当前这一行的底部将会出现“空隙”，因此应将h[j]置零
            res = max(res, maxRect(h));
        }
        return res;
    }

    int maxRect(vector<int>& h) {
        int n = h.size();
        vector<int> leftBound(n), rightBound(n);
        stack<int> S;

        for (int i = 0; i < n; i++) {
            while (!S.empty() && h[S.top()] >= h[i])
                S.pop();
            if (S.empty()) leftBound[i] = -1;
            else leftBound[i] = S.top();
            S.push(i);
        }

        S = stack<int>();
        for (int i = n - 1; i >= 0; i--) {
            while (!S.empty() && h[S.top()] >= h[i])
                S.pop();
            if (S.empty()) rightBound[i] = n;
            else rightBound[i] = S.top();
            S.push(i);
        }

        int res = 0;
        for (int i = 0; i < n; i++)
            res = max(res, h[i] * (rightBound[i] - leftBound[i] - 1));
        return res;
    }
};

```

