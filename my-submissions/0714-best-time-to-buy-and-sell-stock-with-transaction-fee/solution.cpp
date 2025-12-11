class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        // vector<vector<int>> dp(n + 1, vector<int> (2, 0));
        // vector<int> next(2, 0), curr(2, 0);
        int nextSell = 0, nextBuy = 0;
        int currSell = 0, currBuy = 0;
        for (int i = n - 1; i >= 0; --i) {
            int profit = 0;
            profit = max(-prices[i] + nextSell, nextBuy);
            currBuy = profit;

            profit = max(prices[i] - fee + nextBuy, nextSell);
            currSell = profit;

            nextSell = currSell;
            nextBuy = currBuy;
        }
        return currBuy;
    }
};
