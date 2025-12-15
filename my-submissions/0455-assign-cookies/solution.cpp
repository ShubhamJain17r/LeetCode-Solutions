class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0;      // g
        int j = 0;      // s
        while (j < s.size()) {
            if (s[j] >= g[i]) {
                i++;
            }
            if (i == g.size()) return i;
            j++;
        }
        return i;
    }
};
