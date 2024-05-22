栈的应用：

技巧 1：本题可以不用真的维护一个栈，用一个 vector 去模拟会更有利于最终对结果的处理。

技巧 2：在往栈中添加元素时，不要添加 '/'。

```cpp
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> S; // 本题可以不用真的维护一个栈，用一个vector来模拟会更方便
        int i = 1; // 跳过最开头的'/'
        while (i < path.size()) {
            int j = i;
            while (j < path.size() && path[j] != '/') j++;
            string tmp = path.substr(i, j - i); // 往S中添加字符串的时候不要包含'/'，可以使问题得到简化
            if (tmp == "..") {
                if (!S.empty()) S.pop_back();
            }
            else if (tmp != "" && tmp != ".") S.push_back(tmp);
            i = j + 1;
        }

        if (S.empty()) return "/";
        string res;
        for (auto& t : S) res += '/' + t; // trick: 先加'/'再加字符串，这样结尾便不会有'/'
        return res;
    }
};
```

