数学推理：

```cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // 特判（可以缺少，后面的代码可以处理）：数组中元素个数少于2个，直接return
        // if (nums.size() <= 1) return;

        // step 1: 从后往前找到第一组升序的元素，记其下标分别为i, j
        int j = nums.size() - 1;
        while (j - 1 >= 0 && nums[j - 1] >= nums[j]) j--;
        
        if (!j) { // 如果不存在升序对，则直接将整个数组翻转
            reverse(nums.begin(), nums.end());
            return; // 然后返回
        }

        int i = j - 1; // 如果存在升序对，记升序对的下标为(i, j)

        // step 2: 在i的右边，从后往前寻找第一个大于nums[i]的元素（可能就是nums[j]）
        int k = nums.size() - 1;
        while (k > i && nums[k] <= nums[i]) k--;
        swap(nums[i], nums[k]); // 将nums[i]和nums[k]交换（有可能交换的就是nums[i]和nums[j]）

        // step 3: 将j~末尾的元素反转（j~末尾有可能一个元素都没有）
        reverse(nums.begin() + j, nums.end());
    }
};
// 从后往前找到第一组升序的元素对，记下标为i,j
// 在i的右边，从后往前寻找第一个比nums[i]大的数，记其下标为k
// 交换nums[i], nums[k]
// 将j~末尾逆序
//      ijk
// 1237568743
// 1237578643
// 1237573468

```

