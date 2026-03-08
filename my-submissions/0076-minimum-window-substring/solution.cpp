class Solution {
public:
    string minWindow(string s, string t) {

        int m = s.size(), n = t.size();
        if (n > m) return "";

        unordered_map<char,int> freq;

        for (char c : t)
            freq[c]++;

        int required = freq.size();
        int formed = 0;

        unordered_map<char,int> window;

        int l = 0, r = 0;
        int minLen = INT_MAX;
        int start = 0;

        while (r < m) {

            char c = s[r];
            window[c]++;

            if (freq.count(c) && window[c] == freq[c])
                formed++;

            while (l <= r && formed == required) {

                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }

                char ch = s[l];
                window[ch]--;

                if (freq.count(ch) && window[ch] < freq[ch])
                    formed--;

                l++;
            }

            r++;
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
