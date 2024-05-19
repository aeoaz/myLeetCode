栈的简单应用：

```cpp
class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> ht = {
            {')', '('}, {']', '['}, {'}', '{'}
        };
        stack<char> S;
        for (auto c : s) {
            if (c == '(' || c == '{' || c == '[')
                S.push(c);
            else if (S.empty() || S.top() != ht[c]) // 注意要先判栈空，否则可能会取空栈的栈顶导致出错
                return false;
            else S.pop();
        }
        return S.empty();
    }
};

```

