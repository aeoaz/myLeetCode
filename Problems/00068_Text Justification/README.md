字符串解析（规则较复杂，本题可不必重点掌握）：

```cpp
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        vector<string> curRow; // 存放当前行的所有单词
        int leftLen = maxWidth, space = 0; // 当前行还剩多长的长度可用、当前行总的空格数量
        for (int k = 0; k < words.size(); k++) {
            curRow.push_back(words[k]);
            leftLen -= words[k].size();
            if (leftLen <= 0) {
                if (leftLen < 0) {
                    curRow.pop_back();
                    leftLen += words[k].size();
                    k--;
                }

                /* 计算每个空位所需的空格数量 */
                int curCnt = curRow.size(); // 当前行总共的单词数量
                space += leftLen; // 总共的空格数量
                int slot = (curCnt <= 1) ? 1 : (curCnt - 1); // 当前行槽的数量（至少是1）
                vector<int> avgSpace(slot, space / slot); // 先为每个槽分配一样多的空格
                space %= slot; // 如果平均分完之后还有剩余，
                for (int i = 0; i < space; i++) avgSpace[i]++; // 则将这些多出来的空格均匀地分配到靠左的槽中

                /* 将当前行中的单词和空格连接成字符串 */
                string tmp;
                for (int i = 0; i < curRow.size(); i++) {
                    tmp += curRow[i]; // 添加单词
                    if (i < avgSpace.size()) 
                        tmp += string(avgSpace[i], ' '); // 添加空格
                }

                res.push_back(tmp);
                curRow.clear(); // 每一行处理完之后清空
                leftLen = maxWidth, space = 0; // 将剩余长度和空格数量复原
            }
            else {
                space++; // 每个单词后至少要跟一个空格
                leftLen--;
            }
        }

        /* 处理最后一行 */
        if (!curRow.empty()) {
            string tmp;
            for (auto& t : curRow) tmp += t + ' ';
            if (tmp.size() > maxWidth) tmp.pop_back(); // 如果正好多出一个空格，则将它删掉
            else tmp += string(maxWidth - tmp.size(), ' '); // 如果空格数量还不够，则继续添加直至长度等于maxWidth
            res.push_back(tmp);
        }

        return res;
    }
};

```

