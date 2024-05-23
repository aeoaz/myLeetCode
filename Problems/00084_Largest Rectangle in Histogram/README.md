单调栈：

```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) { // 单调栈
        int n = heights.size();
        vector<int> leftBoundary(n), rightBoundary(n);
        stack<int> S; // 栈中存的是索引
        // 先从左往右扫描一遍寻找左边界
        for (int i = 0; i < n; i++) {
            while (!S.empty() && heights[S.top()] >= heights[i])
                S.pop();
            if (S.empty()) leftBoundary[i] = -1;
            else leftBoundary[i] = S.top();
            S.push(i); // 最后不要忘记将当前索引加入栈中
        }
        
        // 再从右往左扫描一遍寻找右边界
        S = stack<int>(); // 先把上一次的元素清空(注意：stack没有clear函数)
        for (int i = n - 1; i >= 0; i--) {
            while (!S.empty() && heights[S.top()] >= heights[i])
                S.pop();
            if (S.empty()) rightBoundary[i] = n;
            else rightBoundary[i] = S.top();
            S.push(i);
        }

        int res = 0;
        for (int i = 0; i < n; i++)
            res = max(res, heights[i] * (rightBoundary[i] - leftBoundary[i] - 1));
        
        return res;
    }
};

```

