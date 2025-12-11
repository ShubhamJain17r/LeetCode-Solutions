class Solution {
public:
    int f(int i, bool buy, vector<int>& prices, vector<vector<int>> &dp) {
        if (i >= prices.size())
            return 0;
        if (dp[i][buy] != -1)
            return dp[i][buy];
        int profit = 0;
        if (buy) {
            profit = max(-prices[i] + f(i + 1, false, prices, dp), f(i + 1, true, prices, dp));
        }
        else
            profit = max(prices[i] + f(i + 2, true, prices, dp), f(i + 1, false, prices, dp));
        return dp[i][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<int>> dp(n + 2, vector<int>(2, 0));
        // vector<int> next(2, 0), curr(2, 0), n2n(2, 0);
        int nextSell = 0, nextBuy = 0;
        int currSell = 0, currBuy = 0;
        int n2nBuy = 0;
        for (int i = n - 1; i >= 0; --i) {
            currBuy = max(-prices[i] + nextSell, nextBuy);
            currSell = max(prices[i] + n2nBuy, nextSell);

            n2nBuy = nextBuy;
            nextBuy = currBuy;
            nextSell = currSell;
        }
        return nextBuy;
    }
};

// class Solution {
// public:
//     int f(int i, bool buy, vector<int>& prices, vector<vector<int>> &dp) {
//         if (i == prices.size())
//             return 0;
//         if (dp[i][buy] != -1)
//             return dp[i][buy];
//         int profit = 0;
//         if (buy) {
//             profit = max(-prices[i] + f(i + 1, false, prices, dp), f(i + 1, true, prices, dp));
//         }
//         else
//             profit = max(prices[i] + f(i + 1, true, prices, dp), f(i + 1, false, prices, dp));
//         return dp[i][buy] = profit;
//     }
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         // vector<vector<int>> dp(n + 1, vector<int> (2, 0));
//         // vector<int> next(2, 0), curr(2, 0);
//         int nextSell = 0, nextBuy = 0;
//         int currSell = 0, currBuy = 0;
//         for (int i = n - 1; i >= 0; --i) {
//             int profit = 0;
//             profit = max(-prices[i] + nextSell, nextBuy);
//             currBuy = profit;

//             profit = max(prices[i] + nextBuy, nextSell);
//             currSell = profit;

//             nextSell = currSell;
//             nextBuy = currBuy;
//         }
//         return currBuy;
//     }
// };
