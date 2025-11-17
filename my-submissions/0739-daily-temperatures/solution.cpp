class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> res(n);
        stack<int> s;
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && temp[i] >= temp[s.top()]) {
                s.pop();
            }
            int days = s.empty() ? 0 : s.top() - i;
            s.push(i);
            res[i] = days;
        }
        return res;
    }
};
