class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(256, -1);
        int maxLen = 0;
        int st = 0;
        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];
            if (last[c] < st) {
                maxLen = max(maxLen, i - st + 1);
            }
            else {
                st = last[c] + 1;
            }
            last[c] = i;
        }
        return maxLen;
    }
};
