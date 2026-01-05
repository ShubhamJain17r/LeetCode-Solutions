class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        if (n & 1 == 1) return false;

        stack<char> st;
        for (const char &c : s) {
            if (c == '(' || c == '{' || c == '[')
                st.push(c);
            else if (c == ')') {
                if (st.empty() || st.top() != '(') return false;
                st.pop();
            }
            else if (c == '}') {
                if (st.empty() || st.top() != '{') return false;
                st.pop();
            }
            else {
                if (st.empty() || st.top() != '[') return false;
                st.pop();
            }
        }
        return st.empty();
    }
};
