字符串解析：

```cpp
class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        for (int i = 0; i < n - 1; i++) {
            string tmp;
            int j = 0;
            while (j < res.size()) {
                char c = res[j++];
                int cnt = 1;
                while (j < res.size() && res[j] == res[j - 1]) j++, cnt++;
                tmp += to_string(cnt) + c;
            }
            res = tmp;
        }
        return res;
    }
};

```

