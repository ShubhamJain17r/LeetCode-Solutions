class Solution {
public:
    int f(int i, int last, vector<vector<int>>& envelopes, vector<vector<int>> &dp) {
        if (i == envelopes.size())
            return 0;
        if (dp[i][last] != -1)
            return dp[i][last];
        int notTake = f(i + 1, last, envelopes, dp);
        int take = 0;
        if (last == 0 || (envelopes[i][0] > envelopes[last - 1][0] && envelopes[i][1] > envelopes[last - 1][1]))
            return 1 + f(i + 1, i + 1, envelopes, dp);
        return dp[i][last] = max(take, notTake);
    }

    static bool comp(vector<int>& v1, vector<int>& v2) {
        if (v1[0] < v2[0]) return true;
        if (v1[0] > v2[0]) return false;
        return v1[1] > v2[1];
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), comp);
        vector<int> dp;
        for (vector<int> &v : envelopes) {
            int idx = lower_bound(dp.begin(), dp.end(), v[1]) - dp.begin();
            if (idx == dp.size())
                dp.push_back(v[1]);
            else 
                dp[idx] = v[1];
        }
        return dp.size();
    }
};
