用两个 `while` 循环：

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0, i = 0;
        while (i < nums.size()) {
            nums[k++] = nums[i++];
            while (i < nums.size() && nums[i] == nums[i - 1]) i++;
        }
        return k;
    }
};

```

