class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> dp;  
        int ans = 0;

        for (int x : arr) {
            int prev = x - difference;

            // If there's a subsequence ending at (x - difference),
            // extend it; otherwise this starts a new subsequence.
            dp[x] = dp.count(prev) ? dp[prev] + 1 : 1;

            ans = max(ans, dp[x]);
        }

        return ans;
    }
};

