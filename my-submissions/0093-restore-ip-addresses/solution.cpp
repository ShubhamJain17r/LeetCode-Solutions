class Solution {
public:
    bool isValid(string &s) {
        int z = stoi(s);
        if (z == 0) return s.length() == 1;
        if (z > 255 || (int)log10(z) + 1 != s.length()) return false;
        return true;
    }
    void restoreIpAddressesHelper(string &s, int idx, vector<string> &temp, vector<string> &ans) {
        if (idx == s.length()) {
            if (temp.size() == 4) {
                string ipAdd = "";
                for (const string &s : temp)
                    ipAdd = ipAdd + s + '.';
                ipAdd.pop_back();       // remove last .
                ans.push_back(ipAdd);
            }
            return;
        }
        if (temp.size() >= 4) return;

        for (int i = idx; i < idx + 3 && i < s.length(); ++i) {
            string curr = s.substr(idx, i - idx + 1);
            if (!isValid(curr)) continue;
            temp.push_back(curr);
            restoreIpAddressesHelper(s, i + 1, temp, ans);
            temp.pop_back();
        }
    }
    vector<string> restoreIpAddresses(string s) {
        int n = s.length();
        if (n < 4) return {};

        // string curr = "255";     // testing isValid function
        // cout<<isValid(curr);

        vector<string> ans;
        vector<string> temp;

        restoreIpAddressesHelper(s, 0, temp, ans);

        return ans;
    }
};
