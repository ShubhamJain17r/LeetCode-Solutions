class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.length();
        int k = t.length();

        int i = 0, j = 0;
        
        while (i < n && j < k){
            if (s[i] == t[j]) i++;
            j++;
        }
        return i==n;
    }
};
