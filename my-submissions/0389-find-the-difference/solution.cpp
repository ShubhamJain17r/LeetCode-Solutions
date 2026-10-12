class Solution {
public:
    char findTheDifference(string s, string t) {
        int ans = 0;
        int len = s.size();
        // for (char c : s) {
        //     ans ^= c;
        // }

        // for (char c : t) {
        //     ans ^= c;
        // }

        for (size_t i = 0; i < s.size(); ++i) {
            ans ^= (s[i] ^ t[i]);
        }

        return ans ^ t[len];

        // return ans;
    }
};
