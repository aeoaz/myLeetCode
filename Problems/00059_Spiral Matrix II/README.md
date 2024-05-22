同 54 题：方向数组的应用

```cpp
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
        int x = 0, y = -1;
        vector<vector<int>> res(n, vector<int>(n));
        int dir = 0;
        vector<vector<bool>> st(n, vector<bool>(n));
        for (int i = 1; i <= n * n; i++) {
            int a = x + dx[dir % 4], b = y + dy[dir % 4]; // 先试探性地走一步
            if (a < 0 || a >= n || b < 0 || b >= n || st[a][b]) { // 如果走错的话就立马纠正
                dir++;
                a = x + dx[dir % 4], b = y + dy[dir % 4];
            }
            res[a][b] = i;
            st[a][b] = true;
            x = a, y = b;
        }
        return res;
    }
};

```

