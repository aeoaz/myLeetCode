trick：“先右下再竖，等于顺时针旋转 90 度”

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        /* 两次对称即可：先沿反对角线对称，再沿中轴左右对称*/
        int n = matrix.size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < i; j++)
                swap(matrix[i][j], matrix[j][i]);
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n / 2; j++)
                swap(matrix[i][j], matrix[i][n - 1 - j]);
    }
};

```

