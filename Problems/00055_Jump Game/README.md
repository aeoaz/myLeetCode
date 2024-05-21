可以用和第 45 题类似的方法：

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int j = 0;
        for (int i = 1; i < nums.size(); i++) {
            while (j + nums[j] < i) j++;
            if (j == i) return false;
        }
        return true;
    }
};

```

