class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        int n = nums.size();
        
        vector<long long> ans;
        ans.push_back(nums[0]);
        int idx = 0;

        for (int i = 1; i < n; ++i) {
            ans.push_back(nums[i]);
            while (idx >= 0 && ans[idx] == ans[idx + 1]) {
                ans[idx] = 2 * static_cast<long long>(ans[idx]);
                ans.pop_back();
                idx--;
            }
            idx++;
        }
        return ans;
    }
};
