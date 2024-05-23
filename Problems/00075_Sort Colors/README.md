三指针：

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        for (int i = 0, k = 0, j = 0; j < nums.size(); j++) {
            if (nums[j] == 0) {
                swap(nums[i], nums[j]);
                i++; // i左边的（不包括i）必然全是0
            }
            
            if (nums[j] == 1) {
                while (k < i) k++; // [i, k)必然全是1
                swap(nums[j], nums[k]);
                k++; // [k, n)必然全是2
            }
        }
    }
};

```

