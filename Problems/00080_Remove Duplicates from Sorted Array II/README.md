同 26 题（只是如果有重复项，本题需额外复制一次）：

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        int i = 0;
        while (i < nums.size()) {
            nums[k++] = nums[i++];
            if (i < nums.size() && nums[i] == nums[i - 1]) // 如果有重复元素，
                nums[k++] = nums[i++]; // 那就再复制一次
            while(i < nums.size() && nums[i] == nums[i - 1]) i++;
        }
        return k;
    }
};

```

