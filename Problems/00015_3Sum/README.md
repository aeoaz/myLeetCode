排序 + 双指针：

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i + 2 < nums.size(); i++) {
            if (i && nums[i] == nums[i - 1]) continue; // 对i去重
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                // 对l和r去重
                while (l > i + 1 && l < r && nums[l] == nums[l - 1]) l++;
                while (r < nums.size() - 1 && l < r && nums[r] == nums[r + 1]) r--;
                if (l < r) {
                    int sum = nums[i] + nums[l] + nums[r];
                    if (sum == 0) {
                        res.push_back({nums[i], nums[l], nums[r]});
                        l++, r--;
                    }
                    else if (sum > 0) r--;
                    else l++;
                }
            }
        }
        return res;
    }
};

```

