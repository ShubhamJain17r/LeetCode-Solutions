class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> seen, added;
        vector<string> res;

        for (int i = 0; i + 9 < s.size(); i++) {
            string sub = s.substr(i, 10);
            if (seen.count(sub) && !added.count(sub)) {
                res.push_back(sub);
                added.insert(sub);
            }
            seen.insert(sub);
        }
        return res;
    }
};
