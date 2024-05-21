高精度 x 高精度：

```cpp
class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.size(), m = num2.size();
        vector<int> A, B;
        for (int i = num1.size() - 1; i >= 0; i--) A.push_back(num1[i] - '0');
        for (int j = num2.size() - 1; j >= 0; j--) B.push_back(num2[j] - '0');

        vector<int> C(n + m);
        for (int i = 0; i < A.size(); i++)
            for (int j = 0; j < B.size(); j++)
                C[i + j] += A[i] * B[j];

        int t = 0;
        for (int i = 0; i < C.size(); i++) {
            t += C[i];
            C[i] = t % 10;
            t /= 10;
        }

        while (C.size() > 1 && C.back() == 0) C.pop_back();

        string res;
        for (int i = C.size() - 1; i >= 0; i--)
            res += to_string(C[i]);
        
        return res;
    }
};

```

