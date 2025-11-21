class Solution {
public:
    string longestPalindrome(string s) {
        string str = "";
        for (int i = 0; i < s.length(); ++i) {
            int x = i - 1, y = i + 1;
            string temp = "";
            temp += s[i];
            while (x >= 0 && y < s.length() && s[x] == s[y]) {
                temp = s[x--] + temp + s[y++];
            }
            if (temp.length() > str.length()) {
                str = temp;
            }
            temp = "";
            temp += s[i];
            if (s[i + 1] == s[i]) {
                temp += s[i+1];
                x = i - 1, y = i + 2;
                while (x >= 0 && y < s.length() && s[x] == s[y]) {
                    temp = s[x--] + temp + s[y++];
                }
                if (temp.length() > str.length()) {
                    str = temp;
                }
            }
        }
        return str;
    }
};
