DFS：

```cpp
class Solution {
public:
    vector<string> res;
    vector<string> path;

    vector<string> restoreIpAddresses(string s) {
        dfs(s, 0, 0); // start表示该判断第几个位置的字符了，cnt=0表示当前已经有几个数字了
        return res;
    }

    void dfs(const string& s, int start, int cnt) {
        if (cnt == 4) {
            if (start == s.size()) {
                string tmp;
                for (auto& t : path) tmp += t + '.';
                tmp.pop_back();
                res.push_back(tmp);
            }
            return;
        }

        for (int len = 1; len <= 3; len++) {
            if (start + len <= s.size()) {
                string cur = s.substr(start, len);
                if (isValid(cur)) {
                    path.push_back(cur);
                    dfs(s, start + len, cnt + 1);
                    path.pop_back();
                }
                else break;
            }
        }
    }

    bool isValid(const string& s) {
        if (s.size() > 1 && s[0] == '0') return false;
        return stoi(s) <= 255;
    }
};
```

