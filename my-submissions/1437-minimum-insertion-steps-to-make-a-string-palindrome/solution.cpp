class Solution {
public:
    int LPS(int n, string &s1, string &s2) {
        vector<int>  prev(n + 1, 1), curr(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            curr[0] = 1;
            for (int j = 1; j <= n; ++j) {
                if (s1[i - 1] == s2[j - 1])
                    curr[j] = 1 + prev[j - 1];
                else
                    curr[j] = max(prev[j], curr[j - 1]);
            }
            prev = curr;
        }
        return prev[n];
    }
    int minInsertions(string s) {
        int n = s.length();
        string sRev = s;
        reverse(sRev.begin(), sRev.end());
        int lps = LPS(n, s, sRev);
        return n - lps + 1;
    }
};
