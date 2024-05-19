模板题：移除元素

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0, i = 0;
        while (i < nums.size()) {
            while (i < nums.size() && nums[i] == val) i++;
            if (i < nums.size()) nums[k++] = nums[i++]; // 注意：此处i < nums.size()不可缺少
        }
        return k;
    }
};

```

