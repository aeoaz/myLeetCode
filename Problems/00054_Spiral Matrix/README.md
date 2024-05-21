方向数组的应用（大体思路：先走一步，看对不对，不对的话立马纠正）（注意本题细节较多）：

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<bool>> st(n, vector<bool>(m));
        int x = 0, y = -1;
        vector<int> res;
        int dir = 0;
        for (int i = 0; i < n * m; i++) {
            int a = x + dx[dir % 4], b = y + dy[dir % 4]; // 试探性地往前走一步
            if (a < 0 || a >= n || b < 0 || b >= m || st[a][b]) { // 如果没有走对，
                dir++; // 先变方向
                a = x + dx[dir % 4], b = y + dy[dir % 4]; // 然后再重新走
            } // 至此，就一定走对了
            res.push_back(matrix[a][b]); // 把走到的位置上的数字加入答案
            st[a][b] = true; // 更新状态数组
            x = a, y = b; // 更新下一次的起点
        }
        return res;
    }
};

```

