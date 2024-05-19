进制转换的新定义问题：

```cpp
class Solution {
public:
    string intToRoman(int num) {
        vector<int> base = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        unordered_map<int, string> ht = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
            {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"},
            {5, "V"}, {4, "IV"}, {1, "I"}
        };
        string res;
        while (num) {
            for (auto b : base) {
                int cnt = num / b;
                while (cnt--) res += ht[b];
                num %= b;
            }
        }
        return res;
    }
};

```

