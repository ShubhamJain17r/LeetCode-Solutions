class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> op;
        stack<int> st;
        int i = 0;
        int curr = 1;
        while (i < target.size()) {
            if (st.empty()) {}
            else if (st.top() < target[i]) {
                st.pop();
                op.push_back("Pop");
            }
            else {
                i++;
            }
            st.push(curr++);
            op.push_back("Push");
        }
        op.pop_back();
        return op;
    }
};
