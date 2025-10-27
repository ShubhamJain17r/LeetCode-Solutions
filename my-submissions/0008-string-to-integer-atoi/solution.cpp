class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        long long number = 0;
        int i = 0;
        while (i < n && s[i] == ' ') i++;
        if (i == n) return 0;

        bool isNeg = false;

        if (s[i] == '-' || s[i] == '+') {
            isNeg = (s[i] == '-');
            i++;
        }
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            int num = s[i] - '0';
            number = number * 10 + num;
            if (isNeg && -number < INT_MIN) return INT_MIN;
            if (!isNeg && number > INT_MAX) return INT_MAX;
            i++;
        }
        return isNeg ? -number : number;
    }
};
