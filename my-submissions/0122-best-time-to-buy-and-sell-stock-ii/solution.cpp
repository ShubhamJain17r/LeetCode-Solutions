class Solution {
public:
int maxProfit(vector<int>& prices) {
    int maxProfit = 0;
    for (int i = 1; i < prices.size(); ++i) {
        int netDiff = prices[i] - prices[i - 1];
        maxProfit = max(maxProfit, maxProfit + netDiff);
    }
    return maxProfit;
}
};
