借用原矩阵的第一行和第一列可以避免开辟额外空间：

```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int firstRow = 1, firstCol = 1;
        for (int i = 0; i < n; i++) if (!matrix[i][0]) firstCol = 0;
        for (int j = 0; j < m; j++) if (!matrix[0][j]) firstRow = 0;

        for (int i = 1; i < n; i++)
            for (int j = 1; j < m; j++) 
                if (!matrix[i][j]) 
                    matrix[0][j] = matrix[i][0] = 0;
        
        for (int i = 1; i < n; i++) 
            if (!matrix[i][0]) 
                for (int j = 0; j < m; j++) matrix[i][j] = 0;

        for (int j = 1; j < m; j++) 
            if (!matrix[0][j])
                for (int i = 0; i < n; i++) matrix[i][j] = 0;

        if (!firstRow)
            for (int j = 0; j < m; j++) matrix[0][j] = 0;
        if (!firstCol)
            for (int i = 0; i < n; i++) matrix[i][0] = 0;
    }
};

```

