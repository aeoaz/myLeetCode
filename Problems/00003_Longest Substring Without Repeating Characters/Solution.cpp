class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> cnt;
        int res = 0;
        for (int l = 0, r = 0; r < n; r++) {
            cnt[s[r]]++;
            while (cnt[s[r]] > 1) cnt[s[l++]]--;
            res = max(res, r - l + 1);
        }
        return res;
    }
};