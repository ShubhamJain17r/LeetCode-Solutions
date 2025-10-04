class Solution {
public:
    string longestPalindrome(string s) {
        int l = s.length();

        int maxLen = 0, currLen = 0;
        string ans = "";

        for (int i = 0; i<l; ++i){
            // check odd length palindrome substring
            int j = i-1, k = i+1;
            currLen = 1;
            while (j >=0 && k<l && s[j] == s[k]){
                currLen += 2;
                j--, k++;
            }
            if (currLen >= maxLen){
                maxLen = currLen;
                ans = s.substr(j+1, maxLen);
                cout<<ans<<endl;
            }

            // check even length palindrome substring
            j = i-1, k = i+1;
            if (s[i] == s[k]){
                k++;
                currLen = 2;
                while (j >=0 && k<l && s[j] == s[k]){
                    currLen += 2;
                    j--, k++;
                }
                if (currLen >= maxLen){
                    maxLen = currLen;
                    ans = s.substr(j+1, maxLen);
                    cout<<ans<<endl;
                }
            }
        }
        return ans;
    }
};
