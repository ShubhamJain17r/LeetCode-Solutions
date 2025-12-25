class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> seen(256, -1);
        int maxLen = 0, l = 0;

        for (int r = 0; r < s.length(); ++r) {
            if (seen[s[r]] != -1 && seen[s[r]] >= l)
                l = seen[s[r]] + 1;
            maxLen = max(maxLen, r - l + 1);
            seen[s[r]] = r;
        }
        return maxLen;
    }
};
