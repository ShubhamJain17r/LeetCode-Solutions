class Solution {
public:
    bool hasSameDigits(string s) {
        if (s.length() == 2){
            if (s[0] != s[1])
                return false;
            return true;
        }
        string t = "";
        for (int i = 1; i < s.length(); ++i){
            t.push_back((s[i] - '0' + s[i-1] - '0')%10);
        }
        return hasSameDigits(t);
    }
};
