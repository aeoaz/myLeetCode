栈的应用（本题可以和第 20 题归为一类，都属于栈的应用）：

```cpp
class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        stack<int> S; // 栈中存的是索引
        for (int i = 0, start = -1; i < s.size(); i++) {
            if (s[i] == '(') S.push(i); // 来左括号，直接入栈
            else { // 来右括号，要看栈是否为空
                if (S.empty()) start = i; // 如果栈空，说明右括号太多了，start需重新更换位置
                else { // 如果栈不空，说明栈顶有左括号
                    S.pop(); // 将左括号弹出
                    if (S.empty()) res = max(res, i - (start + 1) + 1); // 如果弹出后栈空，则从start+1到i皆为有效字符
                    else // 否则，如果弹出左括号后栈顶还有左括号，
                        res = max(res, i - (S.top() + 1) + 1); // 则从栈顶左括号的右边到i皆为有效字符
                }
            }
        }
        return res;
    }
};

```

