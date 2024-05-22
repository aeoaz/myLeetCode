数学推导：

```cpp
class Solution {
public:
    string getPermutation(int n, int k) {
        k--; // 让k减1可以让索引统一（索引从0开始）

        vector<int> nums;
        for (int i = 1; i <= n; i++) nums.push_back(i);

        // 一共有n位，base数组中的值就应该是从0!~(n-1)!
        vector<int> base = {1}; // n至少为1，故base中至少包含0!
        for (int i = 1; i < n; i++) base.push_back(i * base.back()); // 将1!~(n-1)!都加进去

        string res;
        for (int i = base.size() - 1; i >= 0; i--) {
            int j = k / base[i]; // 注意：k在最开头已经减到了1，所以这里的j已经是索引
            res += to_string(nums[j]);
            nums.erase(nums.begin() + j);
            k %= base[i];
        }

        return res;
    }
};

```

