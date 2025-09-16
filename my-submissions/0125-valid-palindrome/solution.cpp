class Solution {
public:
    bool isValid(char c){
        return isUpper(c) || isDigit(c) || isLower(c);
    }
    bool isUpper(char c){
        return (c >='A' && c<='Z');
    }
    bool isDigit(char c){
        return (c>='0' && c<='9');
    }
    bool isLower(char c){
        return (c>='a' && c<='z');
    }
    char toLower(char c){
        if (isUpper(c))
            return c + 32;
        return c;
    }
    bool isPalindrome(string s) {
        int n = s.length();
        int l = 0, r = n-1;
        while (l < r){
            if (!isValid(s[l])){
                l++;
                continue;
            }
            if (!isValid(s[r])){
                r--;
                continue;
            }

            if (s[l] != s[r] && toLower(s[l]) != toLower(s[r])) return false;
            l++, r--;
        }
        return true;
    }
};
