class Solution {
public:
    inline bool isAlNum(char c) {
        return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }
    inline bool isUpper(char c) {
        return (c >= 'A' && c <= 'Z');
    }
    bool isPalindrome(string s) {
        int l = 0, r = s.length() - 1;

        while (l < r) {
            if (!isAlNum(s[l])) {
                l++;
                continue;
            }
            if (!isAlNum(s[r])) {
                r--;
                continue;
            }
            if (isUpper(s[l])) s[l] += 32;
            if (isUpper(s[r])) s[r] += 32;

            if (s[l] != s[r]) return false;
            l++, r--;
        }
        return true;
    }
};
