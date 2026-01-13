class Solution {
public:
bool f(int n, bool chance, vector<vector<int>> &dp) {
    if (n == 1) 
        return !chance;          // true for alice, false for bob
    if (dp[n][chance] != -1)
        return dp[n][chance];

    return dp[n][chance] = f(n - 1, !chance, dp);
}
bool divisorGame(int n) {
    vector<vector<int>> dp(n + 1, vector<int> (2, -1));
    return f(n, true, dp);
}
};
