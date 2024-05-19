排序 + 双指针 + 去重：

需要注意以下四个问题：

- 使用双指针算法的前提是需要对输入数组进行排序；
- i, j, l, r 均需要去重；
- 注意 l 和 r 去完重之后可能就不满足 l < r 了，所以对 l 和 r 去完重之后需要加一个 `if (l < r)` 的判断；
- 本题的四数相加有可能会超出 int 的范围，所以需要将加法转化为 long long 的加法。

代码实现：

```cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i + 3 < nums.size(); i++) {
            if (i && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j + 2 < nums.size(); j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int l = j + 1, r = nums.size() - 1;
                while (l < r) {
                    while (l > j + 1 && l < r && nums[l] == nums[l - 1]) l++;
                    while (r < nums.size() - 1 && l < r && nums[r] == nums[r + 1]) r--;
                    if (l < r) {
                        // 注意sum要定义为long long
                        long long sum = (long long)nums[i] + nums[j] + nums[l] + nums[r]; // trick: 只需要将第一个数转换为long long即可
                        if (sum == target) {
                            res.push_back({nums[i], nums[j], nums[l], nums[r]});
                            l++, r--;
                        }
                        else if (sum > target) r--;
                        else l++;
                    }
                }
            }
        }
        return res;
    }
};

```

