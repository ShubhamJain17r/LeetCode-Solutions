class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        stack<int> s;
        vector<int> res(n, 0);
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && prices[i] < s.top()) s.pop();
            int t = s.empty() ? 0 : s.top();
            s.push(prices[i]);
            res[i] = prices[i] - t;
        }
        return res;
    }
};
