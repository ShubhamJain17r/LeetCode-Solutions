class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int maxDiff = INT_MIN;
        for (int i = 1; i < prices.size(); ++i) {
            int curr = prices[i] - mini;
            maxDiff = max(maxDiff, curr);
            mini = min(mini, prices[i]);
        }
        return max(maxDiff, 0);
    }
};
