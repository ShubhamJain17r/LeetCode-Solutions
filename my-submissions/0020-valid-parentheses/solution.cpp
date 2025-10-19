class Solution {
public:
    bool isOpeningParenthesis(char c){
        return c == '(' || c == '{' || c == '[';
    }
    bool isClosingParenthesis(char c){
        return c == ')' || c == '}' || c == ']';
    }
    bool isValid(string s) {
        if (s.length() % 2) return false;
        stack<char> st;
        for (char c : s){
            if (st.empty()){
                if (isClosingParenthesis(c))
                    return false;
                else 
                    st.push(c);
            }
            else if (isOpeningParenthesis(c))
                st.push(c);
            else if (c == ')' && st.top() != '(' || c == '}' && st.top() != '{' || c == ']' && st.top() != '[') 
                return false;
            else 
                st.pop();
        }
        return st.empty();
    }
};
