class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> last;  // last position of each char
        int l = 0, ans = 0;

        for (int r = 0; r < s.size(); r++) {
            char c = s[r];

            // if character seen and within current window
            if (last.count(c) && last[c] >= l) {
                l = last[c] + 1;   // move left pointer
            }

            last[c] = r;  // update last seen position
            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};

