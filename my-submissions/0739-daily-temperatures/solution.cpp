class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> ans(n, 0);

        stack<int> nextGreater;
        nextGreater.push(n - 1);
        for (int i = n - 2; i >= 0; --i) {
            while (!nextGreater.empty() && temp[nextGreater.top()] <= temp[i]) nextGreater.pop();

            ans[i] = nextGreater.empty() ? 0 : nextGreater.top() - i;

            nextGreater.push(i);
        }
        return ans;
    }
};
