class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        while (i < s.length() && s[i] == ' ') i++;
        int k = 0;
        for (i; i < s.length(); ++i) {
            if (s[i] != ' ' || s[k - 1] != ' ')
                s[k++] = s[i];
        }
        if (s[k - 1] == ' ') k--;
        s.resize(k);
        string res = "";
        reverse(s.begin(), s.end());
        i = 0;
        while (i < s.length()) {
            int st = i;
            string temp = "";
            while (i < s.length() && s[i] != ' ') {
                temp = s[i] + temp;
                i++;
            }
            res += temp;
            if (i < s.length()) res += " ";
            i++;
        }
        return res;
    }
};
