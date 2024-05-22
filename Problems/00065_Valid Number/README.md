确定有限状态自动机（DFA，deterministic finite automation）：（本题可不必重点掌握）

```cpp
class Solution {
public:
    bool isNumber(string s) {
        return dfs(s, 0, -1, 0, 0);
    }

    bool dfs(string& s, int idx, int state, int dotcnt, int ecnt) { // idx表示当前遍历到的索引为idx， dotcnt是小数点出现的次数，ecnt是e/E出现的次数
        if (dotcnt >= 2 || ecnt >= 2) return false; // 如果小数点出现了两次，或e/E出现了两次，则直接返回false

        if (idx == s.size()) { // 只有以数字或'.'结尾才可能合法
            if (state == 1) return true; // 以数字结尾，必合法（不合法的情形已在遍历过程中剔除）
            if (state == 3 && s.size() >= 2 && isdigit(s[s.size() - 2])) return true; // 若以'.'结尾，则类似"2."和"+2."是合法的，其余以'.'结尾的均不合法
            return false; // 其余情形均不合法
        }

        if (state == -1) { // 如果当前状态是初始状态，即刚进入字符串，还未开始状态转移
            char c = s[0];
            if (isdigit(c)) return dfs(s, 1, 1, dotcnt, ecnt); // 如果首字符是数字则转入状态1
            else if (c == '+' || c == '-') return dfs(s, 1, 2, dotcnt, ecnt); // 如果首字符是符号位则转入状态2
            else if (c == '.') return dfs(s, 1, 3, dotcnt + 1, ecnt); // 如果首字符是小数点则转入状态3
            // 其他情况不合法，由最终的return false统一处理
        }
        else { // 当前状态不是初始状态，
            char c = s[idx];
            if (state == 1) { // 前面为数字，当前只能为数字、小数点或e/E
                if (isdigit(c)) return dfs(s, idx + 1, 1, dotcnt, ecnt); // 当前字符为数字，则继续转入状态1
                if (c == '.' && !ecnt) return dfs(s, idx + 1, 3, dotcnt + 1, ecnt); // 当前字符为小数点且小数点前没有出现过e/E，则转入状态3，同时dotcnt加1
                if (c == 'e' || c == 'E') return dfs(s, idx + 1, 4, dotcnt, ecnt + 1); // 当前字符为e或E，转入状态4，同时ecnt加1
            }
            else if (state == 2) { // 前面为'+'或'-'，当前只能为数字或'.'
                if (isdigit(c)) return dfs(s, idx + 1, 1, dotcnt, ecnt);
                if (c == '.' && !ecnt) return dfs(s, idx + 1, 3, dotcnt + 1, ecnt);
            }
            else if (state == 3) { // 前面为小数点，当前只能为数字或e/E
                if (ecnt) return false; // 小数点前面不能有e/E, 如"6e6.5"
                if (isdigit(c)) return dfs(s, idx + 1, 1, dotcnt, ecnt);
                if (c == 'e' || c == 'E') 
                    if (idx >= 2 && isdigit(s[0]) || idx >= 3 && isdigit(s[1])) // ".e"和"+.e"是不合法的，但"1.e"和"+1.e"是合法的
                        return dfs(s, idx + 1, 4, dotcnt, ecnt + 1);
            }
            else if (state == 4) { // 前面为e或E，当前只能为正负号或数字
                if (c == '+' || c == '-') return dfs(s, idx + 1, 2, dotcnt, ecnt);
                if (isdigit(c)) return dfs(s, idx + 1, 1, dotcnt, ecnt);
            }
        }
        return false; // 统一处理前面return false的情形
    }
};

```

