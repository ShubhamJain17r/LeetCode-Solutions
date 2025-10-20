class Solution {
public:
    int calculate(string s) {
        stack<int> nums;       // stack to store numbers
        stack<int> ops;        // stack to store signs (+/-)
        int result = 0, number = 0, sign = 1;

        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];

            if (isdigit(c)) {
                number = c - '0';
                while (i + 1 < s.length() && isdigit(s[i + 1])) {
                    number = number * 10 + (s[i + 1] - '0');
                    i++;
                }
                result += sign * number;
            } else if (c == '+') {
                sign = 1;
            } else if (c == '-') {
                sign = -1;
            } else if (c == '(') {
                nums.push(result);
                ops.push(sign);
                result = 0;
                sign = 1;
            } else if (c == ')') {
                result = nums.top() + ops.top() * result;
                nums.pop();
                ops.pop();
            }
        }
        return result;
    }
};

