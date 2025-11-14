class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(101, 0);
        vector<int> res;
        res.reserve(n);
        for (int val : nums) {
            count[val]++;
        }
        for (int i = 1; i <= 100; ++i) {
            count[i] += count[i-1];
        }
        for (int val : nums) {
            if (val == 0)
                res.push_back(0);
            else 
                res.push_back(count[val - 1]);
        }
        return res;
    }
};
