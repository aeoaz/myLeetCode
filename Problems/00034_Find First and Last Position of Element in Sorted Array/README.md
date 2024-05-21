二分版本 1：（`r = nums.size() - 1`，`while (l < r)`）

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        if (nums.empty()) return {-1, -1}; // 必须要特判，后面的代码无法处理这种边界情况
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }

        if (nums[l] != target) return {-1, -1};
        else
        {
            res.push_back(l);

            int l = 0, r = nums.size() - 1;
            while (l < r)
            {
                int mid = l + r + 1 >> 1;
                if (nums[mid] <= target) l = mid;
                else r = mid - 1;
            }

            res.push_back(l);
        }

        return res;
    }
};

```

