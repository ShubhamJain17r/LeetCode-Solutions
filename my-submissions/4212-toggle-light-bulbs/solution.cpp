class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        set<int> s;
        for (const int &bulb : bulbs) {
            if (s.find(bulb) == s.end()) {
                s.insert(bulb);
            }
            else {
                s.erase(bulb);
            }
        }
        vector<int> res;
        for (const auto &bulb : s) {
            res.push_back(bulb);
        }
        return res;
    }
};
