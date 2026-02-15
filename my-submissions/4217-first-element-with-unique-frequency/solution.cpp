class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int, set<int>> freq;
        unordered_map<int, int> elFreq;
        
        for (const int &num : nums) {
            if (elFreq.find(num) == elFreq.end()) {
                freq[1].insert(num);
                elFreq[num] = 1;
            }
            else {
                int f = elFreq[num];
                freq[f].erase(num);
                freq[f + 1].insert(num);
                elFreq[num]++;
            }
        }
        for (const int &num : nums) {
            int f = elFreq[num];
            if (freq[f].size() == 1) {
                return num;
            }
        }
        return -1;
        
    }
};
