二维表格型 DFS：

```cpp
class Solution {
public:
    bool row[9][9], col[9][9], block[3][3][9];
    void solveSudoku(vector<vector<char>>& board) {
        memset(row, 0, sizeof row);
        memset(col, 0, sizeof col);
        memset(block, 0, sizeof block);

        for (int i = 0; i < 9; i++) 
            for (int j = 0; j < 9; j++) 
                if (board[i][j] != '.') {
                    int t = board[i][j] - '1';
                    row[i][t] = col[j][t] = block[i / 3][j / 3][t] = true;
                }

        dfs(board, 0, 0);
    }

    bool dfs(vector<vector<char>>& board, int x, int y) {
        if (y == 9) x++, y = 0;
        if (x == 9) return true;
        if (board[x][y] != '.') return dfs(board, x, y + 1);

        for (int i = 1; i <= 9; i++) {
            if (!row[x][i - 1] && !col[y][i - 1] && !block[x / 3][y / 3][i - 1]) {
                board[x][y] = i + '0';
                row[x][i - 1] = col[y][i - 1] = block[x / 3][y / 3][i - 1] = true;
                if (dfs(board, x, y + 1)) return true;
                board[x][y] = '.';
                row[x][i - 1] = col[y][i - 1] = block[x / 3][y / 3][i - 1] = false;
            }
        }
        return false;
    }
};

```

