二重 DFS + 回溯：

```cpp
class Solution {
public:
    vector<string> res;
    string path;
    vector<string> generateParenthesis(int n) {
        dfs(n, 0, 0);
        return res;
    }

    void dfs(int n, int left, int right) {
        if (right == n) {
            res.push_back(path);
            return;
        }

        if (left < n) {
            path += '(';
            dfs(n, left + 1, right);
            path.pop_back();
        }

        if (right < left) {
            path += ')';
            dfs(n, left, right + 1);
            path.pop_back();
        }
    }
};

```

