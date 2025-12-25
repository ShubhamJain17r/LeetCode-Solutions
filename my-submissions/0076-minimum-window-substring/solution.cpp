class Solution {
public:
    string minWindow(string s, string t) {
        if (t.length() > s.length()) return "";
        if (t == s)                  return s;

        vector<int> freq(128, 0);
        for (const char &c : t)
            freq[c]++;
        
        int minLen = INT_MAX;
        int idx = -1;

        int l = 0;
        int cnt = 0;
        for (int r = 0; r < s.length(); ++r) {
            char c = s[r];
            freq[c]--;

            if (freq[c] >= 0)
                cnt++;
            // cout<<r<<" "<<cnt<<endl;
            while (cnt == t.length()) {
                if (minLen >= (r - l + 1)) {
                    minLen = (r - l + 1);
                    idx = l;
                }
                freq[s[l]]++;
                if (freq[s[l]] == 1)
                    cnt--;
                l++;
            }
        }
        return idx == -1 ? "" : s.substr(idx, minLen);
    }
};
