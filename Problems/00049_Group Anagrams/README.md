哈希表：

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ht;
        for (auto& s : strs) {
            string t = s;
            sort(t.begin(), t.end());
            ht[t].push_back(s);
        }
        vector<vector<string>> res;
        for (auto& t : ht) res.push_back(t.second);
        return res;
    }
};

```

