哈希表：

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ht;
        for (int i = 0; i < nums.size(); i++) {
            int t = target - nums[i];
            if (!ht.count(t)) ht[nums[i]] = i;
            else return {ht[t], i};
        }
        return {};
    }
};

```

时间复杂度：$O(n)$；

空间复杂度：$O(n)$。