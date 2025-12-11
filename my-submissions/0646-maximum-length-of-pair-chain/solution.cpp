class Solution {
public:
    int f(int i, int last, vector<vector<int>>& pairs, vector<vector<int>> &dp) {
        if (i == pairs.size())
            return 0;
        if (dp[i][last] != -1)
            return dp[i][last];
        int notTake = f(i + 1, last, pairs, dp);
        int take = 0;
        if (last == 0 || pairs[i][0] > pairs[last - 1][1])
            take = 1 + f(i + 1, i + 1, pairs, dp);
        return dp[i][last] = max(take, notTake);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        ranges::sort(pairs, {}, [](const auto& p) { return p[1]; });
        int end = INT_MIN, res = 0;
        for (const auto& p : pairs) {
            if (p[0] > end) {
                res++;
                end = p[1];
            }
        }
        return res;
    }
};
