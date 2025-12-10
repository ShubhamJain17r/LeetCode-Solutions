class Solution {
public:
    int f(int i, int j, string s1, string s2) {
        if (i < 0)
            return j + 1;
        if (j < 0)
            return i + 1;
        if (s1[i] == s2[j])
            return f(i - 1, j - 1, s1, s2);
        int insert = f(i-1, j, s1, s2);
        int del = f(i, j - 1, s1, s2);
        int replace = f(i - 1, j - 1, s1, s2);
        return 1 + min(insert, min(del, replace));
    }
    int minDistance(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        vector<int> prev(m + 1, 0), curr(m + 1, 0);
        for (int j = 0; j <= m; ++j) {
            prev[j] = j;
        }
        for (int i = 1; i <= n; ++i) {
            curr[0] = i;
            for (int j = 1; j <= m; ++j) {
                if (s1[i - 1] == s2[j - 1])
                    curr[j] = prev[j - 1];
                else {
                    int insert = prev[j];
                    int del = curr[j - 1];
                    int replace = prev[j - 1];
                    curr[j] = 1 + min(insert, min(del, replace));
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};
