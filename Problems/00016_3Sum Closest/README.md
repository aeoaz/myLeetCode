类似第 15 题，依旧是排序 + 双指针：

```cpp
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = nums[0] + nums[1] + nums[2];
        for (int i = 0; i + 2 < nums.size(); i++) {
            if (i && nums[i] == nums[i - 1]) continue;
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                while (l > i + 1 && l < r && nums[l] == nums[l - 1]) l++;
                while (r < nums.size() - 1 && l < r && nums[r] == nums[r + 1]) r--;
                if (l < r) { // l和r去完重之后可能就不满足此条件了，所以此判断不能缺少
                    int sum = nums[i] + nums[l] + nums[r];
                    if (sum == target) return sum;
                    else {
                        if (abs(sum - target) < abs(res - target)) res = sum;
                        if (sum > target) r--;
                        else l++;
                    } 
                }
            }
        }
        return res;
    }
};

```

