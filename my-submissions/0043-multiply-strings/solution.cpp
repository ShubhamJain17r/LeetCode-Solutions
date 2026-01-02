class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.length(), m = num2.length();
        if (m > n) multiply(num2, num1);

        string ans = "";
        for (int i = 0; i < m + n; ++i)
            ans.push_back('0');
        int j = m - 1;
        while (j >= 0) {
            int i = n - 1;
            int carry = 0;
            int a = num2[j] - '0';
            while (i >= 0) {
                int b = num1[i] - '0';
                int idx = i + j + 1;
                int mul = a * b + carry + ans[idx] - '0';
                ans[idx] = (mul % 10) + '0';
                carry = mul / 10;
                i--;
            }
            ans[j] = carry + '0';
            j--;
        }
        int i = 0;
        for (; i < ans.length() && ans[i] == '0'; i++);
        return i == ans.length() ? "0" : ans.substr(i);
    }
};
