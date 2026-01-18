class Solution {
public:
    bool isAlpha(char c) {
        return (c >= 'a' && c <= 'z');
    }
    int vowelConsonantScore(string s) {
        int v = 0;
        int c = 0;

        for (int i = 0; i < s.length(); ++i) {
            char ch = s[i];
            if (isAlpha(ch)) {
                if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                    v++;
                else
                    c++;
            }
        }
        return c > 0 ? (v / c) : 0;
    }
};
