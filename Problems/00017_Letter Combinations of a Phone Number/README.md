简单的 DFS + 回溯：

```cpp
class Solution {
public:
    vector<string> res;
    string path;
    unordered_map<char, string> ht = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
        {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
        {'8', "tuv"}, {'9', "wxyz"}
    };
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return res; // 注意：下面的代码处理不了这种边界情况
        dfs(digits, 0);
        return res;
    }

    void dfs(const string& digits, int u) {
        if (u == digits.size()) {
            res.push_back(path);
            return;
        }

        for (auto c : ht[digits[u]]) {
            path += c;
            dfs(digits, u + 1);
            path.pop_back();
        }
    }
};

```

