class Solution {
public:
    static const int MOD = 1e9 + 7;

    // long long f(int i, string &s, vector<long long> &dp, vector<int> &last) {
    //     if (i == 0) return 1;         // empty subsequence
    //     if (dp[i] != -1) return dp[i];

    //     long long res = (2LL * f(i - 1, s, dp, last)) % MOD;

    //     int ch = s[i - 1] - 'a';
    //     int j = last[ch];            // last occurrence

    //     if (j != -1) {
    //         res = (res - f(j - 1, s, dp, last)) % MOD;
    //         if (res < 0) res += MOD;
    //     }

    //     last[ch] = i;                // update last occurrence
        
    //     return dp[i] = res;
    // }

    int distinctSubseqII(string s) {
        int n = s.size();
        vector<long long> dp(n + 1, 0);
        vector<int> last(26, -1);

        dp[0] = 1;
        for (int i = 1; i<= n; ++i) {
            long long res = (2LL * dp[i - 1]) % MOD;

            int ch = s[i - 1] - 'a';
            int j = last[ch];            // last occurrence

            if (j != -1) {
                res = (res - dp[j - 1]) % MOD;
                if (res < 0) res += MOD;
            }

            last[ch] = i;  
            dp[i] = res;
        }

        long long ans = dp[n];

        ans = (ans - 1 + MOD) % MOD;   // remove empty subsequence
        return ans;
    }
};

