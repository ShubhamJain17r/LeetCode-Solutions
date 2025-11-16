class Solution {
public:
    bool isOperation(string s) {
        return s == "+" || s == "-" || s == "*" || s == "/";
    }
    int performOperation(int a, int b, string s) {
        if (s == "+")
            return a+b;
        if (s == "-")
            return b-a;
        if (s == "*")
            return a*b;
        if (s == "/")
            return b/a;
        return 0;        
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string s : tokens) {
            if (isOperation(s)) {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                int t = performOperation(a, b, s);
                st.push(t);
            }
            else {
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};
