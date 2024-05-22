模板：区间合并

```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
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

