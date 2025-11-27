class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;  // stores the smallest tail of all increasing subsequences of length i+1
        
        for (int x : nums) {
            auto it = lower_bound(lis.begin(), lis.end(), x);
            
            if (it == lis.end()) {
                lis.push_back(x);     // extend LIS
            } else {
                *it = x;              // replace to keep tails minimal
            }
        }
        
        return lis.size();
    }
};

