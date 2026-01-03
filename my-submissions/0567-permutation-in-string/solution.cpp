class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        if (n > m) return false;

        int hash1[26] = {0};
        int hash2[26] = {0};
        for (int i = 0; i < n; ++i) {
            hash1[s1[i] - 'a']++;
            hash2[s2[i] - 'a']++;
        }
        for (int j = n; j <= m; ++j) {
            // cout<<s2.substr(j - n, n)<<endl;
            bool flag = true;
            for (int i = 0; i < 26 && flag; ++i) {
                if (hash1[i] != hash2[i]) 
                    flag = false;
            }
            if (flag)
                return true;
            if (j == m) return false;
            hash2[s2[j - n] - 'a']--;
            hash2[s2[j] - 'a']++;
        }
        return false;
    }
};
