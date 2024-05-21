代码：

```cpp
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][9], col[9][9], block[3][3][9];
        memset(row, 0, sizeof row);
        memset(col, 0, sizeof col);
        memset(block, 0, sizeof block);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int t = board[i][j] - '1';
                    if (row[i][t] || col[j][t] || block[i / 3][j / 3][t])
                        return false;
                    else 
                        row[i][t] = col[j][t] = block[i / 3][j / 3][t] = true;
                }
            }
        }
        return true;
    }
};

```

