class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, int> hash;
        int idx = 0;
        for (string s : strs) {
            string t = s;
            sort(t.begin(), t.end());
            if (hash.count(t) == 0) {
                ans.push_back({s});
                hash[t] = idx;
                idx++;
            }
            else {
                int i = hash[t];
                ans[i].push_back(s);
            }
        }
        return ans;
    }
};
