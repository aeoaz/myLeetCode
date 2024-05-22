二分查找 + 区间合并（先用二分查找找到插入位置，将新区间插入，再调用标准的区间合并算法）：

```cpp
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int l = 0, r = intervals.size();
        while (l < r) {
            int mid = l + r >> 1;
            if (intervals[mid][0] >= newInterval[0]) r = mid;
            else l = mid + 1;
        }
        intervals.insert(intervals.begin() + l, newInterval);

        vector<vector<int>> res;
        int st = INT_MIN, ed = INT_MIN;
        for (auto t : intervals) {
            if (ed < t[0]) {
                if (st != INT_MIN) res.push_back({st, ed});
                st = t[0], ed = t[1];
            }
            else ed = max(ed, t[1]);
        }
        if (st != INT_MIN) res.push_back({st, ed});
        return res;
    }
};

```

