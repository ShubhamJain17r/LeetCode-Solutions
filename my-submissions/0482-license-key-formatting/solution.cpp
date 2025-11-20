class Solution {
public:
    bool isCapital(char c) {
        return (c >= 'A' && c <= 'Z');
    }
    bool isDigit(char c) {
        return (c >= '0' && c <= '9');
    }
    string licenseKeyFormatting(string s, int k) {
        int len = s.length();
        string ans = "";
        int j = k;
        for (int i = len - 1; i >= 0; i--) {
            if (j == 0) {
                j = k;
                i++;
                if (i > 0)
                    ans.push_back('-');
                // cout<<ans<<endl;
            }
            else {
                char c = s[i];
                if (c == '-') continue;
                if (!isDigit(c) && !isCapital(c))
                    c -= 32;
                ans.push_back(c);
                j--;
            }
        }
        int i = ans.length() - 1;
        while (i >= 0 && ans[i] == '-') ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
