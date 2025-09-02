class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if (s.length() == 1 || (s.length() == 2 && s[0]!=s[1]))return false;
        string newStr = s + s;
        for (int i = 1; i<newStr.length() - 1; ++i){
            if (newStr[i] == s[0]){
                int j = 0, curr = i;
                while (i < newStr.length()-1 && j < s.length() && newStr[i] == s[j]){
                    i++, j++;
                }
                if (j == s.length())return true;
                i = curr;
            }
        }
        return false;
    }
};
