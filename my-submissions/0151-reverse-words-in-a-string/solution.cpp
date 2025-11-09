class Solution {
public:
    string removeExtraSpaces(string s) {
        int n = s.length();
        int st = 0;
        while (st < n && s[st] == ' ') st++;
        int k = 0;
        for (; st < n; st++) {
            if (s[st] != ' ' || (k > 0 && s[k - 1] != ' '))
                s[k++] = s[st];
        }
        while (k > 0 && s[k-1] == ' ') k--;
        s.resize(k);
        return s;
    }
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        s = removeExtraSpaces(s);
        int n = s.length();
        int start = 0;
        for (int i = 0; i <= n; ++i) {
            if (i == n || s[i] == ' ') {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }
        return s;
    }
};
