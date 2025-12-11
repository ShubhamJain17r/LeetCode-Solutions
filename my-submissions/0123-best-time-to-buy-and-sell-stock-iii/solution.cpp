class Solution {
public:
    int f(int i, bool buy, int k, vector<int>& prices, vector<vector<vector<int>>> &dp) {  // k = 2
        if (k == 0)
            return 0;
        if (i == prices.size())
            return 0;
        if (dp[i][buy][k] != -1)
            return dp[i][buy][k];
        int profit = 0;
        if (buy)
            profit = max(-prices[i] + f(i + 1, false, k, prices, dp), f(i + 1, true, k, prices, dp));
        else
            profit = max(prices[i] + f(i + 1, true, k - 1, prices, dp), f(i + 1, false, k, prices, dp));
        return dp[i][buy][k] = profit;
    }
    // int maxProfit(vector<int>& prices) {
        // int n = prices.size();
        // int k_ = 2;
        // // vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k_ + 1 , 0)));
        // // vector<vector<int>> curr(2, vector<int>(k_ + 1 , 0)), next(2, vector<int>(k_ + 1 , 0));
        // vector<int>nextBuy(k_ + 1 , 0), nextSell(k_ + 1 , 0);
        // vector<int>currBuy(k_ + 1 , 0), currSell(k_ + 1 , 0);
        // for (int i = n - 1; i >= 0; --i) {
        //     for (int k = 1; k <= k_; ++k) {
        //         currBuy[k] = max(-prices[i] + nextSell[k], nextBuy[k]);
        //         currSell[k] = max(prices[i] + nextBuy[k - 1], nextSell[k]);
        //     }
        //     nextBuy = currBuy;
        //     nextSell = currSell;
        // }
        // return currBuy[k_];
    // }
    int maxProfit(vector<int>& prices) {
        int buyOne = 1e9;
        int SellOne = 0;
        int buyTwo = 1e9;
        int SellTwo = 0;
        for(int p : prices) {
            buyOne = min(buyOne, p);
            SellOne = max(SellOne, p - buyOne);
            buyTwo = min(buyTwo, p - SellOne);
            SellTwo = max(SellTwo, p - buyTwo);
        }
        return SellTwo;
    }
};
