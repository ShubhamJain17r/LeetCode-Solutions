class Solution {
public:
    int maxProfit(int k_, vector<int>& prices) {
        int n = prices.size();
        // vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k_ + 1 , 0)));
        // vector<vector<int>> curr(2, vector<int>(k_ + 1 , 0)), next(2, vector<int>(k_ + 1 , 0));
        vector<int>nextBuy(k_ + 1 , 0), nextSell(k_ + 1 , 0);
        vector<int>currBuy(k_ + 1 , 0), currSell(k_ + 1 , 0);
        for (int i = n - 1; i >= 0; --i) {
            for (int k = 1; k <= k_; ++k) {
                currBuy[k] = max(-prices[i] + nextSell[k], nextBuy[k]);
                currSell[k] = max(prices[i] + nextBuy[k - 1], nextSell[k]);
            }
            nextBuy = currBuy;
            nextSell = currSell;
        }
        return currBuy[k_];
    }
};
