class Solution {
public:
    char toLower(char c) {
        if (isupper(c))
           c = tolower(c);
        return c;
    }

    string maskPhone(string s) {
        string ans = "";
        int i = s.length() - 1;
        int countNum = 0;
        while (i >= 0) {
            if (isdigit(s[i])) {
                countNum++;
                if (ans.length() < 4)
                    ans.push_back(s[i]);
            }
            i--;
        }
        ans += "-***-***";
        if (countNum == 10) {
            reverse(ans.begin(), ans.end());
            return ans;
        }   
        ans.push_back('-');  
        while (countNum > 10) {
            ans.push_back('*');
            countNum--;
        }
        ans.push_back('+');
        reverse(ans.begin(), ans.end());
        return ans;
    }

    string maskEMail(string s) {
        string ans = "";
        ans.push_back(tolower(s[0]));
        ans += "*****";
        int i = 1;
        while (s[i+1] != '@') i++;
        ans.push_back(toLower(s[i]));
        ans.push_back('@');
        i+=2;
        while (i < s.length()) {
            ans.push_back(toLower(s[i]));
            i++;
        }
        return ans;
    }

    string maskPII(string s) {
        if (isalpha(s[0])) {
            return maskEMail(s);
        }
        return maskPhone(s);
    }
};
