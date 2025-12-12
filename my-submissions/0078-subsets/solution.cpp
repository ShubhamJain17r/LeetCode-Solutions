class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        int subsets = (1 << n);
        for (int num = 0; num < subsets; ++num) {
            vector<int> subset;
            for (int idx = 0; idx < n; ++idx) {
                if (num & (1 << idx)) {
                    subset.push_back(nums[idx]);
                }
            }
            ans.push_back(subset);
        }
        return ans;
    }
};
