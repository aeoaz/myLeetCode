使用方向数组的二维表格型 DFS：

```cpp
class Solution {
public:
    bool st[10][10];
    int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, 1, -1};
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                if (board[i][j] == word[0])
                    if (dfs(board, word, 1, i, j))
                        return true;
        
        return false;
    }

    bool dfs(vector<vector<char>>& board, string& word, int u, int x, int y) {
        if (u == word.size()) return true;

        st[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < board.size() && b >= 0 && b < board[0].size() && !st[a][b] && board[a][b] == word[u])
                if (dfs(board, word, u + 1, a, b))
                    return true;
        }
        st[x][y] = false;
        return false;
    }
};

```

