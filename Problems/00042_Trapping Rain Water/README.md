贪心 + 双指针：

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int lmax = 0, rmax = 0;
        int l = 0, r = height.size() - 1;
        while (l < r) {
            lmax = max(lmax, height[l]);
            rmax = max(rmax, height[r]);
            if (lmax <= rmax) {
                res += lmax - height[l];
                l++;
            }
            else {
                res += rmax - height[r];
                r--;
            }
        }
        return res;
    }
};

```

