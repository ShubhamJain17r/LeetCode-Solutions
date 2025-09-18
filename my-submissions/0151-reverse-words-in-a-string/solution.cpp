class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());

        int n = s.length();

        int i = 0, j = 0;

        while (i < n){
            if (s[i] == ' '){
                i++;
                continue;
            }
            j = i;
            while (i < n && s[i] != ' ')i++;

            reverse(s.begin() + j, s.begin() + i);
            i++;
        }

        i = 0;
        bool isWordEncountered = (s[0] != ' ');
        int spaceCount = 0;
        while (i < n){
            if (!isWordEncountered){
                while (i < n && s[i] == ' ')i++;
                if (i == n)return s;
                s =  s.substr(i,n);
                n = s.length();
                i = 0;
                isWordEncountered = true;
                continue;
            }
            if (s[i] == ' '){
                spaceCount++;
                if (spaceCount > 1){
                    j = i;
                    while (i < n && s[i] == ' ')i++;
                    if (i == n){
                        s = s.substr(0, j - 1);
                        return s;
                    }
                    s = s.substr(0,j) + s.substr(i,n);
                    n = s.length();
                    i = j-1;
                }
            }
            else {
                spaceCount = 0;
            }
            i++;
        }
        if (s[n-1] == ' ')s = s.substr(0, n-1);

        return s;
    }
};
