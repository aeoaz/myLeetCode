二分版本 3：`while (l <= r)`

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) { // 注意这里必须是l <= r
            int mid = l + r >> 1;
            if (nums[mid] == target) return mid;
            else if (nums[mid] >= nums[l]) { // 注意此处必须要有等于号，因为极端情形下区间[l, mid]将退化为一个点
                if (nums[l] <= target && target < nums[mid])
                    r = mid - 1;
                else l = mid + 1;
            }
            else { // [mid, r]是二分区间
                if (nums[mid] < target && target <= nums[r])
                    l = mid + 1;
                else 
                    r = mid - 1;
            }
        }

        return -1;
    }
};

```

二分版本 1: 寻找左右边界的二分（`r = nums.size() - 1`，`while (l < r)`）

二分版本 2: 寻找插入位置的二分（`r = nums.size()`）

二分版本 3: 通过夹挤找元素的二分（`while (l <= r)`）

