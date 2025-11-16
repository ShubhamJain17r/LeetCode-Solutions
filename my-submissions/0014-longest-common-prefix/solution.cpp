class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prf = "";
        string str = strs[0];
        for (char& c : str) {
            for (string& s : strs) {
                if (s[prf.length()] != c)
                    return prf;
            }
            prf += c;
        }
        return prf;
    }
};
