class Solution {
public:
    inline bool isAlpha(char c) {
        return c >= 'a' && c <= 'z';
    }
    string reverseByType(string s) {
        string alpha = "";
        string special = "";

        for (char &c : s) {
            if (isAlpha(c)) {
                alpha.push_back(c);
            }
            else {
                special.push_back(c);
            }
        }

        reverse(alpha.begin(), alpha.end());
        reverse(special.begin(), special.end());

        int i = 0, j = 0;
        string ans = "";
        for (char &c : s) {
            if (isAlpha(c)) {
                ans.push_back(alpha[i++]);
            }
            else {
                ans.push_back(special[j++]);
            }
        }
        return ans;
    }
};
