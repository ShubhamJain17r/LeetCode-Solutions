class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";

        for (int i = 0; i < strs[0].length(); ++i) {
            char c = strs[0][i];
            for (string &s : strs) {
                if (s.length() <= i || s[i] != c) return ans;
            }
            ans.push_back(c);
        }
        return ans;
    }
};
