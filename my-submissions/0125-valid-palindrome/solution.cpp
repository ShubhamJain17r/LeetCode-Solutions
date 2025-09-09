class Solution {
public:
    bool isUpper(char c){
        return c >= 65 && c <= 90; 
    }
    bool isLower(char c){
        return c>=97 && c<=122;
    }
    bool isAlpha(char c){
        return (c >= 65 && c <= 90) || (c>=97 && c<=122);
    }
    bool isDigit(char c){
        return c>='0' && c<='9'; 
    }
    char toLower(char c){
        if (isUpper(c)){
            return c + 32;
        }
        return '\0';
    }
    bool isPalindrome(string s) {
        int n = s.length();
        int st = 0, ed = n-1;

        while (st < ed){
            while (st < ed && !isAlpha(s[st]) && !isDigit(s[st])) st++;
            while (st < ed && !isAlpha(s[ed]) && !isDigit(s[ed])) ed--;
            if (st == ed) return true;

            if (!isDigit(s[st]) && !isLower(s[st])) s[st] = toLower(s[st]);
            if (!isDigit(s[ed]) && !isLower(s[ed])) s[ed] = toLower(s[ed]);

            if (s[st] != s[ed])return false;
            st++, ed--;
        }
        return true;
    }
};
