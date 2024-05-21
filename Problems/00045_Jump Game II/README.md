代码：

```cpp
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> step(n);
        int j = 0;
        for (int i = 1; i < nums.size(); i++) {
            while (j + nums[j] < i) j++;
            step[i] = step[j] + 1;
        }
        return step[n - 1];
    }
};
```



上述代码是下面原始代码的简化版（原始版更好理解）：

```cpp
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> step(n);
        int j = 0; // 初始时站在索引为0的位置
        for (int i = 1; i < nums.size(); i++) { // 从索引1开始，逐个位置地考察
            if (j + nums[j] >= i) // 如果从j处能够跳到i处，
                step[i] = step[j] + 1; // 则从j处跳1步到i
            else { // 反之，如果从j处不能跳到i处，即j + nums[j] < i
                while (j + nums[j] < i) j++; // 则一直往后寻找，直到找到一个能跳到i处的j(本题的题目数据保证这样的j一定存在)
                step[i] = step[j] + 1; // 找到之后，让j跳一步过去
            }
        }
        return step[n - 1]; // 最终n-1处的步数就是最小步数
    }
};

```