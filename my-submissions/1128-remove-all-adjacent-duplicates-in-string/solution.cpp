class Solution {
public:
    // string removeDuplicates(string s) {
    //     int i = 0;
    //     stack<char> st;

    //     while (i != s.length()) {
    //         if (st.empty() || st.top() != s[i]) {
    //             st.push(s[i]);
    //         }
    //         else {
    //             st.pop();
    //         }
    //         i++;
    //     }

    //     string ans;
    //     while (!st.empty()) {
    //         ans.push_back(st.top());
    //         st.pop();
    //     }

    //     if (ans.length() > 0) 
    //         reverse(ans.begin(), ans.end());

    //     return ans;
    // }

    string removeDuplicates(string s) {
        int write = 0;
        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];
            if (write > 0 && s[write - 1] == c) {
                write--;
            }
            else {
                s[write] = c;
                write++;
            }
        }
        return s.substr(0, write);
    }
};
